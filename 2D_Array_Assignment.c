#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char toLowerCase(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        return ch + ('a' - 'A');
    }
    return ch;
}

// Function to compute total vowels and find the longest name
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

// Function to print the names
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

int main()
{
    int rows = 0, columns = 0;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &columns);

    char ***namesList = (char ***)malloc(rows * sizeof(char **));
    for (int row = 0; row < rows; row++)
    {
        namesList[row] = (char **)malloc(columns * sizeof(char *));
        for (int column = 0; column < columns; column++)
        {
            namesList[row][column] = (char *)malloc(51 * sizeof(char)); // Assuming max name length is 50
        }
    }

    int countVowels = 0;
    char *longestName = NULL;

    compute(namesList, rows, columns, &countVowels, &longestName);

    printNames(namesList, rows, columns);

    printf("\nTotal vowels count: %d\n", countVowels);
    printf("\nLongest Name is: %s\n", longestName);

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            free(namesList[row][column]);
        }
        free(namesList[row]);
    }
    free(namesList);

    return 0;
}
