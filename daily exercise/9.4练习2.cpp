#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(void)
{
    map<string, vector<string>> families;

    //如果map中还没有佟
    if(families.find("佟") == families.end())
    {
        families["佟"];
    }

    families["佟"].push_back("亦凡");

    /*auto i = families.cbegin();
    auto j = families.cend();

    for(auto i = families.cbegin(); i != j; i++)
    {
        cout << i->first << "家："<< endl;

        for(auto k : i->second)
        {
            cout << k <<endl;
        }
    }
    */

    for(auto i : families)
    {
        cout << i.first;

        for(auto j : i.second)
        {
            cout << j << endl;
        }
    }

    return 0;
}