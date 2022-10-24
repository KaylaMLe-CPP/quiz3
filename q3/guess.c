#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int choice = 0;
    const int ABSOLUTE_MAX = 100;
    int max = 10;

    while (choice != 3)
    {
        printf("\nPress 1 to play a game\nPress 2 to change the max number\nPress 3 to quit\n");
        scanf("%d", &choice);
        if (choice < 1 || choice > 3)
        {
            printf("\nInvalid choice\n");
            continue;
        }

        if (choice == 1)
        {
            int target = (rand() % max) + 1;

            int guess;
            printf("\nGuess a number between 1 and %d or enter 'q' to end the game: ", max);
            int scanSuccess = scanf("%d", &guess);

            bool quit = false;
            while (guess != target)
            {
                if (scanSuccess != 1)
                {
                    quit = true;
                    break;
                }

                char *diff = target < guess ? "high" : "low";
                printf("Your guess was too %s. Try again!: ", diff);
                scanSuccess = scanf("%d", &guess);
            }

            if (!quit)
            {
                printf("\nThat's the right number!\n");
            }
        }
        else if (choice == 2)
        {
            do
            {
                printf("\nEnter new max number between 0 and %d: ", ABSOLUTE_MAX);
                scanf("%d", &max);
            } while (max < 0 || max > ABSOLUTE_MAX);
        }
        while ((getchar()) != '\n')
            ;
    }

    printf("\nThanks for playing!\n");
    return 0;
}