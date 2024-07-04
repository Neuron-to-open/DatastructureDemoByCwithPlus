//
// Created by 24887 on 2023/9/27.
//

#include "DoubleLinkedList.h"

#include <cstdlib>
#include <iostream>

using namespace std ;


/**
 * 双向链表类的构造函数。
 * 初始化链表指针。
 */
DoubleLinkedList::DoubleLinkedList() {

}

/**
 * 初始化双向链表。
 * 如果链表指针为空，则返回false；否则，设置链表头尾指针为NULL。
 * @return 初始化成功返回true，否则返回false。
 */
bool DoubleLinkedList::InitTDoubleList() {
    if(this->dll == nullptr){
        return false ;
    }
    this->dll->next = NULL ;
    this->dll->prior = NULL ;

    return true ;
}

/**
 * 以链表头插入方式创建双向链表。
 * @param n 链表中节点的数量。
 */
void DoubleLinkedList::CreateList_H(int n) {
    DNode *tmp = this->dll ;
    this->length = n ;
    int num = n ;
    int data ;
    while (num --){
        DNode *s= new DNode  ;
        data = rand()%100 +1 ;
        cout << data << " " ;
        s->data = data ;
       s->prior = tmp ;
       s->next = tmp->next ;
       tmp->next = s ;
    }
    cout << endl ;
}

/**
 * 显示链表内容。
 * 从链表头开始遍历，打印每个节点的数据。
 */
void DoubleLinkedList::DisplayLink() {
    DNode *tmp = this->dll ;
    while (tmp->next != nullptr ){
        cout << tmp->next->data << " " ;
        tmp = tmp->next ;
    }
    cout << endl ;
}

/**
 * 以尾插入方式创建双向链表。
 * @param n 链表中节点的数量。
 */
void DoubleLinkedList::CreateList_T(int n) {
    int num = n ;
    this->length = n ;
    int data = 0 ;
    DNode *tmp = this->dll ;
    while(num --){
        DNode *s = new DNode  ;
        data = rand()%100 +1 ;
        cout << data << " " ;
        s->data = data ;
        s->prior = tmp ;
        tmp->next = s ;
        s->next = nullptr ;
        tmp = s ;
    }
    cout << endl ;
}



