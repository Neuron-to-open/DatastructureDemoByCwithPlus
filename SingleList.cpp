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
        cout << data << " " ;
        s->data = data ;
        s->next = nullptr ;
        tmp->next = s ;
        tmp = s ;
    }
    cout << endl ;
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
    if (this->linklist != nullptr){
        free(this->linklist) ;
        return true ;
    }

    return false ;
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
