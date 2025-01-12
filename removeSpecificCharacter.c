#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{	
	char* string1 = (char*)malloc(100 * sizeof(char));
	char* result = (char*)malloc(100 * sizeof(char));
	char ch;
	scanf("%[^\n]",string1);
	scanf("\n");
	scanf("%c",&ch);
	int resultIterator = 0;
	for(int iterator = 0; iterator < strlen(string1); iterator++)
	{
		if(string1[iterator] != ch)
		{
			result[resultIterator++] = string1[iterator];
		}
	}
	result[resultIterator] = '\0';
	printf("%s\n", result);
	return 0;
}