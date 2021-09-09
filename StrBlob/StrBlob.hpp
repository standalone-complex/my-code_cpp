#ifndef _STRBLOB_

#define _STRBLOB_

//#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
#include <stdexcept>

//前向声明
class StrBlobPtr;

//最终目标是实现一个模板类，现在只是做一个可以共享底层内存的vector<string>型
class StrBlob
{
    public:

    //友元声明
    friend class StrBlobPtr;
    
    typedef std::vector<std::string>::size_type size_type;

    //空初始化
    StrBlob(): data(std::make_shared<std::vector<std::string>>()){ };
    //列表初始化
    StrBlob(std::initializer_list<std::string> il):
    data(std::make_shared<std::vector<std::string>>(il)) { };

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back (const std::string& t) { data->push_back(t); }
    //pop_back里需要一个check函数
    void pop_back ();
    std::string& front();
    std::string& front() const;
    std::string& back();
    std::string& back() const;
    StrBlobPtr begin() { return StrBlobPtr(*this); }
    StrBlobPtr begin() const { return StrBlobPtr(*this); }
    StrBlobPtr end()
    {
        auto ret = StrBlobPtr(*this, data->size());
        return ret;
    }
    StrBlobPtr end() const
    {
        auto ret = StrBlobPtr(*this, data->size());
        return ret;
    }

    private:
    
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string& msg) const;

};

//为了展示weak_ptr的作用，我们为StrBlob类定义一个伴随指针类StrBlobPtr
class StrBlobPtr
{
    public:

    //构造
    StrBlobPtr(): curr(0) { }
    StrBlobPtr(StrBlob& a, size_t sz = 0):
    wptr(a.data), curr(sz) { };
    StrBlobPtr(const StrBlob& a, std::size_t sz = 0):
    wptr(a.data), curr(sz) { };

    //解引用
    std::string& deref() const;
    //前缀递增
    StrBlobPtr& incr();

    private:

    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
    //check函数
    std:: shared_ptr<std::vector<std::string>>
    check(std::size_t, const std::string&) const;

};

inline
void StrBlob::check(size_type i, const std::string& msg) const
{
    if(i >= data->size())
    {
        throw std::out_of_range(msg);
    }

    return;
}

inline
void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();

    return;
}

inline
std::string& StrBlob::front()
{
    check(0, "front on empty StrBlib");
    return data->front();
}

inline
std::string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

inline
std::string& StrBlob::front() const
{
    check(0, "front on empty StrBlib");
    return data->front();
}

inline
std::string& StrBlob::back() const
{
    check(0, "front on empty StrBlib");
    return data->back();
}

inline
std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string& msg) const
{
    auto ret = wptr.lock();

    if(!ret)
    {
        throw std::runtime_error("unbound StrBlobPtr");
    }

    if(i >= ret->size())
    {
        throw std::out_of_range(msg);
    }

    return ret;
}

inline
std::string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");

    return (*p)[curr];
}

inline
StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    curr++;

    return *this;
}

#endif