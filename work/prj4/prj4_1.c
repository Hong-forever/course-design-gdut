// 输入一个整数，将其插入一含有9个数的有序序列中，确保插入后其仍然有序

#include "stdio.h"

int main()
{
    int arr[10] = {2, 5, 7, 11, 14, 19, 21, 33, 67};
    int num, temp, i;
    printf("原数组为：");
    for(i=0; i<9; i++)
    {
        printf("%4d", arr[i]);
    }
    printf("\n请输入待插入的整数：");
    scanf("%d", &num);

    for(i=0; i<=9; i++)
    {
        if(num <= arr[i])
        {
            temp = num;
            num  = arr[i];
            arr[i] = temp;
        }
    }
    arr[9] = num;

    // for(i=0; i<9; i++)
    // {
    //     if (num <= arr[i]) //查找待插入的位置
    //         break;
    // }
    // for(k=9; k>i; k--)
    // {
    //     arr[k] = arr[k-1];   //移位，准备插入新的整数
    // }
    // arr[i] = num;

    printf("新数组为：");
    for(int i=0; i<10; i++)
    {
        printf("%4d", arr[i]);
    }

    return 0;
}