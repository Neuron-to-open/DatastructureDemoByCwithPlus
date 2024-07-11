//
// Created by 24887 on 2023/9/1.
//

#ifndef ALL_SEQUENCESTACK_H
#define ALL_SEQUENCESTACK_H
#define MAX_STACK_SIZE 100

/* 定义元素类型为整型 */
typedef int SequenceStackDataElement ;
/* 定义顺序栈结构 */
typedef struct {
    SequenceStackDataElement *stack ;
    int top ;
}SeqStack ;

/* 初始化顺序栈 */
class SequenceStack {
public:

    SeqStack seqStack ; // 栈实例

    SequenceStack();


    void InitSequenceStack();

    bool EmptySequenceStack();

    bool Push(SequenceStackDataElement data) ;

    bool Pop(SequenceStackDataElement &data) ;

    bool GetTop(SequenceStackDataElement &data) ;



};
#endif //ALL_SEQUENCESTACK_H
