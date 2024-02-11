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

void print_battleship(void)
{
    printf("\n.______        ___   .___________.___________. __       _______     _______. __    __   __  .______    __");
    printf("\n|   _  |      /   |  |           |           ||  |     |   ____|   /       ||  |  |  | |  | |   _  |  |  |");
    printf("\n|  |_)  |    /  ^  | `---|  |----`---|  |----`|  |     |  |__     |   (----`|  |__|  | |  | |  |_)  | |  |");
    printf("\n|   _  <    /  |_|  |    |  |        |  |     |  |     |   __|     |   |    |   __   | |  | |   ___/  |  |");
    printf("\n|  |_)  |  /  _____  |   |  |        |  |     |  `----.|  |____.----)   |   |  |  |  | |  | |  |      |__|");
    printf("\n|______|  /__|     |__|  |__|        |__|     |_______||_______|_______/    |__|  |__| |__| | _|      (__)");
}

void print_game_rules(void) // Prints out the rules of the game of "Battleship".
{
    printf("The Game Rules are: Battleship is a two player Navy game. The objective of the game is to sink all ships in your enemy's fleet. The Player to sink his/her enemy's fleet first wins. Both players' fleets consist of 5 ships that are hidden from the enemy. Each ship may be differentiated by its size (besides the Cruiser and Submarine) or number of cells it expands on the game board. The Carrier has 5 cells, Battleship has 4 cells, Cruiser has 3 cells, Submarine has 3 cells, and the Destroyer has 2 cells. Once it has been decided on which player goes first, the game starts. Whenever it's Player 1's turn, a prompt should be displayed asking for a position to target on the enemy's Player 2's board. The position should be specified in terms of a row and a column on the board. In one turn, a player can only take one shot at the enemy's (other player's) fleet. The game is over when Player 1 or Player 2 has sunk all of the ships in the fleet of the enemy.");
}

void init_board(char board[][MAX_COLS])
{
    int row_index = 0, col_index = 0;

    for (; row_index < MAX_ROWS; ++row_index)
    {
        for (col_index = 0; col_index < MAX_COLS; ++col_index)
        {
            board[row_index][col_index] = '~';
        }
    }
}

void print_player_board(char board[][MAX_COLS])
{
    int row_index = 0, col_index = 0;

    printf("%5d%4d%4d%4d%4d%4d%4d%4d%4d%4d\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
    for (; row_index < MAX_ROWS; ++row_index)
    {
        printf("%-2d", row_index);
        for (col_index = 0; col_index < MAX_COLS; ++col_index)
        {
            printf("|%2c ", board[row_index][col_index]);
        }
        putchar('\n');
    }
}

void print_computer_board(char board[][MAX_COLS])
{
    int row_index = 0, col_index = 0;
    char place_holder = '~';

    printf("%5d%4d%4d%4d%4d%4d%4d%4d%4d%4d\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
    for (; row_index < MAX_ROWS; ++row_index)
    {
        printf("%-2d", row_index);
        for (col_index = 0; col_index < MAX_COLS; ++col_index)
        {
            if (board[row_index][col_index] == '~' || board[row_index][col_index] == '*' || board[row_index][col_index] == 'm')
            {
                printf("|%2c ", board[row_index][col_index]);
            }
            else
            {
                printf("|%2c ", place_holder);
            }
        }
        putchar('\n');
    }
}

void place_ship(char board[][MAX_COLS], int ship_size, char ship_letter, int direction, int row_choice, int col_choice)
{
    int count = 0, i, j;

    // Place "ship letter" in each desired spot on the board, if right increment columns, if down, increment rows
    if (direction == 'R' || direction == 'r') // User wants ship to go right, need to increment columns
    {
        do
        {

            for (i = 0; i < MAX_ROWS; i++)
            {
                for (j = 0; j <= count; j++)
                {
                    board[row_choice][col_choice + j] = ship_letter;
                }
            }
            count++;
        } while (count != ship_size);
    }

    if (direction == 'D' || direction == 'd')
    {
        do
        {

            for (i = 0; i < MAX_COLS; i++)
            {
                for (j = 0; j <= count; j++)
                {
                    board[row_choice + j][col_choice] = ship_letter;
                }
            }
            count++;
        } while (count != ship_size);
    }
}

int validate_off_board(char board[][MAX_COLS], int row_choice, int col_choice, int ship_size, char direction)
{
    if (direction == 'r' || direction == 'R')
    {
        if (col_choice + ship_size > MAX_COLS)
        {
            return -1;
        }
    }

    if (direction == 'd' || direction == 'D')
    {
        if (row_choice + ship_size > MAX_ROWS)
        {
            return -1;
        }
    }

    return 1;
}

int validate_not_overlap(char board[][MAX_COLS], int row_choice, int col_choice, int ship_length, char direction)
{
    if (direction == 'r' || direction == 'R')
    {
        for (int i = 0; i <= ship_length; i++)
        {
            if (board[row_choice][col_choice + i] != '~')
            {
                return -1;
            }
        }
    }

    if (direction == 'd' || direction == 'D')
    {
        for (int i = 0; i <= ship_length; i++)
        {
            if (board[row_choice + i][col_choice] != '~') // Error here on random placement!
            {
                return -1;
            }
        }
    }
    return 1;
}

void manually_place_ships_on_board(char board[][MAX_COLS]) // function that allows the user to place each of the 5 types of ships on game board. PLACE USER ENTERED VALUES IN BOARD ARRAY
{
    int direction1 = 0, direction2 = 0, direction3 = 0, direction4 = 0, direction5 = 0;
    int row1 = 0, row2 = 0, row3 = 0, row4 = 0, row5 = 0, col1 = 0, col2 = 0, col3 = 0, col4 = 0, col5 = 0;
    int out1 = -1, out2 = -1, out3 = -1, out4 = -1, out5 = -1;
    int overlap1 = -1, overlap2 = -1, overlap3 = -1, overlap4 = -1, overlap5 = -1;

    // Prompt for Carrier Placement
    do
    {
        printf("Enter the row and column number for Carrier as an ordered pair (0-9): ");
        scanf("%d %d", &row1, &col1);

        do
        {
            printf("Enter the direction you want the Carrier to go, from the starting coordinate (right or down) [R/D]: ");
            scanf(" %c", &direction1);
        } while (direction1 != 'r' && direction1 != 'R' && direction1 != 'd' && direction1 != 'D');

        // Validate that the ship is not off the board
        out1 = validate_off_board(board, row1, col1, CARRIER, direction1);

        // Validate that the ship does not overlap with other ships
        overlap1 = validate_not_overlap(board, row1, col1, CARRIER, direction1);
    } while (out1 == -1 || overlap1 == -1);

    place_ship(board, CARRIER, SHIP_CARR, direction1, row1, col1);


    // Prompt for Battleship Placement
    do
    {
        printf("Enter the row and column number for Battleship as an ordered pair (0-9): ");
        scanf("%d %d", &row2, &col2);
        do
        {
            printf("Enter the direction you want the Battleship to go, from the starting coordinate (right or down) [R/D]: ");
            scanf(" %c", &direction2);
        } while (direction2 != 'r' && direction2 != 'R' && direction2 != 'd' && direction2 != 'D');

        // Validate that the ship is not off the board
        out2 = validate_off_board(board, row2, col2, BATTLESHIP, direction2);

        // Validate that the ship does not overlap with other ships
        overlap2 = validate_not_overlap(board, row2, col2, BATTLESHIP, direction2);
    } while (out2 == -1 || overlap2 == -1);

    place_ship(board, BATTLESHIP, SHIP_BAT, direction2, row2, col2);

    // Prompt for Cruiser Placement
    do
    {
        printf("Enter the row and column number for Cruiser as an ordered pair (0-9): ");
        scanf("%d %d", &row3, &col3);

        do
        {
            printf("Enter the direction you want the Cruiser to go, from the starting coordinate (right or down) [R/D]: ");
            scanf(" %c", &direction3);
        } while (direction3 != 'r' && direction3 != 'R' && direction3 != 'd' && direction3 != 'D');

        // Validate that the ship is not off the board
        out3 = validate_off_board(board, row3, col3, CRUISER, direction3);

        // Validate that the ship does not overlap with other ships
        overlap3 = validate_not_overlap(board, row3, col3, CRUISER, direction3);
    } while (out3 == -1 || overlap3 == -1);

    place_ship(board, CRUISER, SHIP_CRUISE, direction3, row3, col3);

    // Prompt for Submarine Placement
    do
    {
        printf("Enter the row and column number for Submarine as an ordered pair (0-9): ");
        scanf("%d %d", &row4, &col4);

        do
        {
            printf("Enter the direction you want the Submarine to go, from the starting coordinate (right or down) [R/D]: ");
            scanf(" %c", &direction4);
        } while (direction4 != 'r' && direction4 != 'R' && direction4 != 'd' && direction4 != 'D');

        // Validate that the ship is not off the board
        out4 = validate_off_board(board, row4, col4, SUBMARINE, direction4);

        // Validate that the ship does not overlap with other ships
        overlap4 = validate_not_overlap(board, row4, col4, SUBMARINE, direction4);
        
    } while (out4 == -1 || overlap4 == -1);

    place_ship(board, SUBMARINE, SHIP_SUB, direction4, row4, col4);

    // Prompt for Destroyer Placement
    do
    {
        printf("Enter the row and column number for Destroyer as an ordered pair (0-9): ");
        scanf("%d %d", &row5, &col5);

        do
        {
            printf("Enter the direction you want the Destroyer to go, from the starting coordinate (right or down) [R/D]: ");
            scanf(" %c", &direction5);
        } while (direction5 != 'r' && direction5 != 'R' && direction5 != 'd' && direction5 != 'D');

        // Validate that the ship is not off the board
        out5 = validate_off_board(board, row5, col5, DESTROYER, direction5);

        // Validate that the ship does not overlap with other ships
        overlap5 = validate_not_overlap(board, row5, col5, DESTROYER, direction5);

    } while (out5 == -1 || overlap5 == -1);
    
    place_ship(board, DESTROYER, SHIP_DEST, direction5, row5, col5);
}

char generate_dir(void)
{
    int num = 0;

    num = (rand() % NUM_DIR); // if 1 do something

    if (num == 1)
    {
        return 'r';
    }

    else
    {
        return 'd';
    }

}

void generate_start_pt(int *row_start, int *col_start, char dir, int ship_length)
{
    if (dir == 'r')
    {
        *row_start = rand() % MAX_ROWS;
        *col_start = rand() % (MAX_COLS - ship_length + 1);
    }
    else if (dir == 'd')
    {
        *row_start = rand() % (MAX_ROWS - ship_length + 1);
        *col_start = rand() % MAX_COLS;
    }
}

void randomly_place_ships_on_board(char board[][MAX_COLS])
{
    int row_start = 0, col_start = 0;
    char dir1 = '\0', dir2 = '\0', dir3 = '\0', dir4 = '\0', dir5 = '\0';
    int overlap1 = -1, overlap2 = -1, overlap3 = -1, overlap4 = -1, overlap5 = -1;

    do
    {
        dir1 = generate_dir();
        generate_start_pt(&row_start, &col_start, dir1, CARRIER);

        // Validate that the ship does not overlap with other ships
        overlap1 = validate_not_overlap(board, row_start, col_start, CARRIER, dir1);
    } while (overlap1 == -1);

    place_ship(board, CARRIER, SHIP_CARR, dir1, row_start, col_start);

    do
    {
        dir2 = generate_dir();
        generate_start_pt(&row_start, &col_start, dir2, BATTLESHIP);

        // Validate that the ship does not overlap with other ships
        overlap2 = validate_not_overlap(board, row_start, col_start, BATTLESHIP, dir2);
    } while (overlap2 == -1);

    place_ship(board, BATTLESHIP, SHIP_BAT, dir2, row_start, col_start);

    do
    {
        dir3 = generate_dir();
        generate_start_pt(&row_start, &col_start, dir3, CRUISER);

        // Validate that the ship does not overlap with other ships
        overlap3 = validate_not_overlap(board, row_start, col_start, CRUISER, dir3);
    } while (overlap3 == -1);

    place_ship(board, CRUISER, SHIP_CRUISE, dir3, row_start, col_start);

    do
    {
        dir4 = generate_dir();
        generate_start_pt(&row_start, &col_start, dir4, SUBMARINE);

        // Validate that the ship does not overlap with other ships
        overlap4 = validate_not_overlap(board, row_start, col_start, SUBMARINE, dir4);
    } while (overlap4 == -1);

    place_ship(board, SUBMARINE, SHIP_SUB, dir4, row_start, col_start);

    do
    {
        dir5 = generate_dir();
        generate_start_pt(&row_start, &col_start, dir5, DESTROYER);

        // Validate that the ship does not overlap with other ships
        overlap5 = validate_not_overlap(board, row_start, col_start, DESTROYER, dir5);
    } while (overlap5 == -1);

    place_ship(board, DESTROYER, SHIP_DEST, dir5, row_start, col_start);
}

void prompt_place_ships(char board[][MAX_COLS]) // Asks user if they want to manually(m) or randomly(r) place their ships, if m, call manually_place_ships_on_board() if r call randomly_place_ships_on_board()
{
    char m_or_r = '\0';

    do
    {
        printf("Would you like to place your ships manually(M) or Randomly(R) [M/R]: "); // Prompts to place ships manually or randomly, and validates user entered option. If not a M or R, re-prompts 
        scanf(" %c", &m_or_r);
    } while (m_or_r != 'm' && m_or_r != 'M' && m_or_r != 'r' && m_or_r != 'R');

    if (m_or_r == 'm' || m_or_r == 'M') // user requested manual ship entry
    {
        manually_place_ships_on_board(board);
    }

    if (m_or_r == 'r' || m_or_r == 'R') // user requested random ship entry
    {
        randomly_place_ships_on_board(board);
    }
}

int check_shot(char board[][MAX_COLS], int row_shot, int col_shot) // function determines if the shot taken was a hit or a miss.
{
    // Checks for HIT
    if (board[row_shot][col_shot] != '~')
    {
        return 1; 
    }

    // Checks for MISS
    if (board[row_shot][col_shot] == '~')
    {
        return 0;
    }
}

void update_board(char board[][MAX_COLS], int hit_or_miss, int row_shot, int col_shot, FILE* outfile) // function that updates the board every time a shot is taken. '*' indicates a hit and 'm' indicates a miss.
{
    int ship_length = 0;

    if (hit_or_miss == 1) // Player Hit
    {
        for (int i = 0; i < MAX_COLS; i++)
        {
            for (int j = 0; j < MAX_COLS; j++)
            {
                board[row_shot][col_shot] = '*';
            }
        }
        printf("\nHit!\n");
        fprintf(outfile, "\nHit!\n");
    }

    if (hit_or_miss == 0) // Player Missed
    {
        for (int i = 0; i < MAX_COLS; i++)
        {
            for (int j = 0; j < MAX_COLS; j++)
            {
                board[row_shot][col_shot] = 'm';
            }
        }
        printf("\nMissed!\n");
        fprintf(outfile, "\nMissed!\n");
    }
}

void manual_shot(char board[][MAX_COLS], FILE *outfile)
{
    int hit_or_miss = 0;
    int row_shot = 0, col_shot = 0;

    printf("Enter the coordinate you'd like to shoot at: ");
    scanf("%d %d", &row_shot, &col_shot);
    fprintf(outfile, "Player shot at: (%d,%d)", row_shot, col_shot);

    hit_or_miss = check_shot(board, row_shot, col_shot);
    //printf("\nHit or miss: %d\n", hit_or_miss);

    printf("\nShooting...");
    Sleep(2000);
    update_board(board, hit_or_miss, row_shot, col_shot, outfile);
}

void random_shot(char board[][MAX_COLS], FILE* outfile)
{
    // Generate random coordinate, call check_shot and update_board functions
    int row_shot = 0, col_shot = 0;
    int hit_or_miss = 0;

    row_shot = rand() % MAX_ROWS;
    col_shot = rand() % MAX_COLS;

    printf("Computer shot at: (%d,%d)", row_shot, col_shot);
    fprintf(outfile, "Computer shot at: (%d,%d)", row_shot, col_shot);

    hit_or_miss = check_shot(board, row_shot, col_shot);

    printf("\nShooting...");
    Sleep(2000);
    update_board(board, hit_or_miss, row_shot, col_shot, outfile);
}

int check_if_sunk_ship(char board[][MAX_COLS], char ship_letter) // function that determines if a ship chars are still on the board
{
    for (int i = 0; i < MAX_COLS; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            if (board[i][j] == ship_letter)
            {
                // ship letters still on board
                return 0;
            }
        }
    }
    return 1;
}

// Nate Burley helped with this function and implementation
void update_current_ships(char board[][MAX_COLS], char *ships_left)
{
    int sunk_ship = 0;
    // If sunk_ship = ship_letter, ships still on board, otherwise, ship sank

    for (int i = 0; i < NUM_SHIPS; i++) 
    {
        char ship = ships_left[i];
        //printf("\nValue: %c", ship);

        if (check_if_sunk_ship(board, ship) == 1) 
        {
            ships_left[i] = '\0';
        }
    }
}

int is_winner(char board[][MAX_COLS], char* ships_left) // function that determines if a winner exists.
{
    for (int i = 0; i < 5; i++)
    {
        if (ships_left[i] != '\0') // No ships on board, player wins
        {
            return 0;
        }
    }
    return 1;
}

void output_stats_p1(char board[][MAX_COLS], Stats player1, FILE* outfile) // function that writes the statistics collected on each player to the log file.
{
    for (int i = 0; i < MAX_COLS; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            if (board[i][j] == '*')
            {
                player1.num_hits++;
            }

            if (board[i][j] == 'm')
            {
                player1.num_misses++;
            }
        }
    }

    fprintf(outfile, "Player 1's stats are: ");
    fprintf(outfile, "\nPlayer 1 took a total of %d shots", player1.num_misses + player1.num_hits);
    fprintf(outfile, "\nPlayer 1 missed %d times", player1.num_misses);
    fprintf(outfile, "\nPlayer 1 hit %d times", player1.num_hits);
    fprintf(outfile, "\nPlayer 1 hits to misses ratio is: %lf", (double)(player1.num_hits / player1.num_misses));
}

void output_stats_p2(char board[][MAX_COLS], Stats player2, FILE* outfile) // function that writes the statistics collected on each player to the log file.
{
    for (int i = 0; i < MAX_COLS; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            if (board[i][j] == '*')
            {
                player2.num_hits++;
            }

            if (board[i][j] == 'm')
            {
                player2.num_misses++;
            }
        }
    }

    printf("\nPlayer 2 missed % d times", player2.num_misses);
    fprintf(outfile, "Player 2's stats are: ");
    fprintf(outfile, "\nPlayer 2 took a total of %d shots", player2.num_misses + player2.num_hits);
    fprintf(outfile, "\nPlayer 2 missed %d times", player2.num_misses);
    fprintf(outfile, "\nPlayer 2 hit %d times", player2.num_hits);
    fprintf(outfile, "\nPlayer 2 hits to misses ratio is: %lf", (double)(player2.num_hits / player2.num_misses));
}

void print_generating(void)
{
    printf("Generating...\n");
    Sleep(2000);
}

void print_slecting_player(void)
{
    printf("\nSelecting Player...");
    Sleep(2000);
}

void print_updating(void)
{
    printf("\nUpdating...\n");
    Sleep(2000);
}
