#include <stdio.h>

int main()
{
    int m = 0;
    int n = 0;
    int tmp = 0;
    scanf("%d %d", &m, &n);
    while(m%n)
    {
        tmp = m%n;
        m = n;
        n = tmp;
    }
    printf("%d\n", n);

    return 0;
}