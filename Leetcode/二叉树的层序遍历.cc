#include <vector>
#include <queue>

using std::vector;
using std::queue;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) {
            return vector<vector<int>>();
        }

        vector<vector<int>> rets;
        vector<int> ret;
        queue<TreeNode*> Queue;

        Queue.push(root);

        while(!Queue.empty()) {
            ret = {};
            
            for(int i = 0, e = Queue.size();
                i!=e; ++i)
            {
                if(Queue.front()->left) {
                    Queue.push(Queue.front()->left);
                }
                if(Queue.front()->right) {
                    Queue.push(Queue.front()->right);
                }

                ret.push_back(Queue.front()->val);
                Queue.pop();
            }

            rets.push_back(ret);
        }

        return rets;
    }
};