#include <vector>
#include <string>
#include <map>
#include <algorithm>

using std::vector;
using std::string;
using std::map;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int count = 0;
        map<int, string> Map;
        vector<int> Temp(score);
        vector<string> Ret;

        sort(Temp.begin(), Temp.end(),
            [](const int& a, const int& b) {
                return a > b;
            });

        for(auto i : Temp) {
            ++count;
            if(Map.size() == 0) {
                Map[i] = "Gold Medal";
            } else if(Map.size() == 1) {
                Map[i] = "Silver Medal";
            } else if(Map.size() == 2) {
                Map[i] = "Bronze Medal";
            } else {
                Map[i] = std::to_string(count);
            }
        }

        for(auto i : score) {
            Ret.push_back(Map[i]);
        }

        return Ret;
    }
};