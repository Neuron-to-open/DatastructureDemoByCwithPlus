//
// Created by 24887 on 2023/7/18.
//
#include <iostream>
#include <cstring>
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


void SimpleSelectSort(int *arr , int size) {
    int i, j, min, temp;
    for (i = 0; i < size; i++)
    {
        // 初始最小值下标
        min = i;
        // 查找后面最小值的下标
        for (j = i + 1; j < size; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        // 交换最小值
        if (min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}


//最大堆调整
void Heapify(int *arr , int k , int len){
    if( k < len ){
        int root = k ;
        int lchild = 2*k + 1 ;
        int rchild = 2*k + 2 ;

        //查找最有孩子结点中的最大结点
        if ( lchild < len && arr[root] < arr[lchild]){
            root = lchild ;
        }
        if (rchild < len && arr[root] < arr[rchild] ){
            root = rchild ;
        }

        if (root != k ){
            Swap(arr[root] , arr[k]) ;
            Heapify(arr , root , len) ;
        }
    }
}


// 创建最大堆
void CreateHeap(int *arr , int len) {
    int i ;
    //最后一个结点下标
    int last = len -1 ;
    //最后一个结点的父结点下标
    int parent = (last-1) / 2 ;
    //从最后一个结点的父结点到根节点
    for (i = parent; i >= 0 ; i --){
        cout << "对结点" << arr[i] << "做最大堆调整" << endl ;
        Heapify(arr, i , len) ;
    }
}


// 堆排序
void HeapSort(int *arr , int len) {
    //创还能最大堆并进行调整
    CreateHeap(arr , len) ;
    cout << "最大堆调整!\n" << endl ;
    int i ;
    //依次取出根节点
    for (i = len-1 ; i >= 0 ; i --){
        Swap(arr[i] , arr[0]) ;
        Heapify(arr, 0, i) ;
    }
}

void DisplayHeapSort(int *arr , int len){
    cout << "**********************" << endl ;
    cout << "       " << arr[0] << endl ;
    cout << "   " <<arr[1] << "       " << arr[2] << endl ;
    cout << " " << arr[3] << " " <<arr[4] << "   " << arr[5] << "   " <<arr[6] << endl ;
    cout << arr[7] << " " <<arr[8] << " " << arr[9] <<endl ;
    cout << "**********************" << endl ;
}

void MergeSort(int *a , int *b , int *c , int la ,int lb){

    int i = 0 , j = 0 , k = 0 ;
    while (i < la && j < lb){
        if( a[i] < b[j]){
            c[k++] = a[i++] ;
        }else {
            c[k++] = b[j++] ;
        }
    }

    while (i < la){
        c[k++] = a[i++] ;
    }
    while ( j < lb){
        c[k++] = b[j++] ;
    }

    PrintArr(c , k ) ;
}


int GetDigit(int M , int i ){
    while (i > 1) {
        M /= 10 ;
        i -- ;
    }
    return M % 10 ;
}

void RadixSort(int *arr , int len) {
    int i , j , k , l , digit ;
    int allot[10][10] ;;

    memset(allot , 0 , sizeof(allot)) ;

    for (i = 1 ; i <= 5 ; i ++) {
        for(j = 0 ; j < len ; j ++){
            //获取当前数据num[j]的第i位数
            digit = GetDigit(arr[j] , i) ;
            k = 0 ;
            //查找插入位置
            while (allot[digit][k]){
                k ++ ;
            }
            allot[digit][k] = arr[j] ;
        }

        l = 0 ;

        for (j = 0 ; j < 10 ; j ++){
            k = 0 ;
            while (allot[j][k]){
                arr[l++] = allot[j][k++] ;
            }
        }

        cout << "对第" << i << "位数进行分配" << endl ;
        cout << "分配数组:" << endl ;
        for(int p = 0 ; p <10 ; p ++){
            cout << "第" << i << "位=" << p ;
            for (int q =0 ; q < 10 ; q ++){
                cout << "\t" << allot[p][q] ;
            }
            cout << endl ;
        }
        memset(allot , 0 , sizeof(allot)) ;
    }
}
