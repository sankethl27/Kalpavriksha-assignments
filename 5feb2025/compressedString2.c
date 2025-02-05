#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct stack
{
    char ch;
    struct stack *next;
}node;

node *top1 = NULL;
node *top2 = NULL;

void push(node **top ,char ch)
{
    node* newNode = malloc(sizeof(node));
    newNode->ch = ch;
    newNode->next = *top;
    *top = newNode;
}

char pop(node **top)
{
    if(*top == NULL) return '\0';
    node *temp = *top;
    char ch = temp->ch;
    *top = temp->next;
    free(temp);
    return ch;
}
int reverseNumber(int num)
{
    int rev = 0;
    while(num > 0)
    {
        rev = rev * 10 + num % 10;
        num = num /10;
    }
    return rev;
}
void rep(int number)
{
    for(int i = 0; i < number; i++)
    {
        node* temp = top2;
        while(temp != NULL)
        {
            push(&top1,temp->ch);
            temp = temp->next;
        }
    }
    node* temp = top2;
    while(temp != NULL)
    {
        node * prev = temp;
        temp = temp->next;
        free(prev);
    }
    top2 = NULL;

}
void printResult(node *temp)
{
    if(temp == NULL)
    {
        return;
    }
    printResult(temp->next);
    printf("%c",temp->ch);
}

void compute(char string[],int size)
{
    
    for(int i = 0; i < size; i++)
    {
        if(string[i] != ']')
        {
            push(&top1,string[i]);
        }
        else
        {
            char topChar = pop(&top1);
            while(topChar != '[')
            {
                push(&top2 , topChar);
                topChar = pop(&top1);

            }
            int number = 0;
            while(top1 != NULL && isdigit(top1->ch))
            {
                topChar = pop(&top1);
                number = number*10 + topChar - '0';  
            }
            number = reverseNumber(number);
            rep(number);
        }
    }
    printResult(top1);
}

int main()
{
    char string[100];
    fgets(string,100,stdin);
    string[strcspn(string,"\n")]='\0';
    int size = strlen(string);
    compute(string,size);
    return 0;
}