#ifndef PROJECT06_CALCULATOR_H
#define PROJECT06_CALCULATOR_H

//��ģ����ļ���д�����Լ����
template<class T1, class T2>
class Person
{
public:
    T1 m_name;
    T2 m_age;
    Person(T1 name, T2 age);
    void ShowPerson();
};

#endif //PROJECT06_CALCULATOR_H
