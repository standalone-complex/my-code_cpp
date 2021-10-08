#include <iostream>
#include <sstream>

using namespace std;

int main(void)
{
    int a, b;
    string s;

    while(getline(cin, s))
    {
        istringstream is(s);
        is >> a;
        a = 0, b = 0;
        while(is >> a)
        {
            b += a;
        }
        cout << b << endl;
    }

    return 0;
}