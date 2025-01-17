#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
int size = 0;

typedef struct SinglyLinkedList
{
    int data;
    struct SinglyLinkedList *next;
} singlyLinkedListNode;

void insertAtBeginning(singlyLinkedListNode **head, int element)
{
    singlyLinkedListNode *newNode = (singlyLinkedListNode *)malloc(sizeof(singlyLinkedListNode));
    newNode->data = element;
    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = *head;
        *head = newNode;
    }
    size++;
}

void insertAtEnd(singlyLinkedListNode **head, int element)
{
    singlyLinkedListNode *currentNode = *head;
    singlyLinkedListNode *newNode = (singlyLinkedListNode *)malloc(sizeof(singlyLinkedListNode));
    newNode->data = element;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
    size++;
}

void insertAtPosition(singlyLinkedListNode **head, int element, int position)
{
    if (position < 0 || position > size)
    {
        printf("Invalid Position\n");
        return;
    }

    singlyLinkedListNode *newNode = (singlyLinkedListNode *)malloc(sizeof(singlyLinkedListNode));
    newNode->data = element;

    if (position == 0)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        int currentPosition = 0;
        singlyLinkedListNode *currentNode = *head;
        while (currentPosition < position - 1)
        {
            currentNode = currentNode->next;
            currentPosition++;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
    size++;
}

void displayList(singlyLinkedListNode *head)
{
    singlyLinkedListNode *currentNode = head;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    else
    {
        while (currentNode != NULL)
        {
            printf("%d ", currentNode->data);
            currentNode = currentNode->next;
        }
        printf("\n");
    }
}

void updateAtBeginning(singlyLinkedListNode *head, int newValue)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        head->data = newValue;
    }
}

void updateAtEnd(singlyLinkedListNode *head, int newValue)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        singlyLinkedListNode *currentNode = head;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
        }
        currentNode->data = newValue;
    }
}

void updateAtPosition(singlyLinkedListNode *head,int newValue,int position)
{
    if (position < 0 || position >= size)
    {
        printf("Invalid Position\n");
    }
    else
    {
        singlyLinkedListNode *currentNode = head;
        for (int i = 0; i < position; i++)
        {
            currentNode = currentNode->next;
        }
        currentNode->data = newValue;
    }
}

void deleteAtBeginning(singlyLinkedListNode **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        singlyLinkedListNode *temp = *head;
        *head = (*head)->next;
        free(temp);
        size--;
    }
}

void deleteAtEnd(singlyLinkedListNode **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
    }
    else if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        size--;
    }
    else
    {
        singlyLinkedListNode *currentNode = *head;
        while (currentNode->next->next != NULL)
        {
            currentNode = currentNode->next;
        }
        free(currentNode->next);
        currentNode->next = NULL;
        size--;
    }
}

void deleteAtPosition(singlyLinkedListNode **head, int position)
{
    if (position < 0 || position >= size)
    {
        printf("Invalid Position\n");
    }
    else if (position == 0)
    {
        deleteAtBeginning(head);
    }
    else
    {
        singlyLinkedListNode *currentNode = *head;
        for (int i = 0; i < position - 1; i++)
        {
            currentNode = currentNode->next;
        }
        singlyLinkedListNode *temp = currentNode->next;
        currentNode->next = currentNode->next->next;
        free(temp);
        size--;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    singlyLinkedListNode *head = NULL;
    while (n--)
    {
        int operation;
        scanf("%d", &operation);
        switch (operation)
        {
            case 1:
            {
                int element;
                scanf("%d", &element);
                insertAtEnd(&head, element);
                break;
            }
            case 2:
            {
                int element;
                scanf("%d", &element);
                insertAtBeginning(&head, element);
                break;
            }
            case 3:
            {
                int position, element;
                scanf("%d %d", &position, &element);
                insertAtPosition(&head, element, position - 1);
                break;
            }
            case 4:
            {
                displayList(head);
                break;
            }
            case 5:
            {
                int position, element;
                scanf("%d %d", &position, &element);
                updateAtPosition(head, element, position - 1);
                break;
            }
            case 6:
            {
                deleteAtBeginning(&head);
                break;
            }
            case 7:
            {
                deleteAtEnd(&head);
                break;
            }
            case 8:
            {
                int position;
                scanf("%d", &position);
                deleteAtPosition(&head, position - 1);
                break;
            }
            default:
            {
                printf("Invalid operation\n");
                break;
            }
        }
    }
    return 0;
}
