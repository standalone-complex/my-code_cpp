#include <iostream>
#include <string>
#include <map>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::vector;

bool judge(string);

int main(void) {
    vector<string> IDs;
    string Astring;
    int n;
    bool flag(false);

    cin >> n; 

    while(cin >> Astring) {
        if(!judge(Astring)) {
            // cout << Astring << endl;
            IDs.push_back(Astring);
            flag = true;
        }
    }

    if(!flag) {
        cout << "All passed" << endl;
        return 0;
    } else {
        for(auto i : IDs) {
            cout << i << endl;
        }
    }

    return 0;
}

bool judge(string ID) {
    for(int i = 0; i<17; ++i) {
        if(ID[i]<'0' or ID[i]>'9') {
            return false;
        }
    }

    map<int, int> Map_1 = {{0,7}, {1,9}, {2,10}, {3,5}, {4,8}, {5,4}, {6,2}, {7,1}, {8,6},
                            {9,3}, {10,7}, {11,9}, {12,10}, {13,5}, {14,8}, {15,4}, {16,2}};
    map<int, char> Map_2 = {{0,'1'}, {1,'0'}, {2,'X'}, {3,'9'}, {4,'8'}, {5,'7'}, {6,'6'}, {7,'5'}, {8,'4'}, {9,'3'}, {10,'2'}};

    int sum = 0;

    for(int i = 0; i<17; ++i) {
        sum += (ID[i]-'0') * Map_1[i];
    }

    // sum /= 100;
    sum %= 11;

    if(Map_2[sum] == ID[ID.size()-1]) {
        return true;
    } else {
        return false;
    }
}