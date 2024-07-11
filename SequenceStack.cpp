//
// Created by 24887 on 2023/9/1.
//

#include "SequenceStack.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

SequenceStack::SequenceStack() {
    InitSequenceStack();
}

void SequenceStack::InitSequenceStack() {
    this->seqStack.top = -1;
    this->seqStack.stack = (SequenceStackDataElement *) malloc(sizeof(SequenceStackDataElement) * MAX_STACK_SIZE);

}

bool SequenceStack::EmptySequenceStack() {
    if (this->seqStack.top == -1) {
        return true;
    }
    return false;
}

bool SequenceStack::Push(SequenceStackDataElement data) {
    if (this->seqStack.top == MAX_STACK_SIZE - 1) {

        cout << "Stack overflow!" << endl;
        return false;
    } else {
        this->seqStack.top++;
        this->seqStack.stack[this->seqStack.top] = data;
        return true;
    }
}

bool SequenceStack::Pop(SequenceStackDataElement &data) {
    if (this->seqStack.top == -1) {
        cout << "Stack is empty!" << endl;
        return false;
    } else {
        data = this->seqStack.stack[this->seqStack.top];
        this->seqStack.top--;
        return true;
    }
}

bool SequenceStack::GetTop(SequenceStackDataElement &data) {

    if (this->seqStack.top == -1) {
        cout << "Stack is empty!" << endl;
        return false;
    } else {
        data = this->seqStack.stack[this->seqStack.top];
        return true;
    }

}


