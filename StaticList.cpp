//
// Created by 24887 on 2024/7/22.
//

#include "StaticList.h"
#include <iostream>
using namespace std;
void StaticLinkList::StaticList_Init() {
    this->staticList[0].next= -1 ;

    for (int i = 1 ; i < MAX_STATICLIST_SIZE ; i++) {
        this->staticList[i].next = -2 ;
    }

    cout << "StaticList_Init" << endl ;
}

int StaticLinkList::StaticList_InsertByLocation(int pos ,StaticListDataElement data) {

    int freePos = -1 ;
    for (int i = 1 ; i < MAX_STATICLIST_SIZE ; i++) {
        if (this->staticList[i].next == -2) {
            freePos = i ;
            break ;
        }
    }

    if (freePos == -1) {
        cout << "StaticList_Insert: No free position" << endl ;
        return 0;
    }

    int current = 0 ;
    int count = 0 ;

    while (count < pos && this->staticList[current].next!= -1) {
        current = this->staticList[current].next ;
        count++ ;
    }

    this->staticList[freePos].data = data ;
    this->staticList[freePos].next = this->staticList[current].next ;
    this->staticList[current].next = freePos ;

    cout << "StaticList_Insert: Insert data " << data << " at position " << pos << endl ;

    return 1 ;
}

int StaticLinkList::StaticList_FindByValue(StaticListDataElement data) {

    int current = this->staticList[0].next ;
    int pos = 1 ;
    while (current != -1) {
        if (this->staticList[current].data == data) {
            cout << "StaticList_FindByValue: Find data " << data << " at position " << pos << endl ;
            return pos ;
        }
        current = this->staticList[current].next ;
        pos++ ;
    }
    cout << "StaticList_FindByValue: Not find data " << data << endl ;
    return -1;
}

int StaticLinkList::StaticList_DeleteByLocation(int pos) {

    int current = 0 ;
    int count = 0 ;

    while (count < pos && this->staticList[current].next!= -1) {
        current = this->staticList[current].next ;
        count++ ;
    }

    if (this->staticList[current].next == -1 || count < pos) {
        cout << "StaticList_DeleteByLocation: position is unvalid " << pos << endl ;
        return 0;
    }


    int toBeDeleted = this->staticList[current].next ;
    cout << "StaticList_DeleteByLocation: Delete data " << this->staticList[toBeDeleted].data << " at position " << pos << endl ;
    this->staticList[current].next = this->staticList[toBeDeleted].next ;
    this->staticList[toBeDeleted].data = -1 ;
    this->staticList[toBeDeleted].next = -2 ;

    return 1;
}

void StaticLinkList::StaticList_Print() {

    int current = this->staticList[0].next ;
    while (current != -1) {
        cout << this->staticList[current].data << " " ;
        current = this->staticList[current].next ;
    }
    cout << endl ;
    cout << "StaticList_Print" << endl ;
}


