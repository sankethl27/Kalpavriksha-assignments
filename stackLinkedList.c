#include <stdio.h>
#include <stdlib.h>

typedef struct singlyLinkedList
{
    int data;
    struct singlyLinkedList *next;
} node;


node *head = NULL;
node *current = NULL;

node *createNode(int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


void enqueue(int value)
{
    node *newNode = createNode(value);
    if(head == NULL)
    {
        head = newNode;
        current = head;
    }
    else 
    {
        current->next = newNode;
        current = current->next;
    }   
}


void pop()
{
    if(head == NULL)
    {
        printf("underFlow");
        return;
    }

    if(head == current)
    {
        free(head);
        head = current = NULL;
        return;
    }
    node* temp = head;
    while(temp->next != current)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    free(current);
    current = temp;
}

int peek()
{
    if(head == NULL)
    {
        printf("Stack is Empty");
        return -1;
    }
    return current->data;
}

int isEmpty()
{
    return head == NULL;
}

int size()
{
    node *temp = head;
    int count = 0;
    while(temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
void printLinkedList()
{
    node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


int main()
{
    int choice, value;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if Empty\n");
        printf("5. Get Size\n");
        printf("6. Print Stack\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("Top element: %d\n", peek());
            break;
        case 4:
            printf("Stack is %s\n", isEmpty() ? "Empty" : "Not Empty");
            break;
        case 5:
            printf("Stack size: %d\n", size());
            break;
        case 6:
            printLinkedList();
            break;
        case 7:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
