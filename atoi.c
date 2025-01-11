#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char* input = (char*) malloc(100 * sizeof(char));	
	scanf("%[^\n]",input);
	getchar();
	int iterator = 0;
	int sign = 1;
	int size = strlen(input);
	long long number = 0;
	if(input[iterator] == '-')
	{
		sign = -1;
		iterator++;
	}
	if(input[iterator] == '+')
	{
		iterator++;
	}
	while(input[iterator] != '\0')
	{	
		if((input[iterator] - '0' < 0) || (input[iterator] - '0' > 9))
		{
			number = 0;
			break;
		}
		number = number * 10 + 1ll * (input[iterator] - '0');
		iterator++;
	}
	if(iterator != size) number = 0;
	if(number != 0) number = number * sign;
	printf("%lld\n",number);
    free(input);
	return 0;
}