#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int data;
    struct stack *next;
}node;

void push(node **top , int data)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

int isEmpty(node **top)
{
    if(*top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pop(node **top)
{
    int x;
    if(*top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else{
        node *temp =*top;
        *top = (*top)->next;
        x = temp->data;
        free(temp);
    }
    return x;
}

int main()
{
    node *top = NULL;
    push(&top,1);
    push(&top,2);
    push(&top,3);
    push(&top,4);
    push(&top,5);
    printf("top is %d\n",pop(&top));
    printf("top is %d\n",pop(&top));
    printf("top is %d\n",pop(&top));
    printf("top is %d\n",pop(&top));
    printf("top is %d\n",pop(&top));
    printf("top is %d\n",pop(&top));
    printf("top is %d\n",pop(&top));
}