//
// Created by 24887 on 2023/7/15.
//

#include "AvlTree.h"

AvlTree::AvlTree() {
    this->root = nullptr ;
}

int AvlTree::getHeight(AvlNode *node) {
    if( node == nullptr){
        return -1 ;
    }
    return node->height;
}

int AvlTree::Max(int a, int b) {
    return (a > b) ? a : b ;
}

int AvlTree::getBalance(AvlNode *node) {
    if (node == nullptr){
        return -2 ;
    }
    return this->getHeight(node->left) - this->getHeight(node->right) ;
}

AvlNode *AvlTree::rightRotate(AvlNode *y) {
    AvlNode* x = y->left ;
    AvlNode* T2 = x ->right ;
    x->right = y ;
    y->left = T2 ;
    x->height = this->Max(this->getHeight(x->left) , this->getHeight(x->right)) +1 ;
    y->height = this->Max(this->getHeight(y->left) , this->getHeight(y->right)) +1 ;
    return x ;
}

AvlNode *AvlTree::leftRotate(AvlNode *x) {
    AvlNode* y = x->right;
    AvlNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = this->Max(this->getHeight(x->left), this->getHeight(x->right)) + 1;
    y->height = this->Max(this->getHeight(y->left), this->getHeight(y->right)) + 1;
    return y;
}

AvlNode *AvlTree::newNode(int key) {

    AvlNode* newnode = new AvlNode ;
    newnode->keydata = key ;
    newnode->height = 1 ;
    newnode->left = nullptr ;
    newnode->right = nullptr ;
    return newnode ;
}


AvlNode *AvlTree::InsertNode(AvlNode *node, ElemTypeAVL key) {
    /*1 Perform the normal BST Insertion**/
    if( node == nullptr){
        return this->newNode(key) ;
    }else if(key < node->keydata){
        this->InsertNode(node->left , key) ;
    }else if (key > node->keydata){
        this->InsertNode(node->right , key) ;
    }else {
        return node ;
    }

    /*2 Update height of this ancestor node**/
    node->height = 1 + this->Max(this->getHeight(node->left) , this->getHeight(node->right)) ;

    /*3 **/
    int balance = this->getBalance(node) ;

    // Left Left Case
    if(balance > 1 && key < node->left->keydata){
        return this->rightRotate(node) ;
    }

    // Right Right Case
    if(balance < -1 && key > node->right->keydata){
        return this->leftRotate(node) ;
    }

    // Left Right Case
    if (balance > 1 && key > node->right->keydata){
        node->left = leftRotate(node->left) ;
        return rightRotate(node) ;
    }

    // Right Left Case
    if( balance < -1 && key < node->right->keydata){
        node->right = rightRotate(node->right) ;
        return leftRotate(node) ;
    }

    return node ;
}



