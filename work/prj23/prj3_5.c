// 输出一有规则的图形，如右图
/*

    *
  * * *  
* * * * * 
  * * *  
    *    
    
*/
#include "stdio.h"
#define LENGTH  11

int main()
{
    for(int i=1; i<=LENGTH; i++)
    {
        if(i%2 != 0)
        {
            for(int j=1; j<=(LENGTH-i); j++)
            {
                printf(" ");
            }
            for(int j=1; j<= i; j++)
            {
                printf("* ");
            }
            printf("\n");
        
        }
    }
    for(int i=LENGTH-1; i>0; i--)
    {
        if(i%2 != 0)
        {
            for(int j=1; j<=(LENGTH-i); j++)
            {
                printf(" ");
            }
            for(int j=1; j<=i; j++)
            {
                printf("* ");
            }
            printf("\n");
        }
    }

    return 0;
}