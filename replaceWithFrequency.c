#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{	
	int frequency = 0;
	char* string = (char*) malloc(100 * sizeof(char));
	char* result = (char*) malloc(100 * sizeof(char));
	scanf("%[^\n]",string);
	getchar();
	int size = strlen(string);
	int iterator = 0;
	char current;
	for(int i = 0; i < size;i++)
	{	
		current = string[i];
		frequency = 0;
		while(string[i] == current)
		{
			frequency++;
			i++;
		}
		i--;
		result[iterator++] = current;
		result[iterator++] = frequency + '0';
	}
	result[iterator] = '\0';
	printf("%s",result);
	return 0;
}