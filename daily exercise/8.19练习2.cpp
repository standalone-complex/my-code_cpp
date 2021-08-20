#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string s1("tho");
    string s2("thru");
    string s3("Man");

    s1.insert(s1.size(), "ugh");
    s2.erase(s2.size()-1);
    s2.insert(s2.size(), "ough");

    cout << s1 << " " << s2 << endl;

    return 0;
}