#include "equations.h"



void display_menu(void)
{
    printf("\n1. Display Rules.\n");
    printf("2. Play Game.\n");
    printf("3. Exit Game.\n");
}

int get_option(void)
{
    int option = 0;
    scanf("%d", &option);
    return option;
}

int validate_option(void)
{
    int option = 0;
    do
    {
        display_menu();
        option = get_option();
    } while (option < 1 || option > 3);

    return option;
}

// Below are given assignment functions
void print_game_rules(void) // Prints out the rules of the game of "craps".
{
    printf("The Game Rules are: A player rolls two dice. Each die has six faces.\n These faces contain 1, 2, 3, 4, 5, and 6 spots.\n After the dice have come to rest, the sum of the spots on the two upward faces is calculated.\n If the sum is 7 or 11 on the first throw, the player wins.\n If the sum is 2, 3, or 12 on the first throw (called craps), the player loses (i.e. the house wins).\n If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's point.\n To win, you must continue rolling the dice until you make your point.\n The player loses by rolling a 7 before making the point.");
}

double get_bank_balance(void) // Prompts the player for an initial bank balance from which wagering will be added or subtracted. The player entered bank balance (in dollars, i.e. $100.00) is returned.
{
    double bank_balance = 0.0;
    
    printf("Enter your bank balance in dollars: ");
    scanf("%lf", &bank_balance);

    return bank_balance;
}

double get_wager_amount(void) // Prompts the player for a wager on a particular roll. The wager is returned.
{
    double wager = 0.0;

    printf("Enter your wager amount in dollars: ");
    scanf("%lf", &wager);

    return wager;
}

int check_wager_amount(double wager, double balance) // Checks to see if the wager is within the limits of the player's available balance. If the wager exceeds the player's allowable balance, then 0 is returned; otherwise 1 is returned.
{
    if (wager > balance)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// Generates a number 1-6
int roll_die(void)
{
    return rand() % 6 + 1; // remainder of any number divided by 6 is 1-5 (need + 1)
}

int calculate_sum_dice(int die1_value, int die2_value) // Sums together the values of the two dice and returns the result. Note: this result may become the player's point in future rolls.
{
    int sum_dice = 0;

    sum_dice = die1_value + die2_value;

    return sum_dice;
}
int is_win_loss_or_point(int sum_dice) // Determines the result of the first dice roll. If the sum is 7 or 11 on the roll, the player wins and 1 is returned. If the sum is 2, 3, or 12 on the first throw (called "craps"), the player loses (i.e. the "house" wins) and 0 is returned. If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's "point" and -1 is returned.
{
    if (sum_dice == 7 || sum_dice == 11)
    {
        return 1;
    }
    if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12)
    {
        return 0;
    }
    if (sum_dice == 4 || sum_dice == 5 || sum_dice == 6 || sum_dice == 8 || sum_dice == 9 || sum_dice == 10) // sum becomes players point
    {
        return -1;
    }
}

int is_point_loss_or_neither(int sum_dice, int point_value) // Determines the result of any successive roll after the first roll. If the sum of the roll is the point_value, then 1 is returned. If the sum of the roll is a 7, then 0 is returned. Otherwise, -1 is returned.
{
    if (sum_dice == point_value)
    {
        return 1;
    }
    else if (sum_dice == 7)
    {
        return 0;
    }
    else
    {
        return -1; // must continue rolling, probably need a loop
    }
}

double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract) // If add_or_subtract is 1, then the wager amount is added to the bank_balance. If add_or_subtract is 0, then the wager amount is subtracted from the bank_balance. Otherwise, the bank_balance remains the same. The bank_balance result is returned.
{
    if (add_or_subtract == 1)
    {
        bank_balance = bank_balance + wager_amount; // wager amount added to bank balance
    }
    if (add_or_subtract == 0)
    {
        bank_balance = bank_balance - wager_amount; // wager amount subtracted from bank balance
    }
    return bank_balance;
}

void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance) // Prints an appropriate message dependent on the number of rolls taken so far by the player, the current balance, and whether or not the player just won his roll. The parameter win_loss_neither indicates the result of the previous roll.
{

}

void sleep(void)
{
    Sleep(2000);
}
