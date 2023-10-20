//
// Created by 24887 on 2023/10/20.
//

#include "OrthogonallistGraph.h"
#include <iostream>
using namespace std ;


void Graph4::InitOLGrpah(OLGraph &G) {
    G.numVertexs = 0 ;
    G.numArcs = 0 ;
    G.vertexList4 = new VertexNode4 [MaxSize4] ;

    int i ;
    for (i = 0 ; i < MaxSize4 ; i ++){
        //相同头顶点的弧
        G.vertexList4[i].headList = new ArcNode  ;
        G.vertexList4[i].headList->nextHeadArc = nullptr ;
        G.vertexList4[i].headList->nextTailArc = nullptr ;

        //相同尾顶点的弧
        G.vertexList4[i].tailList = new ArcNode ;
        G.vertexList4[i].tailList->nextTailArc = nullptr ;
        G.vertexList4[i].tailList->nextHeadArc = nullptr ;
    }

    cout << "已经初始化十字链表" << endl ;
}

void Graph4::CreateOLGraph(OLGraph &G) {
    printf("请输入顶点数和弧数:");
    cin >> G.numVertexs >> G.numArcs ;

    //输入顶点数据
    int i , j , k ;
    for (i = 0 ; i < G.numVertexs ; i ++){
        fflush(stdin) ;
        printf("请输入第%d个顶点信息:", i + 1);
        cin >> G.vertexList4[i].vertexData ;

    }

    int w ;

    for (k = 0 ; k < G.numArcs ; k ++){
        printf("请输入弧(Ai, Aj)的头、尾顶点及其权值:");
        cin >> i >> j >> w ;

        //创建弧结点
        ArcNode * s ;
        s = new ArcNode  ;
        s->arcData = w ;
        s->headVertex = i -1 ;
        s->tailVertex = j -1 ;

        //头插法
        s->nextHeadArc = G.vertexList4[i-1].headList->nextHeadArc ;
        G.vertexList4[i-1].headList->nextHeadArc = s ;

        //头插法插入相同的尾结点
        s->nextTailArc =  G.vertexList4[j-1].tailList->nextTailArc ;
        G.vertexList4[j-1].tailList->nextTailArc = s ;


    }
}

void Graph4::DisplayOLGraph(OLGraph G) {
    int i;
    ArcNode *p;
    for (i = 0; i < G.numVertexs; i++)
    {
        printf("顶点:%c\n", G.vertexList4[i].vertexData);
        // 相同头顶点的弧链表
        printf("\t相同头顶点的弧:");
        p = G.vertexList4[i].headList;
        while (p->nextHeadArc)
        {
            p = p->nextHeadArc;
            printf("(%c)%d(%c) => ",
                   G.vertexList4[p->headVertex].vertexData,
                   p->arcData,
                   G.vertexList4[p->tailVertex].vertexData);
        }
        printf("NULL\n");
        // 相同尾顶点的弧链表
        printf("\t相同尾顶点的弧:");
        p = G.vertexList4[i].tailList;
        while (p->nextTailArc)
        {
            p = p->nextTailArc;
            printf("(%c)%d(%c) => ",
                   G.vertexList4[p->headVertex].vertexData,
                   p->arcData,
                   G.vertexList4[p->tailVertex].vertexData);
        }
        printf("NULL\n");
    }

}
