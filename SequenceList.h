//
// Created by 24887 on 2023/7/13.
//

#ifndef ALL_SEQUENCELIST_H
#define ALL_SEQUENCELIST_H

/* 定义元素类型为整型 */
typedef int SequenceListDataElement ;
/* 定义顺序表结构 */

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
    void Seq_Init() ;

    /* 输出顺序表中的所有元素 */
    /**
    * @brief
    * 输出顺序表中元素的函数
    * @param s
     */
    void Seq_Print() ;

    /* 当顺序表满时，扩大数组长度 */
    /**
    * @brief
    * 当长度不够时，自动增加内存,使用realloc函数增大内存
    * @param s
    */
    void Seq_AddLength() ;

    /* 返回顺序表的长度 */
    /**
    * @brief Get the Length object
    * 获取数组长度
    * @param s
     * @return int
    */
    int Seq_GetLength() ;

    /* 销毁顺序表，释放内存 */
    /**
    * @brief
     * 销毁链表，销毁成功，则返回true。反之则是false；
     * @param s
    * @return true
    * @return false
    */
    bool Seq_Destroy() ;

    /* 判断顺序表是否为空 */
    /**
    * @brief
    * 判断顺序表是否为空
     * @param s
     * @return true
    * @return false
     */
     bool Seq_IsEmpty() ;

     /**
      * @brief 定位元素在表中的位置
      *
      * @param e 待查找的元素
      * @return int 元素的位置，如果未找到返回-1
      */
     int Seq_Locate_Elem(int e) ;

     /**
      * @brief 获取表中指定位置的元素
      *
      * @param i 元素的位置
      * @param Elem 用于存储获取到的元素的引用
      * @return bool 获取是否成功，成功返回true，失败返回false
      */
     bool Seq_Get_Elem(int i , int &Elem) ;

     /**
      * @brief 在表中插入一个元素
      *
      * @param i 插入位置
      * @param elem 待插入的元素
      * @return bool 插入是否成功，成功返回true，失败返回false
      */
     bool Seq_Insert_Elem(int i , int elem) ;

     /**
      * @brief 从表中删除指定位置的元素
      *
      * @param i 待删除元素的位置
      * @param data 用于存储被删除元素的引用
      * @return bool 删除是否成功，成功返回true，失败返回false
      */
     bool Seq_Delete_Elem(int i , int &data) ;

     bool reverseSequenceList() ;
};



#endif //ALL_SEQUENCELIST_H
