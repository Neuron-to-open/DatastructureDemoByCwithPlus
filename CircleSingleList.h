//
// Created by 24887 on 2023/9/28.
//

#ifndef ALL_CIRCLESINGLELIST_H
#define ALL_CIRCLESINGLELIST_H

typedef int CircleSingleLisDataElement ;
typedef struct CirNode{
    CircleSingleLisDataElement data ;
    struct CirNode *next ;
}CirNode;

class CircleSingleList{
public:
    CirNode *CircleList = new CirNode ;
    int length = 0 ;


    /**
     * 初始化链表。
     * @return 初始化成功返回true，失败返回false。
     */
    bool InitList_L() ;

    /**
     * 使用头插法创建链表。
     * @param n 链表中元素的数量。
     */
    void CreateList_H(int n ) ;

    /**
     * 使用尾插法创建链表。
     * @param n 链表中元素的数量。
     */
    void CreateList_R(int n ) ;

    /**
     * 打印链表中的所有元素。
     */
    void ListPrint() ;

    /**
     * 销毁链表。
     * @return 销毁成功返回true，失败返回false。
     */
    bool DestroyList() ;

};
#endif //ALL_CIRCLESINGLELIST_H
