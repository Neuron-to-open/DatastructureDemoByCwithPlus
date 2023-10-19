//
// Created by 24887 on 2023/10/19.
//

#ifndef ALL_STACKANDQUEUE_H
#define ALL_STACKANDQUEUE_H

#define MaxSizeSQ 10
// 定义一个栈
typedef struct {
    char data[MaxSizeSQ] ;
    int top ;
}SqStack;

typedef struct {
    char data[MaxSizeSQ] ;
    int rear , front ;
}SqQueue;


class StackAndQueue{
public:
    SqStack stack ;
    SqStack Queue ;

    void InitStack(SqStack& S) ;
    bool EmptyStack(SqStack S) ;
    void PushStack(SqStack& S, char x) ;
    void PopStack(SqStack& S , char &x) ;

    void InitQueue(SqQueue& Q) ;
    bool EmptyQueue(SqQueue Q) ;
    bool FullQueue(SqQueue Q) ;
    void PushQueue(SqQueue& Q , char x) ;
    void PopQueue(SqQueue& Q , char &x) ;
};

#endif //ALL_STACKANDQUEUE_H
