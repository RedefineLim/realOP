#include "game.h"


void menu()
{
    printf("********************************\n");
    printf("**** 1. play        0.exit *****\n");
    printf("********************************\n");
    printf("\n\n\n");
}


void game()
{
    char ret = 0;

    char board[ROW][COL]={0};
    //初始化棋盘的函数
    InitBoard(board ,ROW ,COL );
    DisplayBoard(board ,ROW ,COL);
    //下棋
    printf("\n温馨提示：坐标的输入的格式是（数字）+（空格）+（数字）+（回车）\n");
    printf("前一位数字表示行数，后一位数字表示列数\n");
    while(1)
    {
        PlayerMove(board, ROW , COL);
        //判断输赢
        ret = IsWin(board ,ROW , COL);
        if(ret!='C')
        {
            break;
        }
        DisplayBoard(board ,ROW ,COL);
        ComputerMove(board ,ROW ,COL);
        //判断输赢
        ret = IsWin(board ,ROW , COL);
        if(ret!='C')
        {
            break;
        }
        DisplayBoard(board ,ROW ,COL);
    }
    if(ret=='*')
    {
        printf("恭喜你，你赢了！\n");
        printf("\n\n\n\n");
    }
    else if(ret=='#')
    {
        printf("真不好意思，你电脑赢了。\n");
        printf("\n\n\n\n");
    }
    else
    {
        printf("平局。\n");
        printf("\n\n\n\n");
    }
        DisplayBoard(board ,ROW ,COL);
}

int main()
{
    srand((unsigned int )time(NULL));

    int input=0;
    do
    {
        menu();
        printf("请选择：>");
        scanf("%d", &input);
        switch( input )
        {
            case 1:
next:
                game();
                Compete(&input);
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("选择错误!\n");
                break;
        }
        if(input==1)
        {
            goto next;
        }

    }while(input);


    system("pause");
    return 0;
}