#include <vector>
//#include <algorithm>
#include <unordered_map>
#include <stack>

using std::vector;
using std::unordered_map;
using std::stack;

// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> ret;

//         for(auto i : nums1) {
//             flag = false;
//             auto it1 = find(nums2.cbegin(), nums2.cend(), i);

//             for(auto it2 = it1+1, ite = nums2.end(); it2 != ite; ++it2) {
//                 if(*it2 > i) {
//                     ret.push_back(*it2);
//                     flag = true;

//                     break;
//                 }
//             }

//             if(flag == false) {
//                 ret.push_back(-1);
//             }
//         }

//         return ret;
//     }

//     bool flag; //默认为fault
// };

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashmap;
        stack<int> st;
        vector<int> ret;
        int T;
        
        for(auto i = nums2.crbegin(), itb = nums2.crend(); i!=itb; ++i) {
            while(!st.empty() && *i > st.top()) {
                st.pop();
            }
            hashmap[*i] = st.empty() ? -1 : st.top();
            st.push(*i);
        }

        for(auto i : nums1) {
            ret.push_back(hashmap[i]);
        }

        return ret;
    }
};