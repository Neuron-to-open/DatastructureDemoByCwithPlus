//
// Created by 24887 on 2023/7/18.
//
#include <iostream>
#include "sort.h"
using namespace std ;


void DirectInsertSort(int *arr, int n) {
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

        for (int k = 0 ; k < n ; k ++){
            cout << arr[k] << " " ;
        }
        cout << endl ;
    }
}
