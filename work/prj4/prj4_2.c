// 将字符串str2连接到字符串str1 后，构成新的字符串str1

#include "stdio.h"
#include "string.h"

int main()
{
    char str1[40], str2[20];
    int len1, len2, i, j;
    printf("Please input string str1: ");
    gets(str1);
    len1 = strlen(str1);

    printf("Please input string str2: ");
    gets(str2);
    len2 = strlen(str2);

    for(i=len1, j=0; j<len2; j++)
    {
        str1[i] = str2[j];
    }
    str1[i] = '\0';

    printf("Processed string is: %s", str1);
    return 0;
}