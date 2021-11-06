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

void postorder(TreeNode* node, vector<int>& ret) {
    if(node == NULL) {
        return;
    }

    postorder(node->left, ret);
    postorder(node->right, ret);
    ret.push_back(node->val);
}

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        
        postorder(root, ret);

        return ret;
    }
};