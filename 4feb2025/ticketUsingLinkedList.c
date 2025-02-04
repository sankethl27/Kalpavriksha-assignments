#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Queue
{
    char movie[20];
    int screen;
    int seat;
    int amount;
    int data;
    char status[10];
    struct Queue *next;
} node;

node *bookedFront = NULL;
node* bookedEnd = NULL;
node* approvedFront = NULL;
node* approvedEnd = NULL;

void printTickets(node* f , node* e)
{
    if(f == NULL)
    {
        printf("No tickets");
        return;
    }
    while(f)
    {
        printf("Movie name  :%s\n",f->movie);
        printf("Screen Number  :%d\n",f->screen);
        printf("Seat Number :%d\n",f->seat);
        printf("Amount  :%d\n",f->amount);
        printf("Status  :%s\n",f->status);
        if(f == e) break;
        f = f->next;
    }
}

void bookTickets()
{
    int value;
    node *newNode = (node*)malloc(sizeof(node));
    getchar();
    printf("Enter movie name\n");
    fgets(newNode->movie,20,stdin);
    newNode->movie[strcspn(newNode->movie,"\n")] = '\0';
    printf("Enter seat number\n");
    scanf("%d",&newNode->seat);
    printf("Enter screen number\n");
    scanf("%d",&newNode->screen);
    printf("Enter Amount\n");
    scanf("%d",&newNode->amount);
    strcpy(newNode->status,"Pending");
    newNode->next = NULL;
    if(bookedFront == NULL)
    {
        bookedFront = bookedEnd = newNode;
    }
    else
    {
        bookedEnd->next = newNode;
        bookedEnd = newNode;
    }
}

void approveTickets()
{
    if(bookedFront == NULL)
    {
        printf("NO tickets to approve");
        return;
    }
    node *temp  = bookedFront;
    bookedFront = bookedFront->next;
    temp->next = NULL;
    strcpy(temp->status,"Approved");
    if(approvedFront == NULL)
    {
        approvedFront = approvedEnd = temp;
    }
    else 
    {
        approvedEnd->next = temp;
        approvedEnd = temp;
    }
    if(bookedFront == NULL)
    {
        bookedEnd = NULL;
    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("Enter your choice\n1.Book Ticket\n2.Approve Ticket\n3.Print Booked\n4.Print Approved(Enter 0 to exit)\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: bookTickets();
            break;

            case 2 : approveTickets();
            break;
            
            case 3 : printTickets(bookedFront,bookedEnd);
            break;

            case 4 : printTickets(approvedFront,approvedEnd);
            break;
            default : return 0;
        }
    }
    return 0;
}