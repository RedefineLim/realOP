#include "game.h"
#include "test.c"

void InitBoard(char board[ROW][COL], int row ,int col)
{
    int i=0;
    int j=0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            board[i][j]= ' ';
        }
    }
}

void DisplayBoard(char board[ROW][COL], int row ,int col)
{
    int i=0;
    for(i=0;i< row; i++)
    {
        //打印数据
        //printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
        //这种写法太捞了
        int j=0;
        for(j=0;j<col;j++)
        {
            printf(" %c ",board[i][j]);
            if(j<col-1)
                printf("|");
        }
        printf("\n");
        //打印分割信息
        if(i<row-1)
        {
            int j=0;
            for(j=0;j<col;j++)
            {
                printf("---");
                if(j<col-1)
                    printf("|");
            }
            printf("\n");
        }
    }
}

void PlayerMove(char board[ROW][COL], int row ,int col )
{
    int x=0;
    int y=0;

    while(1)
    {
        printf("玩家下棋（请输入坐标）：>");
        scanf("%d %d",&x ,&y );
    
        //坐标合法的判断
        if(x>=1 && x<=row && y>=1 && y<=col)
        {
            if(board[x-1][y-1]==' ')
            {
                board[x-1][y-1]='*';
                break;
            }
            else
            {
                printf("被占用，不能下棋，请选择其他位置！ \n");
            }
        }
        else
        {
            printf("坐标输入错误，请重新输入! \n");
        }
    }

}

void ComputerMove(char board[ROW][COL] ,int row ,int col)
{
    printf("电脑下棋：>\n");

    int x=0;
    int y=0;

    while(1)
    {
        x=rand()%row;  //0~2
        y=rand()%col;  //0~2
        if(board[x][y]==' ')
        {
            board[x][y]= '#';
            break;
        }
    }

}

int IsFull(char board[ROW][COL], int row, int col)
{
    int i=0;
    int j=0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(board[i][j]==' ')
                return 0;
        }
    }
    return 1;
}

char IsWin(char board[ROW][COL],int row , int col )
{
    int i=0;
    //判断行
    for(i=0;i<row;i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] ==board[i][2] && board[i][1]!= ' ' )
        {
            return board[i][1];
        }
    }
    //判断列
    int j=0;
    for(j=0;j<col;j++)
    {
        if(board[0][j]==board[1][j] && board[1][j]==board[2][j] && board[1][j] != ' ' )
        {
            return board[1][j];
        } 
    }
    //判断对角线
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[1][1]!= ' ')
    {
        return board[1][1];
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[1][1]!= ' ')
    {
        return board[1][1];
    }
    
    //没有人赢，则此时应该判断平局
    if(IsFull(board ,row, col))
    {
        return 'Q';
    }
    else{
    return 'C';
    }
}

void Compete (int * input)
{
    printf("\n 还要再玩一次吗？\n");
    printf("********************************\n");
    printf("**** 1. YES           0.NO *****\n");
    printf("********************************\n");
    printf("请输入：>");    
    int rot = 0;
    scanf("%d" ,&rot);
    (* input)=rot;
}