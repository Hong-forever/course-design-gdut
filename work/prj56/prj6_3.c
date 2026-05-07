// 运用指向数组的指针，求一数组中所有元素之和

#include "stdio.h"

int sum(int arr[], int n);
int main()
{
    int arr[10] = {10, 8, 5 ,6};

    printf("The sum is %d\n", sum(arr, 10));
    return 0;
}

int sum(int arr[], int n)
{
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += arr[i];
    }
    return sum;
}