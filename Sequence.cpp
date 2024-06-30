//
// Created by 24887 on 2023/7/13.
//

#include "Sequence.h"
#include <cstdlib>
#include <iostream>

using namespace std ;

#define MAXSIZE 100 // 定义最大序列长度

// 初始化序列
Sequence::Sequence(int size) {
    this->seq.size = size;
}

// 初始化表，设定初始长度为6，并随机填充元素
void Sequence::InitTable() {
    this->seq.length = 6;
    this->seq.head = (SequenceDataElement *) malloc(sizeof(SequenceDataElement) * this->seq.length);
    for (int i = 0; i < this->seq.length; ++i) {
        this->seq.head[i] = rand() % 100 + 1;
    }
}

// 显示表的内容
void Sequence::ShowTable() {
    for (int i = 0; i < this->seq.length; ++i) {
        cout << this->seq.head[i] << " ";
    }
    cout << endl;
}

// 销毁表，释放内存
bool Sequence::DestroyTable() {
    if (getLength() != 0) {
        free(this->seq.head);
        return true;
    }
    return false;
}

// 扩充序列的容量
void Sequence::addLength() {
    this->seq.size = this->seq.size * 2;
    this->seq.head = (SequenceDataElement *) realloc(this->seq.head, this->seq.size);
    if (this->seq.head == nullptr) {
        cout << "The Increase fail" << endl;
    }
}

// 获取序列的当前长度
int Sequence::getLength() {
    return this->seq.length;
}

// 判断序列是否为空
bool Sequence::isEmpty() {
    if (getLength() == 0) {
        return true;
    }
    return false;
}

// 在序列中定位元素的位置，返回位置索引，若不存在返回-1
int Sequence::LocateElem(int e) {
    for (int i = 0; i < this->seq.length; i++) {
        if (this->seq.head[i] == e) {
            return i + 1;
        }
    }
    return -1;
}

// 获取序列中指定位置的元素，通过引用返回
bool Sequence::getElem(int i, int &Elem) {
    if (this->seq.length == 0 || this->seq.length < i || i <= 0) {
        return false;
    }
    Elem = this->seq.head[i - 1];
    return true;
}

// 在序列中插入一个元素
bool Sequence::InsertTable(int i, int elem) {
    if (this->seq.size > i && i >= 1) {
        int j = this->seq.length - 1;
        for (; j >= i - 1; --j) {
            this->seq.head[j + 1] = this->seq.head[j];
        }
        this->seq.head[j + 1] = elem;
        this->seq.length++;
        return true;
    }
    return false;
}

// 从序列中删除一个元素，并通过引用返回被删除的元素
bool Sequence::DeleteTable(int i, int &data) {
    if (this->seq.length >= i && i >= 1) {
        data = this->seq.head[i - 1];
        int j = i - 1;
        for (; j <= this->seq.length - 1; ++j) {
            this->seq.head[j] = this->seq.head[j + 1];
        }
        this->seq.length--;
        return true;
    }
    return false;
}







