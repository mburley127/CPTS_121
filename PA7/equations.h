#define _CRT_SECURE_NO_WARNINGS // necessary to ignore scanf_s () warnings

#ifndef EQUATIONS_H
#define EQUATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct card
{
	// index of the value of the face, ace = 1, duece = 2...
	int index_face;
	// index of the suit, hearts = 0, diamonds = 1, clubs = 2, spades = 3
	int index_suit;
	// black = 0, red = 1
	// int color;
	// not played = 0, played = 1
	int is_played;
} Card;

typedef struct hand
{
	Card player_cards[5]; // Houses the the face index, the suit index, the color, and whether or not it's been played
} Hand;


void print_dealing(void);

void deal_cards(Card deck[][13], Hand *cards_in_hand, int num_cards);

void display_player_hand(Card deck[][13], Hand* cards_in_hand, const char* wFace[], const char* wSuit[], int num_cards);

void update_player_hand(Card deck[][13], Hand* cards_in_hand, const char* wFace[], const char* wSuit[], int num_cards_player);

int is_pair(Hand *cards_in_hand, int freq_value[]); // Must have two ticks in frequency card value array at one spot, SUIT DOES NOT MATTER

int is_two_pair(Hand *cards_in_hand, int freq_value[]); // Must have two sets of two ticks in frequency card value array, SUIT DOES NOT MATTER

int is_three_of_kind(Hand *cards_in_hand, int freq_value[]); // Must have three ticks in frequency card value array in one spot, SUIT DOES NOT MATTER

int is_four_of_kind(Hand *cards_in_hand, int freq_value[]); // Must have four ticks in frequency card value array at one spot, SUIT DOES NOT MATTER

int is_flush(Hand *cards_in_hand); // Must have 5 of the same suit in frequency suit array, VALUE DOES NOT MATTER

int is_stright(Hand *cards_in_hand, int freq_value[]); // Must have five ticks in frequency card value array in sequential order, SUIT DOES NOT MATTER

void auto_score_hand(int freq_score_arr[], Hand* cards_in_hand, int freq_value[]);

int check_highest(int freq_score_arr[], Hand* cards_in_hand, int freq_value[]);

void test(Card deck[][13], Hand *cards_in_hand);

void notify_player(int player_hand_score);

void notify_dealer(int dealer_hand_score);

#endif
