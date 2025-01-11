#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void checkAnagram(char* string1 ,char* string2)
{
	int freq1[130] = {0};
	int freq2[130] = {0};
	int size = strlen(string1);
	if(strlen(string1) != strlen(string2))
	{
		printf("False");
		return;
	}
	
	for(int i = 0; i < size; i++)
	{
		freq1[string1[i] - '0']++;
		freq2[string2[i] - '0']++;
	}

	for(int i = 0; i < 130; i++)
	{
		if(freq1[i] != freq2[i])
		{
			printf("False");
			return;
		}
	}
	printf("True");
	
}
int main()
{	
	char* string1 = (char*)malloc(100 * sizeof(char));
	char* string2 = (char*)malloc(100 * sizeof(char));
	scanf("%[^\n]",string1);
	getchar();
	scanf("%[^\n]",string2);
	getchar();
	checkAnagram(string1,string2);
	return 0;
}