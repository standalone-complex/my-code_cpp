#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;

        for(auto i = 0; i<nums.size(); ++i) {
            auto it = hashtable.find(target-nums[i]);

            if(it != hashtable.cend()) {
                return {it->second, i};
            }

            hashtable[nums[i]] = i;
        }

        return {};
    }
};