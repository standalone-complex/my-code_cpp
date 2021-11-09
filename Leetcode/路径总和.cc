struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool traversal(TreeNode* node, int targetSum) {
    if(!node) {
        return false;
    }

    if(node->left == NULL && node->right == NULL) {
        return targetSum == node->val;
    }

    return traversal(node->left, targetSum-node->val) || traversal(node->right, targetSum-node->val);
}

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) {
            return false;
        }

        return traversal(root, targetSum);
    }
};