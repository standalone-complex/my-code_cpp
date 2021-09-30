#ifndef _TEXTQUERY_
#define _TEXTQUERY_

#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <map>
#include <set>
#include <ctype.h>

class QueryResult;

std::ostream& print(std::ostream&, const QueryResult&);

class TextQuery {
    friend class QueryResult;

    public:
    using line_no = std::vector<std::string>::size_type;

    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;

    private:
    std::shared_ptr<std::vector<std::string>> VecPtr;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> Map;
    static std::string cleanup_str(const std::string& word);
};

class QueryResult {
    friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    using line_no = std::vector<std::string>::size_type;

    QueryResult(std::string Word,
                std::shared_ptr<std::vector<std::string>> VecPtr,
                std::shared_ptr<std::set<line_no>> SetPtr):
        Word(Word), VecPtr(VecPtr), SetPtr(SetPtr) { }

    std::set<line_no>::size_type size() const { return SetPtr->size(); }
    std::set<line_no>::const_iterator begin() const { return SetPtr->begin(); }
    std::set<line_no>::const_iterator end() const { return SetPtr->end(); }
    std::shared_ptr<std::vector<std::string>> get_file() { return VecPtr; }
private:
    std::string Word;
    std::shared_ptr<std::vector<std::string>> VecPtr;
    std::shared_ptr<std::set<line_no>> SetPtr;
};

inline
TextQuery::TextQuery(std::ifstream& infile): VecPtr(new std::vector<std::string>)
{
    std::string Aline;
    std::string Aword;
    line_no n;

    while(getline(infile, Aline))
    {
        VecPtr->push_back(Aline);
        n = VecPtr->size() - 1;

        std::istringstream Wordstream(Aline);
        while(Wordstream >> Aword)
        {
            Aword = cleanup_str(Aword);

            auto& SetPtr = Map[Aword];

            if(!SetPtr)
            {
                SetPtr.reset(new std::set<line_no>);
            }

            SetPtr->insert(n);
        }
    }
}

inline
std::string TextQuery::cleanup_str(const std::string& word)
{
    std::string ret;

    for(std::string::const_iterator it = word.cbegin(); it!=word.cend(); ++it)
    {
        //如果不是标点符号
        if(!ispunct(*it))
        {
            //转换小写
            ret += tolower(*it);
        }
    }

    return ret;
}

inline
QueryResult TextQuery::query(const std::string& word) const
{
    //为什么是static
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);

    std::map<std::string, std::shared_ptr<std::set<line_no>>>::const_iterator it = Map.find(cleanup_str(word));

    //it是一个pair类
    if(it == Map.cend())
    {
        return QueryResult(word, VecPtr, nodata);
    }
    else
    {
        return QueryResult(word, VecPtr, it->second);
    }
}

inline
std::string make_plural(std::size_t ctr, const std::string &word, const std::string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

inline
std::ostream& print(std::ostream& os, const QueryResult& result)
{
    os << result.Word << " occurs " << result.SetPtr->size() << " " << make_plural(result.SetPtr->size(), "time", "s") << std::endl;

    for(std::set<TextQuery::line_no>::const_iterator it=result.SetPtr->cbegin(); it!=result.SetPtr->cend(); ++it)
    {
        os << "\t(line " << *it + 1 << ") " << *(result.VecPtr->cbegin() + *it) << std::endl;
    }

    return os;
}

#endif