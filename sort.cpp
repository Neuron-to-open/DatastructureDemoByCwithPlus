//
// Created by 24887 on 2023/7/18.
//

#include "sort.h"


void DirectInsertSort(ElemType *arr, int n) {
    int i ;
    int key ;
    int j ;
    for (int i = 1 ; i < n ; i ++){
        key = arr[i] ;
        j = i -1 ;
        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j] ;
            j -- ;
        }
        arr[j+1] = key ;
    }
}
