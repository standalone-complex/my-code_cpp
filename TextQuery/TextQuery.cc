#include "TextQuery.hh"

using namespace std;

void RunQuery(ifstream&);

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        cout << "error format!" << endl;
        exit(1);
    }

    ifstream input(argv[1]);

    RunQuery(input);

    return 0;
}

void RunQuery(ifstream& infile)
{
    TextQuery TQ(infile);
    string s;

    while(true)
    {
        cout << "enter word to look for, or q to quit: " << flush;
        
        if(!(cin >> s) || s == "q")
        {
            break;
        }

        print(cout, TQ.query(s)) << endl;
    }

    return;
}