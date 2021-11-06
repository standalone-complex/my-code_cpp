#include <vector>

using std::vector;

//用一个桶就可以解决问题 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> bucket(nums.size()+1);

        for(auto i : nums) {
            ++bucket[i];
        }

        for(auto i = 1; i!=bucket.size(); ++i) {
            if(bucket[i] == 0) {
                return i;
            }
        }

        return 0;
    }
};