#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct Queue
{
    int items[SIZE];
    int front, rear;
} Queue;

void initQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q)
{
    return q->front == -1;
}

void enqueue(Queue *q, int value)
{
    if (q->rear == SIZE - 1)
    {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front >= q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front++;
    }
    return item;
}

typedef struct Stack
{
    Queue queue;
} Stack;

void initStack(Stack *s)
{
    initQueue(&s->queue);
}

void push(Stack *s, int value)
{
    int size = s->queue.rear - s->queue.front + 1;
    enqueue(&s->queue, value);
    for (int i = 0; i < size; i++)
    {
        enqueue(&s->queue, dequeue(&s->queue));
    }
}

int pop(Stack *s)
{
    return dequeue(&s->queue);
}

int peek(Stack *s)
{
    if (isEmpty(&s->queue))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return s->queue.items[s->queue.front];
}

int isStackEmpty(Stack *s)
{
    return isEmpty(&s->queue);
}

int main()
{
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element: %d\n", peek(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));

    printf("Stack empty: %s\n", isStackEmpty(&s) ? "Yes" : "No");

    return 0;
}
