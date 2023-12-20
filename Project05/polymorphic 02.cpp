#include "polymorphic 01.h"

int Calculator::getResult(std::string oper) {
    if(oper == "+")
        return num1 + num2;
    else if(oper == "-")
        return num1 - num2;
    else if(oper == "*")
        return num1 * num2;
}

