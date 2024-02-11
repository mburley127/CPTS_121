#include "equations.h"

int main(void)
{
    srand((unsigned int)time(NULL)); // CALL 1 TIME @ begining of main

    int option = 0;
    int dice_values[MAX_SIZE];
    int scoreboard[SC_MAX_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int sb_upper1[UP_MAX_SIZE] = {0, 0, 0, 0, 0, 0};
    int sb_lower1[LOW_MAX_SIZE] = {0, 0, 0, 0, 0, 0, 0};
    int sb_upper2[UP_MAX_SIZE] = { 0, 0, 0, 0, 0, 0 };
    int sb_lower2[LOW_MAX_SIZE] = { 0, 0, 0, 0, 0, 0, 0 };
    int frequency[FREQ_MAX_SIZE] = {0, 0, 0, 0, 0, 0, 0};
    int num_dice = 0;
    int player1 = 0, player2 = 0, round = 0, total = 0;
    int* total_ptr = NULL;
    int total_p1 = 0, total_p2 = 0;

    do
    {
        option = validate_option();

        switch (option)
        {
        case 1: print_game_rules();
            display_scoreboard();
            break;

        case 2: printf("Here we go, good luck players!\n");
            // Code Goes Here
            do
            {
                printf("\nGet ready Player 1!");
                printf("\nPress Any Key to Roll Dice");
                getch(); // gets keyboard character
                system("cls"); //clear output screen

                print_rolling();
                play_round(dice_values, scoreboard, frequency, sb_upper1, sb_lower1, num_dice); // Allows Player 1 to play 1 round

                printf("\nGet ready Player 2!");
                printf("\nPress Any Key to Roll Dice");
                getch(); // gets keyboard character
                system("cls"); //clear output screen

                print_rolling();
                play_round(dice_values, scoreboard, frequency, sb_upper2, sb_lower2, num_dice); // Allows Player 2 to play 1 round

                round++;
            } while (round <= 13); // Alternates players for 14 rounds

            total_ptr = &total;

            printf("\nPlayer 1 score is:");
            total_p1 = total_score(sb_upper1, sb_lower1, total_ptr); // Call to compute and print score for Player 1
            printf("\nYour total score is: %d", total_p1);

            printf("\nPlayer 2 score is:");
            total_p2 = total_score(sb_upper2, sb_lower2, total_ptr); // Call to compute and print score for Player 1
            printf("\nYour total score is: %d", total_p2);

            if (total_p1 > total_p2) // This series of if statements print which player won the game
            {
                printf("\nCongratulations Player 1, you win!");
            }
            else if (total_p2 > total_p1)
            {
                printf("\nCongratulations Player 2, you win!");
            }
            else
            {
                printf("\nIt's a tie, Play Again!");
            }

            break;

        case 3: printf("Thank you for playing!");
            break;

        default: // invalid options
            break;
        }
    } while (option != 3); // sentinel controlled loop



    return 0;
}
