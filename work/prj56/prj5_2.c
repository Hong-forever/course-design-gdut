#include "stdio.h"

long long fac(long long n);
int main()
{
    long long m, n, t;
    printf("Please input 2 integer numbers: ");
    scanf("%lld %lld", &m, &n);
    if(m < n)
    {
        t = m;
        m = n;
        n = t;
    }
    printf("s = %lf", (double)(fac(m)/(fac(m-n)*fac(n))));
    return 0;
}

long long fac(long long n)
{

    if(n==1 || n==0)
        return 1;
    else 
        return n*fac(n-1);
}