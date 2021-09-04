#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string& trans(string& str)
{
    int i;

    for(i=0; i<str.size(); i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] -= ('A' - 'a');
        }

        if(str[i]==',' || str[i]=='.' || str[i]=='!')
        {
            str.erase(i, 1);
        }
    }

    return str;
}

int main(void)
{
    string word;
    map<string, string::size_type> words;
    ifstream in("9.4练习1.txt");

    while(in >> word)
    {
        ++words[trans(word)];
    }

    for(auto i : words)
    {
        cout << i.first << " occurred " << i.second << endl;
    }

    return 0;
}