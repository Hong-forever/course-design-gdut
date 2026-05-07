#include "stdio.h"

int main()
{
    int Tencount, Twecount, Fifcount;
    int i = 0;
    for(Tencount=0; Tencount<=10; Tencount++)
    {
        for(Twecount=0; Twecount<=5; Twecount++)
        {
            for(Fifcount=0; Fifcount<=2; Fifcount++)
            {
                if(Tencount*10 + Twecount*20 + Fifcount*50 == 100)
                {
                     printf("第%d种换法为：10元 %d张; 20元 %d张; 50元 %d张\n", ++i, Tencount, Twecount, Fifcount);
                }
            }
        }
    }

    return 0;
}