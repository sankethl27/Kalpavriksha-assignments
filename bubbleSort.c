#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


typedef struct singlyLinkedList
{
    int data;
    struct singlyLinkedList *next;
}node;


node* createNode(int value)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void swap(node *first , node* second)
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
    
    int swapped;
    node *current = head;
    node* tailPointer = NULL;

    do {
        swapped = 0;
        current = head;

        while (current->next != tailPointer) {
            if (current->data > current->next->data) {
                swap(current , current->next);
                swapped = 1;
            }
            current = current->next;
        }
        tailPointer = current;
    } while (swapped);
}
node* createLinkedList()
{
    node* head = NULL;
    node* current = NULL;
    int number;
    char input;
    while(scanf("%d" , &number) == 1)
    {
        if(head == NULL)
        {
            current = createNode(number);
            head = current;
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
    node *head = createLinkedList();
    bubbleSortLinkedList(head);
    printLinkedList(head);
    return 0;
}
