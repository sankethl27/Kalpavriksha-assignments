#include<stdio.h>
#include<stdlib.h>


void computeUpperTriangularMatrix(int** matrix , int maxRows , int maxColumns)
{
	for(int row = 0; row < maxRows; row++)
	{
		for(int column = 0; column < maxColumns; column++)
		{
			if(column >= row)
			{
				printf("%d ",*(*(matrix + row) + column));
			}
			else printf("  ");
		}
		printf("\n");
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
	computeUpperTriangularMatrix(matrix,maxRows,maxColumns);
}