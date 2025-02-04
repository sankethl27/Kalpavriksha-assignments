#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Stack
{
    char arr[20][20];
    int top;
    int size;
}stack;



void push(stack *s , char string[10])
{
    if(s->top == s->size-1)
    {
        printf("Stack overFlow");
        return;
    }
    else
    {
        s->top++;
        strcpy(s->arr[s->top] ,string);
    }
}

void pop(stack *s)
{
    if(s->top == -1)
    {
        return;
    }
    s->top--;
}

void printFolder(stack *s)
{
    for(int i = 0 ; i <= s->top; i++)
    {
        printf("/%s",s->arr[i]);
    }
    printf("/");
}
int main()
{
    stack *s = malloc(sizeof(stack));
    s->size = 10;
    s->top = -1;
    int count = 4;
    while(count--)
    {
        char string[20];
        scanf("cd ");
        scanf("%[^\n]s",string);
        getchar();
        string[strcspn(string,"/")] = '\0';
        if(strcmp(string,"..")==0)
        {
            pop(s);
        }
        else if(strcmp(string,".") == 0)
        {
            continue;
        }
        else
        {
            push(s,string);
        }
    }
    printFolder(s);
}