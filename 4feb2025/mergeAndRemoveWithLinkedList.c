#include<stdio.h>
#include<stdlib.h>


typedef struct Node
{
    int data;
    struct Node *next;
}node;

node* createNode(int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printLinkedList(node *head)
{
    node *current = head->next;
    node *previous = head;
    if(head != NULL)
    {
        printf("%d ",head->data);
    }
    while (current != NULL)
    {
        if(current->data != previous->data)
        {
            printf("%d ", current->data);
        }
        previous = current;
        current = current->next;
        
    }
    printf("\n");
}

node *getMiddle(node *head)
{
    node *slow = head;
    node *fast = head->next;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* mergeSort(node *head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    node *left = head;
    node *right = getMiddle(head);
    node *temp = right->next;
    right->next = NULL;
    right = temp;
    left = mergeSort(left);
    right = mergeSort(right);
    node *dummy = createNode(-1);
    node *tail = dummy;

    while(left != NULL && right != NULL)
    {
        if(left->data < right->data)
        {
            tail->next = left;
            left = left->next;
        }
        else
        {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;

    }
    while(left != NULL)
    {
        tail->next = left;
        left = left->next;
        tail = tail->next;
    }
    while(right != NULL)
    {
        tail->next = right;
        right = right->next;
        tail = tail->next;
    }
    return dummy->next;
}

int main()
{
    int n = 6;
    node *head = NULL;
    node *current = NULL;
    while(n--)
    {
        int element;
        scanf("%d",&element);
        if(head == NULL)
        {
            current = createNode(element);
            head = current;
        }
        else
        {
            current->next = createNode(element);
            current = current->next;
        }
    }
    head = mergeSort(head);
    printLinkedList(head);
    return 0;
}