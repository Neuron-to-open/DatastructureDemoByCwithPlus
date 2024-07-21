//
// Created by 24887 on 2023/7/14.
//

#ifndef ALL_SINGLELISTWITHHEADNODE_H
#define ALL_SINGLELISTWITHHEADNODE_H

// 定义单链表元素的类型别名
typedef int SingleListDataElement ;  //定义关键字类型别名

// 定义单链表节点结构体
typedef struct SingleListNode{
    SingleListDataElement data ; // 节点数据域
    struct SingleListNode *next ; // 节点指针域，指向下一个节点
}SingleListNode;

// 单链表类定义
class SingleListWithHeadNode{
public:
    SingleListNode *LinklistNode = new SingleListNode ;  // 头结点

    int length = 0  ; // 链表长度

    /**
     * 初始化链表。
     * @return 初始化成功返回true，失败返回false。
     */
    bool List_Init() ;

    /**
     * 通过头插法创建链表。
     * @param n 链表中元素的数量。
     */
    void List_Create_H(int n ) ;

    /**
     * 通过尾插法创建链表。
     * @param n 链表中元素的数量。
     */
    void List_Create_T(int n ) ;

    /**
     * 打印链表的所有元素。
     */
    void List_Print() ;

    /**
     * 销毁链表。
     * @return 销毁成功返回true，失败返回false。
     */
    bool List_Destroy() ;

    /**
     * 从头开始获取链表中第i个元素的值。
     * @param i 第i个元素的位置，从0开始计数。
     * @param data 用于存储获取到的元素值的引用。
     * @return 获取成功返回true，失败返回false。
     */
    // 获取链表第i个元素
    bool List_GetElem_H(int i , int &data) ;

    /**
     * 从头开始在链表中定位元素key的位置。
     * @param key 要定位的元素值。
     * @param loc 用于存储定位到的元素位置的引用。
     * @return 定位成功返回true，失败返回false。
     */
    // 在链表中定位元素key的位置
    bool List_LocateElem_H( int key , int &loc ) ;

    /**
     * 从头开始在链表的第i个位置插入元素e。
     * @param i 插入位置，从0开始计数。
     * @param e 要插入的元素值。
     * @return 插入成功返回true，失败返回false。
     */
    // 在链表第i个位置插入元素e
    bool List_Insert_H(int i , int e) ;

    /**
     * 从头开始删除链表中第i个位置的元素。
     * @param i 要删除元素的位置，从0开始计数。
     * @param data 用于存储被删除元素的值的引用。
     * @return 删除成功返回true，失败返回false。
     */
    // 删除链表第i个位置的元素
    bool List_Delete_H(int i , int &data ) ;

    int List_GetLength() ; // 获取链表长度
};

#endif //ALL_SINGLELISTWITHHEADNODE_H
