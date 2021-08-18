#include <iostream>
#include <string>
#include <vector>

using namespace std;

istream& fun(istream&);

int main(void)
{
    fun(cin);

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