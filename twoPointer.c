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

void findPairWithSum(node *head, int target)
{
    if (head == NULL || head->next == NULL)
    {
        printf("No pair found.\n");
        return;
    }

    node *start = head;
    node *end = head;

    while (end->next != NULL)
        end = end->next;

    while (start != end)
    {
        int sum = start->data + end->data;
        if (sum == target)
        {
            printf("Pair found: (%d, %d)\n", start->data, end->data);
            return;
        }
        else if (sum < target)
        {
            start = start->next;
        }
        else
        {
            node *temp = head;
            while (temp->next != end)
                temp = temp->next;
            end = temp;
        }
    }

    printf("No pair found.\n");
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
int main()
{
    node *head = createLinkedList();

    printf("Enter elements of the sorted linked list : ");
    int value;

    printf("Enter the target sum: ");
    int target;
    scanf("%d", &target);

    printf("Linked List: ");
    printLinkedList(head);

    findPairWithSum(head, target);

    return 0;
}
