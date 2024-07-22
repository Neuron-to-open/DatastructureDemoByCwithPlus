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
bool CircleSingleList::CircleSingleList_Init_L() {
    // 检查链表指针是否为空，如果为空，则初始化失败
    if (this->CircleListHeadNode == nullptr){
        cout << "Error: CircleList is nullptr!" << endl ;
        return false ;
    }

    // 初始化链表的头结点，设置next指针为空，data值为0
    this->CircleListHeadNode->next = nullptr ;
    this->CircleListHeadNode->data = 0 ;
    cout << "CircleList initialized successfully!" << endl ;
    return true ;
}

/**
 * 通过随机数创建循环单链表
 * @param n 链表中节点的数量
 */
void CircleSingleList::CircleSingleList_Create_H(int n) {
    CirNode *tmp = this->CircleListHeadNode ; //头结点
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

    cout << "" << endl ; // 输出换行符
    cout << "CircleList created successfully!" << endl ;
}

void CircleSingleList::CircleSingleList_Create_R(int n) {
    CirNode *tmp = this->CircleListHeadNode ; //头结点
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
            // 如果链表不为空，将新节点插入到链表的尾部
            CirNode *p = tmp->next ;
            while (p->next != tmp){
                p = p->next ;
            }
            p->next = s ;
            s->next = tmp ;
        }
    }

    cout << "" << endl ; // 输出换行符
    cout << "CircleList created successfully!" << endl ;
}

void CircleSingleList::CircleSingleList_Print() {
    CirNode *p = this->CircleListHeadNode->next ; // 指向头结点的下一个节点
    cout << "CircleList: " ;
    do {
        cout << p->data << " " ; // 输出节点数据域
        p = p->next ; // 指向下一个节点
    } while (p != this->CircleListHeadNode->next) ; // 循环到头结点
    cout << endl ;
    cout << "CircleList printed successfully!" << endl ;
}

bool CircleSingleList::CircleSingleList_Destroy() {
    CirNode *p = this->CircleListHeadNode->next ; // 指向头结点的下一个节点
    CirNode *q = nullptr ; // 指向待删除节点的前驱节点
    while (p != this->CircleListHeadNode->next){ // 循环到头结点
        q = p ; // 记录待删除节点的前驱节点
        p= p->next ; // 指向待删除节点的后继节点
        delete q ; // 删除待删除节点
    }
    delete this->CircleListHeadNode ; // 删除头结点
    this->CircleListHeadNode = nullptr ; // 置空头指针
    this->length = 0 ; // 置空链表长度
    cout << "CircleList destroyed successfully!" << endl ;
    return true ;
}







