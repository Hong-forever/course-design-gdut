// 有5个学生，每个学生包括学号、姓名、三门课的成绩，
// 从键盘输入5个学生数据，计算每个人的平均成绩，并将原有数据及平均成绩存放于磁盘文件“stud.txt”中

#include "stdio.h"

#define MAXNAME     10
#define COURNUM     3
#define STUNUM      2

typedef struct {
    char name[MAXNAME];
    int  number;
    float score[COURNUM];
    float sum;
} STUDENT;

int main()
{
    STUDENT stu[STUNUM];
    FILE *fp;
    for(int i=0; i<STUNUM; i++)    //输入10个学生数据
    {
        printf("The %d student: \n", i+1);

        printf("1. name: ");
        fgets(stu[i].name, MAXNAME, stdin);

        printf("2. number: ");
        scanf("%d", &stu[i].number);

        printf("3. scores: ");
        for(int j=0; j<COURNUM; j++)
            scanf("%f", &stu[i].score[j]);

        while(getchar() != '\n')
            continue;
    }

    float average[COURNUM];   
    float Highest = 0;  
    for(int init=0; init<COURNUM; init++)
        average[init] = 0;

    for(int i=0; i<STUNUM; i++)
    {
        stu[i].sum = 0;
        for(int j=0; j<COURNUM; j++)
        {
            stu[i].sum += stu[i].score[j];
        }
    }
    for(int k=0; k<COURNUM; k++)
    {
        for(int h=0; h<STUNUM; h++)
        {
            average[k] += stu[h].score[k];
            if(Highest < stu[h].sum)
                Highest = stu[h].sum;
        }
    }

    fp = fopen("stud.txt", "w+");

    for(int i=0; i<COURNUM; i++)
    {
        printf("The average of the %d course score is %.2f\n", i+1, average[i]/STUNUM);
        fprintf(fp, "The average of the %d course score is %.2f\n", i+1, average[i]/STUNUM);
    }
    printf("And the higest score is %.2f.\n", Highest);
    fprintf(fp, "And the higest score is %.2f.\n", Highest);

    return 0;
}