#include <iostream>
#include <fstream>
#include "Navigation.hh"

using std::cin;
using std::cout;
using std::endl;
using std::fstream;

int LocateVex(ALGraph& G, int v) {
    for(int i=0;i<G.VexNum;i++){
		if(v==G.VNodes[i].Vex[i].VexNum)return i;
	} 
}

void LoadFile(VNode& G) { 
    fstream FP_1("ArcInfo.txt", fstream::in | fstream::out);
    fstream FP_2("ListInfo.txt", fstream::in | fstream::out);

    if(!FP_1 || !FP_2) {
        cout << "\n打开失败！" << endl;
        exit(-1);
    }

    FP_1 << "11 13" << endl;
    FP_2 << 11 << " " << 1 << " " << 300 << endl
        << 6 << " " << 8 << " " << 180 << endl
        << 8 << " " << 9 << " " << 50 << endl
        << 9 << " " << 10 << " " << 70 << endl
        << 10 << " " << 11 << " " << 230 << endl
        << 7 << " " << 11 << " " << 200 << endl
        << 1 << " " << 2 << " " << 100 << endl
        << 2 << " " << 3 << " " << 20 << endl
        << 3 << " " << 4 << " " << 20 << endl
        << 4 << " " << 5 << " " << 30 << endl
        << 5 << " " << 6 << " " << 70 << endl
        << 6 << " " << 7 << " " << 150 << endl
        << 7 << " " << 8 << " " << 60 << endl;

    fstream FP_3("AddressInfo.txt", fstream::in | fstream::out);

    if(!FP_3) {
        cout << "\n打开失败！" << endl;
        exit(-1);
    }

    G.Vex.emplace_back(1, "东区西门", "西安邮电大学长安校区东区的西门");
    G.Vex.emplace_back(2, "逸夫楼", "西安邮电大学东区教学楼");
    G.Vex.emplace_back(3, "安美公寓", "分为安美公寓南楼和北楼");
    G.Vex.emplace_back(4, "安悦公寓", "分为安悦公寓南楼和北楼");
    G.Vex.emplace_back(5, "东升苑", "西安邮电大学东区食堂");
    G.Vex.emplace_back(6, "西邮天桥", "连接西安邮电大学长安校区西区和东区的天桥");
    G.Vex.emplace_back(7, "图书馆", "西安邮电大学图书馆，可以借阅书籍和自习");
    G.Vex.emplace_back(8, "体育馆", "西安邮电大学室内运动场所");
    G.Vex.emplace_back(9, "旭日苑", "西安邮电大学西区食堂");
    G.Vex.emplace_back(10, "美食广场", "西安邮电大学西区食堂");
    G.Vex.emplace_back(11, "西区北门", "西安邮电大学西区的门");

    for(auto i : G.Vex) {
        FP_3 << i.Name << endl
            << i.Info << endl;
    }

    return;
}

void Menu_1(ALGraph& G) {
    int flag;

    printf("|------------------------------------------------校园导航系统------------------------------------------------------|\n");
	printf("|--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*---|\n");
    printf("|                                               1. 添加新地点                                                        |\n");
    printf("|                                               2. 添加新路线                                                        |\n");
    printf("|                                               3. 删除旧路线                                                        |\n");
    printf("|                                               4. 删除旧地点                                                        |\n");
    printf("|                                               5. 西邮校园游览图                                                     |\n");	
    printf("|                                               6. 查询地点信息                                                       |\n");
    printf("|                                               7. 查询地点路线                                                       |\n");
    printf("|                                               8. 查看邻接表                                                        |\n");
    printf("|                                            请选择您需要的操作,输入0退出:                                             |\n");
	printf("|--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*---|\n");
	printf("|--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*---|\n"); 

    cout << "请输入：" << endl;
    cin >> flag;

    switch(flag) {
        case 0: {
            system("clear");
            exit(0);
        }
        case 1: {
            AddPlace(G);
            break;
        } case 2: {
            PrintPlace(G);
            InsertArc(G);
            break;
        } case 3: {
            OutputGraph(G);
            DeleteArc(G);
            break;
        } case 4: {
            DeleteVex(G);
            break;
        } case 5: {
            PrintMap();
            break;
        } case 6: {
            QueryPlace(G);
            break;
        } case 7: {
            QueryPath(G);
            break;
        } case 8: {
            OutputGraph(G);
            break;
        } default: {
            cout << "\n———————————————输入信息错误,请重新输入!!!————————————————————" << endl;
            break;
        }
    }

    return;
}

void Create(ALGraph& G) {
    int v1, v2, w;
    ArcNode* p, *q;
    string Name, Info;
    fstream FP_1("ListInfo.txt", fstream::in | fstream::out);
    fstream FP_2("ArcInfo.txt", fstream::in | fstream::out);
    fstream FP_3("AddressInfo.txt", fstream::in | fstream::out);

    if(!FP_1 || !FP_2 || !FP_3) {
        cout << "\n打开失败！" << endl;
        exit(-1);
    }

    FP_1 >> G.VexNum >> G.ArcNum;
    cout << "\t已读到的顶点数和边数\n";

    for(int i = 0; i<G.VexNum; ++i) {
        FP_3 >> Name >> Info;

        G.VNodes[i].Vex[i].VexNum = i;
        G.VNodes[i].Vex[i].Name = Name;
        G.VNodes[i].Vex[i].Info = Info;

        G.VNodes[i].FirstArc = nullptr;
    }

    cout << "\t已读取到各个顶点的信息,并成功初始化各个顶点对应的链表" << endl;

    for(int k = 0; k<G.ArcNum; ++k) {
        FP_2 >> v1 >> v2 >> w;
        cout << "已读取到第" << k << "条边的两个顶点和权值…" << endl;

        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);

        p = new ArcNode::ArcNode;
        p->AdjVex = j;
        p->Weight = w;
        p->NextArc = nullptr;
        p->NextArc = G.VNodes[i].FirstArc;
        G.VNodes[i].FirstArc = p;

        q = new ArcNode::ArcNode;
        q->AdjVex = i;
        q->Weight = w;
        q->NextArc = nullptr;
        q->NextArc = G.VNodes[j].FirstArc;
        G.VNodes[j].FirstArc = q;
    }

    return;
}

void OutputGraph(ALGraph& G) {
    int i, j;
    ArcNode* p;
    
    cout << "邻接表为：" << endl;

    for(int i = 0; i<G.VexNum; ++i) {
        cout << i << G.VNodes[i].Vex[i].Name;
        p = G.VNodes[i].FirstArc;

        while(p) {
            cout << "["<< p->Weight << "]->" << p->AdjVex;
            p = p->NextArc;
        }

        cout << endl;
    }

    return;
}

void PrintPlace(ALGraph& G) {
    for(int i =0; i<G.VexNum; ++i) {
        cout << i << ". " << G.VNodes[i].Vex[i].Name;
    }

    return;
}

void AddPlace(ALGraph& G) {
    int flag(1), Pb, Pa, Weight;
    VexInfo NewVex;
    string Name, Info;

    cout << "\t\t\t---- 请编辑添加地点的信息----";
    cout << "\n\t\t\t  1.输入地点名称：";
    cin >> Name;
    cout << "\n\t\t\t  2.输入地点简介：";
    cin >> Info;

    NewVex.VexNum = G.VexNum + 1;

    NewVex.Name = Name;
    NewVex.Info = Info;
    
    if(InsertVex(G, NewVex)) {
        cout << "\n\n\t\t\t地点|" << G.VexNum << "." << Name << "|添加成功！" << endl;
    }

    PrintPlace(G);

    while(flag == 1) {
        Pa = G.VexNum;

        cout << "\n\t\t\t---- 请编辑添加的地点的路径信息----";
        cout << "\n\n\t\t  1.输入与|" << G.VexNum << "." << Name << "相连的地点编号：";
        cin >> Pb;
        cout << "输入此路径|" << G.VexNum << "." << G.VNodes[Pa].Vex[Pa].Name << "|-[????]->|" << G.VNodes[Pa].Vex[Pa].Name << "." << G.VNodes
    }
}