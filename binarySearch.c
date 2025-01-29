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

void sortLinkedList(node *head)
{
    if (head == NULL)
        return;

    node *current = head;
    while (current != NULL)
    {
        node *minNode = current;
        node *nextNode = current->next;

        while (nextNode != NULL)
        {
            if (nextNode->data < minNode->data)
            {
                minNode = nextNode;
            }
            nextNode = nextNode->next;
        }

        if (minNode != current)
        {
            swap(current, minNode);
        }

        current = current->next;
    }
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

node *getMiddle(node *start, node *end)
{
    node *slow = start;
    node *fast = start;
    while (fast != end && fast->next != end)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int binarySearch(node *head, int value)
{
    node *start = head;
    node *end = NULL; 

    while (start != end)
    {
        node *mid = getMiddle(start, end);

        if (mid->data == value)
            return 1;
        else if (mid->data < value)
            start = mid->next;
        else
            end = mid;
    }

    return -1;
}

int main()
{
    node *head = createLinkedList();
    int value;
    printf("Linked List: ");
    printLinkedList(head);
    sortLinkedList(head);
    printf("Enter value to search : ");
    scanf("%d", &value);
    int binaryPosition = binarySearch(head, value);
    if (binaryPosition != -1)
        printf("Value found \n");
    else
        printf("Value not found\n");

    return 0;
}
