//
// Created by 24887 on 2023/9/28.
//

#include "CircleSingleList.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std ;


bool CircleSingleList::InitList_L() {
    if (this->CircleList == nullptr){
        return false ;
    }

    this->CircleList->next = nullptr ;
    this->CircleList->data = 0 ;
    return true ;
}

void CircleSingleList::CreateList_H(int n) {
    CirNode *tmp = this->CircleList ; //头结点
    this->length = n ;
    int num = n ;
    int data ;
    while (num --){
        CirNode *s = new CirNode  ;
        data = rand()%100 +1 ;

        cout << data << " " ;
        s->data = data ;
        if(tmp->next == nullptr){
            tmp->next =s ;
            s->next = tmp ;
        }else {
            s->next = tmp->next ;
            tmp->next = s  ;
        }
    }

    cout << endl ;
}
