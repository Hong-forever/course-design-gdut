//2、	运用递归，求任一个字符串的长度。
#include "stdio.h"

int my_strlen(char str[]);

int main()
{
    char str[] = "Huang haihong";
    printf("%d", my_strlen(str));
    return 0;
}

int my_strlen(char str[])
{
    if(*str == '\0')
        return 0;
    else
        return 1+my_strlen(str+1);
}

