# pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::shared_ptr;

// 数据抽象 继承 动态绑定

class AdjList {
private:
// 一些用到的数据结构
    using VertexType = string;
    using EdgeType = int;
    struct EdgeNode;

    struct VertexNode {
        VertexType Data;
        // EdgeNode* Next;
        shared_ptr<EdgeNode> Next;
    };

    struct EdgeNode {
        EdgeNode(int To, int Weight):
            VertexIndex(To), Weight(Weight) { }

        int VertexIndex;
        EdgeType Weight;
        // EdgeNode* Next;
        shared_ptr<EdgeNode> Next;
    };
public:
// 成员函数\
    // 构造函数
    AdjList() = delete;
    AdjList(int&);
    // 接口
    void AddEdge(int, int, EdgeType);
    void DeleteEdge(int, int);
    // void DisPlay();
    void DisPlay_DFS(VertexType);
    void DisPlay_BFS(VertexType);
private:
// 私有函数

private:
// 数据成员
    vector<VertexNode> VertexArray;
    vector<bool> VertexFlagArray;
    int VertexNum, EdgeNum;
};

inline
AdjList::AdjList(int& VertexNum):
    VertexArray(VertexNum), VertexFlagArray(VertexNum),
    VertexNum(0), EdgeNum(0)
{
    int c(0);

    for(auto& i : VertexArray) {
        i.Data = "v" + std::to_string(++c);
    }
}

void AdjList::AddEdge(int From, int To, EdgeType Weight = 0) {
    shared_ptr<EdgeNode> NewNode(std::make_shared<EdgeNode>(To));
    // EdgeNode* NewEdge = new EdgeNode(To, Weight);

    // 头插
    NewNode->Next = VertexArray[From].Next;
    VertexArray[From].Next = NewNode;

    return;
}

void AdjList::DeleteEdge(int From, int To) {

    return;
}