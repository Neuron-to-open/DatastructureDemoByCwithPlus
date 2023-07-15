//
// Created by 24887 on 2023/7/15.
//

#include "BST.h"
#include <iostream>
#include <stack>
using namespace std ;


bstNode* bst::CreateNode(int data) {
    bstNode *newNode = new bstNode ;
    if (newNode == nullptr){
        cout << "Memory error!\n" ;
        return nullptr ;
    }
    newNode->data = data ;
    newNode->left = newNode->right = nullptr ;
    return newNode ;
}

bstNode* bst::InsertNode(bstNode *root ,int data) {
    if (root == nullptr){
        return CreateNode(data) ;
    }
    if(data < root->data){ //左子树
        root->left = InsertNode(root->left , data) ;
    }
    if (data > root->data){
        root->right = InsertNode(root->right, data) ;
    }
    return root ;
}

void bst::InOrderTraversal() {
   stack<bstNode*> s ;
   bstNode *curr = this->root ;

   while ( curr != nullptr || s.empty() == false){
       while (curr != nullptr){
           s.push(curr) ;
           curr = curr->left ;
       }

       curr = s.top() ;
       s.pop() ;
       cout << curr->data << " " ;
       curr = curr->right ;
   }
   cout << endl ;
}
