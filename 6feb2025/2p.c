#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char input[100];
    fgets(input,100,stdin);
    input[strcspn(input,"\n")] = '\0';
    char *token = strtok(input,",");
    while(token !=  NULL)
    {
        int hour;
        int min;
        char str[10];
        int am = 0,pm = 0;
        sscanf(token,"%d:%d %s",&hour,&min,str);
        if(strcmp(str,"am") == 0)
        {
            am = 1;
        }
        else pm = 1;
        if(am == 1)
        {
            if(hour == 12)
            {
                printf("%d:%d am -> %02d:%02d \n",hour,min,0,min);
            }
            else printf("%d:%d am -> %d:%d \n",hour,min,hour,min);
        }
        else
        {
            if(hour == 12)
            {
                printf("%d:%d pm -> %d:%d \n",hour,min,hour,min);
            }
            else printf("%d:%d pm -> %d:%d \n",hour,min,hour+12,min);
        }
        token = strtok(NULL,",");
    }
    return 0;
}


//10:30 am, 2:45 pm, 6:10 am, 12:00 am, 12:30 pm