#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10000

typedef struct stack
{
    char string[MAX];
    struct stack *next;
}node;

node *top = NULL;


void push(node **top , char *ch)
{
    node *newNode = malloc(sizeof(node));
    strcpy(newNode->string, ch);
    newNode->next = *top;
    *top = newNode;
}

char* pop(node **top)
{
    char *ch = malloc(MAX * sizeof(char));
    if(*top != NULL)
    {
        node *temp = *top;
        strcpy(ch ,temp->string);
        *top = temp->next;
        free(temp);
    }
    return ch;
}


// void printStack(node *temp)
// {
//     if(temp == NULL)
//     {
//         return;
//     }
//     printf("%s",temp->string);
//     printStack(temp->next);   
// }
void prefixToInfix(char exp[])
{
    int size = strlen(exp);
    int i = size-1;
    while(i >= 0)
    {
        if(exp[i] == '*' || exp[i] == '/' || exp[i] == '^' || exp[i] == '-' || exp[i] == '+')
        {
            char result[MAX] = "\0";
            char op[2] ="\0";
            op[0] = exp[i];
            strcat(result,"(");
            strcat(result,pop(&top));
            strcat(result,op);
            strcat(result,pop(&top));
            strcat(result,")");
            push(&top,result);
            // printf("result is %s \n",result);
        }   
        else
        {
            char string[2] = "\0";
            string[0] = exp[i];
            push(&top,string);
        }
        i--;
    }
    printf("result is %s : \n",top->string);
}

int main()
{
    char exp[100];
    fgets(exp,100,stdin);
    exp[strcspn(exp,"\n")] = '\0';
    prefixToInfix(exp);
    // printf("result is %s : \n",top->string);
    
}

// Input :  Prefix :  *+AB-CD
// Output : Infix : ((A+B)*(C-D))

// Input :  Prefix :  *-A/BC-/AKL
// Output : Infix : ((A-(B/C))*((A/K)-L))