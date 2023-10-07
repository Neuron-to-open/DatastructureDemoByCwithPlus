//
// Created by 24887 on 2023/10/6.
//

#ifndef ALL_CLUEBINARYTREE_H
#define ALL_CLUEBINARYTREE_H

typedef struct ThreadNode {
    char data ;
    int ltag , rtag ;
    struct ThreadNode *l, *r ;
}ThreadNode;


class cluebinarytree{
public:
    ThreadNode *pre = nullptr ;
    ThreadNode *p = nullptr ;
    ThreadNode *final = nullptr ;
    ThreadNode *final2 = nullptr ;
    ThreadNode *root = nullptr ;

    //采用前序遍历创建二叉树
    ThreadNode* create_ThreadTree() ;

    //中序线索化
    //visit处理当前节点的线索化
    void visit(ThreadNode *q) ;
    void InThread(ThreadNode *T) ;

    //中序线索化的遍历
    //中序遍历找到第一个节点 , 后继
    ThreadNode *FirstNode(ThreadNode *T) ;
    ThreadNode *NextNode(ThreadNode *p) ;
    void InOrder(ThreadNode *T) ;

    //中序遍历找到最后结点，前序
    ThreadNode *LastNode(ThreadNode *T) ;
    ThreadNode *PreNode(ThreadNode *T) ;
    void RevInorder(ThreadNode *T) ;


    //先序遍历
    void PerOrder(ThreadNode *T) ;


    //释放空间
    ThreadNode *PerFree(ThreadNode *T) ;
};
#endif //ALL_CLUEBINARYTREE_H
