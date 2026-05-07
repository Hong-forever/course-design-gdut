// 运用指针将字符串str2连接到字符串str1 后，构成新的字符串str1

#include "stdio.h"

void str_bridge(char str_source[], char str_slave[]);

int main()
{
    char str1[20], str2[10];
    printf("Please input the string1: ");
    // scanf("%s", str1);
    fgets(str1, 10, stdin);
    printf("Please input the string2: ");
    // scanf("%s", str2);
    fgets(str2, 10, stdin);
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    str_bridge(str1, str2);

    printf("After bridging:\n");

    printf("str1_last: %s\n", str1);

    return 0;
}

void str_bridge(char *str_source, char *str_slave)
{
    while(*str_source != '\0')
    {
        str_source++;
    }
    while(*str_slave != '\0')
    {
        *str_source = *str_slave;
        str_source++;
        str_slave++;
    }
    *str_source = '\0';
}