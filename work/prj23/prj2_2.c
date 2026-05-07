#include "stdio.h"

int main()
{ 
    int i;
    printf("\n\n\n========主  菜  单========\n");

    printf("        1------汉字\n");
    printf("        2------拼音\n");
    printf("        3------英文\n");
    printf("请选择：");
    scanf("%d", &i);   

    switch (i)
    {
        case 1:     printf("     中国\n")        ;       break;
        case 2:     printf("     ZHONGGUO\n")    ;       break;
        case 3:     printf("     China\n")       ;       break;

        
        default:    printf("INPUT ERROR!\n")     ;       break;
    } 

    return 0;
}

