#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void trim(char *str)
{
    int start = 0;
    int size = strlen(str);
    while(str[start] != '\0' && str[start] ==  ' ')
    {
        start++;
    }
    int end = size - 1;
    while(end >= start && str[end] == ' ')
    {
        end--;
    }
    
    int length = end - start + 1;
    for(int i = 0; i < length; i++)
    {
        str[i] = str[start + i];
    }
    str[length] = '\0';
}

int main()
{
    char str[] = {"   Hello World    "};
    trim(str);
    printf("String is %s\n",str);
    printf("size is %lld\n",strlen(str));
    return 0;
}