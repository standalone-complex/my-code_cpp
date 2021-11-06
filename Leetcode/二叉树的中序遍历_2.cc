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

// 递归实际上是运行时栈，而迭代用一个显式的栈容器来解决，二者本质上是一致的
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> simulator;
        // 中序遍历
        while(root!=NULL || !simulator.empty()) {
            while(root != NULL) {
            simulator.push(root);
            root = root->left;
            }

            root = simulator.top();
            simulator.pop();
            ret.push_back(root->val);
            root = root->right;
        }

        return ret;
    }
};