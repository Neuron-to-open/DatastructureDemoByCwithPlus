//
// Created by 24887 on 2023/9/27.
//

#include "DoubleLinkedList.h"

#include <cstdlib>
#include <iostream>

using namespace std ;


DoubleLinkedList::DoubleLinkedList() {

}

bool DoubleLinkedList::InitTDoubleList() {
    if(this->dll == nullptr){
        return false ;
    }
    this->dll->next = NULL ;
    this->dll->prior = NULL ;

    return true ;
}

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

void DoubleLinkedList::DisplayLink() {
    DNode *tmp = this->dll ;
    while (tmp->next != nullptr ){
        cout << tmp->next->data << " " ;
        tmp = tmp->next ;
    }
    cout << endl ;
}

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


