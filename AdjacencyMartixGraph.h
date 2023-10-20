//
// Created by 24887 on 2023/10/20.
//

#ifndef ALL_ADJACENCYMARTIXGRAPH_H
#define ALL_ADJACENCYMARTIXGRAPH_H
#define MaxVex1 10
#define INF 65535

typedef char VertexType ;
typedef int Edgetype ;
typedef struct {
    VertexType *vertexs ;
    Edgetype **edges ;
    int numVertexs , numedges ;
}AMGraph ;

class Graph2{
public:
    AMGraph amGraph ;


    void InitAMGraph(AMGraph  &G) ;

    void CreateAMGrpah(AMGraph& G) ;

    void DisplayAMGraph(AMGraph G) ;
};
#endif //ALL_ADJACENCYMARTIXGRAPH_H
