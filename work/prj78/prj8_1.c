#include "stdio.h"
#include "stdlib.h"
typedef struct list {
    int data;
    struct list *next;
} LIST;

int main()
{
    LIST *head, *current;
    int num;
    current = (LIST *)malloc(sizeof(LIST));  
    head = current;
    printf("Please input 5 numbers: ");
    for(int i=0; i<5; i++)
    {
        scanf("%d", &num);
        current->data = num;
        current->next = (LIST *)malloc(sizeof(LIST));
        if(i==4) 
            current->next = NULL; 
        else
            current = current->next;
    }
    current = head;
    printf("The value is: ");
    while(current != NULL)
    {
        printf("->%d ", current->data);
        current = current->next;
    }
    getchar();
    while(current != NULL)
    {
        free(current);
        current = current->next;
    }
}
