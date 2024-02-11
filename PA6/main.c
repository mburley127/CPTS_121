#include "equations.h"

int main(void)
{
    srand((unsigned int)time(NULL)); // CALL 1 TIME @ begining of main

    int option = 0;
    char board_p1[MAX_ROWS][MAX_COLS] = { {'~'}, {'~'} };
    char board_p2[MAX_ROWS][MAX_COLS] = { {'~'}, {'~'} };
    char computer_board[MAX_ROWS][MAX_COLS] = { {'~'}, {'~'} };

    char p1_ships[5] = {'C', 'B', 'R', 'S', 'D'};
    char *p1_ship_ptr = &p1_ships;

    char p2_ships[5] = { 'C', 'B', 'R', 'S', 'D' };
    char *p2_ship_ptr = &p2_ships;

    int player_num = 0, current_player = 0;
    char player_choice = '\0';
    FILE * outfile = NULL;

    Stats player1;
    Stats player2;

    player1.num_hits = 0;
    player1.num_misses = 0;
    player1.total_shots = 0;
    player1.hits_misses_ratio = 0.0;

    player2.num_hits = 0;
    player2.num_misses = 0;
    player2.total_shots = 0;
    player2.hits_misses_ratio = 0.0;

    print_battleship();

    outfile = fopen("battleship.log", "w"); //w outputs to file

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

            print_generating();

            init_board(board_p1);
            init_board(board_p2);
            randomly_place_ships_on_board(board_p2);

            prompt_place_ships(board_p1);
            
            print_generating();

            printf("Player 1's (YOUR) board is: \n");
            print_player_board(board_p1);

            printf("\nHit any key to see who goes first!");
            getch(); // gets keyboard character
            print_slecting_player();

            player_num = rand() % 2 + 1;
            printf("\nThe player who starts will be: %d\n", player_num);

            // Wrap in loop to increment until all ships are sunk for either player
            int play_until1 = is_winner(board_p1, &p1_ships);
            int play_until2 = is_winner(board_p2, &p2_ships);

            do
            {
                if (player_num == 1)
                {
                    manual_shot(board_p2, outfile); // shoots at computer board
                    print_updating();
                    update_current_ships(board_p1, &p1_ships);

                    if (p1_ships[0] == '\0') // If Null Char ay array index 0, print Carrier destroyed
                    {
                        Sleep(2000);
                        printf("\nPlayer Carrier Destroyed!");
                    }
                    else if (p1_ships[1] == '\0') // If Null Char ay array index 1, print Battleship destroyed
                    {
                        Sleep(2000);
                        printf("\nPlayer Battleship Destroyed!");
                    }
                    else if (p1_ships[2] == '\0') // If Null Char ay array index 1, print Cruiser destroyed
                    {
                        Sleep(2000);
                        printf("\nPlayer Cruiser Destroyed!");
                    }
                    else if (p1_ships[3] == '\0') // If Null Char ay array index 1, print Submarine destroyed
                    {
                        Sleep(2000);
                        printf("\nPlayer Submarine Destroyed!");
                    }
                    else if (p1_ships[4] == '\0') // If Null Char ay array index 1, print Destroyer destroyed
                    {
                        Sleep(2000);
                        printf("\nPlayer Destroyer Destroyed!");
                    }

                    printf("\nUpdated Computer Board is: \n");
                    print_player_board(board_p2);
                    update_current_ships(computer_board, &p2_ships);
                    print_computer_board(computer_board);
                    
                    player_num = 2;
                }

                if (player_num == 2)
                {
                    random_shot(board_p1, outfile);
                    print_updating();
                    update_current_ships(board_p2, &p2_ships);

                    if (p2_ships[0] == '\0') // If Null Char ay array index 0, print Carrier destroyed
                    {
                        Sleep(2000);
                        printf("\nComputer Carrier Destroyed!");
                    }
                    else if (p2_ships[1] == '\0') // If Null Char ay array index 1, print Battleship destroyed
                    {
                        Sleep(2000);
                        printf("\nComputer Battleship Destroyed!");
                    }
                    else if (p2_ships[2] == '\0') // If Null Char ay array index 1, print Cruiser destroyed
                    {
                        Sleep(2000);
                        printf("\nComputer Cruiser Destroyed!");
                    }
                    else if (p2_ships[3] == '\0') // If Null Char ay array index 1, print Submarine destroyed
                    {
                        Sleep(2000);
                        printf("\nComputer Submarine Destroyed!");
                    }
                    else if (p2_ships[4] == '\0') // If Null Char ay array index 1, print Destroyer destroyed
                    {
                        Sleep(2000);
                        printf("\nComputer Destroyer Destroyed!");
                    }

                    printf("\nUpdated Player Board is: \n");
                    print_player_board(board_p1);

                    player_num = 1;
                }
            } while (play_until1 == 0 && play_until2 == 0);

            // Print winner
            if (is_winner(board_p1, &p1_ships))
            {
                printf("Player Wins - Congratulations Human. You have bested me... until we meet again.");
            }

            if (is_winner(board_p2, &p2_ships))
            {
                printf("Computer Wins - Take that human! You will always be inferior!");
            }

            // Call to output stats for Player 1
            output_stats_p1(board_p1, player1, outfile);

            // Call to output stats for Player 2
            output_stats_p2(board_p2, player2, outfile);

            fclose(outfile);

            break;

        case 3: printf("Thank you for playing!");
            break;

        default: // invalid options
            break;
        }
    } while (option != 3); // sentinel controlled loop



    return 0;
}
