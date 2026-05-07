// 1、	若正整数A恰好出现在其平方数的右侧，则称A为一个同构数。如：5，6，76。求100以内的所有同构数。
// 要求：（1）编写一子函数int fun（int n），判断给定正整数n是不是同构数，若是，返回1，否则，返回0。
//       （2）编写主函数，调用函数fun()，寻找并输出100以内的所有同构数。
//       （3）在输出同构数的同时，要输出其平方的值。



#include "stdio.h"

int fun(int n);

int main()
{
    for(int i=1; i<100; i++)
    {
        if(fun(i))
        {
            printf("%d does. power2 is %d\n", i, i*i);
        }
        else
        {
            printf("%d doesn't.\n", i);
        }
    }
    return 0;
}

int fun(int n)
{
    int result;
    result = n * n;
    if(n<10 && n>0)
    {
        if(result % 10 == n)
            return 1;
        else
            return 0;
    }
    else if(n>=10 && n<100)
    {
        if(result % 100 == n)
            return 1;
        else
            return 0;
    }
    else
    {
        return 0;
    }
}