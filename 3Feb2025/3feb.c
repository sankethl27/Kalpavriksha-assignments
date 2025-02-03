#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Ticket
{
    char movie[20];
    int screen;
    int seat;
    int amount;
}ticket;


int bFront = 0;
int bEnd = -1;
int aFront = 0;
int aEnd = -1;

int main()
{
    ticket booked[100];
    ticket approved[100];
    int choice;
    while(1)
    {
        printf("Enter your choice(enter 0 to exit)\n");
        scanf(" %d",&choice);
        if(choice == 0)
        {
            break;
        }
        else if(choice == 1)
        {
            bEnd++;
            printf("Enter Movie Name\n");
            scanf(" %s", booked[bEnd].movie);
            printf("Enter Screen Number\n");
            scanf("%d",&booked[bEnd].screen);
            printf("Enter seat number\n");
            scanf("%d",&booked[bEnd].seat);
            printf("Enter amount");
            scanf("%d",&booked[bEnd].amount);
        }
        else if(choice == 2)
        {
            int n;
            printf("Enter number of tickets to approve");
            scanf("%d",&n);
            n += bFront;
            int i = bFront;
            if(n-1 > bEnd)
            {
                printf("No tickets to approve");
                continue;
            }
            for(; i < n && i <= bEnd; i++)
            {
                aEnd++;
                strcpy(approved[aEnd].movie,booked[bFront].movie);
                approved[aEnd].screen =   booked[bFront].screen;
                approved[aEnd].seat = booked[bFront].seat;
                approved[aEnd].amount = booked[bFront].amount;
                
                bFront++;
                if(aFront == -1)
                {
                    aFront = 0;
                }
            }
        }
        else if(choice == 3)
        {
            for(int i = bFront; i <= bEnd; i++)
            {
                printf("Movie : %s,",booked[i].movie);
                printf("Screen Number : %d ",booked[i].screen);
                printf("Seat Number : %d ",booked[i].seat);
                printf("Amount : %d",booked[i].amount);
                printf("status : Pending");
                printf("\n");
            }
        }
        else if(choice == 4)
        {
            if(aEnd == -1)
            {
                printf("No tickets to approve");
                continue;
            }
            else
            {
                for(int i = 0; i <= aEnd; i++)
                {
                    printf("Movie : %s ",approved[i].movie);
                    printf("Screen Number : %d ",approved[i].screen);
                    printf("Seat Number : %d ",approved[i].seat);
                    printf("Amount :  %d",approved[i].amount);
                    printf("status: Approved");
                    printf("\n");
                }
            }
        }
        else
        {
            printf("Enter valid choice");
        }
    }
    return 0;
}
