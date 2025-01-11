#include<stdio.h>
#include<stdlib.h>

int main()
{
	char input[101];
	scanf("%[^\n]",input);
	char **words = (char**) malloc(100 * sizeof(char*));
	char* word = (char*) malloc(100 * sizeof(char));
	int i = 0;
	int column = 0;
	int row = 0;
	while(input[i] == ' ')
	{
		i++;
	}

	while(input[i] != '\0')
	{	
		if(input[i] == ' ')
		{	
			word[column] = '\0';
			words[row++] = word;
			column = 0;
			word = (char*) malloc(100 * sizeof(char));
			while(input[i] == ' ')
			{
				i++;
			}
		}
		else
		{	
			word[column++] = input[i];
			i++;
		}	
	}
	if(column != 0)
	{	
		word[column] = '\0';
		words[row++] = word;
	}
	printf("No of words is : %d\n",row);
}