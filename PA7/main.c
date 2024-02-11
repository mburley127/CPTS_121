#include "equations.h"

int main(void)
{
    srand((unsigned int)time(NULL)); // CALL 1 TIME @ begining of main

    int option = 0;
    char play_again = '\0';
    /* initialize suit array */
    const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" }; // Address stored is to the H in Hearts
    /* initialize face array */
    const char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
        "Nine", "Ten", "Jack", "Queen", "King" };
    /* initalize deck array */
    Card deck[4][13];
    // player hand array
    //Hand cards_in_player_hand = { 0, 0, 0, 0, 0 };
    Hand cards_in_player_hand;
    // dealear hand array
    Hand cards_in_dealer_hand;
    //initialize frequency array for suits of cards (4)
    // char freq_suit[4] = { 0, 0, 0, 0 };
    //initialize frequency array for value of cards
    int freq_value[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    // Number of Cards to re_draw
    int num_cards_player = 0;
    // Number of Cards to re_draw
    int num_cards_dealer = 0;
    // Player Auto Score Array
    int player_score[6] = { 0, 0, 0, 0, 0, 0 };
    // Dealer Auto Score Array
    int dealer_score[6] = { 0, 0, 0, 0, 0, 0 };
    // Player Hand Score
    int player_hand_score = 0;
    // Dealer Hand Score
    int dealer_hand_score = 0;
    int index = 0;

    // init_struct(deck, &cards_in_player_hand);
    // test(deck, &cards_in_player_hand);
    do
    {
        option = validate_option();

        switch (option)
        {
        case 1: print_game_rules();
            break;

        case 2: system("cls"); //clear output screen
            printf("Here we go, good luck players!\n");
            // Code Goes Here

            printf("Press any key to start!");
            char start = getchar();

            while (start == getchar() || play_again == 'Y' || play_again == 'y')
            {
                // deal and display player cards (1-5)
                print_dealing();
                printf("\nHere you player, your cards are: ");
                deal_cards(deck, &cards_in_player_hand, 5, 0);
                // display player cards
                display_player_hand(deck, &cards_in_player_hand, face, suit, 5, 0);
                printf("\n");

                // deal dealer cards (6-10)
                printf("\nNow initializing dealer cards! \n");
                print_dealing();
                deal_cards(deck, &cards_in_dealer_hand, 5,0);
                // display_player_hand(deck, &cards_in_dealer_hand, face, suit, 5, 0);
                printf("\nDone!");
                printf("\n");

                /*int test = is_pair(cards_in_player_hand, freq_value);
                printf("Test = %d", test);*/

                // call function to update player cards (0-3)
                update_player_hand(deck, &cards_in_player_hand, face, suit, num_cards_player, index);

                // check dealer hand and draw new cards accordingly 
                printf("\n");
                print_updating_dealer();
                simulate_dealer(deck, &cards_in_dealer_hand, face, suit, num_cards_dealer, dealer_score, freq_value, index);
                printf("\nDone!");
                printf("\n");
                // display_player_hand(deck, &cards_in_dealer_hand, face, suit, num_cards_dealer, index);

                // check each hand
                player_hand_score = check_highest(player_score, &cards_in_player_hand, freq_value);
                // printf("\nplayer_hand_score: %d", player_hand_score);
                print_scoring();
                notify_player(player_hand_score);

                dealer_hand_score = check_highest(dealer_score, &cards_in_dealer_hand, freq_value);
                // printf("\ndealer_hand_score: %d", dealer_hand_score);
                print_scoring();
                notify_dealer(dealer_hand_score);

                // determine winner of that hand
                if (player_hand_score > dealer_hand_score)
                {
                    printf("\nCongrats player! You beat the house!");
                }
                if (player_hand_score < dealer_hand_score)
                {
                    printf("\nDamn, the house wins!");
                }
                if (dealer_hand_score == player_hand_score)
                {
                    printf("\nWow! A tie. I guess you'll have to play again!");
                }

                printf("\nWould you like to play again?");
                scanf(" %c", &play_again);

                system("cls"); //clear output screen
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
