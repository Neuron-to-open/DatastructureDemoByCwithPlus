//
// Created by 24887 on 2023/10/20.
//

#include "Adjacencymultiplicity.h"
#include <iostream>
using namespace std ;

void Graph::InitAMLGraph(AMLGraph &G) {
    G.numVertexs = 0 ;
    G.numEdges = 0 ;
    G.MutiList = new VertexNode [MaxVex] ;//初始化链表头结点
    int i ;
    for (i = 0 ; i < MaxVex ;i ++){
        G.MutiList[i].edgeList = new EdgeNode ;
        G.MutiList[i].edgeList->nextHeadEdge = nullptr ;
        G.MutiList[i].edgeList->nextTailEdge = nullptr ;
    }

    cout << "已经初始化邻接多重表" << endl ;
}

void Graph::CreateAMLGraph(AMLGraph &G) {
    cout << "请输入顶点数和边数:" << endl ;
    cin >> G.numVertexs ;
    cin >> G.numEdges ;

    int i , j , k ;
    for (i = 0 ;i < G.numVertexs ; i ++){
        cout << "请输入" << i+1 << "个顶点的数据:" ;
        cin >> G.MutiList[i].vertexData ;
    }

    EdgeType w ;
    for (k = 0 ; k < G.numEdges ; k ++){
        cout << "请输入边(vi, vj)的头、尾顶点及其权值:" ;
        cin >> i >> j >> w ;

        EdgeNode* s ;
        s = new EdgeNode ;
        s->visitFlag = 0 ;
        s->edgeData = w ;
        s->headVertex = i -1 ;
        s->tailVertex = j - 1 ;

        //头插法插入相同头顶点的边结点
        s->nextHeadEdge = G.MutiList[i-1].edgeList->nextHeadEdge ;
        G.MutiList[i-1].edgeList->nextHeadEdge = s ;

        //头插法插入相同尾顶点的边结点
        s->nextTailEdge = G.MutiList[j-1].edgeList->nextTailEdge ;
        G.MutiList[j-1].edgeList->nextTailEdge = s ;


    }
    cout << "已完成邻接多重表的创建！" << endl ;
}

void Graph::DisplayAMLGraph(AMLGraph G) {
    int i ;
    EdgeNode  *p ;
    for (i = 0 ; i < G.numVertexs ; i ++){
        p = G.MutiList[i].edgeList->nextHeadEdge ;
        while (p && !p->visitFlag){
            cout << "边: " << G.MutiList[p->headVertex].vertexData << "<->" << G.MutiList[p->tailVertex].vertexData << " (" << p->edgeData << ")" <<  endl ;
            p->visitFlag =1 ;
            p = p->nextHeadEdge ;
        }
    }
}
