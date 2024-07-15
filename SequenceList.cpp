//
// Created by 24887 on 2023/7/13.
//

#include "SequenceList.h"
#include <cstdlib>
#include <iostream>

using namespace std ;

#define MAXSIZE 100 // ����������г���


/**
 * @brief ���캯�������ڴ���һ���յ�˳���б�
 *
 * �ù��캯���������κβ���������һ����ʼ��СΪ0��˳���б�
 */
SequenceList::SequenceList() {
}


/**
 * @brief ���캯�������ڴ���һ��ָ����С��˳���б�
 *
 * @param size ��ʼ�����˳���б��Ԫ��������
 *
 * �ù��캯������һ������������ָ��˳���б�ĳ�ʼ��С��
 * ��������ָ���Ĵ�СΪ˳���б�����㹻�Ŀռ䡣
 */
// ��ʼ������
SequenceList::SequenceList(int size) {
    this->seq.size = size;
    cout << "Initialize the sequence list with size: " << this->seq.size << endl;
}



/**
 * ��ʼ��˳���
 *
 * ���������ڳ�ʼ��һ��˳������������ڴ��Ϊ���е�ÿ��Ԫ�ظ���ֵ��
 * ������˵����Ϊ˳�������㹻�ռ��Դ洢6��Ԫ�أ�������ЩԪ�ر������ʼ��Ϊ1��100֮���������
 * �����ĳ�ʼ���������ں������㷨���Ի����ݲ�����һ�����͵�Ԥ�����衣
 *
 * ��������
 * ����ֵ����
 */
void SequenceList::InitTable() {
    /* ��ʼ��˳���ĳ���Ϊ6 */
    this->seq.length = 6;

    /* �����ڴ��Դ洢˳����Ԫ�ء�ʹ��malloc������̬�����ڴ� */
    /* ע�⣺�������seq.size�Ѿ��ڴ�֮ǰ����ȷ����Ϊ6 */
    this->seq.head = (SequenceListDataElement *) malloc(sizeof(SequenceListDataElement) * this->seq.size);

    /* Ϊ˳����е�ÿ��Ԫ�ظ�һ�������������Χ��1��100 */
    /* ����������ȷ�����ʼ������зǿ��Ҹ�Ԫ�ز�ͬ�ĳ�ʼֵ������������� */
    for (int i = 0; i < this->seq.length; ++i) {
        this->seq.head[i] = rand() % 100 + 1;
    }
    cout << "Initialize the sequence list with random values " << endl;
}


// ��ʾ�������
/**
 * �ڱ�׼����豸����ʾ˳���б�����ݡ�
 * �ú�������˳���б��ÿ��Ԫ�أ��������������ӡ����׼����豸�ϡ�
 * ˳���б�Ľṹ��һ�����й̶���С�����ͷ��ָ�룬�����д洢���б��ʵ��Ԫ�ء�
 *
 * @note �ú�������˳���б��Ѿ�����ȷ��ʼ�������������д洢�������ǺϷ��ġ�
 */
void SequenceList::ShowTable() {
    // ����˳���б��е�ÿ��Ԫ��
    for (int i = 0; i < this->seq.length; ++i) {
        // ��ӡÿ��Ԫ�ص���׼����豸
        cout << this->seq.head[i] << " ";
    }
    // ������з����Խ�����ǰ�еĴ�ӡ
    cout << endl;
    cout << "The length of the sequence list is: " << this->seq.length << endl;
}


/**
 * ����˳���
 *
 * ��������������һ���Ѿ�������˳����ͷ���ռ�õ��ڴ�ռ䡣��ִ�����ٲ���ǰ��
 * ���ȼ��˳����Ƿ�Ϊ�գ�ֻ�е���Ϊ��ʱ�Ž������ٲ�����
 *
 * @return �����ɹ������٣��򷵻�true�������Ϊ�գ��������٣���ʱ����false��
 */
// ���ٱ��ͷ��ڴ�
bool SequenceList::DestroyTable() {
    // ���˳����Ȳ�Ϊ0������Ϊ�գ���������ٲ���
    if (getLength() != 0) {
        // �ͷ�˳���ͷ�����ڴ�ռ䣬���ͷ�������Ŀռ�
        free(this->seq.head);
        // ��ɹ����٣�����true
        cout << "Destroy the sequence list." << endl;
        return true;
    }
    // ��Ϊ�գ��������٣�����false
    cout << "The sequence list is empty. No need to destroy." << endl;
    return false;
}


// �������е�����
// �����еĵ�ǰ��������ʱ�������������������ɸ����Ԫ�ء�
// ����ڴ����ʧ�ܣ����������κβ���������ԭ�������䡣
// �������е�����
void SequenceList::addLength() {
    size_t oldSize = this->seq.size;
    this->seq.size *= 2;
    cout << "New size: " << this->seq.size << endl;

    SequenceListDataElement *newHead = (SequenceListDataElement *) realloc(this->seq.head, this->seq.size * sizeof(SequenceListDataElement));
    if (newHead == nullptr) {
        cout << "The Increase failed. Old size: " << oldSize << endl;
        // �ָ�ԭ���Ĵ�С����Ϊ����ʧ��
        this->seq.size = oldSize;
    } else {
        cout << "The Increase succeeded. New size: " << this->seq.size << endl;
        this->seq.head = newHead;
    }
}


// ��ȡ���еĵ�ǰ����
// ����ֵ��������Ԫ�ص�������
// ��ȡ���еĵ�ǰ����
int SequenceList::getLength() {
    cout << "The length of the sequence list is: " << this->seq.length << endl;
    return this->seq.length;
}


// �ж������Ƿ�Ϊ��
// ����ֵ���������Ϊ�գ��򷵻�true�����򷵻�false��
// �ж������Ƿ�Ϊ��
bool SequenceList::isEmpty() {
    if (getLength() == 0) {
        cout << "The sequence list is empty." << endl;
        return true;
    }
    cout << "The sequence list is not empty." << endl;
    return false;
}



/**
 * ��˳����ж�λԪ�ص�λ�ã�����λ���������������ڷ���-1
 * @param e �����ҵ�Ԫ��
 * @return Ԫ�ص�λ�����������������򷵻�-1
 */
// �������ж�λԪ�ص�λ�ã�����λ���������������ڷ���-1
int SequenceList::LocateElem(int e) {
    for (int i = 0; i < this->seq.length; i++) {
        if (this->seq.head[i] == e) {
            cout << "The element " << e << " is located at index " << i + 1 << endl;
            return i + 1;
        }
    }
    cout << "The element " << e << " is not in the sequence list." << endl;
    return -1;
}


/**
 * ��ȡ˳�����ָ��λ�õ�Ԫ�أ�ͨ�����÷���
 * @param i Ԫ�ص�λ������
 * @param Elem ���ڴ�Ż�ȡ����Ԫ�ص�����
 * @return �Ƿ�ɹ���ȡ��Ԫ��
 */
// ��ȡ������ָ��λ�õ�Ԫ�أ�ͨ�����÷���
bool SequenceList::getElem(int i, int &Elem) {
    if (this->seq.length == 0 || this->seq.length < i || i <= 0) {
        cout << "The index is out of range or the sequence list is empty." << endl;
        return false;
    }
    Elem = this->seq.head[i - 1];
    cout << "The element at index " << i << " is " << Elem << endl;
    return true;
}


/**
 * ��˳�����ָ��λ�ò���һ��Ԫ��
 * @param i ����λ�õ�����
 * @param elem �������Ԫ��
 * @return �Ƿ�ɹ�����Ԫ��
 */
// �������в���һ��Ԫ��
bool SequenceList::InsertTable(int i, int elem) {
    if (this->seq.size > i && i >= 1) {
        int j = this->seq.length - 1;
        for (; j >= i - 1; --j) {
            this->seq.head[j + 1] = this->seq.head[j];
        }
        this->seq.head[j + 1] = elem;
        this->seq.length++;
        cout << "The element " << elem << " is inserted at index " << i << endl;
        return true;
    }
    cout << "The index is out of range or the sequence list is full." << endl;
    return false;
}

/**
 * ��˳�����ɾ��ָ��λ�õ�Ԫ�أ���ͨ�����÷��ر�ɾ����Ԫ��
 * @param i ��ɾ��Ԫ�ص�λ������
 * @param data ���ڴ�ű�ɾ��Ԫ�ص�����
 * @return �Ƿ�ɹ�ɾ��Ԫ��
 */
// ��������ɾ��һ��Ԫ�أ���ͨ�����÷��ر�ɾ����Ԫ��
bool SequenceList::DeleteTable(int i, int &data) {
    if (this->seq.length >= i && i >= 1) {
        data = this->seq.head[i - 1];
        int j = i - 1;
        for (; j <= this->seq.length - 1; ++j) {
            this->seq.head[j] = this->seq.head[j + 1];
        }
        this->seq.length--;
        cout << "The element " << data << " is deleted at index " << i << endl;
        return true;
    }
    cout << "The index is out of range or the sequence list is empty." << endl;
    return false;
}

/**
 * ��ת˳���
 * @return �Ƿ�ɹ���ת˳���
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
    cout << "The sequence list is reversed." << endl;
    return true;
}





