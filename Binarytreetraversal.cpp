//
// Created by 24887 on 2023/7/15.
//

#include "Binarytreetraversal.h"
#include <iostream>
#include <cstdlib>
using namespace std ;


bttNode *bst::PerCreateTree(ElemTypeBTT *s) {

    bttNode* T ;

    if (s[this->i] == '#'){
        this->i ++ ;
        T = nullptr ;
    }else {
        T = new bttNode  ;
        T->data = s[this->i] ;
        this->i ++ ;
        T->left = PerCreateTree( s) ;
        T->right = PerCreateTree(s ) ;
    }

    return T;
}

void bst::PerOrder(bttNode * T) {
    if(T == nullptr){
        return ;
    }else {
        cout << T->data << " " ;
        PerOrder(T->left) ;
        PerOrder(T->right) ;
    }
}

void bst::InOrder(bttNode *T) {
    if(T != nullptr){
        InOrder(T->left) ;
        cout << T->data << " " ;
        InOrder(T->right) ;
    }
}

void bst::ReOrder(bttNode *T) {
    if(T != nullptr ){
        ReOrder(T->left) ;
        ReOrder(T->right) ;
        cout << T->data << " " ;
    }
}


bttNode *bst::PerFree(bttNode *T) {
    if ( T ){
        PerFree(T->left) ;
        PerFree(T->right) ;
        free(T) ;
        T = nullptr ;
    }

    return T ;
}


