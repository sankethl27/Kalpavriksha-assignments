#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int top;
    int size;
    int *arr;
}stack;

int isFull(stack *s)
{
    if(s->top == s->size-1)
    {
        return 1;
    }
    return 0;
}
void push(stack *s , int data)
{
    if(isFull(s))
    {
        printf("IS full\n");
    }
    s->top++;
    s->arr[s->top] = data;
}

int isEmpty(stack *s)
{
    return s->top == -1;
}

int pop(stack *s)
{
    int x;
    if(isEmpty(s))
    {
        printf("is empty\n");
        return -1;
    }
    x = s->arr[s->top];
    s->top--;
    return x;
}
int main()
{
    stack *s = malloc(sizeof(stack));
    s->top = -1;
    s->size = 10;
    s->arr = malloc(sizeof(int));

    push(s,10);
    push(s,9);
    push(s,8);
    push(s,7);
    push(s,6);  
    printf("top is %d\n",pop(s));
    printf("top is %d\n",pop(s));
    printf("top is %d\n",pop(s));
    printf("top is %d\n",pop(s));
    printf("top is %d\n",pop(s));
    printf("top is %d\n",pop(s));
    return 0;

    return 0;
}