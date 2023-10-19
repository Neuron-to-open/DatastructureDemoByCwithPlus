//
// Created by 24887 on 2023/10/19.
//

#include "StackAndQueue.h"
#include <iostream>
using namespace std ;

void StackAndQueue::InitStack(SqStack &S) {
    for (int i = 0 ; i < MaxSizeSQ ; i ++) {
        S.data[i] = '\0' ;
    }
    S.top = -1 ;
}

bool StackAndQueue::EmptyStack(SqStack S) {
    return S.top == -1 ? true : false ;
}

void StackAndQueue::PushStack(SqStack &S , char x) {
    if(S.top == MaxSizeSQ -1 ){
        cout << "Stack is full " << endl ;
    }
    S.top ++ ;
    S.data[S.top] = x ;
}

void StackAndQueue::PopStack(SqStack &S, char &x) {
    if(EmptyStack(S)){
        cout << "Stack is Empty" << endl ;
        return ;
    }

    x = S.data[S.top] ;
    S.top -- ;
}

void StackAndQueue::InitQueue(SqQueue &Q) {
    for (int i = 0 ; i < MaxSizeSQ ; i ++) {
        Q.data[i] = '\0' ;
    }
    Q.rear = 0 ;
    Q.front = 0 ;
}

bool StackAndQueue::EmptyQueue(SqQueue Q) {
    return Q.front == Q.rear ? true : false ;
}

bool StackAndQueue::FullQueue(SqQueue Q) {
    return (Q.rear + 1) % MaxSizeSQ == Q.front ? true : false ;
}

void StackAndQueue::PushQueue(SqQueue &Q, char x) {
    if(!FullQueue(Q)){
        Q.data[Q.rear] = x ;
        Q.rear = (Q.rear + 1) % MaxSizeSQ ;
    }
}

void StackAndQueue::PopQueue(SqQueue &Q, char &x) {
    if (!EmptyQueue(Q)){
        x = Q.data[Q.front] ;
        Q.front = (Q.front + 1) % MaxSizeSQ ;
    }
}


