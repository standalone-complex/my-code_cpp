#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void) {
    string name, phone;
    map<string, string> Map;
    
    while(cin >> name) {
        if(name == "noname")
            break;
        cin >> phone;
        Map[name] = phone;
    }
    
    cin >> name;
    
    if(Map.find(name) == Map.end()) {
        cout << "Not Found." << endl;
        return 0;
    }

    cout << Map[name] << endl;
    
    return 0;
}