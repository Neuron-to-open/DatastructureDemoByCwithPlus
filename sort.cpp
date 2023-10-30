//
// Created by 24887 on 2023/7/18.
//
#include <iostream>
#include "sort.h"
using namespace std ;




void PrintArr(int arr[] , int size ){
    for (int i = 0 ; i < size ; i ++){
        cout << arr[i] << " " ;
    }
    cout << endl ;
}

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

        cout << "the order" << i << "\t" ;
        for (int k = 0 ; k < n ; k ++){
            cout << arr[k] << " " ;
        }
        cout << endl ;
    }
}


void HalfInsertSort(int arr[] , int size ){
    for (int i = 1 ; i < size ; i ++){
        cout << "the order " << i << ": " << endl ;
        cout << "\t" <<"有序序列:"  ;
        for (int k = 0 ; k < i ; k ++){
            cout << arr[k] << " " ;
        }
        cout << endl ;
        cout << "\t" << "需要插入的数据:" << arr[i] << endl ;

        int key = arr[i] ; //标记待插入元素
        int left = 0 ;
        int right = i -1 ;

        if (arr[i] < arr[i-1]){

            while (left <= right){
                int mid = (left + right)/2 ;
                if (arr[mid] > key){
                    right = mid -1 ;
                }else {
                    left = mid + 1 ;
                }
            }

            for (int j = i -1 ; j > right ; j --){
                arr[j+1] = arr[j] ;
            }
            arr[right+1] = key ;

        }
        cout << "\t" << "插入的位置: " << right+1 << endl ;


        cout << "\t" <<  "新的有序序列 :" ;
        for (int k = 0 ; k <= i ; k ++){
            cout << arr[k] << " " ;
        }
        cout << endl ;

    }
}

