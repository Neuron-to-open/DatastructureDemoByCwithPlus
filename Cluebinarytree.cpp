//
// Created by 24887 on 2023/10/6.
//

#include "Cluebinarytree.h"
#include <iostream>
using namespace std ;

ThreadNode *cluebinarytree::create_ThreadTree() {
    ThreadNode * T;
    char ch ;
    cin >> ch ;
    if (ch == '#'){
        T = nullptr ;
    }else {
        T = new ThreadNode ;
        T->data = ch ;
        T->ltag = 0 ;
        T->rtag = 0 ;
        T->l = create_ThreadTree() ;
        T->r = create_ThreadTree() ;
    }
    return T;
}

void cluebinarytree::PerOrder(ThreadNode *T) {
    if(T){
        cout << T->data << " " ;
        PerOrder(T->l) ;
        PerOrder(T->r) ;
    }
    return ;
}

ThreadNode *cluebinarytree::PerFree(ThreadNode *T) {
    ThreadNode *p = FirstNode(T) ;
    while(p != nullptr){
        ThreadNode  *q = NextNode(p) ;
        free(p) ;
        p = q ;
    }

    return T ;
}


void cluebinarytree::visit(ThreadNode *q) {
    //中序遍历只考虑：前节点的后继与当前节点的前驱
    if(q->l == nullptr){
        q->l = pre ;
        q->ltag = 1 ;
    }

    if (pre != nullptr && pre->r == nullptr){
        pre->r = q ;
        pre->rtag = 1 ;
    }

    pre = q ;
}

void cluebinarytree::InThread(ThreadNode *T) {
    if (T == nullptr){
        return ;
    }else {
        InThread(T->l) ;
        visit(T) ;
        InThread(T->r) ;
    }

    //处理最后一个结点的线索
    if(pre->r == nullptr){
        pre->rtag = 1 ;
    }
}

ThreadNode *cluebinarytree::NextNode(ThreadNode *p) {
    if(p->rtag == 0){
        return FirstNode(p->r) ;
    }else {
        return p->r ;
    }
}

void cluebinarytree::InOrder(ThreadNode *T) {
    for (ThreadNode *p = FirstNode(T) ; p != nullptr ; p = NextNode(p)){
        cout << p->data << " " ;
    }
    cout << endl ;
}

ThreadNode *cluebinarytree::LastNode(ThreadNode *T) {
    while (T->rtag == 0){
        T = T->r ;
    }
    return T ;
}

ThreadNode *cluebinarytree::PreNode(ThreadNode *T) {
    if(T->ltag == 0) {
        return LastNode(T->l) ;
    }else {
        return T->l ;
    }
}

void cluebinarytree::RevInorder(ThreadNode *T) {
    for (ThreadNode *p = LastNode(T) ; p != nullptr ; p = PreNode(p)){
        cout << p->data << " " ;
    }
    cout << endl ;
}
