//
// Created by 24887 on 2023/10/20.
//

#include "AdjacencyMartixGraph.h"
#include <iostream>
using namespace std ;
void Graph2::InitAMGraph(AMGraph &G) {
    G.vertexs = new VertexType [MaxVex1] ;
    int i , j ;
    G.edges = new Edgetype * [MaxVex1] ;
    for (i = 0 ; i < MaxVex1 ; i ++){
        G.edges[i] = new Edgetype [MaxVex1] ;
        for (j = 0 ; j < MaxVex1 ;j ++){
            if ( i == j ){
                G.edges[i][j] = 0 ;
            }else {
                G.edges[i][j] = INF ;
            }
        }
    }

    G.numVertexs = 0 ;
    G.numedges = 0 ;
    cout << "已经初始化邻接矩阵!" << endl ;
}

void Graph2::CreateAMGrpah(AMGraph &G) {
    cout << "请输入顶点数和边数" << endl ;
    cin >> G.numVertexs >> G.numedges ;
    int i , j , k , weight ;

    for (i = 0 ; i < G.numVertexs ; i ++){
        fflush(stdin) ;
        printf("请输入第%d个顶点数据:", i + 1);
        cin >> G.vertexs[i] ;
    }

    for (k = 0 ; k < G.numedges ; k ++){
        printf("请输入第%d条边的两顶点及其权值:", k + 1);
        cin >> i >> j >> weight ;
        G.edges[i-1][j-1] = weight ;
        G.edges[j-1][i-1] = weight ;
    }

    cout << "已完成邻接矩阵的创建" << endl ;
}

void Graph2::DisplayAMGraph(AMGraph G) {
    int i , j ;
    cout << "\t" ;
    for (i = 0 ; i < G.numVertexs ; i ++){
        cout << G.vertexs[i] << "\t" ;
    }
    cout << endl ;

    for (i = 0 ; i < G.numVertexs ; i ++){
        cout << G.vertexs[i] << "\t";
        for (j = 0 ; j < G.numVertexs ; j ++){
            if(G.edges[i][j] == INF){
                cout << "∞\t" ;
            }else {
                cout << G.edges[i][j] << "\t" ;
            }
        }
        cout << endl ;
    }
}
