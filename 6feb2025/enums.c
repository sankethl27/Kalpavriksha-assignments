#include<stdio.h>
#include<stdlib.h>

enum Status{BeingProcessed, AwaitingReply, Reopen};

typedef struct LinkedList
{
    int id;
    enum Status status;
    struct LinkedList *next;
}node;


node* createNode(int id , enum Status status)
{
    node* newNode = malloc(sizeof(node));
    newNode -> id = id;
    newNode -> status = status;
    newNode->next = NULL;
    return newNode;
}

void printLinkedList(node *head)
{
    printf("Test print\n");
    node* temp = head;
    while(temp != NULL)
    {
        if(temp->status == BeingProcessed)
        {
            printf("status is %d ",temp->status);
            temp->status = Reopen;
            printf("status is %d\n",temp->status);
        }
        else 
        {
            printf("status is %d ",temp->status);
        }
        temp = temp->next;
    }
}
int main()
{
    node *head = createNode(1,BeingProcessed);
    node *current = head;
    current->next = createNode(2,BeingProcessed);
    current = current->next;
    current->next = createNode(3,Reopen);
    printLinkedList(head);
    printLinkedList(head);
    return 0;
}