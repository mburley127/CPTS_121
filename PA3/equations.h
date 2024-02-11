#define _CRT_SECURE_NO_WARNINGS // necessary to ignore scanf_s () warnings

#ifndef EQUATIONS_H
#define EQUATIONS_H

#include <stdio.h>
#include <math.h>

/***************************************************************************************************************************************
* Function: double read_double(FILE* infile)
* Date Created: Feb 17, 2021
* Date Last Modified: Feb 22, 2021
* Description: This function reads a floating-point value from input.dat
* Input Parameters: Input file
* Returns: floating-point value
* Preconditions: File input.dat
* Postconditions: floating-point value from input.dat is returned
***************************************************************************************************************************************/
double read_double(FILE* infile);

/***************************************************************************************************************************************
* Function: int read_double(FILE* infile)
* Date Created: Feb 17, 2021
* Date Last Modified: Feb 22, 2021
* Description: This function reads an integer value from input.dat
* Input Parameters: Input file
* Returns: integer value
* Preconditions: File input.dat
* Postconditions: integer value from input.dat is returned
***************************************************************************************************************************************/
int read_integer(FILE* infile);

/***************************************************************************************************************************************
* Function: double calculate_sum(double number1, double number2, double number3, double number4, double number5)
* Date Created: Feb 17, 2021
* Date Last Modified: Feb 22, 2021
* Description: This function computes the sum of 5 numbers
* Input Parameters: 5 floating-point numbers
* Returns: floating-point value for the sum of the five numbers
* Preconditions: floating-point values
* Postconditions: sum of 5 numbers is returned
***************************************************************************************************************************************/
double calculate_sum(double number1, double number2, double number3, double number4, double number5);

/***************************************************************************************************************************************
* Function: double calculate_mean(double sum, int number)
* Date Created: Feb 17, 2021
* Date Last Modified: Feb 22, 2021
* Description: This function computes the mean (average)
* Input Parameters: The floating-point sum of a set of numbers, and the integer number of values
* Returns: floating-point value for the mean
* Preconditions: floating-point value for the sum, and an integer value for the number of values
* Postconditions: mean is returned
***************************************************************************************************************************************/
double calculate_mean(double sum, int number);

/***************************************************************************************************************************************
* Function: double calculate_deviation(double number, double mean)
* Date Created: Feb 17, 2021
* Date Last Modified: Feb 22, 2021
* Description: This function computes the deviation by subtracting a given number from the mean
* Input Parameters: The floating-point mean of a set of numbers, and a floating-point number
* Returns: floating-point value for the deviation
* Preconditions: floating-point value for the mean and the number for computation
* Postconditions: deviation is returned
***************************************************************************************************************************************/
double calculate_deviation(double number, double mean);

/***************************************************************************************************************************************
* Function: double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number)
* Date Created: Feb 18, 2021
* Date Last Modified: Feb 22, 2021
* Description: This function computes the variance of 5 deviation values from a number of values by summing the squares of each deviation value and dividing by the number of values
* Input Parameters: The floating-point of 5 deviation values, and an integer number of values
* Returns: floating-point value for the variance
* Preconditions: floating-point values for the deviations, and the number for computation
* Postconditions: variance is returned
***************************************************************************************************************************************/
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);

/***************************************************************************************************************************************
* Function: double calculate_standard_deviation(double variance)
* Date Created: Feb 18, 2021
* Date Last Modified: Feb 22, 2021
* Description: This function computes the standard deviation by computing the square root of the variance
* Input Parameters: The floating-point of variance value
* Returns: floating-point value for the standard deviation
* Preconditions: floating-point value for the variance
* Postconditions: standard deviation is returned
***************************************************************************************************************************************/
double calculate_standard_deviation(double variance);

/***************************************************************************************************************************************
* Function: double find_max(double number1, double number2, double number3, double number4, double number5)
* Date Created: Feb 20, 2021
* Date Last Modified: Feb 22, 2021
* Description: This function finds the largest (max) value of a given set of 5 numbers
* Input Parameters: The floating-point values of 5 numbers
* Returns: floating-point value for returned largest value
* Preconditions: floating-point values for the 5 numbers
* Postconditions: the largest value is returned
***************************************************************************************************************************************/
double find_max(double number1, double number2, double number3, double number4, double number5);

/***************************************************************************************************************************************
* Function: double find_min(double number1, double number2, double number3, double number4, double number5)
* Date Created: Feb 20, 2021
* Date Last Modified: Feb 22, 2021
* Description: This function finds the smallest (max) value of a given set of 5 numbers
* Input Parameters: The floating-point values of 5 numbers
* Returns: floating-point value for returned smallest value
* Preconditions: floating-point values for the 5 numbers
* Postconditions: the smallest value is returned
***************************************************************************************************************************************/
double find_min(double number1, double number2, double number3, double number4, double number5);

/***************************************************************************************************************************************
* Function: void print_double(FILE* outfile, double number)
* Date Created: Feb 20, 2021
* Date Last Modified: Feb 22, 2021
* Description: This function prints a floating-point value to an output file
* Input Parameters: The floating-point value being printed and the outfile
* Returns: printed floating-point value in an output file
* Preconditions: floating-point value being printed and the outfile
* Postconditions: the floating-point result is printed to 2 decimal places
***************************************************************************************************************************************/
void print_double(FILE* outfile, double number);

#endif
