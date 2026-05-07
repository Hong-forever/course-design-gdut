// 有10个学生，每个学生包括学号、姓名、三门课的成绩，
//从键盘输入10个学生数据，要求输出三门课中每一门课的平均成绩，以及最高分学生的数据。

#include "stdio.h"

#define MAX_NAME     10
#define COUR_NUM     3
#define STU_NUM      2

typedef struct {            //结构体定义
    char name[MAX_NAME];
    int  number;
    float score[COUR_NUM];
    float sum;
} STUDENT;

int main()
{
    STUDENT stu[STU_NUM];
    for(int i=0; i<STU_NUM; i++)    //输入10个学生数据
    {
        printf("The %d student: \n", i+1);  //学生序号

        printf("1. name: ");
        fgets(stu[i].name, MAX_NAME, stdin); //学生姓名获取

        printf("2. number: ");
        scanf("%d", &stu[i].number);        //学号

        printf("3. scores: ");
        for(int j=0; j<COUR_NUM; j++)
            scanf("%f", &stu[i].score[j]);  //三科成绩

        while(getchar() != '\n')
            continue;
    }

    float average[COUR_NUM];        //平均成绩
    float Highest = 0;  
    for(int init=0; init<COUR_NUM; init++)
        average[init] = 0;

    for(int i=0; i<STU_NUM; i++)
    {
        stu[i].sum = 0;
        for(int j=0; j<COUR_NUM; j++)
        {
            stu[i].sum += stu[i].score[j];  //学生得分总和
        }
    }
    for(int k=0; k<COUR_NUM; k++)
    {
        for(int h=0; h<STU_NUM; h++)
        {
            average[k] += stu[h].score[k];  //求和，用来求平均值
            if(Highest < stu[h].sum)        //最高分
                Highest = stu[h].sum;
        }
    }

    for(int i=0; i<COUR_NUM; i++)
    {
        printf("The average of the %d course score is %.2f\n", i+1, average[i]/STU_NUM);
    }
    printf("And the higest score is %.2f.\n", Highest);

    return 0;
}