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

void preorder(TreeNode* node, vector<int>& ret) {
    if(node == nullptr) {
        return;
    }

    ret.push_back(node->val);
    preorder(node->left, ret);
    preorder(node->right, ret);

    return;
}

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;

        preorder(root, ret);

        return ret;
    }
};