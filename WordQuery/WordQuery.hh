#ifndef _WORDQUERY_
#define _WORDQUERY_

#include "/home/tyf/Code/my-code_cpp/TextQuery/TextQuery.hh"
#include <iostream>
#include <string>
#include <memory>
#include <set>
#include <iterator>
#include <algorithm>

class QueryBase {
    friend class Query;
protected:
    virtual ~QueryBase() { }
    using line_no = TextQuery::line_no;
private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual std::string rep() const = 0;
};

class Query {
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    Query(const std::string&);

    QueryResult eval(const TextQuery& t) const { return q->eval(t); };
    std::string rep() const {return q->rep(); }
private:
    Query(std::shared_ptr<QueryBase> query): q(query) { }
    std::shared_ptr<QueryBase> q;
};

inline
std::ostream& operator<<(std::ostream& os, const Query& query) {
    return os << query.rep();
}

class WordQuery: public QueryBase {
    friend class Query;
    WordQuery(const std::string& word): query_word(word) { }
    
    QueryResult eval(const TextQuery& t) const { return t.query(query_word); }
    std::string rep() const { return query_word; }
    std::string query_word;
};

inline
Query::Query(const std::string& word): q(new WordQuery(word)) { }

class NotQuery: public QueryBase {
    friend Query operator~(const Query&);
    NotQuery(const Query& q): query(q) { }

    QueryResult eval(const TextQuery& t) const;
    std::string rep() const { return "~(" + query.rep() + ")"; }
    Query query;
};

class BinQuery: public QueryBase {
protected:
    BinQuery(const Query& l, const Query& r, const std::string sign): lhs(l), rhs(r), sign(sign) { }

    std::string rep() const { return "(" + lhs.rep() + " " + sign + " " + rhs.rep() + ")"; }

    Query lhs, rhs;
    std::string sign;
};

class AndQuery: public BinQuery {
    friend Query operator&(const Query&, const Query&);

    AndQuery(const Query& l, const Query& r): BinQuery(l, r, "&") { }

    QueryResult eval(const TextQuery&) const;
};

class OrQuery: public BinQuery {
    friend Query operator|(const Query&, const Query&);

    OrQuery(const Query& l, const Query& r): BinQuery(l, r, "|") { }

    QueryResult eval(const TextQuery&) const;
};

inline
Query operator&(const Query& lhs, const Query& rhs) {
    return std::shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
}

inline
Query operator|(const Query& lhs, const Query& rhs) {
    return std::shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}

inline
Query operator~(const Query& nq) {
    return std::shared_ptr<QueryBase>(new NotQuery(nq));
}

QueryResult NotQuery::eval(const TextQuery& TQ) const {
    QueryResult ret = query.eval(TQ);
    std::shared_ptr<std::set<line_no>> ret_SetPtr(new std::set<line_no>);

    std::set<line_no>::const_iterator itc = ret.begin(), ite = ret.end();

    std::vector<std::string>::size_type sz = ret.get_file()->size();

    //这段循环匹配算法挺有意思的
    for(std::size_t n=0; n!=sz; ++n) {
        if(itc == ite || *itc != n) {
            ret_SetPtr->insert(n);
        } else if(itc != ite) {
            ++itc;
        }
    }

    return QueryResult(rep(), ret.get_file(), ret_SetPtr);
}

QueryResult AndQuery::eval(const TextQuery& TQ) const {
    QueryResult left = lhs.eval(TQ), right = rhs.eval(TQ);

    std::shared_ptr<std::set<line_no>> ret_SetPtr(new std::set<line_no>);

    //对这个算法和这个迭代器容器的了解不深
    std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), std::inserter(*ret_SetPtr, ret_SetPtr->begin()));

    return QueryResult(rep(), left.get_file(), ret_SetPtr);
}

QueryResult OrQuery::eval(const TextQuery& TQ) const {
    QueryResult left = lhs.eval(TQ), right = rhs.eval(TQ);

    std::shared_ptr<std::set<line_no>> ret_SetPtr(new std::set<line_no>(left.begin(), left.end()));

    ret_SetPtr->insert(right.begin(), right.end());

    return QueryResult(rep(), left.get_file(), ret_SetPtr);
}

#endif