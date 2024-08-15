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
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode *current = q.front();
        q.pop();
        if (arr[i] != -1 && i < arr.size()) {
            current->lchild = new TreeNode;
            current->lchild->val = arr[i];
            q.push(current->lchild);
        }
        i++;
        if (i < arr.size() && arr[i] != -1) {
            current->rchild = new TreeNode;
            current->rchild->val = arr[i];
            q.push(current->rchild);
        }
        i++;
    }
    return root ;
}
