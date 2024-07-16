//
// Created by 24887 on 2024/7/11.
//

#include "ListStack.h"
#include <iostream>
using namespace std;
bool ListStack::EmptyListStack() {
    if (this->top->next == nullptr) {
        cout << "Stack is empty" << endl;
        return true;
    }
    cout << "Stack is not empty" << endl;
    return false;
}


void ListStack::InitListStack() {
    this->top->next = nullptr;
    cout << "InitListStack successfully" << endl;
}

bool ListStack::Push(LiStackDataElemType data) {
    int flag = -1 ;
    if (this->top->next == nullptr) {
        StackNode *newNode = new StackNode;
        newNode->data = data;
        newNode->next = nullptr;
        this->top->next = newNode;
        flag = 1 ;
    }else {
        StackNode *newNode = new StackNode;
        newNode->data = data;
        newNode->next = this->top->next;
        this->top->next = newNode;
        flag = 1 ;

    }
    if (flag == 1) {
        cout << "Push data: " << data << " successfully" << endl;
        return true;
    }else {
        return false;
    }
}

bool ListStack::Pop(LiStackDataElemType &data) {
    int flag = -1 ;
    if (this->top->next == nullptr) {
        cout << "Stack is empty" << endl;
        flag = 0;
    }else {
        StackNode *temp = this->top->next;
        data = temp->data;
        this->top->next = temp->next;
        delete temp;
        flag = 1 ;
        cout << "Pop data: " << data << " successfully" << endl;
    }
    if (flag == 1) {
        return true;
    }else {
        return false;
    }
}

bool ListStack::GetTop(LiStackDataElemType &data) {
    int flag = -1 ;
    if (this->top->next == nullptr) {
        cout << "Stack is empty" << endl;
        flag = 0;
    }else {
        data = this->top->next->data;
        flag = 1 ;
        cout << "GetTop data: " << data << " successfully" << endl;
    }
    if (flag == 1) {
        return true;
    }else {
        return false;
    }
}

bool ListStack::DestroyListStack() {
    int flag = -1 ;

    if (this->top->next == nullptr) {
        cout << "Stack is empty" << endl;
        flag = 0;
    }else {
        StackNode *temp = this->top->next;
        while (temp != nullptr) {
            StackNode *next = temp->next;
            delete temp;
            temp = next;
        }
        this->top->next = nullptr;
        flag = 1;
        cout << "DestroyListStack successfully" << endl;
        if (flag == 1 || flag == 0) {
            return true;
        } else {
            return false;
        }

    }

}