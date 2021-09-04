#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    vector<string> some_string;
    ifstream in("9.3练习1.txt");
    istream_iterator<string> sin(in), eof;

    if(!in)
    {
        exit(1);
    }

    while(sin != eof)
    {
        some_string.push_back(*(sin++));
    }

    //范围for，或者用for_each，里面放lambda，魔怔了草
    //文件中取每个string遇到空格或换行
    for(auto e : some_string)
    {
        cout << e << "\n";
    }
    cout << endl;

    return 0;
}