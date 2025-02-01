#include <stdio.h>
#include <stdlib.h>

typedef struct singlyLinkedList
{
    int data;
    struct singlyLinkedList *next;
} node;

node *head = NULL;
node *end = NULL;

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
    if (head == NULL)
    {
        head = newNode;
        end = head;
    }
    else
    {
        end->next = newNode;
        end = newNode;
    }
}

void dequeue()
{
    if (head == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }

    node *temp = head;
    head = head->next;
    free(temp);

    if (head == NULL) 
        end = NULL;
}

int peek()
{
    if (head == NULL)
    {
        printf("Queue is Empty\n");
        return -1;
    }
    return head->data;
}

int isEmpty()
{
    return head == NULL;
}

int size()
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void printQueue()
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
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Check if Empty\n");
        printf("5. Get Size\n");
        printf("6. Print Queue\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printf("Front element: %d\n", peek());
            break;
        case 4:
            printf("Queue is %s\n", isEmpty() ? "Empty" : "Not Empty");
            break;
        case 5:
            printf("Queue size: %d\n", size());
            break;
        case 6:
            printQueue();
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
