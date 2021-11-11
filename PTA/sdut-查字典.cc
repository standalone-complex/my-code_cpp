#include <iostream>
// #include <sstream>
#include <vector>
#include <string>
#include <map>

// using std::istringstream;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::map;

int main(void) {
    int n, m;
    string Aline;
    string key;
    string value;
    map<string, string> Map;

    while(cin >> n >> m) {
        if(!n&&!m) {
            break;
        }

        Map = {};

        for(auto i = 0; i<n; ++i) {
            getline(cin, Aline);
            if(Aline == "") {
                getline(cin, Aline);
            }
            
            auto ite = Aline.find(':');
            key = "", value = "";

            for(auto i = 0; i<ite; ++i) {
                key.push_back(Aline[i]);
            }

            for(auto ic = ite+1, ie = Aline.size(); ic!=ie; ++ic) {
                value.push_back(Aline[ic]);
            }

            Map[key] = value;
        }

        for(auto i = 0; i<m; ++i) {
            cin >> Aline;

            if(Map.find(Aline) == Map.cend()) {
                cout << "Not found!" << endl;
            } else {
                cout << Map[Aline] << endl;
            }
        }
    }

    return 0;
}