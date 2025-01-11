#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void isRotated(char* string1 , char* string2)
{	
	strcat(string1,string1);
	int size = strlen(string1);
	for(int i = 0; i < size; i++)
	{	
		char* substr = (char*) malloc(100 * sizeof(char));
		int k = 0;
		for(int j = i; j < size; j++)
		{
			substr[k++] = string1[j];
			substr[k] = '\0';
			if(strcmp(substr,string2) == 0)
			{
				printf("True");
				return;
			}

		}
	}
	printf("False");
}
int main(){
	char* string1 = (char*)malloc(sizeof(char));
	char* string2 = (char*)malloc(sizeof(char));
	scanf("%[^\n]",string1);
	getchar();
	scanf("%[^\n]",string2);
	getchar();
	isRotated(string1,string2);
}