#ifndef PROJECT06_CALCULATOR_H
#define PROJECT06_CALCULATOR_H
#include "Calculator.h"
#include <iostream>

//类模板分文件编写问题以及解决
template<class T1, class T2>
class Person
{
public:
    T1 m_name;
    T2 m_age;
    Person(T1 name, T2 age);
    void ShowPerson();
};

using namespace std;

template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) {
    m_name = name;
    m_age = age;
}

template<class T1, class T2>
void Person<T1, T2>::ShowPerson() {
    cout << m_name << endl;
    cout << m_age << endl;
}

#endif //PROJECT06_CALCULATOR_H