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

void enqueue(Stack *s, int value)
{
    push(s, value);
}

int dequeue(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Queue is empty\n");
        return -1;
    }

    int topElement = pop(s);

    if (isEmpty(s))
    {
        return topElement;
    }

    int lastElement = dequeue(s);
    push(s, topElement);

    return lastElement;
}

int peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Queue is empty\n");
        return -1;
    }

    int topElement = pop(s);

    if (isEmpty(s))
    {
        push(s, topElement);
        return topElement;
    }

    int frontElement = peek(s);
    push(s, topElement);

    return frontElement;
}

int main()
{
    Stack s;
    initStack(&s);

    enqueue(&s, 10);
    enqueue(&s, 20);
    enqueue(&s, 30);

    printf("Front element: %d\n", peek(&s));
    printf("Dequeued: %d\n", dequeue(&s));
    printf("Dequeued: %d\n", dequeue(&s));

    enqueue(&s, 40);
    printf("Front element: %d\n", peek(&s));

    return 0;
}
