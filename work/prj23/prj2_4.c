// 从键盘上输入1-7之间的数字，输出表示一个星期中对应某一天的英文单词


#include "stdio.h"

int main()
{ 
    int num;
    printf("请输入一个1到7的数字：");

    scanf("%d", &num);
    switch(num)
    {
        case 1: printf("Monday\n");              break;
        case 2: printf("Tuesday\n");             break;
        case 3: printf("Wednesday\n");           break;
        case 4: printf("Thursday\n");            break;
        case 5: printf("Friday\n");              break;
        case 6: printf("Saturday\n");            break;
        case 7: printf("Sunday\n");              break;
        default:    printf("INPUT ERROR\n");
    }

    return 0;
}

