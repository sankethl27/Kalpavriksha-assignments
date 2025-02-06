#include<stdio.h>
#include<stdlib.h>
#include<string.h> 


typedef struct list
{
    char number[10];
    int hour;
    int min;
    struct list *next;
}node;


node *createNode(char number[],int hour,int min)
{
    node *newNode = malloc(sizeof(node));
    strcpy(newNode->number,number);
    newNode->hour = hour;
    newNode->min = min;
    newNode->next = NULL;
    return newNode;
}

void printList(node *head)
{
    node *temp = head;
    while(temp != NULL)
    {
        printf("%s %d %d\n",temp->number,temp->hour,temp->min);
        temp = temp->next;
    }
    printf("\n");
}

node *getMiddle(node *head)
{
    node* slow = head;
    node* fast = head->next;
    while(fast != NULL && fast -> next != NULL)
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
    node* temp = right->next;
    right->next = NULL;
    right = temp;
    left = mergeSort(left);
    right = mergeSort(right);
    node *dummy = createNode(" ",0,0);
    node *tail = dummy;
    while(left != NULL && right != NULL)
    {
        if(left->hour < right->hour)
        {
            tail->next = left;
            left = left->next;
        }
        else if(left->hour > right->hour)
        {
            tail ->next = right;
            right = right -> next;
        }
        else{
            if(left->min < right->min)
            {
                tail->next = left;
                left = left->next;
            }
            else
            {
                tail ->next = right;
                right = right -> next;
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
    char in[100];
    char input[100];
    int size = 0;
    fgets(in,100,stdin);
    in[strcspn(in,"\n")] = '\0';
    for(int i = 0 ; i < strlen(in); i++)
    {
        if(in[i] != ' ')
        {
            input[size++] = in[i];
        }
    }
    printf("%s\n",input);
    node* head = NULL;
    node *current = NULL;
    char *token = strtok(input,"->");
    while(token != NULL)
    {    
        if(strcmp(token,"NULL") == 0)
        {
            break;
        }
        char number[10];
        int hour;
        int min;
        sscanf(token,"(%[^,],%d:%d)",number,&hour,&min);
        node* newNode = createNode(number,hour,min);
        if(head == NULL)
        {
            head = newNode;
            current = newNode;
        }
        else
        {
            current->next = newNode;
            current = current -> next;
        }
        token = strtok(NULL,"->");
    }
    head = mergeSort(head);
    printList(head);
    return 0;
}

//(AA101, 18:30) -> (BA205, 15:45) -> (UA303, 20:15) -> NULL
