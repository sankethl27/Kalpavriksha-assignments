#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct stack
{
    char ch;
    struct stack *next;
}node;

node *top1 = NULL;
node* top2 = NULL;

void push(node **top , char ch)
{
    node *newNode = malloc(sizeof(node));
    newNode->ch = ch;
    newNode->next= *top;
    *top = newNode;
}
char pop(node **top)
{
    if(*top == NULL)
    {
        return -1;
    }
    node *temp = *top;
    char x = temp->ch;
    *top = temp->next;
    free(temp);
    return x;
}

int precedence(char ch)
{
    if(ch == '^') return 3;
    else if (ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    else return 0;
}
void infixToPostfix(char exp[])
{
    int size = strlen(exp);
    char result[100]= "\0";
    // size = 0;
    for(int i = 0; i < size; i++)
    {
        if(exp[i] == '*' || exp[i] == '/' || exp[i] == '-' ||exp[i] == '+' ||exp[i] == '^')
        {
            while(top1 !=NULL && precedence(exp[i])  <= precedence(top1->ch))
            {
                char rem[2] = "\0";
                rem[0] = pop(&top1);
                strcat(result,rem);
            }
            push(&top1,exp[i]);
        }
        else if (exp[i] == '(')
        {
            push(&top1,exp[i]);
        }
        else if(exp[i] == ')')
        {
            char ch = pop(&top1);
            while(top1 != NULL && ch != '(')
            {
                char rem[2] = "\0";
                rem[0] = ch;
                strcat(result,rem);
                ch = pop(&top1); 
            }
        }
        else
        {
            char rem[2] = "\0";
            rem[0] = exp[i];
            strcat(result,rem);
        }
    }
    while(top1!=NULL)
    {
        char rem[2] = "\0";
        rem[0] = pop(&top1);
        strcat(result,rem);
    }
    printf("Infix to Postfix : %s \n",result);
}
void reverse(char *s,int l,int r)
{
    while(l < r)
    {
        char temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        l++;
        r--;
    }
}

void infixToPrefix(char exp[])
{
    reverse(exp,0,strlen(exp)-1);
    for (int i = 0; i < strlen(exp); i++){
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
    }
    int size = strlen(exp);
    char result[100] = "\0";
    for(int i = 0; i < size; i++)
    {
        if(exp[i] == '*' || exp[i] == '/' || exp[i] == '-' ||exp[i] == '+' ||exp[i] == '^')
        {
            while(top1 !=NULL && precedence(exp[i])  < precedence(top1->ch))
            {
                char rem[2] = "\0";
                rem[0] = pop(&top1);
                strcat(result,rem);
            }
            push(&top1,exp[i]);
        }
        else if (exp[i] == '(')
        {
            push(&top1,exp[i]);
        }
        else if(exp[i] == ')')
        {
            while(top1 != NULL && top1->ch != '(')
            {
                char rem[2] = "\0";
                rem[0] = top1->ch;
                strcat(result,rem);
                pop(&top1);
            }
            pop(&top1);
        }
        else
        {
            char rem[2] = "\0";
            rem[0] = exp[i];
            strcat(result,rem);
        }
    }
    while(top1!=NULL)
    {
        char rem[2] = "\0";
        rem[0] = pop(&top1);
        strcat(result,rem);
    }
    reverse(result,0,strlen(result)-1);
    printf("Infix to prefix : %s \n",result);
}

int main()
{
    char exp[100];
    fgets(exp,100,stdin);
    exp[strcspn(exp,"\n")] = '\0';
    // infixToPostfix(exp);
    infixToPrefix(exp);

}

//a+b*(c^d-c)
//(A+B)*C-D+F)

// Input: a*b+c/d
// Output: +*ab/cd 


// Input: (a-b/c)*(a/k-l)
// Output: *-a/bc-/akl