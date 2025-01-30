#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

char pop()
{

    if(top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        char popedElement = stack[top];
        top--;
        return popedElement;
    }
   
}


void push(char value)
{
    if(top ==  MAX_SIZE)
    {
        printf("Stack overflow");
    }
    top = top + 1;
    stack[top] = value;
}

char topElement()
{
    return stack[top];
}


int checkBalanced(char string[])
{
    int size = (int)strlen(string);
    for(int i = 0; i < size; i++)
    {
        if(string[i] == '[' || string[i] == '{' || string[i] == '(')
        {
            push(string[i]);
        }
        else
        {
            if((string[i] == ')' && stack[top] == '(') || (string[i] == '}' && stack[top] == '{') || (string[i] == ']' && stack[top] == '['))
            {
                pop();
            }
            else
            {
                return 0;
            }
            
        }
    }
    if(top != -1)
    {
        return 0;
    }
    return 1;
}

int main()
{
    char string[50];
    scanf("%[^\n]",string);
    getchar();

    if(checkBalanced(string) == 1)
    {
        printf("string is Balanced Paranthesis");
    }
    else{
        printf("string is UnBalanced Paranthesis");
    }
}

// {[()]}