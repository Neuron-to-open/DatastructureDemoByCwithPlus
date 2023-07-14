//
// Created by 24887 on 2023/7/14.
//

#ifndef ALL_SINGLELIST_H
#define ALL_SINGLELIST_H
typedef int ElemType ;  //定义关键字类型别名

typedef struct Node{
    ElemType data ;
    struct Node *next ;
}Node;

class SingleList{
public:
    Node *linklist ;    //链表
    int length ;    //链表长度


    bool InitList_L() ;

    void CreateList_H(int n ) ;

    void CreateList_R(int n ) ;

    void ListPrint() ;

    bool DestroyList() ;
};
#endif //ALL_SINGLELIST_H
