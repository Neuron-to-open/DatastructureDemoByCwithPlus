//
// Created by 24887 on 2023/7/13.
//

#ifndef ALL_SEQUENCELIST_H
#define ALL_SEQUENCELIST_H

/* 定义元素类型为整型 */
typedef int SequenceListDataElement ;
/* 定义顺序表结构 */
/*

typedef: 这个关键字用于为结构体定义一个新的类型名。在这里，我们使用typedef将结构体Node定义为一种新的类型，简化了以后的使用。

struct Node: 这是结构体的定义。结构体是一种聚合数据类型，可以包含多个不同类型的数据。

SingleListDataElement data: 这是结构体中的一个成员变量，名为data，它的类型是SingleListDataElement。这个变量用于存储节点的数据。SingleListDataElement可能是一个自定义的数据类型，在这段代码中没有具体定义，但可以是任意的数据类型，如整数、浮点数、字符、指针等。

*struct Node next: 这是结构体中的另一个成员变量，名为next，它是一个指向结构体Node类型的指针。这个指针用于指向下一个节点，形成一个链表结构。

Node: 在结构体定义的末尾，这个名字是通过typedef关键字引入的，表示我们可以使用Node来代替struct Node。这使得代码在创建和操作链表节点时更加简洁。

总的来说，这段代码定义了一个链表节点的结构体，每个节点包含两个成员：一个用于存储数据的data和一个用于指向下一个节点的指针next。通过这种定义，可以方便地创建和操作单链表。*/
typedef struct {
    SequenceListDataElement *head ; /* 指向数组首元素的指针 */
    int size ; /* 数组的预分配大小 */
    int length ; /* 数组中元素的实际数量 */
}Seq;

/* 顺序表类定义 */
class SequenceList {
public :

    Seq seq ; /* 顺序表实例 */

    /**
     * 空参构造函数
     **/
    SequenceList();

    /**
     * size 初始化
     **/
    SequenceList(int size);

    /* 初始化顺序表，将长度置为0 */
    /**
    * @brief
    * 初始化顺序表
    * 只需要返回对应的数据和值，所以没有必要返回原先创建的数据
    * @return void
    */
    void InitTable() ;

    /* 输出顺序表中的所有元素 */
    /**
    * @brief
    * 输出顺序表中元素的函数
    * @param s
     */
    void ShowTable() ;

    /* 当顺序表满时，扩大数组长度 */
    /**
    * @brief
    * 当长度不够时，自动增加内存,使用realloc函数增大内存
    * @param s
    */
    void addLength() ;

    /* 返回顺序表的长度 */
    /**
    * @brief Get the Length object
    * 获取数组长度
    * @param s
     * @return int
    */
    int getLength() ;

    /* 销毁顺序表，释放内存 */
    /**
    * @brief
     * 销毁链表，销毁成功，则返回true。反之则是false；
     * @param s
    * @return true
    * @return false
    */
    bool DestroyTable() ;

    /* 判断顺序表是否为空 */
    /**
    * @brief
    * 判断顺序表是否为空
     * @param s
     * @return true
    * @return false
     */
     bool isEmpty() ;

     /**
      * @brief 定位元素在表中的位置
      *
      * @param e 待查找的元素
      * @return int 元素的位置，如果未找到返回-1
      */
     int LocateElem(int e) ;

     /**
      * @brief 获取表中指定位置的元素
      *
      * @param i 元素的位置
      * @param Elem 用于存储获取到的元素的引用
      * @return bool 获取是否成功，成功返回true，失败返回false
      */
     bool getElem(int i , int &Elem) ;

     /**
      * @brief 在表中插入一个元素
      *
      * @param i 插入位置
      * @param elem 待插入的元素
      * @return bool 插入是否成功，成功返回true，失败返回false
      */
     bool InsertTable(int i , int elem) ;

     /**
      * @brief 从表中删除指定位置的元素
      *
      * @param i 待删除元素的位置
      * @param data 用于存储被删除元素的引用
      * @return bool 删除是否成功，成功返回true，失败返回false
      */
     bool DeleteTable(int i , int &data) ;

     bool reverseSequenceList() ;
};



#endif //ALL_SEQUENCELIST_H
