//��һ�ֽ����ʽ��ֱ�Ӱ���Դ�ļ�
//#include "setCalcu.cpp"
//�ڶ��ֽ����ʽ����.h��.cpp�ļ�д��һ���ļ�����Ϊ.hpp
#include "Person.hpp"
#include <string>
using namespace std;

int main()
{
    Person<string,int> p ("Tom", 20);
    p.ShowPerson();

    return 0;
}
