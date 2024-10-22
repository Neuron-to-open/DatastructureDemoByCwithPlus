//
// Created by 24887 on 2023/7/13.
//


#include "SequenceList.h"
#include "SingleListWithHeadNode.h"
#include "SingleListWithNoHead.h"
#include "CircleSingleList.h"
#include "DoubleLinkedList.h"
#include "SequenceStack.h"
#include "bracket_matcher.h"
#include "arithmetic_parser.h"
#include "ListBinarytree.h"
#include "AdjacencyMartixGraph.h"
#include "AdjacencyListGraph.h"
#include "Adjacencymultiplicity.h"
#include "OrthogonallistGraph.h"
#include "sort.h"

#include <iostream>
#include <stack>
using namespace std ;


/*
 * 第一章 数据结构的定义
 * 第二章 线性表
 *       顺序表 单链表 循环单链表 双向链表
 * 第三章 栈和队列
 *       栈 队列 括号匹配问题 表达式求值
 * 第四章 串
 *
 * 第五章 树
 *       二叉树的创立与三种遍历
 *       线索二叉树
 *       哈夫曼树
 *
 * 第六章 图
 *
 *
 * */
//顺序表
void OpSeq(){
    SequenceList sequence(10) ; // 创建一个size为10顺序表的实例
    sequence.Seq_Init() ;       //实例中初始化链表各种数据
    sequence.Seq_Print() ;       // 遍历
    cout << "-------------" << endl ;
    sequence.Seq_Insert_Elem(6, 99) ;
    sequence.Seq_Insert_Elem(1, 90) ;
    sequence.Seq_Insert_Elem(4 , 88) ;
    sequence.Seq_Insert_Elem(3 , 520) ;
    sequence.Seq_Print() ;       // 遍历
    cout << "-------------" << endl ;
//
    sequence.reverseSequenceList() ;
    sequence.Seq_Print() ;       // 遍历
    cout << "-" << endl ;

    sequence.Seq_AddLength() ;
    cout << "-------------" << endl ;

    int data ;
    sequence.Seq_Delete_Elem(2 , data) ;
    cout << "Delete the data :" << data << endl ;
    sequence.Seq_Print() ;       // 遍历
    cout << "-------------" << endl ;
    if (sequence.Seq_Destroy()){
        cout << "Delete Success" << endl ;
    }
}


//单链表
void OpSlL(){
    SingleListWithNoHead singleListWithNoHead ;
    singleListWithNoHead.List_Create_T(10) ;
    singleListWithNoHead.List_Print() ;
    singleListWithNoHead.List_DestroyList() ;
//    SingleListWithHeadNode singleList ;
//    singleList.List_Init() ;
//    singleList.List_Create_T(6) ;
//    singleList.List_Print() ;
//    if(singleList.List_Destroy()){
//        cout << "Having Deleting !!!" << endl ;
//    }
//    cout << "-----------" << endl ;
//    SingleListWithHeadNode singleList1 ;
//    singleList1.List_Init() ;
//    singleList1.List_Create_H(6) ;
//    singleList1.List_Print() ;
//    cout << "-----------" << endl ;
//    singleList1.List_InsertByLocation_H(2, 56);
//    singleList1.List_Print() ;
//    singleList1.List_InsertByLocation_H(6, 90) ;
//    singleList1.List_Print() ;
//    singleList1.List_InsertByLocation_H(1, 67) ;
//    singleList1.List_Print() ;
//    cout << singleList1.List_GetLength() << endl ;
//    cout << "-----------" << endl ;
//    if(singleList1.List_Destroy()){
//        cout << "Having Deleting !!!" << endl ;
//    }

}


//双链表
void OpDll(){
    DoubleLinkedList doubleLinkedList ;
    if(doubleLinkedList.DoubleList_Init()){
        cout << "Create a doublelinkedlist successfully" << endl ;
    }

    doubleLinkedList.DoubleList_Create_H(10) ;
    doubleLinkedList.DoubleList_Print() ;

    DoubleLinkedList doubleLinkedList1 ;
    if(doubleLinkedList1.DoubleList_Init()){
        cout <<"Create an another doubleLinkedList successfully" << endl ;
    }
    doubleLinkedList1.DoubleList_Create_T(10) ;
    doubleLinkedList1.DoubleList_Print() ;
}


//括号匹配
void OpBracket(){
    string express ;
    cout << "Please input the express :" ;
    cin >> express ;

    BracketMatcher bracketMatcher ;
    if (bracketMatcher.areBracketsBalanced(express)) {
        cout << "The express is balanced" << endl ;
    } else {
        cout << "The express is not balanced" << endl ;
    }
}

void OpArithmetic(){
    string express ;
    cout << "Please input the express :" ;
    getline(cin, express) ;

    try {
        ArithmeticParser parser(express) ;
        double result = parser.parse() ;
        cout << "The result is :" << result << endl ;
    } catch (const char *error) {
        cout << error << endl ;
    }
}




//void
int main()
{

    cout << "The Function is created to show relevant basic operation in these chapters from Table to sorting !!!" <<endl ;
    int Chapter = -1 ;
    cout << "Please input the number for the Chapter(1:data 2:table 3:stack&queue 4:string 5:tree 6:graph 7:search 8:sorting):" ;
    cin >> Chapter ;

    while (Chapter != -1){
        switch (Chapter) {
            case 1:{
                break;
            }
            case 2: {

                cout << "1~6 分别代表动态顺序链表，单链表，双向链表，循环单链表，循环双链表，静态链表" << endl ;
                int num = -1 ;
                cout << "Please input the number :" ;
                cin >> num ;
                switch (num) {
                    case 1 :{
                        OpSeq() ;
                        break ;
                    }
                    case 2:{
                        OpSlL() ;
                        break;
                    }
                    case 3:{
                        OpDll() ;
                        break ;
                    }
                    case 4:{
                        break;
                    }
                }

                break;

            }
            case 3:{
                cout << "栈与队列" << endl ;
                SequenceStack sequenceStack ;
                sequenceStack.InitSequenceStack() ;
                cout << "Create an another sequenceStack successfully" << endl ;
                sequenceStack.Push(568) ;
                if (sequenceStack.EmptySequenceStack()){
                    cout << "Stack is Empty" << endl ;
                }else {
                    cout << "Stack is not Empty" << endl ;
                }

                SequenceStackDataElement data ;
                sequenceStack.Pop(data) ;
                cout << "Pop the data :" << data << endl ;

//                OpArithmetic() ;
                break ;
            }
            case 4:{
                //串
                break ;
            }
            case 5:{
                //二叉树的遍历
//                cout << "二叉树的遍历" << endl ;
//                BTT() ;
//                cout << "线索二叉树" << endl ;
//                // 中序线索二叉树
//                ClueBT() ;
                //哈夫曼树
//                cout << "Please input the number " << endl ;
//                int nums[10] = {0};
//                for (int i = 0 ; i < 10 ; i ++){
//                    cin >> nums[i] ;
//                }
//
//                Huffman huffman ;
//                huffman.CreateHuffmanTree(huffman.HT , 10 , nums) ;
                ListBinaryTree listBinaryTree ;
                vector<int> nums = {1, 2, 3, -1, 4, 5, 6};
                TreeNode* LBTreeOne = listBinaryTree.CreateBinaryTreeNonRecursive(nums) ;
                listBinaryTree.InOrderThread(LBTreeOne) ;
                listBinaryTree.InOrderTraversal(LBTreeOne) ;
                listBinaryTree.DestroyBinaryTree(LBTreeOne) ;
                cout << endl ;


                break;
            }
            case 6:{

                //邻接矩阵
//                Graph2 graph2 ;
//                graph2.InitAMGraph(graph2.amGraph) ;
//                graph2.CreateAMGrpah(graph2.amGraph) ;
//                graph2.DisplayAMGraph(graph2.amGraph) ;
                //邻接表
//                Graph3 graph3 ;
//                graph3.InitALGraph(graph3.alGraph) ;
//                graph3.CreateALGrapg(graph3.alGraph) ;
//                graph3.DisplayALGraph(graph3.alGraph) ;
                //邻接多重表
//                Graph graph ;
//                graph.InitAMLGraph(graph.G) ;
//                graph.CreateAMLGraph(graph.G) ;
//                graph.DisplayAMLGraph(graph.G) ;
                //十字链表
                Graph4 graph4 ;
                graph4.InitOLGrpah(graph4.olGraph) ;
                graph4.CreateOLGraph(graph4.olGraph) ;
                graph4.DisplayOLGraph(graph4.olGraph) ;
                break ;
            }
            case 7:{

                break;
            }
            case 8:{
//                cout << "Insertion Sort" << endl ;
////                cout << "Please ensure the length of the arr :" ;
////                int num = -1 ;
////                cin >> num ;
////                ElemType arr[num] ;
////                for (int i = 0 ; i < num ; ++ i){
////                    cin >> arr[i] ;
////                }
////                DirectInsertSort(arr , num) ;
                cout << "HalfInsertSort" << endl ;
                int arr[] = {578,432,1325,384,5432,651,3817,564,387,5} ;
                int size = sizeof (arr) / sizeof(arr[0]) ;
                cout << "Before Sorting : " << endl ;
                PrintArr(arr , size) ;
                HalfInsertSort(arr ,size) ;
                cout << endl << "After Sorting :" << endl ;
                PrintArr(arr , size) ;

                cout << "BubbleSort:" << endl ;
                int arr1[] = {5, 243, 42, 123, 55, 56, 32, 23, 78, 324};
                int size1 = sizeof (arr1) / sizeof(arr1[0]) ;
                BubbleSort(arr1 , size1) ;

                cout << "QuickSort:" << endl ;
                int arr2[] = {5, 243, 42, 123, 55, 56, 32, 23, 78, 324};
                int size2 = sizeof (arr2) / sizeof(arr2[0]) ;
                QuickSort(arr2, 0 , size2-1) ;
                PrintArr(arr2 , size2) ;


                cout << "HeapSort:" << endl ;
                int arr3[] = {8, 4, 3, 1, 6, 9, 5, 7, 2, 0};
                int size3 = sizeof (arr3) / sizeof(arr2[3]) ;
                DisplayHeapSort(arr3, size3) ;
                CreateHeap(arr3, size3)  ;
                DisplayHeapSort(arr3 ,size3) ;

                cout <<"MergeSort:" << endl ;
                int a[4] = {0,2,4,6} ;
                int b[6] = {1,3,5,7,8,9};
                int *c = new int[4+6] ;
                MergeSort(a, b, c, 4, 6) ;

                cout << "RadixSort" << endl ;
                int arr4[9] = { 52, 200, 4, 1034, 17, 3319, 8324, 33112, 603 };
                RadixSort(arr4, 9) ;
                break;
            }
            default:{
                break;
            }

        }
        cout << "Please again input the number for the Chapter:" ;
        cin >> Chapter ;
    }

    cout << "The All process has stopped!" << endl ;
    cout << "Thanks for using !" << endl ;
    return 0 ;
}