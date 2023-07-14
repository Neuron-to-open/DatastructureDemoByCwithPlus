//
// Created by 24887 on 2023/7/13.
//

#include "Sequence.h"

#include <cstdlib>
#include <iostream>

using namespace std ;






Sequence::Sequence(int size) {
    this->seq.size = size ;
}

void Sequence::InitTable() {
    this->seq.length = 6 ;
    this->seq.head = (ElemType *) malloc(sizeof(ElemType) * this->seq.length) ;
    for (int i = 0 ; i < this->seq.length ; ++ i){
        this->seq.head[i] = rand()%100 + 1 ;
    }
}

void Sequence::ShowTable() {
    for (int i = 0 ; i < this->seq.length ; ++ i){
         cout << this->seq.head[i] << " " ;
    }
    cout << endl ;
}

bool Sequence::DestroyTable() {

    if(getLength() != 0){
        free(this->seq.head) ;
        return true ;
    }
    return false ;
}

void Sequence::addLength() {
    this->seq.size = this->seq.size * 2 ;
    this->seq.head = (ElemType *) realloc(this->seq.head , this->seq.size) ;
    if (this->seq.head == nullptr ){
        cout << "The Increase fail" << endl ;
    }
}

int Sequence::getLength() {
    return this->seq.length;
}

bool Sequence::isEmpty() {
    if (getLength() == 0){
        return true ;
    }
    return false;
}

int Sequence::LocateElem(int e) {
    for (int i =0 ; i < this->seq.length ; i ++){
        if (this->seq.head[i] == e ){
            return i+1 ;
        }
    }
    return -1;
}

bool Sequence::getElem(int i, int &Elem) {
    if (this->seq.length == 0 || this->seq.length < i || i <= 0 ){
        return false ;
    }
    Elem = this->seq.head[i-1] ;
    return true ;
}

bool Sequence::InsertTable(int i, int elem) {
    if (this->seq.size > i && i >= 1 ){
        int j = this->seq.length - 1 ;
        for ( ; j >= i -1 ; --j){
            this->seq.head[j+1] = this->seq.head[j] ;
        }
        this->seq.head[j+1] = elem ;
        this->seq.length ++ ;
        return true ;
    }
    return false;
}

bool Sequence::DeleteTable(int i, int &data) {
    if ( this->seq.length >= i && i >= 1){
        data = this->seq.head[i-1] ;
        int j = i -1 ;
        for ( ; j <= this->seq.length -1 ; ++ j){
            this->seq.head[j] = this->seq.head[j+1];
        }
        this->seq.length -- ;
        return true ;
    }
    return false ;
}






