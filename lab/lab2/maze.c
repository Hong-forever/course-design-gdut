#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 定义坐标结构体
typedef struct {
    int x;
    int y;
} Position;

// 定义栈结构
typedef struct {
    Position* data;
    int top;
    int capacity;
} Stack;

// 栈操作函数
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (Position*)malloc(capacity * sizeof(Position));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

void push(Stack* stack, Position pos) {
    if (stack->top == stack->capacity - 1) {
        printf("stack is full. \n");
        return;
    }
    stack->data[++stack->top] = pos;
}

Position pop(Stack* stack) {
    if (stack->top == -1) {
        printf("stack is empty.\n");
        return (Position){-1, -1};
    }
    return stack->data[stack->top--];
}
Position gettop(Stack* stack){
    if (stack->top == -1) {
        printf("stack is empty.\n");
        return (Position){-1, -1};
    }
    return stack->data[stack->top];
}


bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// 读取迷宫函数
int** readMaze(const char* filename, int* size) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("无法打开文件");
        return NULL;
    }

    char line[1024];
    *size = 0;
    while (fgets(line, sizeof(line), file)) {
        (*size)++;
    }
    rewind(file);

    int** maze = (int**)malloc(*size * sizeof(int*));
    for (int i = 0; i < *size; i++) {
        maze[i] = (int*)malloc(*size * sizeof(int));
    }

    int row = 0;
    while (fgets(line, sizeof(line), file) && row < *size) {
        char* token = strtok(line, ",");
        int col = 0;
        while (token && col < *size) {
            maze[row][col] = atoi(token);
            token = strtok(NULL, ",");
            col++;
        }
        row++;
    }

    fclose(file);
    return maze;
}

// 迷宫求解函数
void printPath(Stack* stack, int size, int** maze) {
    char** pathMaze = (char**)malloc(size * sizeof(char*));
    for (int i = 0; i < size; i++) {
        pathMaze[i] = (char*)malloc(size * sizeof(char));
        for (int j = 0; j < size; j++) {
            if (maze[i][j] == 1) {
                pathMaze[i][j] = '#';
            } else {
                pathMaze[i][j] = ' ';
            }
        }
    }

    for (int i = 0; i <= stack->top; i++) {
        pathMaze[stack->data[i].x][stack->data[i].y] = '.';
    }

    printf("Path found by BOT:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c ", pathMaze[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < size; i++) {
        free(pathMaze[i]);
    }
    free(pathMaze);
}

bool solveMaze(int** maze, int size) {
    // 定义四个移动方向: 上、右、下、左
    Position directions[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    // 创建访问标记数组
    bool** visited = (bool**)malloc(size * sizeof(bool*));
    for (int i = 0; i < size; i++) {
        visited[i] = (bool*)malloc(size * sizeof(bool));
        for (int j = 0; j < size; j++) {
            visited[i][j] = false;
        }
    }

    // 创建栈并初始化
    Stack* stack = createStack(size * size);
    push(stack, (Position){0, 0});
    visited[0][0] = true;

    while (!isEmpty(stack)) {
        Position current = gettop(stack);
        int x = current.x;
        int y = current.y;

        // 如果到达终点
        if (x == size - 1 && y == size - 1) {
            printf("found the path!\n");
            printPath(stack, size, maze);
            
            // 释放内存
            for (int i = 0; i < size; i++) {
                free(visited[i]);
            }
            free(visited);
            free(stack->data);
            free(stack);
            
            return true;
        }

        // 尝试四个方向
        int i = 0;
        for (; i < 4; i++) {
            int newX = x + directions[i].x;
            int newY = y + directions[i].y;

            // 检查新位置是否有效
            if (newX >= 0 && newX < size && newY >= 0 && newY < size && 
                maze[newX][newY] == 0 && !visited[newX][newY]) {
                
                push(stack, (Position){newX, newY});
                visited[newX][newY] = true;

                break;
            }
        }
        if(i==4) pop(stack);
    }

    printf("no path\n");
    
    // 释放内存
    for (int i = 0; i < size; i++) {
        free(visited[i]);
    }
    free(visited);
    free(stack->data);
    free(stack);
    
    return false;
}

// --- QUEUE ---

// 定义队列节点
typedef struct QNode {
    Position pos;
    struct QNode* next;
} QNode;

// 定义队列结构
typedef struct {
    QNode *front, *rear;
} Queue;

// 队列操作函数
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, Position pos) {
    QNode* temp = (QNode*)malloc(sizeof(QNode));
    temp->pos = pos;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

Position dequeue(Queue* q) {
    if (q->front == NULL) return (Position){-1, -1};
    QNode* temp = q->front;
    Position pos = temp->pos;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return pos;
}

bool isQueueEmpty(Queue* q) {
    return q->front == NULL;
}


// 迷宫求解函数(最短)
void solveMaze_Shortest(int** maze, int size) {
    Position directions[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool** visited = (bool**)malloc(size * sizeof(bool*));
    Position** pred = (Position**)malloc(size * sizeof(Position*));
    for (int i = 0; i < size; i++) {
        visited[i] = (bool*)malloc(size * sizeof(bool));
        pred[i] = (Position*)malloc(size * sizeof(Position));
        for (int j = 0; j < size; j++) {
            visited[i][j] = false;
            pred[i][j] = (Position){-1, -1};
        }
    }

    Queue* queue = createQueue();
    enqueue(queue, (Position){0, 0});
    visited[0][0] = true;

    bool found = false;
    while (!isQueueEmpty(queue)) {
        Position current = dequeue(queue);
        int x = current.x;
        int y = current.y;

        if (x == size - 1 && y == size - 1) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int newX = x + directions[i].x;
            int newY = y + directions[i].y;

            if (newX >= 0 && newX < size && newY >= 0 && newY < size &&
                maze[newX][newY] == 0 && !visited[newX][newY]) {
                
                enqueue(queue, (Position){newX, newY});
                visited[newX][newY] = true;
                pred[newX][newY] = current;
            }
        }
    }

    if (found) {
        printf("\nShortest path found:\n");
        char** pathMaze = (char**)malloc(size * sizeof(char*));
        for (int i = 0; i < size; i++) {
            pathMaze[i] = (char*)malloc(size * sizeof(char));
            for (int j = 0; j < size; j++) {
                pathMaze[i][j] = (maze[i][j] == 1) ? '#' : ' ';
            }
        }

        int pathLen = 0;
        Position crawl = {size - 1, size - 1};
        while (crawl.x != -1 && crawl.y != -1) {
            pathMaze[crawl.x][crawl.y] = '.';
            crawl = pred[crawl.x][crawl.y];
            pathLen++;
        }

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                printf("%c ", pathMaze[i][j]);
            }
            printf("\n");
        }
        printf("Shortest path length: %d\n", pathLen);

        for (int i = 0; i < size; i++) {
            free(pathMaze[i]);
        }
        free(pathMaze);

    } else {
        printf("\nNo path found.\n");
    }

    // Free memory
    for (int i = 0; i < size; i++) {
        free(visited[i]);
        free(pred[i]);
    }
    free(visited);
    free(pred);
    // Free queue memory
    while(!isQueueEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

// 主函数
int main() {
    int n;
    int** maze = readMaze("maze.txt", &n);
    if (!maze) return 1;

    printf("The maze:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    if (!solveMaze(maze, n)) {
        printf("CANNOT find the path\n");
    }

    solveMaze_Shortest(maze, n);

    // 释放迷宫内存
    for (int i = 0; i < n; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}