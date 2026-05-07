// 3、	运行折半查找法，在一个有序序列中查找某一特定的数。
#include "stdio.h"
#include "string.h"

#define     LENGTH      10

int main()
{
    int arr[LENGTH] = {0, 2, 4, 5, 6, 8, 9, 12, 17, 29};
    int low=0, mid, high=LENGTH-1, num;
    
    printf("Please input the number you find: ");
    scanf("%d", &num);

    while(low <= high)
    {
        mid = (low + high) / 2;
        if(num == arr[mid])
        {
            printf("The number is at arr[%d]\n", mid);
            break;
        }
        else    if(num > arr[mid])  low  = mid + 1;
        else                        high = mid - 1;
    }

    return 0;
}