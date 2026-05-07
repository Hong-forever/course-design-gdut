#include <stdio.h>

int swap(int *p,int *q)
{int t;
 t=*p;
*p=*q;
*q=t;
 
return 0;
}

int main()
{int a,b;
printf("请输入两个整数：");
scanf("%d%d",&a,&b);
printf("两个数交换前顺序为:a=%d,b=%d",a,b);
swap(&a,&b);
printf("两个数交换后顺序为:a=%d,b=%d",a,b);

return 0;
}