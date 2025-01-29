#include <stdio.h>
#include <string.h>
#include <math.h>
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
}
void bubbleSortLinkedList(node *head)
{
    node *current = head;
    node *tail;
    int size = 0;
    if(head == NULL)
    {
        printf("List is empty");
    }
    while(current->next != NULL)
    {
        size++;
        current = current->next;
    }
    tail = current;
    current = head;
    for(int i = 0; i < size; i++)
    {
        while(current != tail)
        {
            if(current->data > current->next->data)
            {
                swap(current, current->next);
            }
            current = current->next;
        }
        tail = current;
        current = head;
    }
}

node *createLinkedList()
{
    node *head = NULL;
    node *current = NULL;
    int number;
    char input;
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
    bubbleSortLinkedList(head);
    printLinkedList(head);
    return 0;
}
