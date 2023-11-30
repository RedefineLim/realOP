#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Menu()
{
    puts("猜数字游戏");
    puts("*************************");
    puts("*************************");
    puts("*****1.play  0.exit******");
    puts("*************************");
    puts("*************************");
}

void game()
{
    int num = rand()%100 + 1;
    while(1)
    {
        int i = 0;
        printf("请输入一个数字:>");
        scanf("%d", &i);
        if(i<num)
        {
            printf("猜小了\n");
        }
        else if(i>num)
        {
            printf("猜大了\n");
        }
        else
        {
            printf("恭喜你，猜到了正确数字！\n");
            break;
        }
    }
}

int main()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        Menu();
        printf("请选择:>");
        scanf("%d", &input);
        switch(input)
        {
            case 1:
                game();
                break;
            case 0:
                printf("退出游戏！\n");
                break;
            default:
                printf("\a选择错误，请重新选择！\n");
                break;
        }
    }while(input);
    puts("再见！");

    return 0;
}