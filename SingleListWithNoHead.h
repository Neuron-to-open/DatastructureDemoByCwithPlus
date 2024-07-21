//
// Created by 24887 on 2024/7/21.
//

#ifndef ALL_SINGLELISTWITHNOHEAD_H
#define ALL_SINGLELISTWITHNOHEAD_H

typedef struct NodeOne{
    int data;
    struct NodeOne* next;
}NodeOne;

bool InitList(NodeOne *L) ;
bool List_Create_H(NodeOne *L, int n) ;
bool List_Create_T(NodeOne *L, int n) ;
bool List_Insert(NodeOne *L, int i, int x) ;
bool List_Get_Elem(NodeOne *L, int i, int &x) ;
bool List_Del(NodeOne *L, int i) ;
void List_Print(NodeOne *L) ;
bool DestroyList(NodeOne *L) ;

#endif //ALL_SINGLELISTWITHNOHEAD_H
