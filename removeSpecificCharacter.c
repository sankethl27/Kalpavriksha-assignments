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
	int j = 0;
	for(int i = 0; i < strlen(string1); i++)
	{
		if(string1[i] != ch)
		{
			result[j++] = string1[i];
		}
	}
	result[j] = '\0';
	printf("%s\n", result);
	return 0;
}