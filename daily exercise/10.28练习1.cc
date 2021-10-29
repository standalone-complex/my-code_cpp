#include <iostream>
#include <sstream>
#include <map>
#include <string>

using std::string;
using std::map;
using std::istringstream;
using std::cin;
using std::cout;
using std::endl;

int main(void) {
    string str;
    char c;
    map<int, int> m;

    cin >> str;

    istringstream is(str);

    while(is >> c) {
        ++m[c-48];
    }

    for(auto i : m) {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}