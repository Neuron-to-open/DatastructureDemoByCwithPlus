//
// Created by 24887 on 2024/7/13.
//

#include "SequenceQueue.h"
#include <iostream>
using namespace std;
bool SequenceQueue::IsEmptySeqQueue() {
    if (this->sequeue.front == this->sequeue.rear) {
        cout << "队列为空" << endl;
        return true;
    }else {
        cout << "队列不为空" << endl;
        return false;
    }
}

bool SequenceQueue::IsFullSeqQueue() {
    if ( this->sequeue.rear == MaxSize -1 ) {
        cout << "队列已满" << endl;
        return true;
    }else {
        cout << "队列未满" << endl;
        return false;
    }
}

bool SequenceQueue::EnQueue(SeqQueueDataElemType data) {
    if (IsFullSeqQueue()) {
        cout << "队列已满,不能再入队" << endl;
        return false;
    }
    this->sequeue.data[this->sequeue.rear] = data;
    this->sequeue.rear = (this->sequeue.rear + 1) % MaxSize;
    cout << "入队成功" << endl;
    return true;
}

int SequenceQueue::GetLengthSeqQueue() {

    return this->sequeue.rear - this->sequeue.front ;
}

bool SequenceQueue::DeQueue(SeqQueueDataElemType &data) {
    if (this->sequeue.front == this->sequeue.rear) {
        cout << "队列为空,不能出队" << endl;
        return false;
    }else {
        data = this->sequeue.data[this->sequeue.front];
        this->sequeue.front = (this->sequeue.front + 1) % MaxSize;
        cout << "出队成功" << endl;
        return true;
    }
}

void SequenceQueue::InitSeqQueue() {
    this->sequeue.front = 0;
    this->sequeue.rear = 0;
    cout << "队列 初始化成功" << endl;
}

void SequenceQueue::DestroySeqQueue() {
    this->sequeue.front = 0;
    this->sequeue.rear = 0;
    cout << "队列 销毁成功" << endl;

}


