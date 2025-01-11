#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{	
	char* input = (char*)malloc(100 * sizeof(char));
	scanf("%[^\n]",input);
	getchar();
	char** words = (char**)malloc(100 * sizeof(char*));
	char* word = strtok(input," ");
	char* longestWord = (char*)malloc(100 * sizeof(char));
	int row = 0;
	int result = 0;
	if(word == NULL)
	{
		printf("");
		return 0;
	}
	if(word != NULL)
	{
		while(word != NULL)
		{	
			words[row++] = word;
			word = strtok(NULL," ");
		}
		longestWord = words[0];
		for(int i = 0; i < row; i++)
		{
			if(strlen(words[i]) >= strlen(longestWord))
			{
				longestWord = words[i];
			}
		}
		printf("%s",longestWord);	
	}
	
}