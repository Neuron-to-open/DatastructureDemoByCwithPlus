//
// Created by 24887 on 2024/8/15.
//

#ifndef ALL_LISTBINARYTREE_H
#define ALL_LISTBINARYTREE_H
#include <vector>

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

    void InOrderTraversal(TreeNode* &root) ;
} ;

#endif //ALL_LISTBINARYTREE_H
