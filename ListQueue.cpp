//
// Created by 24887 on 2024/7/16.
//

#include "ListQueue.h"
#include <iostream>
using namespace std;

bool ListQueue::DestroyListQueue() {
    if ( this->rear == this->front ) {
        cout << "队列为空" << endl;
        return true;
    }
    while ( this->rear!= this->front ) {
        QueueNode *p = this->front ;
        while (p->next != nullptr) {
            p = p->next;
        }
    }

    return false;
}

bool ListQueue::EmptyListQueue() {
    if ( this->rear == this->front ) {
        cout << "队列为空" << endl;
        return true;
    }
    cout << "队列不为空" << endl;
    return false;
}

bool ListQueue::InitListQueue() {
    QueueNode *p = new QueueNode;
    this->front = p;
    this->rear = p;
    cout << "队列初始化成功" << endl;
}

bool ListQueue::Enqueue(LiQueueDataElemType data) {
    if ( this->rear == this->front ) {
        cout << "队列为空" << endl;
        QueueNode *p = new QueueNode;
        p->data = data;
        p->next = nullptr;
        this->front->next = p;
        this->rear = p;
        cout << "元素入队成功" << endl;

    } else {
        QueueNode *p = new QueueNode;
        p->data = data;
        p->next = nullptr;
        this->rear->next = p;
        this->rear = p;
        cout << "元素入队成功" << endl;

    }

    return true ;

}

bool ListQueue::Dequeue(LiQueueDataElemType &data) {
    if ( this->rear == this->front ) {
        cout << "队列为空" << endl;
        return false;
    }
    QueueNode *p = this->front;
    this->front = this->front->next;
    data = p->data;
    delete p;
    cout << "元素出队成功" << endl;
    return true;
}

bool ListQueue::GetHead(LiQueueDataElemType &data) {
    if ( this->rear == this->front ) {
        cout << "队列为空" << endl;
        return false;
    }
    data = this->front->data;
    cout << "获取队头元素成功" << endl;
    return false;
}

