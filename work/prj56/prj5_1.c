#include "stdio.h"

#define     NUM     5     

void order(int a[], int n);

int main()
{
    int a[NUM];
    printf("Please input one list: ");
    for(int i=0; i<NUM; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The list input is: ");
    for(int i=0; i<NUM; i++)
    {
        printf("%4d", a[i]);
    }
    printf("\n");

    order(a, NUM);
    printf("The list output is: ");
    for(int i=0; i<NUM; i++)
    {
        printf("%4d", a[i]);
    }
    printf("\n");


    return 0;
}

void order(int a[], int n)
{
    int temp;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

