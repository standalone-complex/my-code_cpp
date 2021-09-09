#ifndef _TEXTQUERT_
#define _TEXTQUERY_

#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <memory>

class QueryResult;

class TextQuery
{
    public:

    //构造函数
    TextQuery(std::ifstream&);
    QueryResult& query(const std::string&);

    private:

    std::vector<std::string> lines;
    //一个单词对应好多行应该用multimap吧
    std::multimap<std::string, std::size_t> WordToLine;

};

class QueryResult
{
    public:

    QueryResult(TextQuery, const std::string&);

    private:

    std::size_t AppearTime;
    std::set<std::size_t> lines;
    std::shared_ptr<TextQuery> pointer;

};

TextQuery::TextQuery(std::ifstream& infile)
{
    std::size_t counter = 1;
    std::string words;
    std::string word;

    while(getline(infile, words))
    {
        lines.push_back(words);
        std::istringstream iss(words);

        while(iss >> word)
        {
            //想起来了multimap类不支持下标运算，因为不是一一对应
            WordToLine.insert({word, counter});
        }

        counter++;
    }
}

std::ostream& print(std::ostream& os, QueryResult& result);

#endif