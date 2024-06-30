//
// Created by 24887 on 2023/7/14.
//

#ifndef ALL_SINGLELIST_H
#define ALL_SINGLELIST_H

// 定义单链表元素的类型别名
typedef int SingleListDataElement ;  //定义关键字类型别名

// 定义单链表节点结构体
typedef struct Node{
    SingleListDataElement data ; // 节点数据域
    struct Node *next ; // 节点指针域，指向下一个节点
}Node;

// 单链表类定义
class SingleList{
public:
    Node *linklist = new Node ;  // 链表头指针
    int length = 0  ; // 链表长度

    /**
     * 初始化链表。
     * @return 初始化成功返回true，失败返回false。
     */
    // 初始化链表
    bool InitList_L() ;

    /**
     * 通过头插法创建链表。
     * @param n 链表中元素的数量。
     */
    // 通过头插法创建链表
    void CreateList_H(int n ) ;

    /**
     * 通过尾插法创建链表。
     * @param n 链表中元素的数量。
     */
    // 通过尾插法创建链表
    void CreateList_R(int n ) ;

    /**
     * 打印链表的所有元素。
     */
    // 打印链表所有元素
    void ListPrint() ;

    /**
     * 销毁链表。
     * @return 销毁成功返回true，失败返回false。
     */
    // 销毁链表
    bool DestroyList() ;

    /**
     * 从头开始获取链表中第i个元素的值。
     * @param i 第i个元素的位置，从0开始计数。
     * @param data 用于存储获取到的元素值的引用。
     * @return 获取成功返回true，失败返回false。
     */
    // 获取链表第i个元素
    bool GetElem_L(int i , int &data) ;

    /**
     * 从头开始在链表中定位元素key的位置。
     * @param key 要定位的元素值。
     * @param loc 用于存储定位到的元素位置的引用。
     * @return 定位成功返回true，失败返回false。
     */
    // 在链表中定位元素key的位置
    bool LocateElem_L( int key , int &loc ) ;

    /**
     * 从头开始在链表的第i个位置插入元素e。
     * @param i 插入位置，从0开始计数。
     * @param e 要插入的元素值。
     * @return 插入成功返回true，失败返回false。
     */
    // 在链表第i个位置插入元素e
    bool ListInsert_L(int i , int e) ;

    /**
     * 从头开始删除链表中第i个位置的元素。
     * @param i 要删除元素的位置，从0开始计数。
     * @param data 用于存储被删除元素的值的引用。
     * @return 删除成功返回true，失败返回false。
     */
    // 删除链表第i个位置的元素
    bool ListDelete_L(int i , int &data ) ;
};

#endif //ALL_SINGLELIST_H
