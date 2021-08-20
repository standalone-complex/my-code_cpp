#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    /* capacity */
    /* reserve */
    /* shrink */
    /* assign */
    /* replace */
    /* erase */
    vector<string> word_array;
    string word;
    fstream in("8.18练习.txt");

    while(in >> word)
    {
        word_array.push_back(word);
    }

    auto j = word_array.end();

    for(auto i=word_array.begin(); i!=j; i++)
    {
        cout << *i << endl;
    }

    return 0;
}