// 1、	判断一方阵是不是对称矩阵。
#include "stdio.h"
#include "string.h"

#define     VER     2
#define     HOR     2


int main()
{
    int arr[VER][HOR];
    int num = 0;
    printf("Please input one matrix: ");
    for(int i=0; i<VER; i++)
    {        
        for(int j=0; j<HOR; j++)
        {
            printf("\nMatrix[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i=0; i<VER; i++)
    {
        for(int j=0; j<HOR; j++)
        {
            if(arr[i][j] == arr[j][i])
            {
                num++;
            }
        }
    }
    if(num == VER*HOR)
        printf("Matrix you have input is symmetrical.\n");
    else
        printf("Matrix you have input isn't symmetrical.\n");

    return 0;
}