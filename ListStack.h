//
// Created by 24887 on 2024/7/11.
//

#ifndef ALL_LISTSTACK_H
#define ALL_LISTSTACK_H

typedef int LiStackDataElemType;

typedef struct StackNode {
    LiStackDataElemType data ;
    struct StackNode *next;
} StackNode;

class ListStack {
public:
    StackNode *top = new StackNode;

    bool EmptyListStack() ;
    bool GetTop(LiStackDataElemType &data) ;
    void InitListStack() ;
    bool Pop(LiStackDataElemType &data) ;
    bool Push(LiStackDataElemType data) ;
    bool DestroyListStack() ;
};
#endif //ALL_LISTSTACK_H
