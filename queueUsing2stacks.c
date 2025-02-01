#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct Stack
{
    int items[SIZE];
    int top;
} Stack;

void initStack(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, int value)
{
    if (s->top == SIZE - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    s->items[++s->top] = value;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return s->items[s->top--];
}

typedef struct Queue
{
    Stack s1, s2;
} Queue;

void initQueue(Queue *q)
{
    initStack(&q->s1);
    initStack(&q->s2);
}

void enqueue(Queue *q, int value)
{
    push(&q->s1, value);
}

int dequeue(Queue *q)
{
    if (isEmpty(&q->s2))
    {
        if (isEmpty(&q->s1))
        {
            printf("Queue is empty\n");
            return -1;
        }

        while (!isEmpty(&q->s1))
        {
            push(&q->s2, pop(&q->s1));
        }
    }

    return pop(&q->s2);
}

int peek(Queue *q)
{
    if (isEmpty(&q->s2))
    {
        if (isEmpty(&q->s1))
        {
            printf("Queue is empty\n");
            return -1;
        }

        while (!isEmpty(&q->s1))
        {
            push(&q->s2, pop(&q->s1));
        }
    }

    return q->s2.items[q->s2.top];
}

int main()
{
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Front element: %d\n", peek(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    enqueue(&q, 40);
    printf("Front element: %d\n", peek(&q));

    return 0;
}
