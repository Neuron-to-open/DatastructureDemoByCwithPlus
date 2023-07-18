cmake_minimum_required(VERSION 3.25)
project(All)

set(CMAKE_CXX_STANDARD 17)

add_executable(All Sequence.cpp Sequence.h main.cpp SingleList.cpp SingleList.h BST.cpp BST.h AvlTree.cpp AvlTree.h Sotring.cpp Sotring.h)
