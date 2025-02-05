#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack
{
    char string[20];
    struct stack *next;
}node;

node *top = NULL;

void push(char string[])
{

    node *newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->string ,string);
    newNode->next = top;
    top = newNode;
}

char *pop()
{
    char *string = malloc(20 * sizeof(char));
    if(top != NULL)
    {  
        strcpy(string,top->string);
        node* temp = top;
        top = top->next;
        free(temp);
    }
    return string;
}

int main()
{
    char expression[30];
    scanf("%s",expression);
    int size = strlen(expression);
    int i = size - 1;
    while(i >= 0)
    {
        if((expression[i] >= 'A' && expression[i] <= 'Z') || (expression[i] >= 'a'&& expression[i] <= 'z') || (expression[i] >= '0' && expression[i] <= '9'))
        {
            char string[2] = {expression[i] , '\0'};
            push(string);
        }
        else
        {
            char result[20];
            char operartor[2] = {expression[i] , '\0'};
            strcpy(result,"(");
            strcat(result,pop());
            strcat(result,operartor);
            strcat(result,pop());
            strcat(result,")");
            push(result);
        }
        i--;
    }
    printf("result is %s",pop());
}