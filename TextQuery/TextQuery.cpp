#include <iostream>
#include "TextQuery.hpp"

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