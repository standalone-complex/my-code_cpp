#include <stack>
#include <vector>

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> simulator;
        TreeNode* prenode = NULL;

        while(root || !simulator.empty()) {
            while(root) {
                simulator.push(root);
                root = root->left;
            }
            
            // 左子树已经处理完了
            root = simulator.top();
            simulator.pop();

            // 判断右子树是否处理完了
            if(!root->right || root->right==prenode) {
                ret.push_back(root->val);
                // 已经处理完了
                prenode = root;
                root = NULL;
            } else {
                // 二次进栈,优先处理右子树
                simulator.push(root);
                root = root->right;
            }
        }

        return ret;
    }
};