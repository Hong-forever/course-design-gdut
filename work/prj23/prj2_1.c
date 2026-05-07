#include "stdio.h"
#include "math.h"

int main()
{ 
    float a, b, c, x1, x2, d;
    printf("请输入 ax^2+bx+c=0 方程三系数值\n");
    scanf("%f %f %f", &a, &b, &c);

    if(abs(a) <= 1e-6)  
    {
        printf("该方程非一元二次方程.\n");
    }
    else
    {
        d = pow(b, 2) - 4*a*c;
        if(fabs(d) <= 1e-6)
        {
            printf("该方程的两个相等实根为：x1, x2=%4.2f\n", -b/(2*a));
        }
        else if(d > 1e-6)
        {
            x1 = (-b + sqrt(d))/(2*a);
            x2 = (-b - sqrt(d))/(2*a);
            printf("该方程的两个不等实根为：x1=%4.2f, x2=%4.2f\n", x1, x2);
        }
        else
        {
            printf("该方程的两个复数根为：x1=%4.2f+%4.2fi, x2=%4.2f-%4.2fi\n", -b/(2*a), sqrt(-d)/(2*a), -b/(2*a), sqrt(-d)/(2*a));
        }

    }

    return 0;
}

