#include "equations.h"

int main(void)
{
    srand((unsigned int)time(NULL)); // CALL 1 TIME @ begining of main

    int option = 0;
    int check_wager = 0;
    int die1_value = 0, die2_value = 0;
    int sum_dice = 0;
    int first_roll = 0;
    int next_roll = 0;
    int point_value = 0;
    int add_or_subtract = 0;
    double bank_balance = 0.0;
    double wager = 0.0;

    do
    {
        option = validate_option();

        switch (option)
        {
        case 1: print_game_rules();
            break;

        case 2: printf("Here we go, good luck!\n");
            bank_balance = get_bank_balance();
            do 
            {
                do
                {
                    wager = get_wager_amount();
                    check_wager = check_wager_amount(wager, bank_balance);
                } while (wager >= bank_balance);

                die1_value = roll_die(); // Rolls Die and prints result
                printf("die1: %d\n", die1_value);
                die2_value = roll_die(); // Rolls Die and prints result
                printf("die2: %d\n", die2_value);

                printf("You rolled a %d and a %d", die1_value, die2_value);

                sum_dice = calculate_sum_dice(die1_value, die2_value);
                printf("\nThe sum of the dice is: %d", sum_dice);

                first_roll = is_win_loss_or_point(sum_dice); // Call to function which returns 1, 0, -1
                if (first_roll == 1)
                {
                    printf("\nCongratulations, you win!");
                    bank_balance = adjust_bank_balance(bank_balance, wager, add_or_subtract);
                    printf("\nYour new bank balance is: %lf\n", bank_balance); 
                }
                if (first_roll == 0)
                {
                    printf("\nCraps, unfortunately the casino wins!");
                    bank_balance = adjust_bank_balance(bank_balance, wager, add_or_subtract);
                    printf("\nYour new bank balance is: %lf\n", bank_balance);
                }
                if (first_roll == -1)
                {
                    point_value = calculate_sum_dice(die1_value, die2_value);
                    printf("\nYour point value is: %d, good luck with future rolls!", point_value);

                    do
                    {
                        sleep();
                        // Next set of rolls to make point 
                        die1_value = roll_die(); // Rolls Die and prints result
                        printf("\ndie1: %d\n", die1_value);
                        die2_value = roll_die(); // Rolls Die and prints result
                        printf("die2: %d\n", die2_value);

                        printf("You rolled a %d and a %d", die1_value, die2_value);

                        // Sum dice again
                        sum_dice = calculate_sum_dice(die1_value, die2_value);
                        printf("\nThe sum of the dice is: %d", sum_dice);

                        // Next roll to detrmine point or loss
                        next_roll = is_point_loss_or_neither(sum_dice, point_value);
                        if (next_roll == 1)
                        {
                            printf("\nCongratulations, you made your point and you win the game!");
                            bank_balance = adjust_bank_balance(bank_balance, wager, add_or_subtract);
                            printf("\nYour new bank balance is: %lf\n", bank_balance);
                        }
                        if (next_roll == 0)
                        {
                            printf("\nDamn, unfortunately the casino wins!");
                            bank_balance = adjust_bank_balance(bank_balance, wager, add_or_subtract);
                            printf("\nYour new bank balance is: %lf\n", bank_balance);
                        }
                    } while (next_roll == -1);
                }
            } while (bank_balance != 0);
            break;

        case 3: printf("Thank you for playing!");
            break;

        default: // invalid options
            break;
        }
    } while (option != 3); // sentinel controlled loop

 

    return 0;
}
