#include "bankto.h"
#include <iostream>

int main()
{
    using std::cout;
    using std::cin;
    Bank Dick("Dick", "133153664");
    cout << "����Ҫ���Ĳ�����\n1�����\n2��ȡǮ" << std::endl;
    int num = 0;
    cin >> num;
    double save = 0;
    double out = 0;
    switch (num)
    {
        case 1:
            cout << "��������Ҫ�����Ǯ��:>";
            cin >> save;
            Dick.put_in(save);
            break;
        case 2:
            cout << "��������Ҫȡ����Ǯ��:>";
            cin >> out;
            Dick.get_out(out);
            break;
        default:
            break;
    }
    cout << "��������Ǯ���ǣ�";
    Dick.Show();

    return 0;
}