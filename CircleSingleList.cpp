//
// Created by 24887 on 2023/9/28.
//

#include "CircleSingleList.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std ;



/**
 * 初始化循环单链表
 * @return 是否成功初始化的标志，如果链表指针为空，则初始化失败；否则，初始化成功。
 */
bool CircleSingleList::InitList_L() {
    // 检查链表指针是否为空，如果为空，则初始化失败
    if (this->CircleList == nullptr){
        return false ;
    }

    // 初始化链表的头结点，设置next指针为空，data值为0
    this->CircleList->next = nullptr ;
    this->CircleList->data = 0 ;
    return true ;
}

/**
 * 通过随机数创建循环单链表
 * @param n 链表中节点的数量
 */
void CircleSingleList::CreateList_H(int n) {
    CirNode *tmp = this->CircleList ; //头结点
    this->length = n ; // 设置链表长度
    int num = n ; // 初始化节点计数器
    int data ; // 用于存储随机数的数据变量

    // 循环创建n个节点
    while (num --){
        CirNode *s = new CirNode  ; // 创建新节点
        data = rand()%100 +1 ; // 生成1到100之间的随机数

        cout << data << " " ; // 输出随机数
        s->data = data ; // 将随机数赋值给新节点的数据域
        if(tmp->next == nullptr){ // 如果链表为空，将新节点链接到头结点，并形成循环
            tmp->next =s ;
            s->next = tmp ;
        }else {
            // 如果链表不为空，将新节点插入到链表的头部
            s->next = tmp->next ;
            tmp->next = s  ;
        }
    }

    cout << endl ; // 输出换行，用于格式化输出
}

