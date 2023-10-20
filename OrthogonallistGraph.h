//
// Created by 24887 on 2023/10/20.
//

#ifndef ALL_ORTHOGONALLISTGRAPH_H
#define ALL_ORTHOGONALLISTGRAPH_H

#define MaxSize4 20
//弧结构
typedef struct ArcNode{
    int arcData ; //弧的权值
    int headVertex, tailVertex;   // 弧的头顶点和尾顶点
    struct ArcNode *nextHeadArc, *nextTailArc;  // 指向相同头、尾顶点的弧指针
}ArcNode, *ArcList;

//顶点结构
typedef struct VertexNode44{
    char vertexData ;
    ArcList headList , tailList ;
}VertexNode4 , *VertexList4;

//十字链表结构
typedef struct {
    VertexList4 vertexList4;
    int numVertexs , numArcs ;
}OLGraph;

class Graph4{
public:
    OLGraph olGraph ;

    void InitOLGrpah(OLGraph& G) ;

    void CreateOLGraph(OLGraph& G) ;

    void DisplayOLGraph(OLGraph G) ;
};


#endif //ALL_ORTHOGONALLISTGRAPH_H
