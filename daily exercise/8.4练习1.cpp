#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(void)
{
    string buf = "hello";
    string::size_type len;
    vector<int> v;
    vector<vector<int>> ivec;
    // vector<string> svec = ivec; 错误
    vector<string> svec(10, "null");

    //getline(cin, buf);

    len = buf.size();

    cout << buf.size() << " " << buf  << " " << len << endl;

    for(auto& c : buf)
    {
        c = toupper(c);

        cout << c;
    }

    cout << endl;

    return 0;
}