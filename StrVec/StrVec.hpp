#ifndef _STRVEC_
#define _STRVEC_

#include <iostream>
#include <utility>
#include <string>
#include <memory>
#include <algorithm>

class StrVec
{
    public:

    StrVec():
    elements(nullptr), first_free(nullptr), cap(nullptr) { }

    StrVec(const StrVec&);
    StrVec(std::initializer_list<std::string>);
    StrVec& operator=(const StrVec&);
    ~StrVec();

    void push_back(const std::string&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string* begin() const { return elements; }
    std::string* end() const { return first_free; }
    void reserve(size_t n) { if(n > capacity()) reallocate(n); };
    void resize(size_t);
    void resize(size_t, const std::string& s);

    private:

    void free();
    void reallocate();
    void reallocate(size_t);
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
    void chk_n_alloc() { if(size() == capacity()) reallocate(); }

    static std::allocator<std::string> alloc;

    std::string* elements;
    std::string* first_free;
    std::string* cap;

};

inline
void StrVec::push_back(const std::string& s)
{
    chk_n_alloc();

    alloc.construct(first_free++, s);

    return;
}

inline
std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string* b, const std::string* e)
{
    auto data = alloc.allocate(e - b);

    return {data, uninitialized_copy(b, e, data)};
}

inline
void StrVec::free()
{
    if(elements)
    {
        for(auto p=first_free; p!=elements; /*empty*/)
        {
            alloc.destroy(--p);
        }

        /* for_each + lambda version
            for_each(elements, first_free,
                [] (std::string& s) { alloc.destroy(&s); });
        */

        alloc.deallocate(elements, cap-elements);
    }

    return;
}

inline
StrVec::~StrVec() { free(); }

inline
StrVec::StrVec(const StrVec& s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());

    elements = newdata.first;
    first_free = newdata.second;
    cap = newdata.second;
}

inline
StrVec::StrVec(std::initializer_list<std::string> il)
{
    auto newdata = alloc_n_copy(il.begin(), il.end());

    elements = newdata.first;
    first_free = newdata.second;
    cap = newdata.second;
}

inline
StrVec& StrVec::operator=(const StrVec& rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());

    free();

    elements = data.first;
    first_free = data.second;

    return *this;
}

inline
void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;

    auto newdata = alloc.allocate(newcapacity);

    auto dest = newdata;
    auto elem = elements;

    for(size_t i=0; i!=size(); i++)
    {
        alloc.construct(dest++, std::move(*elem++));
    }

    free();

    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;

    return;
}

inline
void StrVec::reallocate(size_t newcapacity)
{
    auto newdata = alloc.allocate(newcapacity);

    auto dest = newdata;
    auto elem = elements;

    for(size_t i=0; i!=size(); i++)
    {
        alloc.construct(dest++, std::move(*elem++));
    }

    free();

    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;

    return;
}

inline void StrVec::resize(size_t n, const std::string& s = "")
{
    if(n > size())
    {
        while(n > size())
        {
            push_back(s);
        }
    }
    else if(n < size())
    {
        while(n > size())
        {
            alloc.destroy(--first_free);
        }
    }

    return;
}

#endif