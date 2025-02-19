#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isValid(char ch)
{
    if((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <='f') || (ch >= 'A' && ch <= 'F'))
    {
        return 1;
    }
    return 0;
}
int validateIpv6(char *string)
{
    int group = 0;
    int iterator = 0;
    while(iterator < strlen(string) && group < 8)
    {
        char first = string[iterator++];
        char second = string[iterator++];
        char third = string[iterator++];
        char fourth = string[iterator++];
        char colon = string[iterator++];
        if(colon != ':') break;
        if(isValid(first) && isValid(second) && isValid(third)  && isValid(fourth))
        {
            group++;
        }
        else 
        {
            break;
        }
    }
    if(group != 7)
    {
        return 0;
    }
   return 1;
}

int validateIpv4(char *string)
{
    printf("In IPV4\n");
    int first = -1;
    int second = -1;
    int third = -1;
    int fourth = -1; 
    sscanf(string,"%d.%d.%d.%d",&first,&second,&third,&fourth);
    if(first >= 0 && first<=255 && second >= 0 && second <=255 && third >= 0 && third<=255 && fourth >= 0 && fourth<=255) 
    {
        return 1;
    }
    return 0;
}
int checkIpv4(char *string)
{
    if(strlen(string) > 15)
    {
        return -1;
    } 
}
int main()
{
    printf("Enter address\n");
    char *string = malloc(100 * sizeof(char));
    scanf("%s",string);
    int valid = 0;
    if(checkIpv4(string) == -1)
    {
        if(validateIpv6(string))
        {
            valid = 1;
            printf("Valid IPV6 adress\n");
        }
        
    }
    else
    {
        if(validateIpv4(string))
        {
            valid = 1;
            printf("Valid IPV4 address\n");
        }
    }
    if(!valid)
    {
        printf("Neither\n");
    }
    return 0;
}