#include <string>
#include <vector>

using std::string;
using std::vector;

struct VexInfo {
    int VexNum;
    string Name;
    string Info;
};

struct ArcNode {
    int AdjVex;
    int Weight;
    ArcNode* NextArc;
};

struct VNode {
    vector<VexInfo> Vex;
    ArcNode* FirstArc;
};

struct ALGraph {
    vector<VNode> VNodes;
    int VexNum;
    int ArcNum;
};

void Menu_1(void);
void LoadFile(VNode&);
void Create(ALGraph&);
void OutputGraph(ALGraph&);