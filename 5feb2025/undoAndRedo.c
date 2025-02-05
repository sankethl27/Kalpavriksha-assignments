#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack
{
    char ch;
    struct stack *next;
}node;

node *undo = NULL;
node *redo = NULL;

int isEmpty(node *top)
{
    if(top == NULL) return 1;
    return 0;
}

void printString(node *temp)
{
    if(temp == NULL)
    {
        printf("result is : ");
        return;
    }
    printString(temp->next);
    printf("%c",temp->ch);
}
void push(char value)
{
    node *newNode  = malloc(sizeof(node));
    newNode->ch = value;
    newNode->next = undo;
    undo = newNode;
}

void undoFunc()
{
    node *temp = undo;
    undo = undo->next;
    temp->next = redo;
    redo = temp;
}

void redoFunc()
{
    node *temp = redo;
    redo = redo->next;
    temp->next = undo;
    undo = temp;
}

int main()
{
    printf("Enter string\n");
    char string[100];
    fgets(string,100,stdin);
    string[strcspn(string,"\n")] = '\0';
    int size = strlen(string);
    for(int i = 0; i < size; i++)
    {
        push(string[i]);
    }
    printf("Enter no of operations");
    int operations;
    scanf("%d",&operations);
    int choice;
    // scnaf(" ");
    while(operations--)
    {
        printf("1.Undo\n2.redo\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
                    if(isEmpty(undo))
                    {
                        printf("Nothing to Undo\n");
                        break;
                    }
                    undoFunc();
                    printString(undo);
                    printf("\n");
                    break;
            case 2: 
                if(isEmpty(redo))
                {
                    printf("Nothing to redo\n");
                    break;
                }
                redoFunc();
                printString(undo);
                printf("\n");
                break;
        default:printf("Enter valid choice");
            break;
        }
    }

}