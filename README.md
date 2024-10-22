# 项目名称

[![GitHub stars](https://img.shields.io/github/stars/Neuron-to-open/DatastructureAndVisiable?style=flat-square)](https://github.com/Neuron-to-open/DatastructureAndVisiable/stars)
[![GitHub forks](https://img.shields.io/github/forks/Neuron-to-open/DatastructureAndVisiable?style=flat-square)](https://github.com/yourusername/yourprojectname/network/members)
[![GitHub license](https://img.shields.io/github/license/Neuron-to-open/DatastructureAndVisiable?style=flat-square)](https://github.com/yourusername/yourprojectname/blob/master/LICENSE)

项目简介：此项目主要是使用C++实现基本和高级的数据结构

## 目录

- [快速开始](#快速开始)
- [安装](#安装)
- [使用说明](#使用说明)
- [配置项](#配置项)
- [贡献指南](#贡献指南)
- [许可证](#许可证)
- [联系方式](#联系方式)

## 快速开始

使用C++和C实现基本的和高级的数据结构。

using C++ and C to implement basic and advanced data structures.


## 安装

操作系统：win

编译器：gcc

c++ 版本 ：c++11

1. 下载项目
2. 配置好环境
3. 运行main.cpp文件 在shell中输入对应的指令去实现对应操作

## 使用说明

详细介绍如何使用项目，包括API调用示例、界面操作指南等。可以包含截图或GIF动图以提高可读性。

第一部分 : 线性表
    
    1.1 顺序表
        SequenceList.cpp SequenceList.h
        顺序表的基本操作
        a. 初始化赋值表   --  Seq_Init()
        b. 打印输出表值   --  Seq_Print()
        c. 插入元素在表   --  Seq_Insert_Elem()
        d. 删除元素在表   --  Seq_Delete_Elem()
        e. 获取位置元素   --  Seq_Get_Elem()
        f. 获取元素位置   --  Seq_Locate_Elem()
        g. 判断表是否空   --  Seq_IsEmpty()
        h. 获取表的长度   --  Seq_GetLength()
        i. 销毁表的所有   --  Seq_Destroy()
        j. 增大表的容量   --  Seq_AddLength()
        定义的元素类型 SequenceDataElement

    1.2 链表
        A.SingleListWithHeadNode.cpp SingleListWithHeadNode.h
        带头结点单链表的基本操作
        a. 初始化链表   --  List_Init()
        b. 头插法创建链表   --  List_Create_H() 
        c. 尾插法创建链表   --  List_Create_T()
        d. 打印链表   --  List_Print()
        e. 销毁链表   --  List_Destroy()
        f. 获取指定位置元素 -- List_GetElem_H(int i, int &data)      
        g. 查找指定值的元素位置   --  List_LocateElem_H(int key, int &loc)
        h. 在指定位置插入元素   --  List_InsertByLocation_H(int i, int e)      
        i. 删除指定位置的元素   --  List_DeleteByLocation_H(int i, int &data)
        j. 求取链表长度   --  List_GetLength()
        定义的元素类型 SingleListDataElement
        

        B.SingleListWithNoNode.cpp SingleListWithNoNode.h
        不带头结点单链表的基本操作
        a. 初始化链表   --  List_Init()
        b. 头插法创建链表   --  List_Create_H() 
        c. 尾插法创建链表   --  List_Create_T()
        d. 打印链表   --  List_Print()
        e. 销毁链表   --  List_Destroy()
        f. 获取指定位置元素 -- List_GetElem_H(int i, int &data)      
        g. 查找指定值的元素位置   --  List_LocateElem_H(int key, int &loc)
        h. 在指定位置插入元素   --  List_InsertByLocation_H(int i, int e)      
        i. 删除指定位置的元素   --  List_DeleteByLocation_H(int i, int &data)
        j. 求取链表长度   --  List_GetLength()
        定义的元素类型 
        

        C.DoubleLinkList.cpp DoubleLinkList.h
        双链表的基本操作
        a. 初始化双链表   --  DoubleList_Init()
        b. 头插法创建双链表   --  DoubleList_Create_H() 
        c. 尾插法创建双链表   --  DoubleList_Create_T()
        d. 打印双链表   --  DoubleList_Print()
        e. 销毁双链表   --  DoubleList_Destroy()

        D.CircleSingleList.cpp CircleSingleList.h
        循环单链表的基本操作
        a. 初始化循环单链表   --  CircleSingleList_Init()
        b. 头插法创建循环单链表   --  CircleSingleList_Create_H() 
        c. 尾插法创建循环单链表   --  CircleSingleList_Create_T()
        d. 打印循环单链表   --  CircleSingleList_Print()
        e. 销毁循环单链表   --  CircleSingleList_Destroy()

        E.CircleDoubleLinkList.cpp CircleDoubleLinkList.h

        F.Static.cpp Static.h
        静态链表
        a. 初始化静态链表   --  StaticList_Init()
        b. 在指定位置插入元素   --  StaticList_InsertByLocation()
        c. 按值查找元素位置   --  StaticList_FindByValue()
        d. 删除指定位置的元素   --  StaticList_DeleteByLocation()
        e. 打印静态链表   --  Static_Print()


第二部分 : 栈、队列与数组

    2.1 栈
        栈的基本操作
        a. 初始化栈   --  InitStack()
        b. 压栈   --  Push()
        c. 弹栈   --  Pop()        
        d. 栈是否为空   --  IsEmpty()

    2.2 队列
        队列的基本操作
        a. 初始化队列   --  InitQueue()
        b. 入队   --  EnQueue()
        c. 出队   --  DeQueue()
        d. 队列是否为空   --  IsEmpty()
        e. 队列是否已满   --  IsFull()

## 配置项
第一部分 : 线性表

第二部分 : 栈、队列与数组

第三部分 : 串

第四部分 : 树

第五部分 : 图

第六部分 : 排序

第七部分 : 查找

后续持续增加
第一阶段:使用C++的简易的oop实现对应操作

第二阶段:重新学习C++高级知识，对第一部分代码进行重构

## 贡献指南

欢迎贡献！请阅读我们的[贡献指南](CONTRIBUTING.md)，了解如何向项目提交bug报告、提出新特性建议或进行代码贡献。

## 许可证

本项目遵循[MIT许可证](LICENSE)发布。

## 联系方式

- 问题反馈：[提Issue](https://github.com/Neuron-to-open/DatastructureAndVisiable/issues)
- 电子邮件：youremail@example.com
- 社区/论坛：如有，请提供链接

---

请根据实际情况替换方括号中的内容，如`xxx@xxx.com`, `Your Project All Rights Reserved`, `https://github.com/xxx`, 以及联系方式等信息。