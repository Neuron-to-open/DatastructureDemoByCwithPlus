//
// Created by 24887 on 2023/7/15.
//

#ifndef ALL_BST_H
#define ALL_BST_H



typedef int ElemType ;
typedef struct bstNode {
    ElemType data ;
    struct bstNode *left ;
    struct bstNode *right ;
}bstNode;

class bst{
public:

    bstNode *root = nullptr ;//根节点引用。
    bstNode* CreateNode(int data) ;

    bstNode* InsertNode(bstNode *root , int data) ;

    void InOrderTraversal() ;
};
#endif //ALL_BST_H
