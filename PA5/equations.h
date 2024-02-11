#define _CRT_SECURE_NO_WARNINGS // necessary to ignore scanf_s () warnings

#ifndef EQUATIONS_H
#define EQUATIONS_H
#define MAX_SIZE 6
#define SC_MAX_SIZE 13
#define UP_MAX_SIZE 6
#define LOW_MAX_SIZE 7
#define FREQ_MAX_SIZE 7

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


void display_menu(void);

int get_option(void);

int validate_option(void);

void print_game_rules(void);

void init_roll_die(void);

void display_dice(int dice[], int i);

void print_rolling(void);

void update_dice_values(int dice[]);

void display_scoreboard(void);

int aces(int dice[], int frequency[]);

int twos(int dice[], int frequency[]);

int threes(int dice[], int frequency[]);

int fours(int dice[], int frequency[]);

int fives(int dice[], int frequency[]);

int sixes(int dice[], int frequency[]);

int three_of_kind(int dice[], int frequency[]); // Checks for 3 of a kind, and sums ALL the dice values together for points

int four_of_kind(int dice[], int frequency[]); // Checks for 4 of a kind, and sums ALL the dice values together for points

int full_house(int dice[], int frequency[]); // Checks for 3 of a kind and 2 of a kind, awards 25 points to player

int small_straight(int dice[], int frequency[]); // Checks for 4 dice values in sequential order, awards 30 points to player

int large_straight(int dice[], int frequency[]); // Checks for 5 dice values in sequential order, awards 40 points to player

int yahtzee(int dice[], int frequency[]); // Checks for 5 of a kind, awards 50 points to player

int chance(int dice[], int frequency[]);

void compute_score(int dice[], int scoreboard[], int frequency[], int sb_upper[], int sb_lower[]);

int total_score(int sb_upper[], int sb_lower[], int* total);

void play_round(int dice[], int scoreboard[], int frequency[], int sb_upper[], int sb_lower[], int num_dice);

#endif
