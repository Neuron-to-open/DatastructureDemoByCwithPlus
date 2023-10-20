//
// Created by 24887 on 2023/10/20.
//

#include "AdjacencyListGraph.h"
#include <iostream>
using namespace std ;

void Graph3::InitALGraph(ALGraph &G) {
    G.numVertexs = 0 ;
    G.numEdges = 0 ;
    G.vertexList = new VertexNode3 [MaxALG] ;

    int i ;
    for (i = 0 ; i < MaxALG ; i ++){
        G.vertexList[i].edgeList = new EdgeNode3 ;
        G.vertexList[i].edgeList->next = nullptr ;
    }

    cout << "已经初始化邻接表" << endl ;

}

void Graph3::CreateALGrapg(ALGraph &G) {
    printf("请输入顶点数和边数:");
    cin >> G.numVertexs >> G.numEdges ;

    int i , j , k ;
    int w ;
    //输入顶点数据
    for (i = 0 ; i < G.numVertexs ; i ++ ){
        fflush(stdin) ;
        printf("请输入第%d个顶点数据:", i + 1);
        cin >> G.vertexList[i].vertexData ;
    }

    //输入边的权值
    for (k = 0 ; k < G.numEdges ; k ++){
        printf("请输入边(vi, vj)上的顶点序号及权值:");
        cin >> i >> j >> w ;

        EdgeNode3 *p1, *p2 ;
        p1 = new EdgeNode3 ;
        p2 = new EdgeNode3 ;

        p1->edgeData = w ;
        p1->next = G.vertexList[i-1].edgeList->next ;
        G.vertexList[i-1].edgeList->next = p1 ;
        p1->adjvex = j -1 ;

        p2->edgeData = w ;
        p2->next = G.vertexList[j-1].edgeList->next ;
        G.vertexList[j-1].edgeList->next = p2 ;
        p2->adjvex = j-1 ;
    }
}

void Graph3::DisplayALGraph(ALGraph G) {
    int i;
    EdgeNode3 *p;
    for (i = 0; i < G.numVertexs; i++)
    {
        printf("顶点:%c\t边:", G.vertexList[i].vertexData);
        // 获取边链表数据
        p = G.vertexList[i].edgeList;
        while (p->next)
        {
            p = p->next;
            printf("%d(%c)->", p->edgeData, G.vertexList[p->adjvex].vertexData);
        }
        printf("NULL\n");
    }
    printf("\n");

}
