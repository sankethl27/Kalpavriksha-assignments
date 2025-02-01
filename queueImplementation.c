#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int queue[SIZE];
int front = -1, end = -1;

void enqueue(int value)
{
    if (end == SIZE - 1)
    {
        printf("Overflow: Queue is full\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++end] = value;
}

int dequeue()
{
    if (front == -1 || front > end)
    {
        printf("Underflow: Queue is empty\n");
        return -1;
    }
    int removed = queue[front++];
    if (front > end)
        front = end = -1;
    return removed;
}

int peek()
{
    if (front == -1 || front > end)
    {
        printf("Queue is empty\n");
        return -1;
    }
    return queue[front];
}

void printQueue()
{
    if (front == -1 || front > end)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= end; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
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
            value = peek();
            if (value != -1)
                printf("Front element: %d\n", value);
            break;
        case 4:
            printQueue();
            break;
        case 5:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
