#include <iostream>
#include "polymorphic 01.h"
using namespace std;

int main()
{
    Calculator c;
    c.num1 = 10;
    c.num2 = 10;
    cout << c.getResult("+") << endl;

    return 0;
}