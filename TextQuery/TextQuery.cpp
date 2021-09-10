#include <iostream>
#include "TextQuery.hpp"

/*
    首先是TextQuery类的设计，一个动态分配的vecotr<string>和一个从字符串指向一个指向set的指针的map
    接收一个ifstream流初始化，将文本以行为单位保存在vector中，将单词所在的行加入map对应值的动态分配的set中
    QueryResult类接收一个string，一个指向set<size_t>的指针，还有一个指向vector<string>的指针
    然后就可以输出，从set中得到出线次数和行号，带入vector的下标输出行信息
*/

using namespace std;

void RunQuery(ifstream&);

int main(int argc, char* argv[])
{
    if(argc != 1)
    {
        cout << "error format!" << endl;

        return 0;
    }

    ifstream in(argv[0]);

    if(!in)
    {
        cout << "no such file!" << endl;

        exit(1);
    }

    RunQuery(in);

    return 0;
}

void RunQuery(ifstream& infile)
{
    string s;
    TextQuery tq(infile);

    while(true)
    {
        cout << "enter word to look for, or q to quit: ";

        if(!(cin>>s) || s == "q")
        {
            break;
        }

        print(cout, tq.query(s)) << endl;
    }

    return;
}