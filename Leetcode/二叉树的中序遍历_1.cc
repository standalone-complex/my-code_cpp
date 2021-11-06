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

void inorder(TreeNode* node, vector<int>& ret) {
    if(!node) {
        return;
    }

    inorder(node->left, ret);
    ret.push_back(node->val);
    inorder(node->right, ret);
}

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;

        inorder(root, ret);

        return ret;
    }
};

