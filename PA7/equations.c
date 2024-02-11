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

void print_game_rules(void) // Prints out the rules of the game of "Battleship".
{
    printf("Play begins with each player being dealt five cards, one at a time, all face down. The remaining deck is placed aside, often protected by placing a chip or other marker on it. Players pick up the cards and hold them in their hands, being careful to keep them concealed from the other players, then a round of betting occurs. If more than one player remains after the first round, the draw phase begins.Each player specifies how many of their cards they wish to replace and discards them.The deck is retrieved, and each player is dealt in turn from the deck the same number of cards they discarded so that each player again has five cards. A second after the draw betting round occurs beginning with the player to the dealers left or else beginning with the player who opened the first round (the latter is common when antes are used instead of blinds). This is followed by a showdown, if more than one player remains, in which the player with the best hand wins the pot.");
}

void print_dealing(void)
{
    printf("Dealing Cards...\n");
    Sleep(2000);
}

void print_scoring(void)
{
    printf("\nScoring Hand...");
    Sleep(3000);
}

void print_updating(void)
{
    printf("\nUpdating Hand...");
    Sleep(2000);
}

void print_updating_dealer(void)
{
    printf("\nUpdating Dealer Hand...");
    Sleep(2000);
}

// Daniel Rouhana and I made this function
void deal_cards(Card deck[][13], Hand *cards_in_hand, int num_cards, int index) // Card deck[][13] stores the suit, face, color and whether or not the card
{
    int col = 0, row = 0;
    int temp = 0;
    
    
    for (int i = 0; i < num_cards; i++)
    {
        // find an unplayed card
        do
        {
            row = rand() % 4;
            col = rand() % 13;
            temp = deck[row][col].is_played;
            // SET IS_PLAYED TO 1
            deck[row][col].is_played = 1;
        } while (temp == 1);

        // printf("row: %d\n, col: %d\n", row, col);

        // convert integers spit out by rand function to suits and faces
        cards_in_hand->player_cards[index].index_suit = row;
        cards_in_hand->player_cards[index].index_face = col;
        index++;

    }
    // test(deck, cards_in_hand);
}

void display_player_hand(Card deck[][13], Hand *cards_in_hand, const char* wFace[], const char* wSuit[], int num_cards, int index)
{
    // deal_cards(deck, cards_in_hand, 5, 0);
    // test(deck, cards_in_hand);
    for (int i = 0; i < 5; i++)
    {
        int row = cards_in_hand->player_cards[i].index_suit;
        int col = cards_in_hand->player_cards[i].index_face;

        printf("\n%5s of %-8s", wFace[col], wSuit[row]);
    }
}

void replace_cards(Card deck[][13], int num_cards, Hand* cards_in_hand, int index)
{
    // int update_hand[5] = { 0, 0, 0, 0, 0 };
    int option = 0;
    int row = 0, col = 0;

    if (num_cards <= 3)
    {
        // create second for loop inside if block
        for (int i = 0; i < num_cards; i++)
        {
            // prompt user for which card to update
            printf("Which card would you like to change? ");
            scanf("%d", &option);

            deal_cards(deck, cards_in_hand, 1, option - 1);
        }
    }
}

void update_player_hand(Card deck[][13], Hand* cards_in_hand, const char* wFace[], const char* wSuit[], int num_cards, int index)
{
    int update_index = 0;

    printf("How many cards would you like to draw? ");
    scanf("%d", &num_cards);

    do
    {
        if (num_cards == 1)
        {
            // function call to update 1 card
            replace_cards(deck, num_cards, cards_in_hand, index);
            print_updating();
            printf("\n");
            printf("\nHere you go player, your updated hand: ");
            display_player_hand(deck, cards_in_hand, wFace, wSuit, num_cards, index);
        }

        if (num_cards == 2)
        {
            // function call to update 2 cards
            replace_cards(deck, num_cards, cards_in_hand, index);
            print_updating();
            printf("\n");
            printf("\nHere you go player, your updated hand: ");
            display_player_hand(deck, cards_in_hand, wFace, wSuit, num_cards, index);
        }

        if (num_cards == 3)
        {
            // function call to update 3 cards
            replace_cards(deck, num_cards, cards_in_hand, index);
            print_updating();
            printf("\n");
            printf("\nHere you go player, your updated hand: ");
            display_player_hand(deck, cards_in_hand, wFace, wSuit, num_cards, index);
        }
    } while (num_cards < 0 || num_cards > 3);
}

int is_pair(Hand *cards_in_hand, int freq_value[]) // Must have count = 2 as that signifies two cards have the same face value(1, 2, 3...), SUIT DOES NOT MATTER
{
    int temp = 0;
    int count_two = 0; // count set at 1 
    int pair = 0;
    
    for (int i = 0; i < 5; i++)
    {
        temp = cards_in_hand->player_cards[i].index_face; // Loop over all indicies of face values (1, 2, 3...) and store in temp variable
        freq_value[temp] += 1; // measures "tick marks"
        // printf("\nfrequency[temp] = %d", frequency[temp]); 

        if (freq_value[temp] >= 2)
        {
            count_two += 1;
        }
        // printf("\ncount_two = %d", count_two);
    }

    if (count_two == 1)
    {
        //printf("\nPlayer has a pair!");
        pair = 1;
    }

    // Must use Reset Loop to reset freq array back to 0
    for (int loop = 0; loop < 13; loop++)
    {
        freq_value[loop] = 0;
    }

    return pair;
}

int is_two_pair(Hand *cards_in_hand, int freq_value[]) // Must have two sets of two ticks in frequency card value array, SUIT DOES NOT MATTER
{
    int temp = 0;
    int count_two = 0; // count set at 1 
    int two_pair = 0;

    for (int i = 0; i < 5; i++)
    {
        temp = cards_in_hand->player_cards[i].index_face; // Loop over all indicies of face values (1, 2, 3...) and store in temp variable
        freq_value[temp] += 1; // measures "tick marks"
        // printf("\nfrequency[temp] = %d", frequency[temp]); 

        if (freq_value[temp] >= 2) // Must change to make two pair
        {
            count_two += 1;
        }
        // printf("\ncount_two = %d", count_two);
    }

    if (count_two == 1)
    {
        //printf("\nPlayer has a two pair!");
        two_pair = 2;
    }

    // Must use Reset Loop to reset freq array back to 0
    for (int loop = 0; loop < 13; loop++)
    {
        freq_value[loop] = 0;
    }

    return two_pair;
}

int is_three_of_kind(Hand *cards_in_hand, int freq_value[]) // Must have three ticks in frequency card value array in one spot, SUIT DOES NOT MATTER
{
    int temp = 0;
    int count_three = 0; // count set at 1 
    int three_of_kind = 0;

    for (int i = 0; i < 5; i++)
    {
        temp = cards_in_hand->player_cards[i].index_face; // Loop over all indicies of face values (1, 2, 3...) and store in temp variable
        freq_value[temp] += 1; // measures "tick marks"
        // printf("\nfrequency[temp] = %d", frequency[temp]); 

        if (freq_value[temp] >= 3)
        {
            count_three += 1;
        }
        // printf("\ncount_two = %d", count_two);
    }

    if (count_three == 1)
    {
        //printf("\nPlayer has a three of a kind!");
        three_of_kind = 3;
    }

    // Must use Reset Loop to reset freq array back to 0
    for (int loop = 0; loop < 13; loop++)
    {
        freq_value[loop] = 0;
    }

    return three_of_kind;
}

int is_four_of_kind(Hand *cards_in_hand, int freq_value[]) // Must have four ticks in frequency card value array at one spot, SUIT DOES NOT MATTER
{
    int temp = 0;
    int count_four = 0; // count set at 1 
    int four_of_kind = 0;

    for (int i = 0; i < 5; i++)
    {
        temp = cards_in_hand->player_cards[i].index_face; // Loop over all indicies of face values (1, 2, 3...) and store in temp variable
        freq_value[temp] += 1; // measures "tick marks"
        // printf("\nfrequency[temp] = %d", frequency[temp]); 

        if (freq_value[temp] >= 3)
        {
            count_four += 1;
        }
        // printf("\ncount_two = %d", count_two);
    }

    if (count_four == 1)
    {
        // printf("\nPlayer has a four of a kind!");
        four_of_kind = 4;
    }

    // Must use Reset Loop to reset freq array back to 0
    for (int loop = 0; loop < 13; loop++)
    {
        freq_value[loop] = 0;
    }
    
    return four_of_kind;
}

// Daniel Rouhana helped with this function
int is_flush(Hand *cards_in_hand) 
{
    int temp = 0;
    int count = 1; // count set at 1 

    temp = cards_in_hand->player_cards[0].index_suit; // Flag set to the suit of the card at index 0

    for (int i = 1; i < 5; i++)
    {
        if (cards_in_hand->player_cards[i].index_suit == temp) // if card at next index in each following iteration = the suit of the card at index 0, add 1 to count
        {
            count += 1;
        }
    }

    return (count == 5) ? 1 : 0;
}

int is_straight(Hand *cards_in_hand, int freq_value[]) // Must have five ticks in frequency card value array in sequential order, SUIT DOES NOT MATTER
{
    int i, temp = 0, count = 0;
    int straight = 0;

    for (i = 1; i < 5; i++)
    {
        temp = cards_in_hand->player_cards[i].index_face;
        freq_value[temp] += 1; // measures "tick marks"
    }

    // for loop to check for sequential order i = 0, i < MAX, i++
    for (i = 1; i < 5; i++)
    {
        if (freq_value[i] >= 1)
        {
            count += 1;
            if (count == 5)
            {
                break;
            }
        }

        if (freq_value[i] == 0)
        {
            count = 0;
        }
        // printf("\nfrequency[temp] = %d at %d", frequency[i], i);
    }

    // printf("count = %d", count);
    if (count == 5)
    {
        straight = 6;
    }
    // Must Print Reset Loop to reset freq array back to 0
    for (int loop = 0; loop < 13; loop++)
    {
        freq_value[loop] = 0;
    }

    return straight;
}

void auto_score_hand(int freq_score_arr[], Hand *cards_in_hand, int freq_value[])
{
    // create scoring option freq array with six spots, if scoring option returned, populate scoring array, choose largest tick in freq array
    // freq_score_arr[0] = pair, freq_score_arr[1] = two pair, freq_score_arr[2] = three of kind... 
    
    int is_hand = 0;

    // tick index 0 of freq_score_arr[] for pair
    is_hand = is_pair(cards_in_hand, freq_value);

    if (is_hand == 1)
    {
        freq_score_arr[0] = 1;
    }

    // tick index 1 of freq_score_arr[] for two pair
    is_hand = is_two_pair(cards_in_hand, freq_value);

    if (is_hand == 2)
    {
        freq_score_arr[1] = 1;
    }

    // tick index 2 of freq_score_arr[] for three of a kind
    is_hand = is_three_of_kind(cards_in_hand, freq_value);

    if (is_hand == 3)
    {
        freq_score_arr[2] = 1;
    }

    // tick index 3 of freq_score_arr[] for four of a kind
    is_hand = is_four_of_kind(cards_in_hand, freq_value);

    if (is_hand == 4)
    {
        freq_score_arr[3] = 1;
    }

    // tick index 4 of freq_score_arr[] for flush
    is_hand = is_flush(cards_in_hand);

    if (is_hand == 5)
    {
        freq_score_arr[4] = 1;
    }

    // tick index 5 of freq_score_arr[] for straight
    is_hand = is_straight(cards_in_hand, freq_value);

    if (is_hand == 6)
    {
        freq_score_arr[5] = 1;
    }
}

// calls auto score hand for player and dealer, loops backward to check for index with highest tick, then selects a winner
int check_highest(int freq_score_arr[], Hand *cards_in_hand, int freq_value[])
{
    int found = 0;

    // Function call that populates scoring frequency scoring array
    auto_score_hand(freq_score_arr, cards_in_hand, freq_value);

    // Loop over frequency scoring array 
    for (int i = 5; i > 0; i--) // Decrements through freq scoring array
    {
        if (freq_score_arr[i] == 1)
        {
            found = i; // sets found equal to the the index where the first tick in freq array is found
            break;
        }
    }

    return found;
}

void simulate_dealer(Card deck[][13], Hand* cards_in_hand, const char* wFace[], const char* wSuit[], int num_cards, int freq_score_arr[], int freq_value[], int index)
{
    int check_hand = 0;

    // If dealer has a pair, must draw 3 cards
    check_hand = is_pair(cards_in_hand, freq_value);

    if (check_hand == 1) 
    {
        // call deal function to draw 3 cards and display resulting hand
        deal_cards(deck, cards_in_hand, 3, index);
    }

    // If dealer has a two pair, must draw 1 card
    check_hand = is_two_pair(cards_in_hand, freq_value);

    if (check_hand == 2)
    {
        // call deal function to draw 1 card and display resulting hand
        deal_cards(deck, cards_in_hand, 1, index);
    }

    // If dealer has a three of a kind, must draw 2 cards
    check_hand = is_three_of_kind(cards_in_hand, freq_value);

    if (check_hand == 3)
    {
        // call deal function to draw 2 cards and display resulting hand
        deal_cards(deck, cards_in_hand, 2, index);
    }

    // Didn't get to finish...
}

void notify_player(int player_hand_score)
{
    switch (player_hand_score)
    {
    case 1: printf("\nPlayer has a pair! Do better next time...");
        break;
    case 2: printf("\nPlayer has a two pair! Seriously, do better...");
        break;
    case 3: printf("\nPlayer has a three of a kind! That's a little better, I guess...");
        break;
    case 4: printf("\nPlayer has a four of a kind! Now that's a good hand!");
        break;
    case 5: printf("\nPlayer has a straight! Suck on that dealer...");
        break;
    case 6: printf("\nPlayer has a flush! Alright! Finally a hand that might actually win!");
        break;
    default: printf("\nSeriously?? Nothing? That's just embarrassing. Don't even bother playing another game...");
        break;
    }
}

void notify_dealer(int dealer_hand_score)
{
    switch (dealer_hand_score)
    {
    case 1: printf("\nDealer has a pair! You might actually have a chance at winning player...");
        break;
    case 2: printf("\nDealer has a two pair! You'll probably blow it player...");
        break;
    case 3: printf("\nDealer has a three of a kind! You're probably screwed...");
        break;
    case 4: printf("\nDealer has a four of a kind! I mean, dang, that's just a good hand!");
        break;
    case 5: printf("\nDealer has a straight! *mic drop*");
        break;
    case 6: printf("\nDealer has a flush! Sucks to be you player...");
        break;
    default: printf("\nSeriously?? Nothing? Good chance you'll win player...");
        break;
    }
}

void test(Card deck[][13], Hand* cards_in_hand)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            printf(" %d ", deck[i][j].is_played);
        }
        putchar('\n');
    }
    putchar('\n');
    putchar('\n');

    for (int k = 0; k < 5; k++)
    {
        printf("cards_in_hand.player_cards[i].index_suit: %d\n", cards_in_hand->player_cards[k].index_suit);
        printf("cards_in_hand.player_cards[i].index_face: %d\n", cards_in_hand->player_cards[k].index_face);
    }
}

void init_struct(Card deck[][13], Hand* cards_in_hand)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            deck[i][j].is_played = 0;
            deck[i][j].index_face = 0;
            deck[i][j].index_suit = 0;
        }
    }

    for (int k = 0; k < 5; k++)
    {
        cards_in_hand->player_cards[k].index_suit = -1;
        cards_in_hand->player_cards[k].index_face = -1;
    }
}
