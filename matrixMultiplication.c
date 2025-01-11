#include<stdio.h>
#include<stdlib.h>


void freeMemory(int **matrix , int rows)
{
    for(int row = 0; row < rows; row++)
    {
        free(*(matrix + row));
    }
    free(matrix);

}
void printMatrix(int **matrix , int rows , int columns)
{
    for(int row = 0; row < rows; row++)
    {
        for(int column = 0; column < columns; column++)
        {
            printf("%d " , *(*(matrix + row) + column));
        }
        printf("\n");
    }
}

int** takeInput(int **matrix , int *rows ,int *columns)
{   
    scanf("%d %d",rows,columns);
    matrix = (int**) malloc(*rows * sizeof(int*));

    for(int row = 0; row < *rows; row++)
    {
        matrix[row] = (int*) malloc(*columns * sizeof(int));
    }

    for(int row = 0; row < *rows; row++)
    {
        for(int column = 0; column < *columns; column++)
        {
            scanf("%d",*(matrix + row) + column);
        }
    }
    return matrix;
}

void matrixMultiplication(int **matrix1 , int **matrix2 , int rows1 , int columns1 , int rows2 , int columns2)
{   
    if(columns1 != rows2)
    {
        printf("Cannot Perform Matrix Multiplication");
    }
    else
    {
        int **matrix = (int**) malloc(rows1 * sizeof(int*));
        for(int row = 0; row < rows1; row++)
        {
            matrix[row] = (int*) malloc(columns2 * sizeof(int));
        }

        for(int row = 0; row < rows1; row++)
        {
            for(int column = 0; column < columns2; column++)
            {
                int product = 0;
                for(int iterator = 0; iterator < columns1; iterator++)
                {
                    product += (*(*(matrix1 + row)+ iterator)) * (*(*(matrix2 + iterator)+ column));
                } 
                matrix[row][column] = product;
            }
               
        }
        printMatrix(matrix,rows1,columns2);
        freeMemory(matrix,rows1);
    }
}
int main()
{   
    int rows1 = 0 , rows2 = 0;
    int columns1 = 0 , columns2 = 0;
    int **matrix1;
    int **matrix2;
    matrix1 = takeInput(matrix1,&rows1,&columns1);
    matrix2 = takeInput(matrix2,&rows2,&columns2);
    matrixMultiplication(matrix1,matrix2,rows1,columns1,rows2,columns2);
    freeMemory(matrix1,rows1);
    freeMemory(matrix2,rows2);
    return 0;
}