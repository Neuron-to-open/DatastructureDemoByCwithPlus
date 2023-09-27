//
// Created by 24887 on 2023/7/13.
//

#ifndef ALL_SEQUENCE_H
#define ALL_SEQUENCE_H

typedef int ElemType ;
typedef struct {
    ElemType *head ;
    int size ;
    int length ;
}Seq;

class Sequence {
public :

    Seq  seq ;

    /**
     *空参构造函数
     **/
    Sequence();

    /**
     * size 初始化
     **/
    Sequence(int size);

    /**
    * @brief
    * 初始化顺序表
    * 只需要返回对应的数据和值，所以没有必要返回原先创建的数据
    * @return void
    */
    void InitTable() ;

    /**
    * @brief
    * 输出顺序表中元素的函数
    * @param s
     */
    void ShowTable() ;


    /**
    * @brief
    * 当长度不够时，自动增加内存,使用realloc函数增大内存
    * @param s
    */
    void addLength() ;


    /**
    * @brief Get the Length object
    * 获取数组长度
    * @param s
     * @return int
    */
    int getLength() ;

    /**
    * @brief
     * 销毁链表，销毁成功，则返回true。反之则是false；
     * @param s
    * @return true
    * @return false
    */
    bool DestroyTable() ;

    /**
    * @brief
    * 判断顺序表是否为空
     * @param s
     * @return true
    * @return false
     */
     bool isEmpty() ;


     int LocateElem(int e) ;


     bool getElem(int i , int &Elem) ;


     bool InsertTable(int i , int elem) ;

     bool DeleteTable(int i , int &data) ;
};


#endif //ALL_SEQUENCE_H
