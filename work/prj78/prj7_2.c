// 13个人围成一圈，从第1个人开始顺序报号1、2、3。凡报到“3”者退出圈子，找出最后留在圈子中的人原来的序号。

#include "stdio.h"

#define NUM     13

typedef struct {
    int order_s;
    int order_n;
    int state;
    int out;
} MEM;

int main()
{
    MEM men[NUM];
    for(int i=0; i<NUM; i++)    //初始化
    {
        men[i].order_s = i+1;
        men[i].order_n = i+1;
        men[i].state = 0;
        men[i].out = 0;
    }
    int remain = NUM;
    int temp = NUM;
    while(remain != 1)
    {
        for(int i=0; i<NUM; i++)
            if((men[i].order_n)%10 == 3)    
                men[i].state = 1;       //第一轮
        for(int j=0; j<NUM; j++)
        {
            if(men[j].state != 1)
                men[j].order_n = ++temp;    //开始计数
            if((men[j].order_n)%10 == 3)
                men[j].state = 1;
        }
        for(int k=0; k<NUM; k++)
            if(men[k].state == 1 && men[k].out != 1)
            {
                men[k].out = 1;
                remain--;                //remain为未淘汰人数
            }
                
    }
    for(int i=0; i<NUM; i++)
        if(men[i].state != 1)
            printf("The last: %d\n", men[i].order_s);

    return 0;
}