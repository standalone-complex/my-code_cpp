struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool traversal(TreeNode* lnode, TreeNode* rnode) {
    if(!lnode && !rnode) { return true; }
    if(!lnode || !rnode) { return false; }

    return lnode->val==rnode->val && traversal(lnode->right, rnode->left) && traversal(lnode->left, rnode->right);
}

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // 递归三要素：确定递归目的；确定递归结束条件；缩小递归范围
        return traversal(root, root);
    }
};