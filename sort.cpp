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


void BubbleSort(int arr[] , int size ){
    int i , j , count = 0 , round = 0 ,temp  ;
    for(i = 0 ; i < size - 1 ; i ++){
        for (j = 0 ; j < size - i -  1 ; j ++){
            //每一趟挑选最大的.
            if (arr[j] > arr[j+1]){
                temp = arr[j] ;
                arr[j] = arr[j+1] ;
                arr[j+1] = temp ;
            }
            count ++ ;
        }
        round ++ ;
    }

    PrintArr(arr , size) ;
    cout << "\t排序总次数" << round << ",比较总次数:" << count << endl ;
    return ;
}


// 快速排序
int GetMinIndex(int *arr , int left , int right){
    int mid = (left + right) / 2;

    if (arr[left] < arr[right])
    {
        if (arr[mid] < arr[left])
        {
            return left;
        }
        else if (arr[mid] <arr[right])
        {
            return mid;
        }
        else
        {
            return right;
        }
    }
    else
    {
        if (arr[mid] < arr[right])
        {
            return right;
        }
        else if (arr[mid] < arr[left])
        {
            return mid;
        }
        else
        {
            return left;
        }
    }
}


void Swap(int &a , int &b){
    int temp = a ;
    a = b ;
    b = temp ;
}


int PartSort(int *arr , int left , int right){
    int key = GetMinIndex(arr, left , right) ;
    Swap(arr[key] , arr[left]) ;

    key = arr[left] ;

    int hole = left ;

    while (left < right)
    {
        while (left < right && arr[right] >= key)
        {
            right--;
        }
        arr[hole] = arr[right];
        hole = right;

        while (left < right && arr[left] <= key)
        {
            left++;
        }
        arr[hole] = arr[left];
        hole = left;
    }

    arr[hole] = key;
    return hole;
}


void QuickSort(int *arr , int begin , int end ){
    if (begin >= end){
        return ;
    }
    int key = PartSort(arr , begin , end) ;
    QuickSort(arr, begin , key -1) ;
    QuickSort(arr, key + 1 , end) ;
}