//
// Created by 24887 on 2024/8/15.
//

#include "ListBinaryTree.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

TreeNode *ListBinaryTree::CreateBinaryTreeNonRecursive(std::vector<int> &arr) {
    if (arr.empty() || arr[0] == -1) {
        return nullptr;
    }

    TreeNode *root = new TreeNode ;
    root->val = arr[0];
    root->left_type = 0;
    root->right_type = 0;
    root->lchild = nullptr;
    root->rchild = nullptr;
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* current = q.front();
        q.pop();
        if (arr[i] != -1 && i < arr.size()) {
            current->lchild = new TreeNode;
            current->lchild->val = arr[i];
            current->lchild->left_type = 0;
            current->lchild->right_type = 0;
            current->lchild->lchild = nullptr;
            current->lchild->rchild = nullptr;
            q.push(current->lchild);
        }
        i++;
        if (i < arr.size() && arr[i] != -1) {
            current->rchild = new TreeNode;
            current->rchild->val = arr[i];
            current->rchild->left_type = 0;
            current->rchild->right_type = 0;
            current->rchild->lchild = nullptr;
            current->rchild->rchild = nullptr;
            q.push(current->rchild);
        }
        i++;
    }
    return root ;
}

void ListBinaryTree::InOrderThread(TreeNode *&root) {
    TreeNode *pre = nullptr;
    if (root != nullptr) {
        InOrderThreadUtil(root, pre) ;
        pre->rchild = nullptr;
        pre->right_type = 1;
    }
}

void ListBinaryTree::InOrderThreadUtil(TreeNode *&t, TreeNode *&pre) {
    if (t != nullptr) {
        InOrderThreadUtil(t->lchild, pre) ;
        if (t->lchild == nullptr) {
            t->left_type = 1;
            t->lchild = pre ;
        }

        if (pre != nullptr && pre->rchild == nullptr) {
            pre->rchild = t;
            pre->right_type = 1;
        }

        pre = t ;
        InOrderThreadUtil(t->rchild, pre) ;
    }
}

void ListBinaryTree::InOrderTraversal(TreeNode* root) {
    if (root != nullptr) {
        if (root->left_type == 0) {
            InOrderTraversal(root->lchild) ;
        }
        cout << root->val << " " ;
        if (root->right_type == 0) {
            InOrderTraversal(root->rchild) ;
        }

    }
}

void ListBinaryTree::DestroyBinaryTree(TreeNode *&root) {
    if (root != nullptr) {
        if (root->left_type == 0) {
            DestroyBinaryTree(root->rchild);
        }

        if (root->right_type == 0) {
            DestroyBinaryTree(root->lchild);
        }

        delete root ;
    }
}




