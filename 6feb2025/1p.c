#include<stdio.h>
#include<stdlib.h>

typedef struct linkedList
{
    int data;
    struct linkedList *next;
}node;

node *createNode(int data)
{
    node* newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode ->next = NULL;
    return newNode;
}

void printList(node *head)
{
    node *temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

node* takeInput()
{
    node* head = NULL;
    node* current = NULL;
    int number;
    while(scanf("%d",&number) == 1)
    {
        node *newNode = createNode(number);
        if(head == NULL)
        {
            head = newNode;
            current = head;
        }
        else
        {
            current->next = createNode(number);
            current = current->next;
        }
        if(getchar() == '\n')
        {
            break;
        }
    }
    return head;
}

int main()
{
    node *head = takeInput();
    printList(head);
    return 0;
}