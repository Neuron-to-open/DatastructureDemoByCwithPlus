//
// Created by 24887 on 2023/10/19.
//

#include <cstdio>
#include <iostream>
#include <cstring>
#include "Huffman.h"

using namespace std;
void Huffman::Select(HuffmanTree &HT, int n, int &s1, int &s2) {
    //寻找第一个双亲域为0，且权值最小的结点
    int min ;

    for (int i = 1 ; i <= n ; i ++){
        if (HT[i].parent == 0){
            min = i ;
            break ;
        }
    }

    for (int i = 1 ; i <= n ; i ++){
        if (HT[i].parent == 0){
            if (HT[i].weight < HT[min].weight){
                min = i ;
            }
        }
    }

    s1 = min ;

    for (int i = 1; i <= n ; i ++){
        if (HT[i].parent == 0 && i != s1){
            min = i ;
            break;
        }
    }

    for (int i = 1; i <= n ; i ++){
        if (HT[i].parent == 0 && i != s1){
            if (HT[i].weight < HT[min].weight){
                min = i ;
            }
        }
    }

    s2 = min ;
}

void Huffman::printTree(HuffmanTree &HT, int n) {
    printf("==============================\n");
    for (int i = 1; i <= n; i++)
    {

        printf("%d th   ", i);
        printf("%d   ", HT[i].weight);
        printf("%d   ", HT[i].parent);
        printf("%d  ", HT[i].lchild);
        printf("%d   \n", HT[i].rchild);
        printf("---------------------------\n");
    }
}

void Huffman::CreateHuffmanTree(HuffmanTree &HT, int n, int *ht) {
    //初始
    int i ;
    int m = 2 * n -1 ;
    int s1 , s2 ;
    HT = new HTNode [m+1] ;

    for (int i = 1 ; i <= m ; i ++ ){
        HT[i].parent = 0 ;
        HT[i].lchild = 0 ;
        HT[i].rchild = 0 ;
        if ( i <= n) {
            HT[i].weight = ht[i - 1];
        }
    }

    cout << "\nHT start status" << endl ;

    printTree(HT, m) ;

    for (int i = n + 1 ; i <= m ; i ++){
        Select(HT , i - 1  ,s1 ,s2) ;

        HT[s1].parent = i ;
        HT[s2].parent = i ;
        HT[i].lchild = s1 ;
        HT[i].rchild = s2 ;
        HT[i].weight = HT[s1].weight + HT[s2].weight ;
    }

    cout << "\nHT end status" << endl ;
    printTree(HT , m ) ;

}

void Huffman::CreateHuffmanCode(HuffmanTree HT, HuffmanCode &HC, int n) {
    int i , c , f ;
    HC = new char* [n+1] ;
    cd = new char [n] ;
    cd[n-1] = '\0' ;
    for (i = 1 ; i <= n ; i ++){
        start = n -1 ;
        c = i ;
        f = HT[i].parent ;

        while (f != 0 ){
            if (HT[f].lchild == c){
                cd[--start] = '0' ;
            }else {
                cd[--start] = '1' ;
            }
            c = f ;
            f = HT[f].parent ;
        }

        HC[i] = new char [n - start] ;

        strcpy(HC[i] , &cd[start]) ;
        printf("%d th ----->" , i) ;
        for (int j = start; j <= n - 1; ++j)
        {
            printf("%c ", cd[j]);
        }
        printf("\n");
    }
    delete cd ;
}
