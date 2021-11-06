#include <vector>
#include <stack>

using std::vector;
using std::stack;

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> simulator;

        while(root != NULL || !simulator.empty()) {
            while(root != NULL) {
                simulator.push(root);
                ret.push_back(root->val);
                root = root->left;
            }

            root = simulator.top();
            simulator.pop();
            root = root->right;
        }
        return ret;
    }
};