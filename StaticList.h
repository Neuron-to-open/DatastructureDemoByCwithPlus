//
// Created by 24887 on 2024/7/22.
//

#ifndef ALL_STATICLIST_H
#define ALL_STATICLIST_H

#define MAX_STATICLIST_SIZE 7

typedef int StaticListDataElement;

typedef struct {
    StaticListDataElement data;
    int next ;
} StaticList[MAX_STATICLIST_SIZE];

class StaticLinkList {
public:
    StaticList  staticList;

    void StaticList_Init() ;

    int StaticList_InsertByLocation(int pos , StaticListDataElement data) ;

    int StaticList_FindByValue(StaticListDataElement data) ;

    int StaticList_DeleteByLocation(int pos) ; //Delete

    void StaticList_Print() ;

};
#endif //ALL_STATICLIST_H
