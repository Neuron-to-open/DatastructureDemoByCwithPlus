//
// Created by 24887 on 2023/7/13.
//

#include "SequenceList.h"
#include <cstdlib>
#include <iostream>

using namespace std ;

#define MAXSIZE 100 // 定义最大序列长度


/**
 * @brief 构造函数，用于创建一个空的顺序列表。
 *
 * 该构造函数不接受任何参数，创建一个初始大小为0的顺序列表。
 */
SequenceList::SequenceList() {
}

/**
 * @brief 构造函数，用于创建一个指定大小的顺序列表。
 *
 * @param size 初始分配给顺序列表的元素数量。
 *
 * 该构造函数接受一个整数参数来指定顺序列表的初始大小。
 * 它将根据指定的大小为顺序列表分配足够的空间。
 */
// 初始化序列
SequenceList::SequenceList(int size) {
    this->seq.size = size;
}



/**
 * 初始化顺序表
 *
 * 本函数用于初始化一个顺序表，包括分配内存和为表中的每个元素赋初值。
 * 具体来说，它为顺序表分配足够空间以存储6个元素，并且这些元素被随机初始化为1到100之间的整数。
 * 这样的初始化操作对于后续的算法测试或数据操作是一个典型的预处理步骤。
 *
 * 参数：无
 * 返回值：无
 */
void SequenceList::InitTable() {
    /* 初始化顺序表的长度为6 */
    this->seq.length = 6;

    /* 分配内存以存储顺序表的元素。使用malloc函数动态分配内存 */
    /* 注意：这里假设seq.size已经在此之前被正确设置为6 */
    this->seq.head = (SequenceListDataElement *) malloc(sizeof(SequenceListDataElement) * this->seq.size);

    /* 为顺序表中的每个元素赋一个随机整数，范围是1到100 */
    /* 这样做可以确保表初始化后具有非空且各元素不同的初始值，方便后续操作 */
    for (int i = 0; i < this->seq.length; ++i) {
        this->seq.head[i] = rand() % 100 + 1;
    }
}


// 显示表的内容
/**
 * 在标准输出设备上显示顺序列表的内容。
 * 该函数遍历顺序列表的每个元素，并将它们逐个打印到标准输出设备上。
 * 顺序列表的结构是一个具有固定大小数组的头部指针，数组中存储了列表的实际元素。
 *
 * @note 该函数假设顺序列表已经被正确初始化，并且数组中存储的数据是合法的。
 */
void SequenceList::ShowTable() {
    // 遍历顺序列表中的每个元素
    for (int i = 0; i < this->seq.length; ++i) {
        // 打印每个元素到标准输出设备
        cout << this->seq.head[i] << " ";
    }
    // 输出换行符，以结束当前行的打印
    cout << endl;
}


/**
 * 销毁顺序表
 *
 * 本函数用于销毁一个已经创建的顺序表，释放其占用的内存空间。在执行销毁操作前，
 * 会先检查顺序表是否为空，只有当表不为空时才进行销毁操作。
 *
 * @return 如果表成功被销毁，则返回true；如果表为空，无需销毁，此时返回false。
 */
// 销毁表，释放内存
bool SequenceList::DestroyTable() {
    // 如果顺序表长度不为0，即表不为空，则进行销毁操作
    if (getLength() != 0) {
        // 释放顺序表头部的内存空间，即释放整个表的空间
        free(this->seq.head);
        // 表成功销毁，返回true
        return true;
    }
    // 表为空，无需销毁，返回false
    return false;
}


// 扩充序列的容量
// 当序列的当前容量不足时，将容量翻倍，以容纳更多的元素。
// 如果内存分配失败，将不进行任何操作并保持原容量不变。
// 扩充序列的容量
void SequenceList::addLength() {
    size_t oldSize = this->seq.size;
    this->seq.size *= 2;
    cout << "New size: " << this->seq.size << endl;

    SequenceListDataElement *newHead = (SequenceListDataElement *) realloc(this->seq.head, this->seq.size * sizeof(SequenceListDataElement));
    if (newHead == nullptr) {
        cout << "The Increase failed. Old size: " << oldSize << endl;
        // 恢复原来的大小，因为增加失败
        this->seq.size = oldSize;
    } else {
        cout << "The Increase succeeded. New size: " << this->seq.size << endl;
        this->seq.head = newHead;
    }
}


// 获取序列的当前长度
// 返回值：序列中元素的数量。
// 获取序列的当前长度
int SequenceList::getLength() {
    return this->seq.length;
}


// 判断序列是否为空
// 返回值：如果序列为空，则返回true；否则返回false。
// 判断序列是否为空
bool SequenceList::isEmpty() {
    if (getLength() == 0) {
        return true;
    }
    return false;
}



/**
 * 在顺序表中定位元素的位置，返回位置索引，若不存在返回-1
 * @param e 待查找的元素
 * @return 元素的位置索引，若不存在则返回-1
 */
// 在序列中定位元素的位置，返回位置索引，若不存在返回-1
int SequenceList::LocateElem(int e) {
    for (int i = 0; i < this->seq.length; i++) {
        if (this->seq.head[i] == e) {
            return i + 1;
        }
    }
    return -1;
}


/**
 * 获取顺序表中指定位置的元素，通过引用返回
 * @param i 元素的位置索引
 * @param Elem 用于存放获取到的元素的引用
 * @return 是否成功获取到元素
 */
// 获取序列中指定位置的元素，通过引用返回
bool SequenceList::getElem(int i, int &Elem) {
    if (this->seq.length == 0 || this->seq.length < i || i <= 0) {
        return false;
    }
    Elem = this->seq.head[i - 1];
    return true;
}


/**
 * 在顺序表中指定位置插入一个元素
 * @param i 插入位置的索引
 * @param elem 待插入的元素
 * @return 是否成功插入元素
 */
// 在序列中插入一个元素
bool SequenceList::InsertTable(int i, int elem) {
    if (this->seq.size > i && i >= 1) {
        int j = this->seq.length - 1;
        for (; j >= i - 1; --j) {
            this->seq.head[j + 1] = this->seq.head[j];
        }
        this->seq.head[j + 1] = elem;
        this->seq.length++;
        return true;
    }
    return false;
}

/**
 * 从顺序表中删除指定位置的元素，并通过引用返回被删除的元素
 * @param i 被删除元素的位置索引
 * @param data 用于存放被删除元素的引用
 * @return 是否成功删除元素
 */
// 从序列中删除一个元素，并通过引用返回被删除的元素
bool SequenceList::DeleteTable(int i, int &data) {
    if (this->seq.length >= i && i >= 1) {
        data = this->seq.head[i - 1];
        int j = i - 1;
        for (; j <= this->seq.length - 1; ++j) {
            this->seq.head[j] = this->seq.head[j + 1];
        }
        this->seq.length--;
        return true;
    }
    return false;
}

/**
 * 反转顺序表
 * @return 是否成功反转顺序表
 */
bool SequenceList::reverseSequenceList() {
    if (this->seq.length == 0) {
        return false;
    }
    int i = 0;
    int j = this->seq.length - 1;
    while (i < j) {
        int temp = this->seq.head[i];
        this->seq.head[i] = this->seq.head[j];
        this->seq.head[j] = temp;
        i++;
        j--;
    }
    return true;
}





