//
// Created by 24887 on 2023/7/14.
//

#ifndef ALL_SINGLELISTWITHHEADNODE_H
#define ALL_SINGLELISTWITHHEADNODE_H

/*

typedef: 这个关键字用于为结构体定义一个新的类型名。在这里，我们使用typedef将结构体Node定义为一种新的类型，简化了以后的使用。

struct Node: 这是结构体的定义。结构体是一种聚合数据类型，可以包含多个不同类型的数据。

SingleListDataElement data: 这是结构体中的一个成员变量，名为data，它的类型是SingleListDataElement。这个变量用于存储节点的数据。SingleListDataElement可能是一个自定义的数据类型，在这段代码中没有具体定义，但可以是任意的数据类型，如整数、浮点数、字符、指针等。

*struct Node next: 这是结构体中的另一个成员变量，名为next，它是一个指向结构体Node类型的指针。这个指针用于指向下一个节点，形成一个链表结构。

Node: 在结构体定义的末尾，这个名字是通过typedef关键字引入的，表示我们可以使用Node来代替struct TreeNode。这使得代码在创建和操作链表节点时更加简洁。

总的来说，这段代码定义了一个链表节点的结构体，每个节点包含两个成员：一个用于存储数据的data和一个用于指向下一个节点的指针next。通过这种定义，可以方便地创建和操作单链表。*/

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
    bool List_InsertByLocation_H(int i , int e) ;

    /**
     * 从头开始删除链表中第i个位置的元素。
     * @param i 要删除元素的位置，从0开始计数。
     * @param data 用于存储被删除元素的值的引用。
     * @return 删除成功返回true，失败返回false。
     */
    // 删除链表第i个位置的元素
    bool List_DeleteByLocation_H(int i , int &data ) ;

    int List_GetLength() ; // 获取链表长度
};

#endif //ALL_SINGLELISTWITHHEADNODE_H
