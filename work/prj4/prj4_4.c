// 2、	实现两个字符串拷贝的功能    strcpy?
#include "stdio.h"
#include "string.h"

#define     LENGTH      20

int main()
{
    char str_source[LENGTH];
    char str_target[LENGTH];

    printf("Please input the string you want to copy: ");
    fgets(str_source, LENGTH, stdin);

    for(int i=0; i<LENGTH; i++)
    {
        str_target[i] = str_source[i];
    }

    printf("STR_TARGET: ");
    puts(str_target);
    return 0;
}