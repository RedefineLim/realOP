#include "game2.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
    int i = 0;
    int j = 0;
    for(i=0;i<rows; i++)
    {
        for(j=0;j<cols;j++)
        {
            board[i][j] = set;
        }
    }

}

void DisplsyBoard(char board[ROWS][COLS], int row, int col)
{
    int i = 0;
    int j = 0;
    printf("------------------扫雷游戏------------------\n");
    printf("  ");
    for(j=1;j<=col;j++)
    {
        printf("%d ", j);
    }
    printf("\n");
    for(i=1;i<=row;i++)
    {
        printf("%d " , i);
        for(j=1;j<=col;j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("------------------扫雷游戏------------------\n");

}

void SetMine(char board[ROWS][COLS], int row, int col)
{
    int count = EASY_COUNT;
    while(count)
    {
        int x = rand()%ROW +1;
        int y = rand()%COL +1;

        if(board[x][y] == '0')
        {
            board[x][y] = '1';
            count--;
        }
    }
}

int get_mine_count(char board[ROWS][COLS] , int x, int y)
{
    return (board[x-1][y-1]+
            board[x-1][y]+
            board[x-1][y+1]+
            board[x][y-1]+
            board[x][y+1]+
            board[x+1][y-1]+
            board[x+1][y]+
            board[x+1][y+1] - 8*'0');
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS] , int row, int col)
{
    int x = 0;
    int y = 0;
    int win = 0;   //找到非雷的个数

    while(win<row*col-EASY_COUNT)
    {
    printf("请输入排查的坐标：>");
    scanf("%d %d", &x , &y);

    if(x>=1 && x<=ROW && y>=1 && y<=COL)
    {
        if(show[x][y] != '*')
        {
            printf("这个雷已经被排查过了，不能重复排查！\n");
        }
        else
        {
            if(mine[x][y]=='1')     //如果是雷
            {
            printf("很遗憾， 你被炸死了。\n");
            DisplsyBoard(mine , ROW, COL);
            break;
            }
        }
        if(mine[x][y]=='1')     //如果是雷
        {
            printf("很遗憾， 你被炸死了。\n");
            DisplsyBoard(mine , ROW, COL);
            break;
        }
        else    //如果不是雷
        {
            win++;
            int count = get_mine_count(mine , x, y);
            show[x][y] = count+ '0';    //转换成数字字符
            DisplsyBoard(show , ROW, COL);
        }
        
    }
    else
    {
        //统计（x，y）坐标周围雷的个数
        int count = printf("输入坐标非法，请重新输入！\n");
    }
    }
    if(win == col*row- EASY_COUNT)
    {
        printf("恭喜你排雷成功啦！\n");
        DisplsyBoard(mine , ROW, COL);
    }
}
