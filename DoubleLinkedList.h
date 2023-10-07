//
// Created by 24887 on 2023/9/27.
//

#ifndef ALL_DOUBLELINKEDLIST_H
#define ALL_DOUBLELINKEDLIST_H

typedef int ELemTypeDL ;
typedef struct DNode{
    ELemTypeDL data ;
    struct DNode *next , *prior ;
}DNode;

class DoubleLinkedList {
public:
    DNode *dll = new DNode; //头指针
    int length ; //链表长度
    /**
     * 空参
     * */
    DoubleLinkedList() ;
    /**
   * @brief
   * 初始化顺序表
   * 只需要返回对应的数据和值，所以没有必要返回原先创建的数据
   * @return void
   */
    bool InitTDoubleList() ;

    void CreateList_H(int n) ; //头插法

    void CreateList_T(int n ) ; //尾插法

    void DisplayLink() ;

};
#endif //ALL_DOUBLELINKEDLIST_H
