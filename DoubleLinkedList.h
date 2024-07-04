//
// Created by 24887 on 2023/9/27.
//

#ifndef ALL_DOUBLELINKEDLIST_H
#define ALL_DOUBLELINKEDLIST_H

typedef int DoubleLinkedListDataElement ;
typedef struct DNode{
    DoubleLinkedListDataElement data ;
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
    
    /**
     * @brief 创建链表（头插法）
     * 
     * 本函数通过头插法创建一个包含n个节点的链表。头插法是指在链表的头部插入新节点，
     * 使得新节点成为链表的第一个节点。这种方法适用于需要将新元素总是放在列表开始位置的场景。
     * 
     * @param n 要创建的链表中节点的数量。n大于0时，函数将创建一个包含n个节点的链表。
     */
    void CreateList_H(int n) ;
    
    /**
     * @brief 创建链表（尾插法）
     * 
     * 本函数通过尾插法创建一个包含n个节点的链表。尾插法是指在链表的尾部插入新节点，
     * 使得新节点成为链表的最后一个节点。这种方法适用于需要将新元素总是放在列表末尾的场景。
     * 
     * @param n 要创建的链表中节点的数量。n大于0时，函数将创建一个包含n个节点的链表。
     */
    void CreateList_T(int n) ;
    
    /**
     * @brief 显示链表内容
     * 
     * 本函数用于显示链表中的所有节点的值。它遍历链表，并按顺序打印每个节点的值。
     * 这是一个用于调试和用户界面的函数，帮助查看链表的当前状态。
     */
    void DisplayLink() ;

};
#endif //ALL_DOUBLELINKEDLIST_H
