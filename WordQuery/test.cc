#include <iostream>
#include <fstream>
#include "WordQuery.hh"

using namespace std;

int main(void)
{
    ifstream in("/home/tyf/my-code_cpp/TextQuery/storyDataFile");
    TextQuery TQ(in);

    Query res = Query("a") & Query("he");

    print(cout, res.eval(TQ)) << endl;

    return 0;
}