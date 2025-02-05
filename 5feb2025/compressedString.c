#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack
{
    char string[100];
    struct stack *next;
}node;

node *top = NULL;

void push(char string[])
{
    node* newNode = malloc(sizeof(node));
    strcpy(newNode->string,string);
    newNode->next = top;
    top = newNode;
}

char *pop()
{
    char *result = malloc(100 * sizeof(char));
    strcpy(result,top->string);
    node *temp = top;
    top = top->next;
    free(temp);
    return result;
}

void reverse(char *s , int l , int r)
{
    if(l >= r) return;
    char temp = s[l];
    s[l] = s[r];
    s[r] = temp;
    reverse(s,l+1,r-1);
}

void printResult(node *temp)
{
    if(temp == NULL)
    {
        return;
    }
    printResult(temp->next);
    printf("%s",temp->string);
}
void compute(char string[],int size)
{
    
    for(int i = 0; i < size; i++)
    {
        if(string[i] != ']')
        {
            char str[2] = "\0";
            str[0] = string[i];
            push(str);
        }
        else
        {
            char result[1000] = "\0";
            char str[100] = "\0";
            char topString[100];
            strcpy(topString,pop());
            while(strcmp(topString,"[") != 0)
            {
                strcat(str,topString);
                strcpy(topString,pop());

            }
            char num[2] =  "\0";
            strcpy(num,pop());
            int number = num[0] - '0';
            reverse(str,0,strlen(str)-1);
            while(number--)
            {
                strcat(result,str);
            }
            printf("string is %s : \n",result);
            push(result);
        }
    }
    printf("result is :\n");
    printResult(top);
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
