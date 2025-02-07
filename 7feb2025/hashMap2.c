#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct HashMap
{
    char name[105];
    long long number;
}HashMap;

typedef struct linkedList
{
    HashMap map;
    struct linkedList *next;
}node;

node *createNode(char name[],long long number)
{
    node *newNode = malloc(sizeof(HashMap));
    strcpy(newNode->map.name,name);
    newNode->map.number = number;
    return newNode;
}

void printLinkedList(node* head)
{
    node *temp = head;
    while(temp != NULL)
    {
        printf("%s %lld\n",temp->map.name,temp->map.number);
        temp = temp->next;
    }
}

void add(node **head , char name[],long long number)
{
    node *newNode = malloc(sizeof(node));
    strcpy(newNode->map.name,name);
    newNode->map.number = number;
    newNode->next = *head;
    *head = newNode;
}

int search(node *head,char name[])
{
    node *temp = head;
    while(temp != NULL)
    {
        if(strcmp(temp->map.name,name)==0)
        {
            printf("%lld\n",temp->map.number);
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int delete(node **head,char name[])
{
    node *current = *head;
    node *previous = NULL;
    while(current != NULL)
    {
        if(strcmp(current->map.name,name)==0)
        {
            break;
        }
        previous = current;
        current = current->next;
    }
    if(current == NULL)
    {
        return 0;
    }
    if(*head == current)
    {
        *head = current->next;
    }
    else
    {
       previous->next = current->next;
    }
    free(current);
    return 1;
}
int main() {
    int n;
    scanf("%d",&n);
    scanf("\n");
    char input[100];
    char operation[100];
    char name[100];
    long long number;
    node *head = NULL;
    for(int i = 0;i < n; i++)
    {
        fgets(input,100,stdin);
        input[strcspn(input,"\n")] = '\0';
        sscanf(input ,"%[^(](",operation);
        if(strcmp(operation,"add") == 0)
        {

            sscanf(input," add(\"%[^\"]\", %lld)",name,&number);
            add(&head,name,number);
            printf("Success\n");
        }
        else if(strcmp(operation,"search") == 0)
        {
             sscanf(input," search(\"%[^\"]\")",name);
            if(!search(head,name))
            {
                printf("Not Found\n");
            }

        }
        else
        {
             sscanf(input," delete(\"%[^\"]\")",name);
            if(delete(&head, name) == 1)
            {
                printf("Success\n");
            }
            else
            {
                printf("Not Found\n");
            }
        }

    }
    return 0;
}