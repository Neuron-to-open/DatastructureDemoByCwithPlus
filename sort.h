//
// Created by 24887 on 2023/7/18.
//

#ifndef ALL_SORT_H
#define ALL_SORT_H

/**
 *  Insertion Sort
 *      Direct Insertion Sort ¡Ì
 *      Half Insertion Sort ¡Ì
 *      shell Sort
 *  Swap Sort
 *      bubble Sort ¡Ì
 *      Quick Sort ¡Ì
 *  Select Sort
 *      Easy selection Sort ¡Ì
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

void SimpleSelectSort(int *arr , int size) ;

void Heapify(int *arr , int k , int len) ;

void CreateHeap(int *arr , int len) ;

void HeapSort(int *arr , int len) ;

void DisplayHeapSort(int *arr , int len) ;

void MergeSort(int *a , int *b , int *c , int la ,int lb) ;

int GetDigit(int M , int i ) ;

void RadixSort(int *arr , int len) ;

#endif //ALL_SORT_H
