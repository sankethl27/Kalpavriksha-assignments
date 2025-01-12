#include<stdio.h>
#include<stdlib.h>

int main()
{
	char input[101];
	scanf("%[^\n]",input);
	char **words = (char**) malloc(100 * sizeof(char*));
	char* word = (char*) malloc(100 * sizeof(char));
	int iterator = 0;
	int column = 0;
	int row = 0;
	while(input[iterator] == ' ')
	{
		iterator++;
	}

	while(input[iterator] != '\0')
	{	
		if(input[iterator] == ' ')
		{	
			word[column] = '\0';
			words[row++] = word;
			column = 0;
			word = (char*) malloc(100 * sizeof(char));
			while(input[iterator] == ' ')
			{
				iterator++;
			}
		}
		else
		{	
			word[column++] = input[iterator];
			iterator++;
		}	
	}
	if(column != 0)
	{	
		word[column] = '\0';
		words[row++] = word;
	}
	printf("No of words is : %d\n",row);
}