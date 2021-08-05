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
    string buf;
    vector<string> lines;

    while(cin >> buf)
    {
        for(auto& c : buf)
        {
            c = toupper(c);
        }

        lines.push_back(buf);
    }

    for(auto t : lines)
    {
        cout << t << endl;
    }

    return 0;
}