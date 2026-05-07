// 求1—100之间，能被5整除的数之和。
#include "stdio.h"

int main()
{
    int sum = 0;
    for(int i=0; i<=100; i++)
    {
        if(i%5 == 0 && i != 0)
        {
            sum += i;
        }
    }
    printf("1—100之间，能被5整除的数之和为：%d\n", sum);

    return 0;
}