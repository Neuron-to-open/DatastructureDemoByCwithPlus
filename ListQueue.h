//
// Created by 24887 on 2024/7/16.
//

#ifndef ALL_LISTQUEUE_H
#define ALL_LISTQUEUE_H

typedef int LiQueueDataElemType;

typedef struct QueueNode {
    LiQueueDataElemType data;
    struct QueueNode *next;
} QueueNode;

class ListQueue {
public:
    QueueNode *front = new QueueNode;
    QueueNode *rear = new QueueNode;
    bool DestroyListQueue();
    bool EmptyListQueue();
    bool GetHead(LiQueueDataElemType &data);
    bool InitListQueue();
    bool Enqueue(LiQueueDataElemType data);
    bool Dequeue(LiQueueDataElemType &data);
};

#endif //ALL_LISTQUEUE_H
