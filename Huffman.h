//
// Created by 24887 on 2023/10/19.
//

#ifndef ALL_HUFFMAN_H
#define ALL_HUFFMAN_H
typedef struct {
    int weight ;
    int parent , lchild , rchild ;
}HTNode , *HuffmanTree;

typedef char ** HuffmanCode ;
class Huffman{
public:
    int start ;
    char *cd ;

    HuffmanTree HT ;
    HuffmanCode HC ;

    void Select( HuffmanTree &HT , int n , int& s1 , int &s2) ;

    void printTree(HuffmanTree &HT , int n ) ;

    void CreateHuffmanTree(HuffmanTree &HT , int n , int *ht) ;

    void CreateHuffmanCode(HuffmanTree HT , HuffmanCode &HC , int n) ;
};
#endif //ALL_HUFFMAN_H
