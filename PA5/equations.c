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

void print_game_rules(void) // Prints out the rules of the game of "Yahtzee".
{
    printf("The Game Rules are: Each turn gives a player 3 opportunities to roll the dice in order to\n score the highest number of points from dice combinations. First Roll: Roll all five\n dice. Either you may stop your turn here and mark your points or set aside dice\n which are keepers and roll again. Second Roll: You may roll any or all of the\n dice from the first roll. You do not need to declare which combination you are\n attempting to roll for as it may change after the second roll. After the\n second roll you may stop and score yourself or roll again. Third Roll: Again, you\n may roll and or all of the five dice. After this roll you must score yourself or\n mark a zero. After marking your score, your turn is over, and play moves to\n the other player. On the score card there are 13 columns which correspond to\n the 13 rounds in each game. On your turn you must fill in a box, even if you score\n yourself zero. Good Luck!\n");
}

///////////////////////////////////////////////////////////////////////////   Dice Roll and Update Fuctions   //////////////////////////////////////////////////////////////////////////////////////////////

// Roll 5 dice, store values in an array, displays the values
void init_roll_dice(int dice[]) 
{
    int i;

    for (i = 1; i < MAX_SIZE; i++)
    {
        dice[i] = rand() % 6 + 1;
    }
}

void display_dice(int dice[], int i)
{
    for (i = 1; i < MAX_SIZE; i++)
    {
        printf("\nDie %d value = %d", i, dice[i]);
    }
}

void print_rolling(void)
{
    printf("Rolling dice...");
    Sleep(2000);
}

// Function to find number of dice to re-roll, loop on that number, inside of loop asks which dice to re-roll, re-rolls die, and puts value back into array
void update_dice_values(int dice[]) // Daniel Rouhana tweaked this function, and helped me come up with way to validate the same dice wasn't being selected twice!
{
    int count = 0, new_die = 0, num_dice = 0;
    int dice_ref[6] = {0, 0, 0, 0, 0, 0};
    
    do
    {
        printf("\nEnter the total number of dice you wish to re-roll: ");
        scanf("%d", &num_dice);
    } while (num_dice < 0 || num_dice > 5); // Any total dice number between 1 and 5 breaks out of loop

    for (int i = 0; i < num_dice; i++)  
    {
        do
        {
            printf("\nWhich specific dice would you like to re-roll? "); // Asks which die to re-roll,
            scanf("%d", &new_die);
            if (dice_ref[new_die] == 1)
            {
                printf("\nYou already selected this dice, please roll again!");
            }
        } while (new_die < 0 || new_die > 5 || dice_ref[new_die] == 1); // Any dice number between 1 and 5 breaks out of loop, if dice_ref not replaced by 1, exit loop to re-roll

        dice[new_die] = rand() % 6 + 1; 
        dice_ref[new_die] = 1;
        printf("Die %d value = %d\n", new_die, dice[new_die]); // Displays new dice value and stores value in array
    }
    display_dice(dice, new_die); // Function that Displays original array with updated values
}

void display_scoreboard(void)
{
    printf("\n       Scoreboard Options:");

    printf("\n1. Sum of 1's     7. Three-of-a-kind");
    printf("\n2. Sum of 2's     8. Four-of-a-kind");
    printf("\n3. Sum of 3's     9. Full house");
    printf("\n4. Sum of 4's     10. Small straight");
    printf("\n5. Sum of 5's     11. Large straight");
    printf("\n6. Sum of 6's     12. Yahtzee");
    printf("\n          13. Chance");
}

////////////////////////////////////////////////////////////////////////////////   Scoring Fuctions   ///////////////////////////////////////////////////////////////////////////////////////////////////

int aces(int dice[], int frequency[]) // Daniel Rouhana helped with this function
{
    int i, temp = 0;
    int sum1 = 0, points1 = 0;
    
    for (i = 1; i <= 5; i++)
    {
        temp = dice[i] - 1; // Subtracts 1 from dice value and stores it in temp  

        if (temp == 0) // If temp = 0 (Dice Value = 1), execute conditional
        {
            frequency[temp] += 1; // Adds 1 to frequency index for each temp value = 0 (Dice Value = 1)
            sum1 = sum1 + dice[i]; // Calculates sum of dice values counted in frequency index
        }

    }
    points1 = sum1;

    return points1;
}

int twos(int dice[], int frequency[])
{
    int i, temp = 0;
    int sum2 = 0, points2 = 0;

    for (i = 1; i <= 5; i++)
    {
        temp = dice[i] - 1; 

        if (temp == 1)
        {
            frequency[temp] += 1;
            sum2 = sum2 + dice[i];
        }
    }
    points2 = sum2;
    return points2;
}

int threes(int dice[], int frequency[])
{
    int i, temp = 0;
    int sum3 = 0, points3 = 0;

    for (i = 1; i <= 5; i++)
    {
        temp = dice[i] - 1; 

        if (temp == 2)
        {
            frequency[temp] += 1;
            sum3 = sum3 + dice[i];
        }
    }
    points3 = sum3;
    return points3;
}

int fours(int dice[], int frequency[])
{
    int i, temp = 0;
    int sum4 = 0, points4 = 0;

    for (i = 1; i <= 5; i++)
    {
        temp = dice[i] - 1;

        if (temp == 3)
        {
            frequency[temp] += 1;
            sum4 = sum4 + dice[i];
        }
    }
    points4 = sum4;
    return points4;
}

int fives(int dice[], int frequency[])
{
    int i, temp = 0;
    int sum5 = 0, points5 = 0;

    for (i = 1; i <= 5; i++)
    {
        temp = dice[i] - 1; 

        if (temp == 4)
        {
            frequency[temp] += 1;
            sum5 = sum5 + dice[i];
        }
    }
    points5 = sum5;
    return points5;
}

int sixes(int dice[], int frequency[])
{
    int i, temp = 0;
    int sum6 = 0, points6 = 0;

    for (i = 1; i <= 5; i++)
    {
        temp = dice[i] - 1;

        if (temp == 5)
        {
            frequency[temp] += 1;
            sum6 = sum6 + dice[i];
        }
    }
    points6 = sum6;
    return points6;
}

int three_of_kind(int dice[], int frequency[]) // Checks for 3 of a kind, and sums ALL the dice values together for points
{
    int i, temp = 0, index;
    int sum7 = 0, count_three = 0, points7 = 0;

    for (i = 1; i < MAX_SIZE; i++)
    {
        temp = dice[i] - 1;
        frequency[temp] += 1; // measures "tick marks"
        // printf("\nfrequency[temp] = %d", frequency[temp]); 

        if (frequency[temp] >= 3)
        {
            count_three += 1;
        }
        // printf("\ncount_three = %d", count_three);
    }

    if (count_three == 1)
    {
        for (index = 1; index < MAX_SIZE; index++)
        {
            sum7 = sum7 + dice[index];
        }
    }
    //printf("\nThe sum of the dice is: %d", sum7);

    // Must Print Reset Loop to reset freq array back to 0
    for (int loop = 0; loop < 7; loop++)
    {
        frequency[loop] = 0;
    }

    points7 = sum7;
    return points7;
}

int four_of_kind(int dice[], int frequency[]) // Checks for 4 of a kind, and sums ALL the dice values together for points
{
    int i, temp = 0, index;
    int sum8 = 0, count_four = 0, points8 = 0;

    for (i = 1; i < MAX_SIZE; i++)
    {
        temp = dice[i] - 1;
        frequency[temp] += 1; // measures "tick marks"

        if (frequency[temp] >= 4)
        {
            count_four += 1;
        }
    }

    if (count_four == 1)
    {
        for (index = 1; index < MAX_SIZE; index++)
        {
            sum8 = sum8 + dice[index];
        }
    }

    for (int loop = 0; loop < 7; loop++)
    {
        frequency[loop] = 0;
    }

    points8 = sum8;
    return points8;
}

int full_house(int dice[], int frequency[]) // Checks for 3 of a kind and 2 of a kind, awards 25 points to player
{
    int i, temp = 0, index;
    int score9 = 0, count_full_house = 0, points9 = 0;

    for (i = 1; i < MAX_SIZE; i++)
    {
        temp = dice[i] - 1;
        frequency[temp] += 1; // measures "tick marks"

        if (frequency[temp] >= 3 && frequency[temp] >= 2)
        {
            count_full_house += 1;
        }
    }

    if (count_full_house == 1)
    {
        points9 = 25;
    }

    // Must Print Reset Loop to reset freq array back to 0
    for (int loop = 0; loop < 7; loop++)
    {
        frequency[loop] = 0;
    }

    return points9;
}

int small_straight(int dice[], int frequency[]) // Checks for 4 dice values in sequential order, awards 30 points to player
{
    int i, temp = 0, count = 0;
    int score10 = 0, points10 = 0;

    for (i = 1; i < MAX_SIZE; i++)
    {
        temp = dice[i];
        frequency[temp] += 1; // measures "tick marks"
    }

    // for loop to check for sequential order
    for (i = 1; i < FREQ_MAX_SIZE; i++)
    {
        if (frequency[i] >= 1)
        {
            count += 1;
            if (count == 4)
            {
                break;
            }
        }

        if (frequency[i] == 0)
        {
            count = 0;
        }
        // printf("\nfrequency[temp] = %d at %d", frequency[i], i);
    }

    // printf("\ncount = %d", count);
    if (count >= 4)
    {
        points10 = 30;
    }
    // Must Print Reset Loop to reset freq array back to 0
    for (int loop = 0; loop < 7; loop++)
    {
        frequency[loop] = 0;
    }

    return points10;
}

int large_straight(int dice[], int frequency[]) // Checks for 5 dice values in sequential order, awards 40 points to player
{
    int i, temp = 0, count = 0;
    int score10 = 0, points11 = 0;

    for (i = 1; i < MAX_SIZE; i++)
    {
        temp = dice[i];
        frequency[temp] += 1; // measures "tick marks"
    }

    // for loop to check for sequential order i = 0, i < MAX, i++
    for (i = 1; i < FREQ_MAX_SIZE; i++)
    {
        if (frequency[i] >= 1)
        {
            count += 1;
            if (count == 5)
            {
                break;
            }
        }

        if (frequency[i] == 0)
        {
            count = 0;
        }
        // printf("\nfrequency[temp] = %d at %d", frequency[i], i);
    }

    // printf("count = %d", count);
    if (count == 5)
    {
        points11 = 40;
    }
    // Must Print Reset Loop to reset freq array back to 0
    for (int loop = 0; loop < 7; loop++)
    {
        frequency[loop] = 0;
    }

    return points11;
}

int yahtzee(int dice[], int frequency[]) // Checks for 5 of a kind, awards 50 points to player
{
    int i, temp = 0;
    int points12 = 0, count_five = 0;

    for (i = 1; i < MAX_SIZE; i++)
    {
        temp = dice[i] - 1;
        frequency[temp] += 1; // measures "tick marks"

        if (frequency[temp] >= 5)
        {
            count_five += 1;
        }
    }

    if (count_five == 1)
    {
        points12 = 50;
    }

    // Must Print Reset Loop to reset freq array back to 0
    for (int loop = 0; loop < 7; loop++)
    {
        frequency[loop] = 0;
    }

    return points12;
}

int chance(int dice[], int frequency[]) // Checks for 5 of a kind, awards 50 points to player
{
    int i;
    int sum13 = 0, points13 = 0;

    for (i = 1; i < MAX_SIZE; i++)
    {
        sum13 = sum13 + dice[i];
    }

    printf("\nThe sum of the dice is: %d", sum13);

    // Must Print Reset Loop to reset freq array back to 0
    for (int loop = 0; loop < 7; loop++)
    {
    frequency[loop] = 0;
    }

    points13 = sum13;
    return points13;
}

////////////////////////   Total Scorebord Functions   ////////////////////////
void compute_score(int dice[], int scoreboard[], int frequency[], int sb_upper[], int sb_lower[])  // Computes total score for 1 player given scoreboard scores, while adding 35 point upper bonus if upper score >= 63 
{
    int score_select = 0;
    // int upper_score = 0, lower_score = 0, final_score = 0;

    display_scoreboard();

    printf("\nPlease enter your scoreboard selection: ");
    scanf("%d", &score_select);

    switch (score_select)
    {
    case 1: // This is when the user selects 1 for the score menu, calls function to compute sum of the ones, score = sum 1's
        // Setting scoreboard value for when 1's are selected to 1, and printing scoreboard array to check for value of 0 at that index
        // Scoreboard array updates index from 0 to 1 at index 0 for scoreboard choice 1
        scoreboard[0] = 1; // Scoreboard array updates index from 0 to 1 at index 1 for scoreboard choice 1
        sb_upper[0] = aces(dice, frequency);
        printf("\nThe points given for aces is: %d", sb_upper[0]);
        break;

    case 2: 
        scoreboard[1] = 1; // Scoreboard array updates index from 0 to 1 at index 1 for scoreboard choice 2
        sb_upper[1] = twos(dice, frequency); // sb_upper[] stores the sum of the twos rolled
        printf("\nThe points given for twos is: %d", sb_upper[1]); // Displays point value to user
        break;

    case 3: 
        scoreboard[2] = 1;
        sb_upper[2] = threes(dice, frequency);
        printf("\nThe points given for threes is: %d", sb_upper[2]);
        break;

    case 4: 
        scoreboard[3] = 1;
        sb_upper[3] = fours(dice, frequency);
        printf("\nThe points given for fours is: %d", sb_upper[3]);
        break;

    case 5: 
        scoreboard[4] = 1;
        sb_upper[4] = fives(dice, frequency);
        printf("\nThe points given for fives is: %d", sb_upper[4]);
        break;

    case 6: 
        scoreboard[5] = 1;
        sb_upper[5] = sixes(dice, frequency);
        printf("\nThe points given for sixes is: %d", sb_upper[5]);
        break;

    case 7: 
        scoreboard[6] = 1;
        sb_lower[0] = three_of_kind(dice, frequency); // sb_lower[] stores the sum of all dice when 3 of 1 face value are rolled in this case
        printf("\nThe points given for 3 of a kind is: %d", sb_lower[0]); // Displays point value to user
        break;

    case 8: 
        scoreboard[7] = 1;
        sb_lower[1] = four_of_kind(dice, frequency);
        printf("\nThe points given for 4 of a kind is: %d", sb_lower[1]);
        break;

    case 9: 
        scoreboard[8] = 1;
        sb_lower[2] = full_house(dice, frequency);
        printf("\nThe points given for a full house is: %d", sb_lower[2]);
        break;

    case 10: 
        scoreboard[9] = 1;
        sb_lower[3] = small_straight(dice, frequency);
        printf("\nThe points given for a small straight is: %d", sb_lower[3]);
        break;

    case 11: 
        scoreboard[10] = 1;
        sb_lower[4] = large_straight(dice, frequency);
        printf("\nThe points given for a large straight is: %d", sb_lower[4]);
        break;

    case 12: 
        scoreboard[11] = 1;
        sb_lower[5] = yahtzee(dice, frequency);
        printf("\nThe points given for a YAHTZEE! is: %d", sb_lower[5]);
        break;

    case 13: 
        scoreboard[12] = 1;
        sb_lower[6] = chance(dice, frequency);
        printf("\nThe points given for chance is: %d", sb_lower[6]);
        break;
    }

}

int total_score(int sb_upper[], int sb_lower[], int *total)
{
    int score_up = 0, score_low = 0;

    for (int i = 0; i < UP_MAX_SIZE; i++) // Loops over the values stored in upper scoreboard array, adds them, and updates score_up as it iterates through
    {
        score_up = score_up + sb_upper[i];
    }
    printf("\nThe score of the upper scoreboard is: %d", score_up);

    for (int index = 0; index < LOW_MAX_SIZE; index++)
    {
        score_low = score_low + sb_lower[index]; // Loops over the values stored in lower scoreboard array, adds them, and updates score_low as it iterates through
    }
    printf("\nThe score of the lower scoreboard is: %d", score_low);

    if (score_up >= 63)
    {
        *total = score_up + score_low + 35; // If upper score sum is greater than or equal to 63, then a 35 point bonus is awarded to the total score
    }

    else
    {
        *total = score_up + score_low; // Computes total score for 1 player
    }
    
    return *total;
}

///////////////////////////////////////////////////////////////////////////   Play Round   //////////////////////////////////////////////////////////////////////////////////////////////

void play_round(int dice[], int scoreboard[], int frequency[], int sb_upper[], int sb_lower[], int num_dice) // Function to ask user whether to roll again or select points on scoreboard FOR THE FIRST RE-ROLL
{
    char roll_again1 = '\0';
    char roll_again2 = '\0';

    init_roll_dice(dice);
    display_dice(dice, num_dice);

    // First re-roll. If first re-roll = Y, should prompt for second re-roll. If first re-roll = N, should display scoreboard and allow user to make scoring choice. 
    do
    {
        printf("\nWant to roll again (y/n)? "); // Prompts to roll again, and validates user entered option. If not a y or n, re-prompts 
        scanf(" %c", &roll_again1);
    } while (roll_again1 != 'y' && roll_again1 != 'Y' && roll_again1 != 'n' && roll_again1 != 'N');

    if (roll_again1 == 'y' || roll_again1 == 'Y') // If player wants to roll dice, dice values are updated, stored and displayed for FIRST re-roll
    {
        update_dice_values(dice);
    }

    if (roll_again1 == 'n' || roll_again1 == 'N') // If player does not want to roll dice, scoreboard is displayed so they can choose scoring option
    {
        compute_score(dice, scoreboard, frequency, sb_upper, sb_lower);
    }

    if (roll_again1 != 'n' && roll_again1 != 'N') // If player does not enter no for first re-roll, promptes for second re-roll
    {
        do
        {
            printf("\nWant to roll again (y/n)? ");
            scanf(" %c", &roll_again2);
        } while (roll_again2 != 'y' && roll_again2 != 'Y' && roll_again2 != 'n' && roll_again2 != 'N');

        if (roll_again2 == 'n' || roll_again2 == 'N') // If player does not want to roll dice, scoreboard is displayed so they can choose scoring option
        {
            compute_score(dice, scoreboard, frequency, sb_upper, sb_lower);
        }

        if (roll_again2 == 'y' || roll_again2 == 'Y') // If player wants to roll dice, dice values are updated, stored and displayed. For SECOND re-roll, user must select scoring choice
        {
            update_dice_values(dice);
            compute_score(dice, scoreboard, frequency, sb_upper, sb_lower);
        }
    }
}
