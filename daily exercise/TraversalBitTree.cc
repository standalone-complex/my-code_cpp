#include <iostream>
#include <vector>
#include <string>
#include "/home/tyf/my-code_cpp/Leetcode/二叉树的中序遍历_1.cc"

using std::vector;
using std::string;

TreeNode* Create_BitTree(void);

int main(void) {
    vector<int> Vec;
    Solution obj;

    TreeNode* root = Create_BitTree();

    Vec = obj.inorderTraversal(root);

    for(auto& i : Vec) {
        std::cout << i << " ";
    }
}

TreeNode* Create_BitTree(void) {
    string c;

    std::cout << "请输入节点的值：" << std::endl;
    std::cin >> c;

    if(c == "#") {
        return nullptr;
    }

    TreeNode* node = new TreeNode(atoi(c.c_str()));

    node->left = Create_BitTree();
    node->right = Create_BitTree();

    return node;
}