#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100

typedef struct Student
{
    char name[MAX_SIZE];
    int roll;
    int marks;
    struct Student *next;
}node;

node *createNode(char name[],int marks, int roll)
{
    node *newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->name,name);
    newNode->roll = roll;
    newNode->marks = marks;
    return newNode;
}

void printLinkedList(node *head)
{
    node* current = head;
    while(current != NULL)
    {
        printf("%s ",current->name);
        printf("%d ",current->marks);
        printf("%d ",current->roll);
        current = current->next;
        printf("\n");
    }
}

node* getMiddle(node *head)
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

    node *dummy = createNode(" ",-1,-1);
    node *tail = dummy;

    while(left != NULL && right != NULL)
    {
        if(left->marks > right->marks)
        {
            tail->next = left;
            left = left->next;
        }
        else if(right->marks > left->marks)
        {
            tail->next = right;
            right = right->next;
        }
        else
        {
            if(left->roll < right->roll)
            {
                tail->next = left;
                left = left->next;
            }
            else
            {
                tail->next = right;
                right = right->next;
            }
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
    node *head = NULL;
    head = createNode("Alice",85,103);
    node* current = head;
    current->next = createNode("Bob",90,101);
    current = current->next;
    current->next = createNode("Charlie",85,102);
    current = current->next;
    current->next = createNode("david",95,104);
    current = current->next;
    printLinkedList(head);
    head = mergeSort(head);
    printf("Sorted order is : \n");
    printLinkedList(head);
    return 0;
}