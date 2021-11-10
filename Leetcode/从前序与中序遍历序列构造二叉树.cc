#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

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
    TreeNode* traversal(int left, int right, vector<int>& preorder, vector<int>& inorder) {
        if(left > right) {
            return nullptr;
        }

        int root_val = preorder[pre_index];
        int inorder_index = hashmap[root_val];
        ++pre_index;

        TreeNode* root = new TreeNode(root_val);

        root->left = traversal(left, inorder_index-1, preorder, inorder);
        root->right = traversal(inorder_index+1, right, preorder, inorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        pre_index = 0;
        
        for(auto& i : inorder) {
            hashmap[i] = idx++;
        }

        return traversal(0, preorder.size()-1, preorder, inorder);
    }
private:
    int pre_index;
    unordered_map<int, int> hashmap;
};