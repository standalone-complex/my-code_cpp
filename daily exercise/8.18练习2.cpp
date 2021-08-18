#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    vector<string> string_array;
    string tmp;
    ifstream in("8.18练习.txt");

    while(getline(in, tmp))
    {
        string_array.push_back(tmp);
    }

    auto j = string_array.end();

    for(auto i=string_array.begin(); i!=j; i++)
    {
        cout << *i << endl;
    }

    return 0;
}