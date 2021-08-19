#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <deque>

using namespace std;

istream& fun(istream&);

int main(void)
{
    stringstream ss("Hello World!");

    fun(ss);

    return 0;
}

istream& fun(istream& is)
{
    char c;

    while(is >> c)
    {
        cout << c;
    }

    cout << endl;

    

    return is;
}