#include<stdio.h>
#include<stdlib.h>

int main()
{
	char input[101];
	scanf("%s",input);
	char result[100];
	int ascii[26] = {0};
	int i = 0; 
	int j = 0;
	while(input[i] != '\0')
	{	
		if(ascii[input[i] - 'a'] == 0)
		{
			result[j] = input[i];
			ascii[input[i] - 'a'] = 1;
			j++;

		}
		i++;
	}
	result[j] = '\0';
	printf("%s",result);
	return 0;
}