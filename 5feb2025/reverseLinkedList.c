#include<stdio.h>
#include<stdlib.h>


typedef struct Node
{
    int data;
    struct Node *next;
}node;

node* createNode(int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printLinkedList(node *head)
{
    node *current = head->next;
    node *previous = head;
    if(head != NULL)
    {
        printf("%d ",head->data);
    }
    while (current != NULL)
    {
        if(current->data != previous->data)
        {
            printf("%d ", current->data);
        }
        previous = current;
        current = current->next;
        
    }
    printf("\n");
}

node* reverseList(node* head) {
    node* previous = NULL;
    node* current = head;
    node* second;
    while(current != NULL)
    {
        second = current->next;  
        current->next = previous;
        previous = current;
        current = second;
    }
    return previous;
}

int main()
{
    int n = 5;
    node *head = NULL;
    node *current = NULL;
    while(n--)
    {
        int element;
        scanf("%d",&element);
        if(head == NULL)
        {
            current = createNode(element);
            head = current;
        }
        else
        {
            current->next = createNode(element);
            current = current->next;
        }
    }
    head = reverseList(head);
    printLinkedList(head);
    return 0;
}