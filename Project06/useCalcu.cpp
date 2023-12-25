//第一种解决方式：直接包含源文件
//#include "setCalcu.cpp"
//第二种解决方式：讲.h和.cpp文件写成一个文件，改为.hpp
#include "Person.hpp"
#include <string>
using namespace std;

int main()
{
    Person<string,int> p ("Tom", 20);
    p.ShowPerson();

    return 0;
}
