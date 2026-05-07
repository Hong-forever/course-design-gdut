#include "stdio.h"
#include "math.h"

int main()
{
    int m, n, t, max, min;
    printf("请输入两个正整数：");
    scanf("%d %d", &m, &n);

    min = m * n;
    if(m < n)
    {
        t = n;
        n = m;
        m = t;
        while (n != 0)
        {
            t = m % n;
            m = n;
            n = t;
        }
        printf("最大公约数为：%d\n", m);
        printf("最小公倍数：  %d\n", min/m);
    }
    else
    {
        while (n != 0)
        {
            t = m % n;
            m = n;
            n = t;
        }
        printf("最大公约数为：%d\n", m);
        printf("最小公倍数：  %d\n", min/m);
    }
    return 0;
}