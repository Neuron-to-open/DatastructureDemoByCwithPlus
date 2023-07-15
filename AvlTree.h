//
// Created by 24887 on 2023/7/15.
//

#ifndef ALL_AVLTREE_H
#define ALL_AVLTREE_H

typedef int ElemType ;
typedef struct AvlNode{
    struct AvlNode* left ;
    struct AvlNode* right ;
    int height ; //高度
    ElemType keydata ;
}AvlNode;


class AvlTree{
    AvlNode* root ; // root
public:
    AvlTree();

    int getHeight(AvlNode *node) ;

    int getBalance(AvlNode *node) ;

    int Max(int a , int b) ;

    AvlNode* rightRotate(AvlNode* y) ;

    AvlNode* leftRotate(AvlNode* x) ;

    AvlNode* newNode(int key) ;
    AvlNode* InsertNode(AvlNode* node , ElemType key) ;
};


#endif //ALL_AVLTREE_H
