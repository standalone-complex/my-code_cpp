#include <iostream>
#include <algorithm>
#include "StrBlob.hpp"

using namespace std;

int main(void)
{
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
        cout << b2.size() << endl;
    }

    cout << b1.size() << endl;
    cout << b1.front() << " " << b1.back() << endl;

    const StrBlob b3 = b1;
    cout << b3.front() << " " << b3.back() << endl;

    //it1!=it2暂时实现不了
    /*for(auto it1 = b1.begin(),
        it2 = b1.end(); it1!=it2; it1.incr())
    {
        cout << it1.deref() << endl;
    }*/

    return 0;
}