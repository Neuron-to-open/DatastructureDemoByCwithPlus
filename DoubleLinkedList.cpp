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
    this->dll->next = nullptr ;
    this->dll->prior = nullptr ;

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

/**
 * 销毁双向链表。
 * 该函数遍历链表，逐个删除链表节点，最后删除链表头节点，从而彻底销毁链表。
 * 这是一个成员函数，它操作类的私有成员dll，该成员是链表的头节点指针。
 *
 * @return bool 返回true，表示链表已成功销毁。本函数不涉及返回值的实际使用，主要是为了符合函数签名的要求。
 */
void DoubleLinkedList::DestroyList() {
    // 检查链表是否为空，避免空指针解引用
    if (this->dll == nullptr) {
        cout << "The list is empty." << endl;
        return ; // 链表为空，直接返回成功
    }

    // 保存当前节点，从链表头开始遍历
    DNode *tmp = dll;
    DNode *p = nullptr;

    // 遍历链表直到最后一个节点
    while (tmp->next != nullptr) {
        // 暂存下一节点
        p = tmp->next;

        // 删除当前节点，注意：这里不直接使用tmp->prev，因为函数的目的是销毁链表，
        // 而不是调整链表内部指针。如果需要在删除节点后调整剩余节点的指针，那么就需要考虑tmp->prev的更新。
        delete tmp;

        // 将tmp更新为下一个待删除的节点
        tmp = p;
    }

    // 删除最后一个节点
    delete tmp;

    // 清空头指针，确保链表状态一致
    dll = nullptr;

    // 打印提示信息
    cout << "The list has been destroyed." << endl;
}



