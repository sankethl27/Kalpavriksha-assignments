#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
    int size;
    int front;
    int end;
    int *arr;
}queue;

int isEmpty(queue* q)
{
    if(q->front == -1 || q->front > q->end)
    {
        return 1;
    }
    return 0;
}
int isFull(queue *q)
{
    if(q->end == q->size-1)
    {
       return 1;
    }
    else return 0;
}
void enqueue(queue *q , int data)
{
    if(isFull(q))
    {
        printf("queue is full");
    }
    else
    {
        if(q->front == -1)
        {
            q->front = 0;
        }
        q->end++;
        q->arr[q->end] = data;
    }
}

int dequeue(queue *q)
{
    int x;
    if(isEmpty(q))
    {
        printf("Queue is Empty");
        return -1;
    }
    else
    {
        x = q->arr[q->front];
        q->front++;
    }
    if(q->front > q->end)
    {
        q->front = q->end = -1;
    }
    return x;
}

int main()
{
    queue *q = malloc(sizeof(queue));
    q->size = 4;
    q->front = -1;
    q->end = -1;
    q->arr = malloc(q->size * sizeof(int));
    enqueue(q,10);
    enqueue(q,9);
    enqueue(q,8);
    enqueue(q,7);
    printf("The element removed is %d\n",dequeue(q));
    printf("The element removed is %d\n",dequeue(q));
    printf("The element removed is %d\n",dequeue(q));
    free(q->arr);
    free(q);
}