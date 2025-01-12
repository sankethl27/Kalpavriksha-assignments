#include<stdio.h>
#include<stdlib.h>


void computeUpperTriangularMatrix(int** matrix , int maxRows , int maxColumns)
{	
	int sum = 0;
	for(int row = 0; row < maxRows; row++)
	{
		for(int column = 0; column < maxColumns; column++)
		{
			if(column ==  row)
			{
				sum += *(*(matrix + row) + column);
			}	
		}
	}
	printf("Trace of the matrix is : %d\n",sum);
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
	computeUpperTriangularMatrix(matrix,maxRows,maxColumns);
}