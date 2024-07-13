//
// Created by 24887 on 2024/7/13.
//

#ifndef ALL_SEQUENCEQUEUE_H
#define ALL_SEQUENCEQUEUE_H
#define MaxSize 100
typedef int SeqQueueDataElemType;

typedef struct {
    SeqQueueDataElemType data[100];
    int front;
    int rear;
} SeqQueue;

class SequenceQueue {
public:
    SeqQueue sequeue ;
    bool IsEmptySeqQueue()  ;
    bool IsFullSeqQueue()  ;
    bool EnQueue(SeqQueueDataElemType data)  ;
    bool DeQueue(SeqQueueDataElemType &data)  ;
    int GetLengthSeqQueue()  ;
    void InitSeqQueue()  ;
    void DestroySeqQueue()  ;
} ;
#endif //ALL_SEQUENCEQUEUE_H
