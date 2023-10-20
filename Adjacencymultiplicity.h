//
// Created by 24887 on 2023/10/20.
//

#ifndef ALL_ADJACENCYMULTIPLICITY_H
#define ALL_ADJACENCYMULTIPLICITY_H

#define MaxVex 20
typedef char VertexType ; //顶点数据类型
typedef int EdgeType ; //边权值的数值类型

typedef struct EdgeNode{
    int visitFlag ;
    EdgeType edgeData ;
    int headVertex , tailVertex ; //该边所连接的两个顶点下标
    struct EdgeNode *nextHeadEdge, *nextTailEdge ; //分别指向相同顶点的边链表。
}EdgeNode, *EdgeList;

typedef struct VertexNode {
    VertexType vertexData ;
    EdgeList edgeList ;
}VertexNode;

typedef struct {
    VertexNode *MutiList ; //顶点顺序表
    int numVertexs, numEdges ; //顶点数和边数
}AMLGraph ;

class Graph{
public:
    AMLGraph G ;
    void InitAMLGraph(AMLGraph& G) ;
    void CreateAMLGraph(AMLGraph& G) ;
    void DisplayAMLGraph(AMLGraph G) ;
};
#endif //ALL_ADJACENCYMULTIPLICITY_H
