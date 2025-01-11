#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{	
	char* input1 = (char*) malloc(100 * sizeof(char));
	char* input2 = (char*) malloc(100 * sizeof(char));
	scanf("%[^\n]",input1);
	getchar();
	scanf("%[^\n]",input2);
	getchar();
	int size = strlen(input1);
	for(int i = 0; i < size; i++)
	{	
		char* substr = (char*) malloc(100 * sizeof(char));
		int k = 0;
		for(int j = i; j < size; j++)
		{
			substr[k++] = input1[j];
			substr[k] = '\0';
			if(strcmp(substr,input2) == 0)
			{
				printf("%d",j-strlen(input2)+1);
				return 0;
			}

		}
	}
	printf("%d",-1);
	return 0;
}