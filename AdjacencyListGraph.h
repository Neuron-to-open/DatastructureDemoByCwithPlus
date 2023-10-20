//
// Created by 24887 on 2023/10/20.
//

#ifndef ALL_ADJACENCYLISTGRAPH_H
#define ALL_ADJACENCYLISTGRAPH_H

#define MaxALG 20
//边结构---链表
typedef struct EdgeNode3{
    int adjvex ;
    int edgeData ;
    struct EdgeNode3* next ;
}EdgeNode3, *EdgeList3;

//顶点结构---顺序表
typedef struct {
    char vertexData ;
    EdgeList3 edgeList ;
}VertexNode3 , *VertexList3;


//邻接表结构
typedef struct {
    VertexList3 vertexList ;
    int numVertexs , numEdges ; //顶点数
}ALGraph;

class Graph3{
public:
    ALGraph alGraph ;
    void InitALGraph(ALGraph& G) ;

    void CreateALGrapg(ALGraph& G) ;

    void DisplayALGraph(ALGraph G) ;
};
#endif //ALL_ADJACENCYLISTGRAPH_H
