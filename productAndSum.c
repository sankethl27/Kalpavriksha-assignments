#include<stdio.h>
#include<stdlib.h>

void computeProductAndSum(int** matrix , int maxRows , int maxColumns)
{
	int sum = 0;
	int product = 1;

	for(int row = 0; row < maxRows; row++)
	{
		for(int column = 0; column < maxColumns; column++)
		{
			product *= *(*(matrix + row) + column);
			sum += *(*(matrix + row) + column);
		}
	}
	printf("sum is %d : \n",sum);
	printf("Product is %d : \n" , product);
}
int main()
{
	int maxRows = 0,maxColumns = 0;
	scanf("%d %d",&maxRows,&maxColumns);
	int **matrix = (int**) malloc(maxRows * sizeof(int*));

	for(int row = 0; row < maxRows; row++)
	{
		matrix[row] = (int*)malloc(maxColumns * sizeof(int));
		for(int column = 0; column < maxColumns; column++)
		{
			scanf("%d",(*(matrix + row) + column));
		}
	}
	computeProductAndSum(matrix,maxRows,maxColumns);
}