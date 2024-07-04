//
// Created by 24887 on 2023/7/13.
//

#ifndef ALL_SEQUENCELIST_H
#define ALL_SEQUENCELIST_H

/* ����Ԫ������Ϊ���� */
typedef int SequenceListDataElement ;
/* ����˳���ṹ */
typedef struct {
    SequenceListDataElement *head ; /* ָ��������Ԫ�ص�ָ�� */
    int size ; /* �����Ԥ�����С */
    int length ; /* ������Ԫ�ص�ʵ������ */
}Seq;

/* ˳����ඨ�� */
class SequenceList {
public :
    Seq seq ; /* ˳���ʵ�� */


    /**
     * �ղι��캯��
     **/
    SequenceList();


    /**
     * size ��ʼ��
     **/
    SequenceList(int size);

    /* ��ʼ��˳�����������Ϊ0 */
    /**
    * @brief
    * ��ʼ��˳���
    * ֻ��Ҫ���ض�Ӧ�����ݺ�ֵ������û�б�Ҫ����ԭ�ȴ���������
    * @return void
    */
    void InitTable() ;

    /* ���˳����е�����Ԫ�� */
    /**
    * @brief
    * ���˳�����Ԫ�صĺ���
    * @param s
     */
    void ShowTable() ;

    /* ��˳�����ʱ���������鳤�� */
    /**
    * @brief
    * �����Ȳ���ʱ���Զ������ڴ�,ʹ��realloc���������ڴ�
    * @param s
    */
    void addLength() ;

    /* ����˳���ĳ��� */
    /**
    * @brief Get the Length object
    * ��ȡ���鳤��
    * @param s
     * @return int
    */
    int getLength() ;

    /* ����˳����ͷ��ڴ� */
    /**
    * @brief
     * �����������ٳɹ����򷵻�true����֮����false��
     * @param s
    * @return true
    * @return false
    */
    bool DestroyTable() ;

    /* �ж�˳����Ƿ�Ϊ�� */
    /**
    * @brief
    * �ж�˳����Ƿ�Ϊ��
     * @param s
     * @return true
    * @return false
     */
     bool isEmpty() ;

     /**
      * @brief ��λԪ���ڱ��е�λ��
      *
      * @param e �����ҵ�Ԫ��
      * @return int Ԫ�ص�λ�ã����δ�ҵ�����-1
      */
     int LocateElem(int e) ;

     /**
      * @brief ��ȡ����ָ��λ�õ�Ԫ��
      *
      * @param i Ԫ�ص�λ��
      * @param Elem ���ڴ洢��ȡ����Ԫ�ص�����
      * @return bool ��ȡ�Ƿ�ɹ����ɹ�����true��ʧ�ܷ���false
      */
     bool getElem(int i , int &Elem) ;

     /**
      * @brief �ڱ��в���һ��Ԫ��
      *
      * @param i ����λ��
      * @param elem �������Ԫ��
      * @return bool �����Ƿ�ɹ����ɹ�����true��ʧ�ܷ���false
      */
     bool InsertTable(int i , int elem) ;

     /**
      * @brief �ӱ���ɾ��ָ��λ�õ�Ԫ��
      *
      * @param i ��ɾ��Ԫ�ص�λ��
      * @param data ���ڴ洢��ɾ��Ԫ�ص�����
      * @return bool ɾ���Ƿ�ɹ����ɹ�����true��ʧ�ܷ���false
      */
     bool DeleteTable(int i , int &data) ;

     bool reverseSequenceList() ;
};



#endif //ALL_SEQUENCELIST_H
