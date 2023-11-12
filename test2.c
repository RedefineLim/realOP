#include "game2.h"
#include "game2.c"

void menu()
{
    printf("*************************\n");
    printf("******1.play 0.exit******\n");
    printf("*************************\n");
}

void game()
{
    char mine[ROWS][COLS] = {'0'};    //存放布置好的雷的信息
    char show[ROWS][COLS] = {'0'};    //存放排查出的雷的信息
    //初始化数组的内容为指定的内容
    //mine数组在没有布置雷的时候都是字符'0'
    InitBoard(mine ,ROWS, COLS, '0');
    //show数组在没有排查雷的时候都是字符'*'
    InitBoard(show ,ROWS, COLS, '*');
    //布置雷
    SetMine(mine ,ROW , COL);

    //DisplsyBoard(mine, ROW, COL);
    DisplsyBoard(show, ROW, COL);
    //排查雷
    FindMine(mine ,show, ROW, COL);
}

int main()
{
    int input = 0;
    srand((unsigned int )time(NULL));
    do
    {
        menu();
        printf("请选择：>");
        scanf("%d" ,&input);
        switch(input)
        {
            case 1:
                game();
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("选择错误，请重新选择！\n");
                break; 
        }
        
    }while(input);

    system("pause");
    return 0;
}