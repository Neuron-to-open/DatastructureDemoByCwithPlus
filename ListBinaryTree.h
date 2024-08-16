//
// Created by 24887 on 2024/8/15.
//

#ifndef ALL_LISTBINARYTREE_H
#define ALL_LISTBINARYTREE_H
#include <vector>

/*
 * left_type == 0 表示指向结点的左孩子
 * right_type == 0 表示指向结点的右孩子
 * left_type == 1 表示指向结点的前驱
 * right_type == 1 表示指向结点的后继
 * */
typedef struct Thread {
    struct Thread *lchild , *rchild ;
    int val ;
    int left_type ;
    int right_type ;
}TreeNode ;

class ListBinaryTree {

public:



    TreeNode* CreateBinaryTreeNonRecursive(std::vector<int> &arr) ;

    void InOrderThread(TreeNode* &root) ;

    void InOrderThreadUtil(TreeNode* &t, TreeNode* &pre) ;

    void InOrderTraversal(TreeNode* root) ;

    void DestroyBinaryTree(TreeNode* &root) ;
} ;

#endif //ALL_LISTBINARYTREE_H
