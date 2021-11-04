#include <iostream>
#include <map>
// #include <set>
#include <string>
#include <algorithm>

using std::string;
// using std::set;
using std::multimap;
using std::cin;
using std::endl;
using std::cout;

int main(void) {
    int T, n, temp_score, temp_count, target_score, target_count, critical, nn;
    string target_team, temp_team;
    multimap<int, int> Map;
    // set<int> Set;

    cin >> T;

    while(T) {
        cin >> n >> target_team;
        nn = n;
        Map = multimap<int, int>();

        while(n) {
            cin >> temp_team >> temp_count >> temp_score;

            if(temp_team == target_team) {
                target_count = temp_count;
                target_score = temp_score;
            }

            // Map[temp_count] = temp_score;
            Map.insert(std::make_pair(temp_count, temp_score));

            --n;
        }

        critical = 0.4 * nn;

        auto it = Map.cbegin();
        
        while(critical) {
            it++;
            --critical;
        }

        if(it->first <= target_count && it->second <= target_score) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

        --T;
    }

    return 0;
}