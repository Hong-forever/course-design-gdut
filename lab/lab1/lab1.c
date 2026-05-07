//============================================//
// 姓名：黄海鸿 
// 学号：3123009487
// 联系方式：3224318821@qq.com
// 班级：2023级集成电路设计与集成系统3班
// 题目：lab1蹴鞠游戏模拟
//============================================//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 学生节点
typedef struct Student {
    int id;                 // 学号
    int num;                // 纸条上的整数（随机数）
    struct Student* next;
} Student;

Student* InitList(int N, int m, int* numbers) {
    Student* head = (Student*)malloc(sizeof(Student));
    head->id = 1; // 欧阳修
    head->num = m; // 欧阳修的纸条数字为初始 m
    head->next = head;

    Student* tail = head;
    for (int i = 2; i <= N; i++) {
        Student* newStu = (Student*)malloc(sizeof(Student));
        newStu->id = i;
        newStu->num = numbers[i - 2];  // 纸条上的数字
        newStu->next = head;

        tail->next = newStu;
        tail = newStu;
    }
    return head;
}

// 释放链表
void FreeList(Student* head) {
    while(head) {
        Student* tmp = head;
        if(head->next == head) { // 只有一个节点
            free(tmp);
            break;
        }
        head = head->next;
        free(tmp);
    }
}

void Game(int N, int m, int* numbers, int* winner) {
    Student* head = InitList(N, m, numbers);

    Student* current = head;
    Student* prev = head;
    
    while (current->id != 1) {
        prev = current;
        current = current->next;
    }

    int step = m;
    int remaining = N;

    printf("\n游戏开始！\n");

    while (remaining > 1) {
        for (int i = 0; i < step; i++) {
            prev = current;
            current = current->next;
        }

        // 淘汰 current
        Student* toDel = current;
        step = toDel->num;   // 用被淘汰学生袋子里的数字作为新步长
        prev->next = toDel->next;
        current = toDel->next;
        if (toDel == head) {
            head = toDel->next;
        }
        printf("淘汰学生学号: %d, 纸条数字: %d\n", toDel->id, toDel->num);

        free(toDel);
        remaining--;
    }

    *winner = current->id;
    printf("\n获胜者学号: %d\n", *winner);
    FreeList(head);
}

int main() {
    srand(time(NULL));  // 随机种子

    int N, m;
    int select;

    printf("\n请输入学生人数 N: ");
    scanf("%d", &N);
    while(N < 2) {
        printf("学生人数必须大于等于2，请重新输入 N: ");
        scanf("%d", &N);
    }
    
    printf("请输入初始 m: ");
    scanf("%d", &m);
    while(m <= 0) {
        printf("初始 m 必须大于0，请重新输入 m: ");
        scanf("%d", &m);
    }

    printf("请选择昭文袋数字生成方式（1-随机，2-学号）: ");
    scanf("%d", &select);
    while(select != 1 && select != 2) {
        printf("输入错误，请重新选择（1-随机，2-学号）: ");
        scanf("%d", &select);
    }

    int* numbers = (int*)malloc((N - 1) * sizeof(int));
    printf("\n每个学生纸条上的随机数：\n");
    printf("学号 1 : %d\n", m); // 欧阳修的纸条数字为初始 m
    for (int i = 0; i < N - 1; i++) {
        if(select == 1) {
            numbers[i] = rand() % 100 + 1;  // 1~100 随机数
        } else {
            numbers[i] = i + 2; // 学号作为纸条数字
        }
        printf("学号 %d : %d\n", i + 2, numbers[i]);
    }

    int winner;
    Game(N, m, numbers, &winner);

    printf("\nN = %d, m = %d, winner = %d\n", N, m, winner);

    free(numbers);
    return 0;
}