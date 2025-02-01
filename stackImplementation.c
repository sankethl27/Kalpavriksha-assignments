#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
int top = -1;

int pop(int *stack)
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return -1; 
    }
    int poppedElement = stack[top];
    top--;
    return poppedElement;
}

void push(int *stack, int value)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    top++;
    stack[top] = value;
}

int size()
{
    return top + 1;
}

int peek(int *stack)
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

int main()
{
    int stack[MAX_SIZE];
    int choice, value;

    while (1)
    {
        printf("\nStack Operations:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Size\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(stack, value);
            break;
        case 2:
            value = pop(stack);
            if (value != -1)
                printf("Popped element: %d\n", value);
            break;
        case 3:
            value = peek(stack);
            if (value != -1)
                printf("Top element: %d\n", value);
            break;
        case 4:
            printf("Stack size: %d\n", size());
            break;
        case 5:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice, try again.\n");
        }
    }
}
