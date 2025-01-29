#include <stdio.h>
#include <stdlib.h>

typedef struct singlyLinkedList
{
    int data;
    struct singlyLinkedList *next;
} node;

node *createNode(int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void swap(node *first, node *second)
{
    int temp = first->data;
    first->data = second->data;
    second->data = temp;
}

void printLinkedList(node *head)
{
    node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

node* insertionSortLinkedList(node *head)
{
    node* current = head->next;
    node* dummy = (node*)createNode(-1);
    dummy->next = head;
    node *previous = head;
    while(current != NULL)
    {
        node* temp = dummy;
        if(previous->data <= current->data)
        {
            previous = current;
            current = current->next;
        }
        else
        {
            node* temp = dummy; 
            while(temp->next->data <  current->data)
            {
                temp = temp->next;
            }
            previous->next = current->next;
            current->next = temp->next;
            temp->next = current;
            current = previous->next;   
        } 
    }
    return dummy->next;
}

node *createLinkedList()
{
    node *head = NULL;
    node *current = NULL;
    int number;

    while (scanf("%d", &number) == 1)
    {
        if (head == NULL)
        {
            current = createNode(number);
            head = current;
        }
        else
        {
            current->next = createNode(number);
            current = current->next;
        }
        if (getchar() == '\n')
        {
            break;
        }
    }
    return head;
}

int main()
{
    node *head = createLinkedList();
    head = insertionSortLinkedList(head);
    printf("Ascending order of  elements are: ");
    printLinkedList(head);
    return 0;
}
