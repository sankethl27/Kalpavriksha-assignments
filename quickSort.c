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

node *partition(node *head, node **left, node **right)
{
    node *pivot = head;
    node *current = head->next;

    *left = NULL;
    *right = NULL;

    while (current != NULL)
    {
        node *next = current->next;
        if (current->data < pivot->data)
        {
            current->next = *left;
            *left = current;
        }
        else
        {
            current->next = *right;
            *right = current;
        }
        current = next;
    }

    return pivot;
}

node *quickSortLinkedList(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    node *left, *right;
    node *pivot = partition(head, &left, &right);

    left = quickSortLinkedList(left);
    right = quickSortLinkedList(right);

    node *current = left;
    if (current == NULL)
    {
        pivot->next = right;
        return pivot;
    }

    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = pivot;
    pivot->next = right;

    return left;
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

int findSmallestFrequency(node *head)
{
    if (head == NULL)
        return 0;

    int smallest = head->data;
    int count = 1;
    node *current = head->next;

    while (current != NULL)
    {
        if (current->data == smallest)
        {
            count++;
        }
        else
        {
            break; 
        }
        current = current->next;
    }

    return count;
}

int main()
{

    node *head = createLinkedList();

    head = quickSortLinkedList(head);
    printf("Sorted elements: \n");
    printLinkedList(head);

    int frequency = findSmallestFrequency(head);
    printf("Frequency of smallest element: %d\n", frequency);

    return 0;
}
