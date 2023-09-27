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
    Node *linklist = new Node;    //链表头指针
    int length ;    //链表长度

    bool InitList_L() ;

    void CreateList_H(int n ) ; //头插法

    void CreateList_R(int n ) ; //尾插法

    void ListPrint() ;

    bool DestroyList() ;

    bool GetElem_L(int i , int &data) ;

    bool LocateElem_L( int key , int &loc ) ;

    bool ListInsert_L(int i , int e) ;

    bool ListDelete_L(int i , int data ) ;
};
#endif //ALL_SINGLELIST_H
