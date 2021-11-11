#include <iostream>
#include <set>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::set;
using std::vector;
using std::string;

int main(void) {
    string Word;
    set<string> Set;

    while(cin >> Word) {
        if(Word == "!!!!!") {
            break;
        }
        
        Set.insert(Word);
    }
    
    cout << Set.size() << endl;

    if(Set.size() > 10) {
        auto itc = Set.cbegin();
        for(int i = 0; i<10; ++itc, ++i) {
            cout << *itc << endl;
        }
    } else {
        for(auto i : Set) {
            cout << i << endl;
        }
    }

    return 0;
}