#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    string name;
    vector<string> Vec;

    while(cin >> name) {
        if(name == "end")
            break;
        Vec.push_back(name);
    }

    sort(Vec.begin(), Vec.end());

    for(auto i = Vec.begin(); i != Vec.end(); ++i) {
        cout << *i << " ";
    }

    cout << endl;

    return 0;
}