#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include "/home/tyf/Downloads/json.hpp"
// #include "/home/tyf/my-code_cpp/Leetcode/二叉树的中序遍历_1.cc"

using std::cin;
using std::cout;
using std::ofstream;
using std::endl;
using std::string;
using std::map;
using std::vector;
using nlohmann::json;

struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(char x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 自底向上
TreeNode* HuffmanTree(map<int, char>&);
void HuffmanCode(TreeNode*, map<string, string>&);

int main(void) {
    int n1, n3;
    string n2;
    map<int, TreeNode*> HuffmanTable;
    map<char, string> Map_Ret;
    vector<int> Vec;
    json js;

    cin >> n1 >> n2;

    while(cin >> n3) {
        Vec.push_back(n3);
    }

    for(int i = 0, e = Vec.size();
        i<e; ++i)
    {
        HuffmanTable[Vec[i]] = new TreeNode(n2[i]);
    }

    TreeNode* root = HuffmanTree(HuffmanTable);

    HuffmanCode(root, Map_Ret, "");

    for(auto i : Map_Ret) {
        js[i.second] = i.first;
        cout << i.first << ":" << i.second << endl;
    }

    string CodeMap(js.dump());

    ofstream os("HuffmanTable.json");

    os << CodeMap << endl;

    return 0;
}

TreeNode* HuffmanTree(map<int, TreeNode*>& Table) {
    if(Table.size() == 0) {
        return nullptr;
    }

    if(Table.size() == 1) {
        return Table[0];
    }

    TreeNode* Node1 = Table[0];
    TreeNode* Node2 = Table[1];

    TreeNode* NewNode = new TreeNode('\0', Node1, Node2);
    
    auto it = Table.cbegin();

    int NewWeight = it++->first + it->first;
    Table.erase(it--->first);
    Table.erase(it->first);
    Table[NewWeight] = NewNode;

    HuffmanTree(Table);
}

void HuffmanCode(TreeNode* node, map<char, string>& map_ret, string Code) {
    if(!node) {
        return;
    }
    
    if(!node->left && !node->right) {
        map_ret[node->val] = Code;
        return;
    }

    string lCode = Code + '0';
    string rCode = Code + '1';

    HuffmanCode(node->left, map_ret, lCode);
    HuffmanCode(node->right, map_ret, rCode);
}