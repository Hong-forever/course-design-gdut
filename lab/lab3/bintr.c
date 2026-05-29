#include "stdio.h"
#include "malloc.h"
#include "chapter5.h"

#define MAX_QUEUE_SIZE 100
typedef struct {
    PBinTreeNode data[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void enQueue(Queue *q, PBinTreeNode node) {
    if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front) return;
    q->data[q->rear] = node;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
}

PBinTreeNode deQueue(Queue *q) {
    if (isEmpty(q)) return NULL;
    PBinTreeNode node = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return node;
}

int getTreeDepth(PBinTreeNode t) {
    if (t == NULL) return 0;
    int leftDepth = getTreeDepth(t->llink);
    int rightDepth = getTreeDepth(t->rlink);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

void listLayerNodeRecur(PBinTreeNode t, int targetLayer, int currentLayer) {
    if (t == NULL) return;
    if (currentLayer == targetLayer) {
        printf("%c  ", t->info);
        return; 
    }
    listLayerNodeRecur(t->llink, targetLayer, currentLayer + 1);
    listLayerNodeRecur(t->rlink, targetLayer, currentLayer + 1);
}

void listLayerNode(BinTree t, int layer) {
    if (t == NULL) {
        printf("二叉树为空！\n");
        return;
    }
    printf("第 %d 层节点：", layer);
    listLayerNodeRecur(t, layer, 1);
    printf("\n");
}

void levelOrder(BinTree t) {
    if (t == NULL) {
        printf("二叉树为空！\n");
        return;
    }
    Queue q;
    initQueue(&q);
    enQueue(&q, t);
    printf("广度优先顺序：");
    while (!isEmpty(&q)) {
        PBinTreeNode node = deQueue(&q);
        printf("%c  ", node->info);
        if (node->llink != NULL) enQueue(&q, node->llink);
        if (node->rlink != NULL) enQueue(&q, node->rlink);
    }
    printf("\n");
}

int main() {
    BinTree p1 = NULL;
    int k = 1, num;

    while (k) {
        printf("\n&&&&&&&&&&&&&&输入序号执行相应操作&&&&&&&&&&&&&&&&&\n");
        printf("            输入1，建立一个二叉树！  \n");
        printf("---------------------------------------------------\n");
        printf("            输入2，查看建立的二叉树！\n");
        printf("---------------------------------------------------\n");
        printf("            输入3，先根周游二叉树！\n");
        printf("---------------------------------------------------\n");
        printf("            输入4，中根周游二叉树！\n");
        printf("---------------------------------------------------\n");
        printf("            输入5，后根周游二叉树！\n");
        printf("---------------------------------------------------\n");
        printf("            输入6，计算二叉树层数（深度）！\n");
        printf("---------------------------------------------------\n");
        printf("            输入7，列出指定层级的节点！\n");
        printf("---------------------------------------------------\n");
        printf("            输入8，广度优先顺序列出节点！\n");
        printf("---------------------------------------------------\n");
        printf("            输入其他，退出操作！\n");
        printf("---------------------------------------------------\n");
        
		int result = scanf("%d", &num);
		if (result != 1) {
			printf("输入无效！请输入一个整数。\n");
			while (getchar() != '\n'); 
			continue;
		}


        switch (num) {
            case 1:
                printf("请按照先根顺序输入二叉树元素(大小写字母)，.代表子树为空\n");
                while (getchar() != '\n'); 
                p1 = consBinTree();
                if (p1) printf("二叉树建立成功！\n");
                else printf("二叉树建立失败！\n");
                break;
            case 2:
                printf("建立的二叉树形状为：\n\n");
                if (p1 != NULL) show(p1, 0);
                else printf("二叉树为空！\n");
                break;
            case 3:
                printf("先根周游序列为：\n");
                preOrder(p1);
                printf("\n");
                break;
            case 4:
                printf("中根周游序列为：\n");
                inOrder(p1);
                printf("\n");
                break;
            case 5:
                printf("后根周游序列为：\n");
                postOrder(p1);
                printf("\n");
                break;
            case 6:
                if (p1 == NULL) printf("二叉树为空！\n");
                else printf("二叉树层数（深度）为：%d\n", getTreeDepth(p1));
                break;
            case 7: {
                if (p1 == NULL) {
                    printf("二叉树为空！\n");
                    break;
                }
                int layer;
                printf("请输入要查看的层数（从1开始）：");
                scanf("%d", &layer);
                int depth = getTreeDepth(p1);
                if (layer < 1 || layer > depth)
                    printf("层数超出范围！当前二叉树共有 %d 层\n", depth);
                else
                    listLayerNode(p1, layer);
                break;
            }
            case 8:
                levelOrder(p1);
                break;
            default:
                printf("退出！\n");
                k = 0;
                break;
        }
    }
    return 0;
}