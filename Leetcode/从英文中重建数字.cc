#include <sstream>
#include <string>
#include <map>
// #include <set>

using std::istringstream;
using std::string;
using std::map;
// using std::set;

class Solution {
public:
    string originalDigits(string s) {
        // set<char> Set;
        map<int, int> Map{{0,0}, {1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}, {7,0}, {8,0}, {9,0}};
        istringstream in(s);
        char c;
        string ret;

        while(in >> c) {
            // Set.insert(c);
        }

        return ret;
    }
};