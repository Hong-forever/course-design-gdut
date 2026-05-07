// 判断任一个数是否是质数。

#include "stdio.h"

int main()
{
    int num;
    int i;
    printf("请输入一个数：");
    scanf("%d", &num);
    if(num == 2)
    {
        printf("%d是质数\n", num);
    }
    else if(num == 0 || num == 1)
    {
        printf("输入%d错误", num);
    }
    else
    {
        for(i=2; i<num/2+1; i++)
        {
            if(num%i == 0)
            {
                printf("%d不是质数\n", num);
                break;
            }
        }
    }
    if(i == num/2+1)
    {
        printf("%d是质数\n", num);
    }

    return 0;
}