//
// Created by 24887 on 2023/7/13.
//


#include "SequenceList.h"
#include "SingleListWithHeadNode.h"
#include "CircleSingleList.h"
#include "DoubleLinkedList.h"
#include "SequenceStack.h"
#include "StackAndQueue.h"
#include "Binarytreetraversal.h"
#include "Cluebinarytree.h"
#include "Huffman.h"
#include "AdjacencyMartixGraph.h"
#include "AdjacencyListGraph.h"
#include "Adjacencymultiplicity.h"
#include "OrthogonallistGraph.h"
#include "sort.h"

#include <iostream>
#include <stack>
using namespace std ;


/*
 * ��һ�� ���ݽṹ�Ķ���
 * �ڶ��� ���Ա�
 *       ˳��� ������ ѭ�������� ˫������
 * ������ ջ�Ͷ���
 *       ջ ���� ����ƥ������ ���ʽ��ֵ
 * ������ ��
 *
 * ������ ��
 *       �������Ĵ��������ֱ���
 *       ����������
 *       ��������
 *
 * ������ ͼ
 *
 *
 * */
//˳���
void OpSeq(){
    SequenceList sequence(10) ; // ����һ��sizeΪ10˳����ʵ��
    sequence.Seq_Init() ;       //ʵ���г�ʼ�������������
    sequence.Seq_Print() ;       // ����
    cout << "-------------" << endl ;
    sequence.Seq_Insert_Elem(6, 99) ;
    sequence.Seq_Insert_Elem(1, 90) ;
    sequence.Seq_Insert_Elem(4 , 88) ;
    sequence.Seq_Insert_Elem(3 , 520) ;
    sequence.Seq_Print() ;       // ����
    cout << "-------------" << endl ;
//
    sequence.reverseSequenceList() ;
    sequence.Seq_Print() ;       // ����
    cout << "-" << endl ;

    sequence.Seq_AddLength() ;
    cout << "-------------" << endl ;

    int data ;
    sequence.Seq_Delete_Elem(2 , data) ;
    cout << "Delete the data :" << data << endl ;
    sequence.Seq_Print() ;       // ����
    cout << "-------------" << endl ;
    if (sequence.Seq_Destroy()){
        cout << "Delete Success" << endl ;
    }
}


//������
void OpSlL(){
    SingleListWithHeadNode singleList ;
    singleList.List_Init() ;
    singleList.List_Create_T(6) ;
    singleList.List_Print() ;
    if(singleList.List_Destroy()){
        cout << "Having Deleting !!!" << endl ;
    }
    cout << "-----------" << endl ;
    SingleListWithHeadNode singleList1 ;
    singleList1.List_Init() ;
    singleList1.List_Create_H(6) ;
    singleList1.List_Print() ;
    cout << "-----------" << endl ;
    singleList1.List_InsertByLocation_H(2, 56);
    singleList1.List_Print() ;
    singleList1.List_InsertByLocation_H(6, 90) ;
    singleList1.List_Print() ;
    singleList1.List_InsertByLocation_H(1, 67) ;
    singleList1.List_Print() ;
    cout << singleList1.List_GetLength() << endl ;
    cout << "-----------" << endl ;
    if(singleList1.List_Destroy()){
        cout << "Having Deleting !!!" << endl ;
    }
}


//˫����
void OpDll(){
    DoubleLinkedList doubleLinkedList ;
    if(doubleLinkedList.InitTDoubleList()){
        cout << "Create a doublelinkedlist successfully" << endl ;
    }

    doubleLinkedList.CreateList_H(10) ;
    doubleLinkedList.DisplayLink() ;

    DoubleLinkedList doubleLinkedList1 ;
    if(doubleLinkedList1.InitTDoubleList()){
        cout <<"Create an another doubleLinkedList successfully" << endl ;
    }
    doubleLinkedList1.CreateList_T(10) ;
    doubleLinkedList1.DisplayLink() ;
}


//����ƥ������
bool Check(char str[] , int len){
    StackAndQueue stackAndQueue ;
    stackAndQueue.InitStack(stackAndQueue.stack) ;
    for (int i = 0 ; i < len ; i ++){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
            stackAndQueue.PushStack(stackAndQueue.stack , str[i]) ;
        }else {
            if(stackAndQueue.EmptyStack(stackAndQueue.stack)){
                return false ;
            }
            char top ;
            stackAndQueue.PopStack(stackAndQueue.stack , top) ;
            if((str[i] == ')' && top != '(') ||
                (str[i] == ']' && top != '[') ||
               ( str[i] == '}' && top != '{')){
                return false ;
            }
        }
    }

    return stackAndQueue.EmptyStack(stackAndQueue.stack) ;

}


//��׺���ʽת��Ϊ��׺���ʽ
int getpriority(char c){
    if ( c == '+' || c == '-'){
        return -1 ;
    }else {
        return 1 ;
    }
}


//s1������ջ s2�Ƿ���ջ
void convert(string& express, stack<char>& s1, stack<char>& s2)
{
    int i = 0;
    while (express[i] != '\0')//ɨ����׺���ʽ
    {
        if ('0' <= express[i] && express[i] >= '9')//���ɨ�赽�˲�������ֱ����s1
        {
            s1.push(express[i++]);
        }
        else if (express[i] == '(')//���ɨ�赽�������ţ�ֱ����s2
        {
            s2.push(express[i++]);
        }
        else if (express[i] == '+' || express[i] == '-' || express[i] == '*' || express[i] == '/')//ɨ�赽������������ȼ��ж�
        {
            if (s2.empty() || s2.top() == '(' || getpriority(express[i]) > getpriority(s2.top()))//�����ʱS2Ϊ�ջ���ջ��Ԫ��Ϊ�����ţ�����ɨ�赽����������ȼ�����ջ����������ȼ�������S2
            {
                s2.push(express[i++]);
            }
            else//��֮���ȼ������С�ڵ��ڵĻ�����ô��Ҫ���������ջȻ����s1
            {
                char temp = s2.top();
                s2.pop();
                s1.push(temp);
            }
        }
        else if (express[i] == ')')//���һ���������ɨ�赽�������ţ���ô�Ͱ�S2��ջ���������ŵ�Ԫ�����γ�ջ��ջ
        {
            while (s2.top() != '(')
            {
                char temp = s2.top();
                s2.pop();
                s1.push(temp);
            }
            //ע�����ֹͣѭ����ʱ��S2��ջ��Ԫ���������ţ����ǲ�Ҫ����������ջ������ֱ�Ӷ���������
            s2.pop();
            i++;//��Ҫ���Ǻ���
        }
    }
    while (!(s2.empty()))//���s2û�пգ���ô���γ�s2����s1
    {
        char temp = s2.top();
        s2.pop();
        s1.push(temp);
    }
}


//�������ı���:Per
void BTT() {
    bst bstTree ;
    int n ;
    ElemTypeBTT s[100] = {0};
    cout << "Enter the PerOrder String ( '#' is on behalf of null ) :  ";
    cin >> s ;
    bstTree.root = bstTree.PerCreateTree(s) ;
    bstTree.PerOrder(bstTree.root) ;
    cout << endl ;
    bstTree.InOrder(bstTree.root) ;
    cout << endl ;
    bstTree.ReOrder(bstTree.root) ;
    cout << endl ;
    bstTree.PerFree(bstTree.root) ;
}


//����������
void ClueBT(){
    cluebinarytree cbt1 ; //����һ����������ʵ��1
    cout << "Please input the PreOrder string " << endl ;
    cbt1.root = cbt1.create_ThreadTree() ;
    cbt1.PerOrder(cbt1.root) ;
    cout << endl ;


    cbt1.InThread(cbt1.root) ;
    cbt1.InOrder(cbt1.root) ;
    cbt1.RevInorder(cbt1.root) ;

    cbt1.PerFree(cbt1.root) ;
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

                cout << "1~6 �ֱ����̬˳������������˫������ѭ��������ѭ��˫������̬����" << endl ;
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
                cout << "ջ�����" << endl ;
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


                break ;
            }
            case 4:{
                //��
                break ;
            }
            case 5:{
                //�������ı���
//                cout << "�������ı���" << endl ;
//                BTT() ;
//                cout << "����������" << endl ;
//                // ��������������
//                ClueBT() ;
                //��������
                cout << "Please input the number " << endl ;
                int nums[10] = {0};
                for (int i = 0 ; i < 10 ; i ++){
                    cin >> nums[i] ;
                }

                Huffman huffman ;
                huffman.CreateHuffmanTree(huffman.HT , 10 , nums) ;

                break;
            }
            case 6:{

                //�ڽӾ���
//                Graph2 graph2 ;
//                graph2.InitAMGraph(graph2.amGraph) ;
//                graph2.CreateAMGrpah(graph2.amGraph) ;
//                graph2.DisplayAMGraph(graph2.amGraph) ;
                //�ڽӱ�
//                Graph3 graph3 ;
//                graph3.InitALGraph(graph3.alGraph) ;
//                graph3.CreateALGrapg(graph3.alGraph) ;
//                graph3.DisplayALGraph(graph3.alGraph) ;
                //�ڽӶ��ر�
//                Graph graph ;
//                graph.InitAMLGraph(graph.G) ;
//                graph.CreateAMLGraph(graph.G) ;
//                graph.DisplayAMLGraph(graph.G) ;
                //ʮ������
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