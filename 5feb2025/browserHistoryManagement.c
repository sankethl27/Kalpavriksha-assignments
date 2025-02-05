#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack
{
    char string[30];
    struct stack *next;
}node;

node *top = NULL;

// Push 
void addAWebsite()
{
    printf("Enter URL :\n");
    char website[40];
    fgets(website,40,stdin);
    website[strcspn(website,"\n")] = '\0';
    node *newNode = malloc(sizeof(node));
    strcpy(newNode->string,website);
    newNode->next = top;
    top = newNode;
    
}

//Print all
void viewHistory()
{
    if(top == NULL)
    {
        printf("Histoty is Empty\n");
        return;
    }
    node *temp = top;
    while(temp != NULL)
    {
        printf("%s\n",temp->string);
        temp = temp->next;
    }
}

//Edit URL
void editUrl()
{
    char string[40];
    printf("Enter url u want to modify\n");
    fgets(string,40,stdin);
    string[strcspn(string,"\n")] = '\0';
    node *temp = top;
    int found = 0;
    while(temp != NULL)
    {
        if(strcmp(temp->string,string) == 0)
        {
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if(found)
    {
        char newString[40];
        printf("Enter new URL\n");
        fgets(newString,40,stdin);
        newString[strcspn(newString,"\n")] = '\0'; 
        strcpy(temp->string,newString);
    }
    else
    {
        printf("URL NOT FOUND\n");
    }

}


//POP
void removeRecentUrl()
{
    if(top == NULL)
    {
        printf("Empty stack");
        return;
    }
    node *temp = top;
    top = top->next;
    printf("Deleted URL is %s\n",temp->string);
    free(temp);
}

int main()
{
    int n;
    printf("Enter number of operations\n");
    scanf("%d",&n);
    int choice;
    while(n--)
    {
        printf("1.Add a website\n2.view History\n3.Edit a url\n4.Remopve recent website\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                // scanf(" ");
                addAWebsite();
                break;
            case 2:
                viewHistory();
                break;
            case 3:
                // scanf(" ");
                editUrl();
                break;
            case 4:
                removeRecentUrl();
                break;
        }
    }
}