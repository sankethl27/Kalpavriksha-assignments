#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Queue
{
    int data;
    struct Queue *next;
}node;

node *front = NULL;
node *end = NULL;

void enqueue(int data,node **front,node **end)
{
    node* newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if(*front == NULL)
    {
        *front = *end = newNode;
    }
    else
    {
        (*end)->next = newNode;
        *end = newNode;
    }
}

int dequeue(node **front,node **end)
{
    int x;
    if(*front == NULL)
    {
        printf("queue is Empty\n");
        return -1;
    }
    x = (*front)->data;
    node *temp = *front;
    *front = temp->next;
    free(temp);
    if(*front == NULL)
    {
        *end = NULL;
    }
    return x;
}

int main()
{
    enqueue(10,&front,&end);
    enqueue(20,&front,&end);
    enqueue(30,&front,&end);
    enqueue(40,&front,&end);
    enqueue(50,&front,&end);
    printf("front is %d\n",dequeue(&front,&end));
   printf("front is %d\n",dequeue(&front,&end));
   printf("front is %d\n",dequeue(&front,&end));
   printf("front is %d\n",dequeue(&front,&end));
   printf("front is %d\n",dequeue(&front,&end));
   printf("front is %d\n",dequeue(&front,&end));
   printf("front is %d\n",dequeue(&front,&end));
   printf("front is %d\n",dequeue(&front,&end));
    return 0;
}