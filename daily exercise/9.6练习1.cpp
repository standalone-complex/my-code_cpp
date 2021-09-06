#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main(void)
{
    map<string, vector<int>> _1;
    //map类的key_type为关键字的类型，mapped_type为值的类型，value_type为一个pair类型，一个pair保存两个数据类型，这里会保存map的关键字和值的类型
    map<string, vector<int>>::key_type _4;
    map<string, vector<int>>::mapped_type _5;
    map<string, vector<int>>::value_type _6;

    //map的.insert()返回一个pair类，first为一个指向此map的value_type类的迭代器，second为一个bool，根据其中置位判断插入的key是否存在
    auto _2 = _1.insert({"Hello", {1, 2, 3}});
    auto _3 = _1.find("Hello");

    return 0;
}