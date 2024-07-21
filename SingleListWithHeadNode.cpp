//
// Created by 24887 on 2023/7/14.
//

#include "SingleListWithHeadNode.h"
#include <cstdlib>
#include <iostream>
using namespace std ;
/*
 * 有效的使用引用，可以避免单链表的断链
 * 对于链表，如果更改原链表，那么就要使用指针的指针或者 对于指针的引用。
 * 对于链表，但是如果只是更改链表的中间节点，那么只需要链表的指针就行
 * 另外，通过new和malloc等函数，其实是用在堆区创建空间，赋予结构体一个合理的地址空间。
*/


/**
 * 初始化单链表
 *
 * 本函数用于初始化一个单链表。它首先检查链表是否已经初始化过，如果链表指针为空，则表示尚未初始化，
 * 此时函数将链表的头节点设置为空指针，表示链表为空。如果链表已经初始化过，则不进行任何操作。
 *
 * @return bool 返回true表示链表已成功初始化（或已经是空链表），返回false表示链表已初始化过。
 */
bool SingleListWithHeadNode::List_Init() {
    // 检查链表是否为空，如果为空，则初始化链表头结点为NULL
    if (this->LinklistNode == nullptr) {
        return false;
    }
    this->LinklistNode->data = -1 ;
    this->LinklistNode->next = nullptr; // 头结点指针域置空
    cout << "链表已初始化" << endl;
    return true;
}


/**
 * 头插法创建单链表
 *
 * 本函数通过头插法创建一个含有n个元素的单链表。元素值为随机生成的1到100之间的整数。
 *
 * @param n 插入的元素数量
 */
void SingleListWithHeadNode::List_Create_H(int n) {
    SingleListNode *tmp = this->LinklistNode; // 头结点
    this->length = n;
    int num = n;
    int data;
    while (num--) {
        SingleListNode *s = new SingleListNode;
        data = rand() % 100 + 1;
        cout << data << " ";
        s->data = data;
        s->next = tmp->next;
        tmp->next = s;
    }
    cout << endl;
    cout << "链表头插法创建成功" << endl;
}


/**
 * 尾插法创建单链表
 *
 * 本函数通过尾插法创建一个含有n个元素的单链表。元素值为随机生成的1到100之间的整数。
 *
 * @param n 插入的元素数量
 */
void SingleListWithHeadNode::List_Create_T(int n) {
    int num = n;
    this->length = n;
    int data = 0;
    SingleListNode* tmp = this->LinklistNode;
    while (num--) {
        SingleListNode *s = new SingleListNode;
        data = rand() % 100 + 1;
        s->data = data;
        s->next = nullptr;
        tmp->next = s;
        tmp = s;
    }
    cout << "链表尾插法创建成功" << endl;
}

/**
 * 打印链表
 *
 * 本函数用于打印链表中的所有元素，从头节点之后的第一个节点开始打印，直到最后一个节点。
 */
void SingleListWithHeadNode::List_Print() {
    SingleListNode *tmp = this->LinklistNode->next;
    while (tmp != nullptr) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
    cout << "链表打印成功" << endl;
}

/**
 * 销毁单链表
 *
 * 本函数用于销毁单链表，释放所有节点的内存。
 *
 * @return bool 返回true表示链表已成功销毁，返回false表示链表为空。
 */
bool SingleListWithHeadNode::List_Destroy() {
    if (this->LinklistNode != nullptr) {
        SingleListNode *tmp = this->LinklistNode;
        SingleListNode *s = tmp->next;
        while (s != nullptr) {
            tmp = s->next;
            delete s;
            s = tmp;
        }
        this->LinklistNode->next = nullptr;
        cout << "链表已销毁" << endl;
        return true;
    } else {
        cout << "链表为空，无法销毁" << endl;
        return false;
    }
}


/**
 * 获取指定位置的元素
 *
 * 本函数用于获取链表中指定位置的元素值。位置从1开始计算。
 *
 * @param i 指定位置
 * @param data 引用参数，用于返回元素值
 * @return bool 返回true表示成功获取元素，返回false表示位置不合法或链表为空。
 */
bool SingleListWithHeadNode::List_GetElem_H(int i, int &data) {
    SingleListNode *tmp = this->LinklistNode->next;
    int j = 1;
    while (j < i && tmp != nullptr) {
        tmp = tmp->next;
        j++;
    }
    if (!tmp || j > i) {
        return false;
    }
    data = tmp->data;
    cout << "获取元素成功" << endl;
    return true;
}

/**
 * 查找指定值的元素位置
 *
 * 本函数用于查找链表中第一个等于指定值的元素，并返回其位置。位置从0开始计算。
 *
 * @param key 指定值
 * @param loc 引用参数，用于返回元素位置
 * @return bool 返回true表示找到元素，返回false表示未找到元素。
 */
bool SingleListWithHeadNode::List_LocateElem_H(int key, int &loc) {
    SingleListNode *tmp = this->LinklistNode->next;
    int length = 0;
    while (tmp != nullptr && tmp->data != key) {
        tmp = tmp->next;
        length++;
    }

    if (!tmp) {
        return false;
    }
    loc = length;
    cout << "找到元素位置" << endl;
    return true;
}

/**
 * 在指定位置插入元素
 *
 * 本函数用于在链表中的指定位置插入元素。位置从1开始计算。
 *
 * @param i 插入位置
 * @param e 插入的元素值
 * @return bool 返回true表示插入成功，返回false表示位置不合法或链表为空。
 */
bool SingleListWithHeadNode::List_Insert_H(int i, int e) {
    int j = 0;
    SingleListNode *tmp = this->LinklistNode;
    // 找到第i-1个结点 举例为i=3 则j=1 就停止了即位置2
    while (tmp != nullptr && j < i - 1) {
        j++;
        tmp = tmp->next;
    }
    if (tmp == nullptr || j > i - 1) {
        return false;
    }
    SingleListNode *s = new SingleListNode;
    s->data = e;
    s->next = tmp->next;
    tmp->next = s;
    this->length++;
    cout << "插入元素成功" << endl;
    return true;
}

/**
 * 删除指定位置的元素
 *
 * 本函数用于删除链表中的指定位置的元素。位置从1开始计算。
 *
 * @param i 删除位置
 * @param data 引用参数，用于返回删除的元素值
 * @return bool 返回true表示删除成功，返回false表示位置不合法或链表为空。
 */
bool SingleListWithHeadNode::List_Delete_H(int i, int &data) {
    SingleListNode *tmp = this->LinklistNode;
    int j = 0;
    while (tmp != nullptr && j < i - 1) {
        tmp = tmp->next;
        j++;
    }

    if (tmp == nullptr || tmp->next == nullptr) {
        return false;
    }
    SingleListNode *s = tmp->next;
    data = s->data;
    tmp->next = s->next;
    delete s;
    cout << "删除元素成功" << endl;
    return true;
}


int SingleListWithHeadNode::List_GetLength() {
    cout << "链表长度为" << this->length << endl;
   return this->length;
}