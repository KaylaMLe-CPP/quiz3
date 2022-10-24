#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    srand(time(NULL));
    int digits[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int square[3][3];
    int count = 0;
    bool notMatch = true;

    while (notMatch) // probably better off as a do while
    {
        notMatch = false;
        count++;

        // randomizes list of digits
        for (int i = 0; i < 9; i++)
        {
            int swapIndex = (rand() + i) % 9;
            int swaptmp = digits[i];
            digits[i] = digits[swapIndex];
            digits[swapIndex] = swaptmp;
        }

        // fills magic array
        for (int i = 0; i < 9; i++)
        {
            square[i / 3][i % 3] = digits[i];
        }

        // checks for sum matches
        int leftDiagSum = 0;  // upper left - bottom right diagonal sum
        int rightDiagSum = 0; // upper right - bottom left diagonal sum
        // first row used as reference sum
        int sum = square[0][0] + square[0][1] + square[0][2];

        for (int i = 0; i < 3; i++)
        {
            // checks rows
            int rowSum = square[i][0] + square[i][1] + square[i][2];
            if (rowSum != sum)
            {
                printf("Row %d sums to %d!\n", i, rowSum);
                notMatch = true;
            }

            // checks columns
            int colSum = square[0][i] + square[1][i] + square[2][i];
            if (colSum != sum)
            {
                printf("Column %d sums to %d!\n", i, colSum);
                notMatch = true;
            }

            leftDiagSum += square[i][i];
            rightDiagSum += square[i][2 - i];
        }

        if (leftDiagSum != sum)
        {
            printf("Upper left to bottom right diagonal sums to %d!\n", leftDiagSum);
            notMatch = true;
        }

        if (rightDiagSum != sum)
        {
            printf("Upper right to bottom left diagonal sums to %d!\n", rightDiagSum);
            notMatch = true;
        }

        printf("\n");
    }

    printf("\n%d squares tested before a Lo Shu magic square found!\n ___\n", count);

    for (int row = 0; row < 3; row++)
    {
        printf("|");

        for (int col = 0; col < 3; col++)
        {
            printf("%d", square[row][col]);
        }

        printf("|\n");
    }

    printf(" ___\n");
    return 0;
}