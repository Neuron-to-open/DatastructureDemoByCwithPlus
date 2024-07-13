//
// Created by 24887 on 2024/7/13.
//

#ifndef ALL_SEQUENCEQUEUE_H
#define ALL_SEQUENCEQUEUE_H
typedef int SeqQueueDataElemType;

typedef struct {
    SeqQueueDataElemType *data;
    int front;
    int rear;
} SeqQueue;

class SequenceQueue {
public:
    SeqQueue *queue = new SeqQueue;
    bool IsEmptySeqQueue()  ;
    bool IsFullSeqQueue()  ;
    bool EnQueue(SeqQueueDataElemType data)  ;
    bool DeQueue(SeqQueueDataElemType &data)  ;
    int GetLengthSeqQueue()  ;
    void InitSeqQueue()  ;
    void DestroySeqQueue()  ;
}
#endif //ALL_SEQUENCEQUEUE_H
