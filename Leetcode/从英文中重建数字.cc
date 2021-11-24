#include <string>
#include <vector>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_map;

class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> HashTable;
        for (char ch: s) {
            ++HashTable[ch];
        }

        vector<int> cnt(10);
        cnt[0] = HashTable['z'];
        cnt[2] = HashTable['w'];
        cnt[4] = HashTable['u'];
        cnt[6] = HashTable['x'];
        cnt[8] = HashTable['g'];

        cnt[3] = HashTable['h'] - cnt[8];
        cnt[5] = HashTable['f'] - cnt[4];
        cnt[7] = HashTable['s'] - cnt[6];

        cnt[1] = HashTable['o'] - cnt[0] - cnt[2] - cnt[4];

        cnt[9] = HashTable['i'] - cnt[5] - cnt[6] - cnt[8];

        string ans;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                ans += char(i + '0');
            }
        }
        return ans;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/reconstruct-original-digits-from-english/solution/cong-ying-wen-zhong-zhong-jian-shu-zi-by-9g1r/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。