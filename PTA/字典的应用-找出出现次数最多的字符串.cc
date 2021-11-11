#include <iostream>
#include <string>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

int main(void) {
    int max_int;
    string Astring, max_string;
    map<string, int> Map;

    while(cin >> Astring) {
        if(Astring == "q") {
            break;
        }

        if(Map.find(Astring) == Map.cend()) {
            Map[Astring] = 1;
        } else {
            ++Map[Astring];
        }
    }

    auto itc = Map.cbegin();

    max_string = itc->first;
    max_int = itc->second;
    ++itc;

    for(auto ite = Map.cend(); itc!=ite; ++itc) {
        if(itc->second > max_int) {
            max_string = itc->first;
            max_int = itc->second;
        }
    }

    cout << max_string << " " << max_int << endl;

    return 0;
}