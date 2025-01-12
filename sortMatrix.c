#include<stdio.h>
#include<stdlib.h>


int comp(void const *a,void const *b)
{
	return *(int*)a - *(int*)b;
}

void printMatrix(int** matrix , int maxRows , int maxColumns)
{
	for(int row = 0; row < maxRows; row++)
	{
		for(int column = 0; column < maxColumns; column++)
		{
			printf("%d ",*(*(matrix + row) + column));
		
		}
		printf("\n");
	}
}

void sortMatrix(int** matrix , int maxRows , int maxColumns)
{	
	for(int row = 0; row < maxRows; row++)
	{
		qsort(matrix[row],maxColumns,sizeof(int),comp);
	}
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
	sortMatrix(matrix,maxRows,maxColumns);
	printMatrix(matrix,maxRows,maxColumns);
}