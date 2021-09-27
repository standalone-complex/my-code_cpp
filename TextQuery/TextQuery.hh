#ifndef _TEXTQUERY_
#define _TEXTQUERY_

#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <map>
#include <set>

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
};

class QueryResult {
    friend std::ostream& print(std::ostream&, const QueryResult&);

    public:
    using line_no = std::vector<std::string>::size_type;

    QueryResult(std::string Word,
                std::shared_ptr<std::vector<std::string>> VecPtr,
                std::shared_ptr<std::set<line_no>> SetPtr):
        Word(Word), VecPtr(VecPtr), SetPtr(SetPtr) { }

    private:
    std::string Word;
    std::shared_ptr<std::vector<std::string>> VecPtr;
    std::shared_ptr<std::set<line_no>> SetPtr;
};

#endif