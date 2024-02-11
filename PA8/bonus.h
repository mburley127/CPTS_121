#define _CRT_SECURE_NO_WARNINGS // necessary to ignore scanf_s () warnings

#ifndef EQUATIONS_H
#define EQUATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// Code for string cat function
char* my_str_n_cat(char* dest, const char* src, int n); // Appends n number of elements from source to the end of dest

// Code for Binary Search used from in class notes
int binary_search(int list[], int size, int target, int* pos_ptr);

// Bubble sorting strings
void bubble_sort(char* cars[], int num);

// Test if a number is prime, code help from (https://www.programiz.com/c-programming/examples/prime-number) - Credit Nate Burley for the idea
int is_prime(int num);

// Recursive Sum Primes
int sum_primes_rec(unsigned int num);

#endif
