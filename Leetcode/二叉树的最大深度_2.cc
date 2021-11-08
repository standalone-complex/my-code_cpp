
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void traversal(TreeNode* node, int deepth, int& ret) {
    if(!node) {
        return;
    }

    ++deepth;

    if(ret < deepth) {
        ret = deepth;
    }

    traversal(node->left, deepth, ret);
    traversal(node->right, deepth, ret);
}

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int ret=0, deepth=0;

        traversal(root, deepth, ret);
        
        return ret;
    }
};