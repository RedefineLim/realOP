#include <stdio.h>
#include <math.h>

int main()
{
    int i = 0;
    for(i=101;i<200;i+=2)
    {
        int j = 0;
        for(j=2;j<sqrt(i);j++)
        {
            int flag = 1;
            if(i%j == 0)
            {
                flag = 0;
                break;
            }
        } 
        printf("%d ",i);
    }
    printf("\n");

    return 0;
}