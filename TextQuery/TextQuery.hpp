#ifndef _TEXTQUERY_
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

    friend class QueryResult;

    //构造函数
    TextQuery(std::ifstream&);
    QueryResult query(const std::string& s)  { return QueryResult(*this, s); }

    private:

    std::vector<std::string> lines;
    //一个单词对应好多行应该用multimap吧
    //其实可以用map，一个单词对应一个set，其中放出现行数，但是同一行重复出现怎么办？
    std::multimap<std::string, std::size_t> WordToLine;

};

class QueryResult
{
    public:

    QueryResult(TextQuery&, const std::string&);

    private:

    std::size_t AppearTime;
    std::set<std::size_t> lines;
    std::shared_ptr<std::vector<std::string>> pointer;

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

QueryResult::QueryResult(TextQuery& a, const std::string& word)
{
    AppearTime = 0;

    //我们获得了一个map和一个vector
    //应该根据word确定在map中的遍历范围，直接获得ApperTimes和lines
    for(auto i = a.WordToLine.lower_bound(word),
            j = a.WordToLine.upper_bound(word);
            i != j; i++)
    {
        AppearTime++;
        lines.insert((*i).second); //map迭代器解引用后获得一个pair类
    }
}

std::ostream& print(std::ostream& os, QueryResult result);

#endif