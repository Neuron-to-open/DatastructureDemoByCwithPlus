//
// Created by 24887 on 2023/7/15.
//

#ifndef ALL_BINARYTREETRAVERSAL_H
#define ALL_BINARYTREETRAVERSAL_H



typedef char ElemTypeBTT ;

typedef struct bttNode {
    ElemTypeBTT data ;
    struct bttNode *left ;
    struct bttNode *right ;
}bttNode;

class bst{
public:

    bttNode *root = nullptr ;//根节点引用。

    int i = 0 ;

    bttNode* PerCreateTree(ElemTypeBTT s[]) ; // 先序递归建立二叉树

    void PerOrder(bttNode* T) ; //先序遍历

    void InOrder(bttNode* T) ; //中序遍历

    void ReOrder(bttNode* T) ; //后序遍历

    bttNode* PerFree(bttNode* T) ;
};
#endif //ALL_BINARYTREETRAVERSAL_H
