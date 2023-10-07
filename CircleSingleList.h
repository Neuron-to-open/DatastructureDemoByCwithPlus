//
// Created by 24887 on 2023/9/28.
//

#ifndef ALL_CIRCLESINGLELIST_H
#define ALL_CIRCLESINGLELIST_H

typedef int ElemTypeCSL ;
typedef struct CirNode{
    ElemTypeCSL data ;
    struct CirNode *next ;
}CirNode;

class CircleSingleList{
public:
    CirNode *CircleList = new CirNode ;
    int length = 0 ;


    bool InitList_L() ;

    void CreateList_H(int n ) ; //头插法

    void CreateList_R(int n ) ; //尾插法

    void ListPrint() ;

    bool DestroyList() ;

};
#endif //ALL_CIRCLESINGLELIST_H
