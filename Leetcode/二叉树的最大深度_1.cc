#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int traversal(TreeNode* node) {
    if(!node) {
        return 0;
    }

    return std::max(traversal(node->left), traversal(node->right)) + 1;
}

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int ret;

        ret = traversal(root);

        return ret;
    }
};