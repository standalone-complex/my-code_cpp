#ifndef PERSON

#define PERSON

#include <string>

using namespace std;

struct Person 
{
    std::string name;
    std::string address;

    /* 为什么不直接用.name或者.address呢,还写个成员函数来不是多此一举？ */
    std::string GetName() const { return name;}
    std:: string GetAddress() const { return address;}
};

#endif