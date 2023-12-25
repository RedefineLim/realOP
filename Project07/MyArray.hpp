#ifndef PROJECT07_MYARRAY_H
#define PROJECT07_MYARRAY_H
#include <iostream>
using namespace std;

//��ģ�崴��ʱ�����ڵ��õ�ʱ��
template<class T>
class MyArray
{
private:
    T* pAddress;    //ָ��������ٵ���ʵ������
    int m_capacity;
    int m_size;
public:
    MyArray(int capacity) {
        m_capacity = capacity;
        m_size = 0;
        pAddress = new T[m_capacity];
    }
    //��������
    MyArray(const MyArray& arr) {
        m_capacity = arr.m_capacity;
        m_size = arr.m_size;
//        pAddress = arr.pAddress;
        pAddress = new T[arr.m_capacity];
        //���
        //��arr�е�����Ԫ�� ȫ����������
        for(int i = 0; i < m_size; ++i) {
            pAddress[i] = arr.pAddress[i];
        }
    }

    ~MyArray() {
        if(pAddress != NULL) {
            delete [] pAddress;
            pAddress = NULL;
        }
    }

    //β�巨
    void Push_Back(const T& val) {
        //�ж������Ƿ��Ѿ����������
        if(m_capacity == m_size)
            return ;
        pAddress[m_size] = val;
        ++m_size;
    }

    //βɾ��
    void Pop_Back() {
        if(m_size == 0)
            return ;
        --m_size;
    }

    //ͨ���±귽ʽ���������е�Ԫ��


    MyArray& operator=(const MyArray& arr) {
        //�ж�ԭ�������Ƿ������ݣ�����У����ͷ�
        if(pAddress != NULL) {
            delete [] pAddress;
            pAddress = NULL;
            m_capacity = 0;
            m_size = 0;
        }
        m_capacity = arr.m_capacity;
        m_size = arr.m_size;
        pAddress = new T [m_capacity];
        for(int i = 0;i<m_capacity; ++i) {
            pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }

    T& operator[](int index) {  //����T&���ѱ����ֵ��Ϊ����ʹ��
        return pAddress[index];
    }

    int get_size() {
        return m_size;
    }
};

#endif //PROJECT07_MYARRAY_H
