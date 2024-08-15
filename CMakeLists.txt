cmake_minimum_required(VERSION 3.25)
project(All)

set(CMAKE_CXX_STANDARD 17)

add_executable(All
        SequenceList.cpp SequenceList.h
        main.cpp
        SingleListWithHeadNode.cpp SingleListWithHeadNode.h
        Binarytreetraversal.cpp Binarytreetraversal.h
        AvlTree.cpp AvlTree.h
        sort.cpp sort.h
        SequenceStack.cpp SequenceStack.h
        DoubleLinkedList.cpp DoubleLinkedList.h
        CircleSingleList.cpp CircleSingleList.h
        Cluebinarytree.cpp Cluebinarytree.h
        Huffman.cpp Huffman.h
        Adjacencymultiplicity.cpp Adjacencymultiplicity.h
        AdjacencyMartixGraph.cpp AdjacencyMartixGraph.h
        AdjacencyListGraph.cpp AdjacencyListGraph.h
        OrthogonallistGraph.cpp OrthogonallistGraph.h
        ListStack.cpp ListStack.h
        SequenceQueue.cpp
        SequenceQueue.h
        ListQueue.cpp
        ListQueue.h
        SingleListWithNoHead.cpp
        SingleListWithNoHead.h
        StaticList.cpp
        StaticList.h
        bracket_matcher.cpp
        bracket_matcher.h
        arithmetic_parser.cpp
        arithmetic_parser.h
        ListBinaryTree.cpp
        ListBinaryTree.h
        ListBinaryTree.h
)
