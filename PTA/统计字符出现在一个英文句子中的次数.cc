#include <iostream>
// #include <sstream>
#include <string>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
// using std::istringstream;

void trans(char& c);

int main(void) {
    bool flag(true);
    string Aline;
    char c;
    unordered_map<char, int> Map;
    while(cin.get(c)) {
        trans(c);

        if(Map.find(c) ==Map.cend()) {
            Map[c] = 1;
        } else {
            ++Map[c];
        }
    }
    cout << "{";
    for(auto i : Map) {
        if(flag) {
            flag = false;
        } else {
            cout << ",";
        }
        
        cout << "\'" << i.first << "\'" << ":" << i.second;
    }
    cout << "}";

    return 0;
}

void trans(char& c) {
    if(c>='A' and c<='Z') {
        c += 32;
    }

    return;
}