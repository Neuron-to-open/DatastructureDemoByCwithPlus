//
// Created by 24887 on 2023/7/14.
//

#include "SingleList.h"
#include <cstdlib>
#include <iostream>
using namespace std ;


bool SingleList::InitList_L() {
    this->linklist = new Node  ;    //生成头结点
    if (this->linklist == nullptr){
        return false ;
    }
    this->linklist->next = NULL ;   //头结点指针域置空
    return true ;
}

void SingleList::CreateList_R(int n) {
    int num = n ;
    this->length = n ;
    int data = 0 ;
    Node* tmp ;
    tmp = this->linklist ;
    while (num --){
        Node *s = new Node  ;
        data = rand()% 100 +1 ;
        s->data = data ;
        s->next = nullptr ;
        tmp->next = s ;
        tmp = s ;
    }
}

void SingleList::ListPrint() {
    Node *tmp = this->linklist->next ;
    while ( tmp != nullptr ){
        cout << tmp->data << " " ;
        tmp = tmp->next ;
    }
    cout << endl ;
}

bool SingleList::DestroyList() {
    if(this->linklist != nullptr){
        Node *tmp = this->linklist ;
        Node *s = tmp->next ;
        while (s != nullptr){
            tmp = s->next ;
            delete s ;
            s = tmp ;
        }
        this->linklist->next = nullptr ;
        return true ;
    }else {
        return false ;
    }
}

void SingleList::CreateList_H(int n) {

    Node *tmp = this->linklist; //头结点
    this->length = n ;
    int num = n ;
    int data ;
    while (num --){
        Node *s = new Node  ;
        data = rand()%100 + 1 ;
        cout << data << " " ;
        s->data = data ;
        s->next = tmp->next ;
        tmp->next =s ;
    }
    cout << endl ;

}

bool SingleList::GetElem_L(int i, int &data) {
    Node *tmp = this->linklist->next ;
    int j = 1 ;
    while ( j < i && tmp != nullptr){
        tmp = tmp->next ;
        j ++ ;
    }
    if(!tmp || j > i ){
        return false ;
    }
    data = tmp->data ;
    return true ;
}

bool SingleList::LocateElem_L(int key, int &loc ) {
    Node * tmp = this->linklist->next ;
    int length = 0 ;
    while (tmp != nullptr && tmp->data != key){
        tmp = tmp->next ;
        length ++ ;
    }

    if (!tmp){
        return false ;
    }
    loc = length ;
    return true ;
}

bool SingleList::ListInsert_L(int i, int e) {
    int j = 0 ;
    Node *tmp = this->linklist ;
    //找到第i-2个结点 举例为i= 3 则j = 1 就停止了即位置2
    while (tmp != nullptr && j < i-2){
        j ++ ;
        tmp = tmp->next ;
    }
    if (tmp == nullptr || j > i -1 ){
        return false ;
    }
    Node *s = new Node  ;
    s->data = e ;
    s->next = tmp->next ;
    tmp->next = s ;
    return true ;
}

bool SingleList::ListDelete_L(int i, int data) {
    Node *tmp = this->linklist->next ;
    int j = 0 ;
    while (tmp != nullptr && j < i - 1 ){
        tmp = tmp->next ;
    }

    if (tmp == nullptr || (j > i -1) ){
        return false ;
    }
    Node *s = tmp->next ;
    tmp->next = s->next ;
    delete s ;
    return true ;
}
