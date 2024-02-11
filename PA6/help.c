#include <stdio.h>
#include <time.h>
#define MAX_ROWS 10
#define MAX_COLS 10
#define NUM_DIR 2

typedef enum direction
{
    VERTICAL, HORIZONTAL;
} Direction;

typedef struct stats
{
    int num_hits;
    int num_misses; 
    int total_shots;
    double hits_to_misses_ratio;
} Stats;

void init_board(char board[][MAX_COLS], int num_rows, int num_cols);

void display_board(char board[][MAX_COLS], int num_rows, int num_cols);

Direction genereate_dir(void);

void generate_start_pt (int *row_start_ptr, int *col_start_ptr, Direction dir, int ship_length);


int main (void)
{
    char p1_board[MAX_ROWS][MAX_COLS] = {{'~'},{'~'}};
    int row_start = 0, col_start = 0;

    dir = generate_dir();
    generate_start_pt(&row_start, &col_start, dir, 3);
}

void init_board(char board[][MAX_COLS], int num_rows, int num_cols)
{
    int row_index = 0, col_index = 0;

    for(; row_index < num_rows; ++row_index)
    {
        for(; col_index < num_cols; ++col_index)
        {
            board[row_index][col_index] = '~';
        }
    }
}

void display_board(char board[][MAX_COLS], int num_rows, int num_cols);
{
    int row_index = 0, col_index = 0;

    printf("%5d%4d%4d%4d%4d%4d%4d%4d%4d%4d%4d\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);

    for(; row_index < num_rows; ++row_index)
    {
        printf("%-2d", row_index);
        for(; col_index < num_cols; ++col_index)
        {
            printf("|%2c ", board[row_index][col_index]);
        }
        putchar("\n");
    }
}

Direction genereate_dir(void)
{
    return (Direction)(rand()% NUM_DIR);
}

generate_start_pt (int *row_start_ptr, int *col_start_ptr, Direction dir, int ship_length)
{
    if (dir == HORIZONTAL)
    {
        *row_start_ptr = rand() % MAX_ROWS;
        *col_start_ptr = rand() % (MAX_COLS - ship_length + 1);
    }
    else if (dir == VERTICAL)
    {
        *row_start_ptr = rand() % (MAX_ROWS - ship_length + 1);
        *col_start_ptr = rand() % MAX_COLS;
    }
}


// Output function help
FILE* infile = NULL, * outfile = NULL;

infile = fopen("payroll.txt", "r"); //r stands for read
outfile = fopen("payroll.txt", "w"); //w outputs to another file


/*FILE* outfile = fopen("battleship_log.log", "w");

	Stats player1, player2;

	player1.num_misses = 0;
	player1.num_hits = 0;

	player1.num_hits++;
	player1.num_misses++;

	fprintf("Player 1's stats are: ");
	fprintf(outfile, "\nPlayer 1 took a total of %d shots", player1.num_misses + player1.num_hits);
	printf("Player 1 missed %d times\n\n", player1.num_hits);*/



// Selina Nguyen helped with this function
// Function outputs when carrier has been sunk
void check_carrier(char board[][MAX_COLS], FILE* outfile)
{
    int check = 0;

    for (int i = 0; i < MAX_COLS; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            if (board[i][j] == SHIP_CARR) // If there's still Carrier ships on board, check set to 1
            {
                check = 1;
            }
        }
    }

    if (check != 1) // If check is NOT 1, no carrier ships, so display ship was sunk
    {
        fprintf(outfile, "\nThe Carrier has been sunk!");
        printf("\nThe Carrier has been sunk!");
    }
}

// Function outputs when Battleship has been sunk
void check_battleship(char board[][MAX_COLS], FILE* outfile)
{
    int check = 0;

    for (int i = 0; i < MAX_COLS; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            if (board[i][j] == SHIP_BAT) // If there's still Battleship ships on board, check set to 1
            {
                check = 1;
            }
        }
    }

    if (check != 1) // If check is NOT 1, no Battleship ships, so display ship was sunk
    {
        fprintf(outfile, "\nThe Battleship has been sunk!");
        printf("\nThe Battleship has been sunk!");
    }
}

// Function outputs when Cruiser has been sunk
void check_cruiser(char board[][MAX_COLS], FILE* outfile)
{
    int check = 0;

    for (int i = 0; i < MAX_COLS; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            if (board[i][j] == SHIP_CRUISE) // If there's still Cruiser ships on board, check set to 1
            {
                check = 1;
            }
        }
    }

    if (check != 1) // If check is NOT 1, no Cruiser ships, so display ship was sunk
    {
        fprintf(outfile, "\nThe Cruiser has been sunk!");
        printf("\nThe Cruiser has been sunk!");
    }
}

// Function outputs when Submarine has been sunk
void check_submarine(char board[][MAX_COLS], FILE* outfile)
{
    int check = 0;

    for (int i = 0; i < MAX_COLS; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            if (board[i][j] == SHIP_SUB) // If there's still Submarine ships on board, check set to 1
            {
                check = 1;
            }
        }
    }

    if (check != 1) // If check is NOT 1, no Submarine ships, so display ship was sunk
    {
        fprintf(outfile, "\nThe Submarine has been sunk!");
        printf("\nThe Submarine has been sunk!");
    }
}

// Function outputs when Destroyer has been sunk
void check_destroyer(char board[][MAX_COLS], FILE* outfile)
{
    int check = 0;

    for (int i = 0; i < MAX_COLS; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            if (board[i][j] == SHIP_DEST) // If there's still Destroyer ships on board, check set to 1
            {
                check = 1;
            }
        }
    }

    if (check != 1) // If check is NOT 1, no Destroyer ships, so display ship was sunk
    {
        fprintf(outfile, "\nThe Destroyer has been sunk!");
        printf("\nThe Destroyer has been sunk!");
    }
}
