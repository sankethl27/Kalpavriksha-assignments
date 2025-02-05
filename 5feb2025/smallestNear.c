#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int data;
    struct stack *next;
}node;

node *top = NULL;

void push(int value)
{
    node* newNode = malloc(sizeof(node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int isEmpty()
{
    if(top == NULL) return 1;
    return 0;
}

int pop()
{
    int x = -1;
    if(!isEmpty())
    {
        x = top->data;
        node *temp = top;
        top = top->next;
        free(temp);
    }
    return x;
}

void printArray(int *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
}
void smallerNearElement(int *arr , int size)
{
    int *pse = malloc(size * sizeof(int));
    for(int i = 0; i < size; i++)
    {
        while(!isEmpty() && arr[i] < arr[top->data])
        {
            pop();
        }
        if(!isEmpty())
        {
            pse[i] = arr[top->data];
        }
        else
        {
            pse[i] = -1;
        }
        push(i);
    }
    printArray(pse,size);
}
int main()
{
    int arr[6] = {4,5,6,2,10,8};
    smallerNearElement(arr,6);
    return 0;
}