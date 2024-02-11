#define _CRT_SECURE_NO_WARNINGS // necessary to ignore scanf_s () warnings

#ifndef EQUATIONS_H
#define EQUATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define NUM_SHIPS 5
#define NUM_DIR 2
#define CARRIER 5
#define BATTLESHIP 4
#define CRUISER 3
#define SUBMARINE 3
#define DESTROYER 2

#define SHIP_CARR 'C'
#define SHIP_BAT 'B'
#define SHIP_CRUISE 'R'
#define SHIP_SUB 'S'
#define SHIP_DEST 'D'

typedef struct stats
{
	int num_hits;
	int num_misses;
	int total_shots;
	double hits_misses_ratio;
} Stats;

void display_menu(void);

int get_option(void);

int validate_option(void);

void print_game_rules(void);

void print_battleship(void);

void init_board(char board[][MAX_COLS]); // sets each cell in a game board to '-'.

void print_player_board(char board[][MAX_COLS]); // function that displays a board to the screen. Player1's board should be displayed differently than Player2's board.
// Hint: pass in a flag(int) that stores whether or not you just passed in Player1's or Player2's board.Then perform the different logic for Player1's board versus Player2's board.

void print_computer_board(char board[][MAX_COLS]);

// char select_who_starts_first(int player_num); // function randomly determines if Player 1 or Player 2 goes first in the game.

void place_ship(char board[][MAX_COLS], int ship_size, char ship_letter, int direction, int row_choice, int col_choice);

int validate_off_board(char board[][MAX_COLS], int row_choice, int col_choice, int ship_size, char direction);

int validate_not_overlap(char board[][MAX_COLS], int row_choice, int col_choice, int ship_size, char direction);

void manually_place_ships_on_board(char board[][MAX_COLS]); // function that allows the user to place each of the 5 types of ships on his / her game board.

char generate_dir(void);

void generate_start_pt(int* row_start_ptr, int* col_start_ptr, char dir, int ship_length);

void randomly_place_ships_on_board(char board[][MAX_COLS]); // function that randomly places the 5 types of ships on a given board.

void prompt_place_ships(char board[][MAX_COLS]); // Asks user if they want to manually(m) or randomly(r) place their ships, if m, call manually_place_ships_on_board() if r call randomly_place_ships_on_board()

int check_shot(char board[][MAX_COLS], int row_shot, int col_shot); // Takes a shot at board, function determines if the shot taken was a hit or a miss.

void update_board(char board[][MAX_COLS], int hit_or_miss, int row_shot, int col_shot, FILE* outfile); // function that updates the board every time a shot is taken. '*' indicates a hit and 'm' indicates a miss.

void manual_shot(char board[][MAX_COLS], FILE* outfile);

void random_shot(char board[][MAX_COLS], FILE* outfile);

int check_if_sunk_ship(char board[][MAX_COLS], char ship_letter); // function that determines if a ship was sunk.

void update_current_ships(char board[][MAX_COLS], char* ships_left);

int is_winner(char board[][MAX_COLS], char* ships_left); // function that determines if a winner exists.

void output_stats_p1(char board[][MAX_COLS], Stats player1, FILE* outfile);

void output_stats_p2(char board[][MAX_COLS], Stats player2, FILE* outfile); // function that writes the statistics collected on each player to the log file.

void print_generating(void);

void print_slecting_player(void);

void print_updating(void);


#endif
