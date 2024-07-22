//
// Created by 24887 on 2024/7/21.
//

#ifndef ALL_SINGLELISTWITHNOHEAD_H
#define ALL_SINGLELISTWITHNOHEAD_H

typedef struct SingleListWithoutHeadDataElement{
    int data;
    struct SingleListWithoutHeadDataElement* next;
}SingleListWithoutHeadDataElement;

class SingleListWithNoHead {
public:
    SingleListWithoutHeadDataElement *head = nullptr;
    bool List_Create_H(int n) ;
    bool List_Create_T(int n) ;
    bool List_Insert( int i, int x) ;
    bool List_Get_Elem(int i, int &x) ;
    bool List_Del(int i) ;
    void List_Print() ;
    bool List_DestroyList() ;
} ;



#endif //ALL_SINGLELISTWITHNOHEAD_H
