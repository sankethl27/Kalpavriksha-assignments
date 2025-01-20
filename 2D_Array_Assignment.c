#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char toLowerCase(char character)
{
    if (character >= 'A' && character <= 'Z')
    {
        character =  character + ('a' - 'A');
    }
    return character;
}

void compute(char ***namesList, int rows, int columns, int *countVowels, char **longestName)
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            printf("Enter name for position [%d][%d]: ", row, column);
            scanf("%s", namesList[row][column]);

            if (row == 0 && column == 0 || strlen(*longestName) < strlen(namesList[row][column]))
            {
                *longestName = namesList[row][column];
            }

            char ch = toLowerCase(namesList[row][column][0]);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                (*countVowels)++;
            }
        }
    }
}

void printNames(char ***namesList, int rows, int columns)
{
    printf("\nNames List:\n");
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            printf("%s ", namesList[row][column]);
        }
        printf("\n");
    }
}


void freeMemory(char ***namesList , int rows , int columns)
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            free(namesList[row][column]);
        }
        free(namesList[row]);
    }
    free(namesList);
}
int main()
{
    int rows = 0, columns = 0;
    int countVowels = 0;
    char *longestName = NULL;
    char ***namesList = (char ***)malloc(rows * sizeof(char **));
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &columns);
    for (int row = 0; row < rows; row++)
    {
        namesList[row] = (char **)malloc(columns * sizeof(char *));
        for (int column = 0; column < columns; column++)
        {
            namesList[row][column] = (char *)malloc(51 * sizeof(char));
        }
    }
    compute(namesList, rows, columns, &countVowels, &longestName);
    printNames(namesList, rows, columns);
    printf("\nTotal vowels count: %d\n", countVowels);
    printf("\nLongest Name is: %s\n", longestName);
    freeMemory(namesList , rows , columns);
    return 0;
}
