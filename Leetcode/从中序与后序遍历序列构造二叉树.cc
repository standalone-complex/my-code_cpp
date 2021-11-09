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
    TreeNode* traversal(int left, int right, vector<int>& inorder, vector<int>& postorder) {
        if(left > right) {
            return nullptr;
        }

        int root_val = postorder[post_index];
        int inorder_index = hashmap[root_val];

        TreeNode* root = new TreeNode(root_val);

        --post_index;

        root->right = traversal(inorder_index+1, right, inorder, postorder);
        root->left = traversal(left, inorder_index-1, inorder, postorder);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx = 0;
        post_index = inorder.size() - 1;
        
        for(auto& i : inorder) {
            hashmap[i] = idx++;
        }

        return traversal(0, inorder.size()-1, inorder, postorder);
    }
private:
    int post_index;
    unordered_map<int, int> hashmap;
};