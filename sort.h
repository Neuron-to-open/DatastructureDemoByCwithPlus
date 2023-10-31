//
// Created by 24887 on 2023/7/18.
//

#ifndef ALL_SORT_H
#define ALL_SORT_H

/**
 *  Insertion Sort
 *      Direct Insertion Sort
 *      Half Insertion Sort
 *      shell Sort
 *  Swap Sort
 *      bubble Sort
 *      Quick Sort
 *  Select Sort
 *      Easy selection Sort
 *      Heap Sort
 *  Merge Sort
 *  Radix Sort
 * */


void PrintArr(int arr[] , int size ) ; //´òÓ¡Êý×é

void DirectInsertSort(int arr[] , int n );   // Direct Insertion Sort

void ShellSort(int arr[] , int size) ;

void HalfInsertSort(int arr[] , int size ) ;

void BubbleSort(int arr[] , int size ) ;

int GetMinIndex(int *arr , int left , int right) ;

void Swap(int &a , int &b) ;

int PartSort(int *arr , int left , int right) ;

void QuickSort(int *arr , int begin , int end ) ;

void DirectSelectSort(int *arr , int size) ;
#endif //ALL_SORT_H
