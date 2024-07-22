//
// Created by 24887 on 2024/7/21.
//

#include "SingleListWithNoHead.h"
#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>

using namespace std;
bool SingleListWithNoHead::List_Create_H( int n) {

    while ( n -- ) {
        int random_number = rand() % 100 + 1;
        cout << random_number << " ";
        if (this->head == nullptr) {
            this->head = new SingleListWithoutHeadDataElement;
            this->head->data = random_number;
            this->head->next = nullptr;

        }else {
            SingleListWithoutHeadDataElement *p = new SingleListWithoutHeadDataElement;
            p->data = random_number;
            p->next = this->head->next;
            this->head = p ;
        }
    }
    cout << endl ;
    cout << "List created successfully!" << endl;
    return true;
}

bool SingleListWithNoHead::List_Create_T(int n) {
    SingleListWithoutHeadDataElement *tail= nullptr;
    while (n --) {
        int random_number = rand() % 100 + 1;
        cout << random_number << " ";
        if (this->head == nullptr) {
            this->head = new SingleListWithoutHeadDataElement;
            this->head->data = random_number;
            this->head->next = nullptr;
            tail = this->head;
        }else {
            SingleListWithoutHeadDataElement *p = new SingleListWithoutHeadDataElement;
            p->data = random_number;
            p->next = nullptr;
            if (tail != nullptr) {
                tail->next = p;
                tail = p;
            }
        }
    }

    cout << endl ;
    cout << "List created successfully!" << endl;

    return true ;
}

void SingleListWithNoHead::List_Print() {
    SingleListWithoutHeadDataElement *p = this->head;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "List printed successfully!" << endl;
}

bool SingleListWithNoHead::List_DestroyList() {
    if (this->head != nullptr) {
        SingleListWithoutHeadDataElement *p = this->head;
        while (p != nullptr) {
            SingleListWithoutHeadDataElement *q = p->next;
            delete p;
            p = q;
        }
        this->head = nullptr;
        cout << "List destroyed successfully!" << endl;
        return true;
    }else {
        cout << "List is empty!" << endl;
        return false;
    }
}
