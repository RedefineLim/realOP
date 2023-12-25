#include "Calculator.h"
#include <iostream>
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