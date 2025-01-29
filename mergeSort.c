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

node *mergeSortedLists(node *a, node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    if (a->data >= b->data)
    {
        a->next = mergeSortedLists(a->next, b);
        return a;
    }
    else
    {
        b->next = mergeSortedLists(a, b->next);
        return b;
    }
}

void splitLinkedList(node *source, node **front, node **back)
{
    node *slow = source;
    node *fast = source->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

void mergeSortLinkedList(node **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return;

    node *head1 = *head;
    node *front;
    node *back;

    splitLinkedList(head1, &front, &back);

    mergeSortLinkedList(&front);
    mergeSortLinkedList(&back);

    *head = mergeSortedLists(front, back);
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

    mergeSortLinkedList(&head);
    printf("Descending order of  elements are: \n");
    printLinkedList(head);
    return 0;
}
