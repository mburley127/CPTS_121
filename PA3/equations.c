#include "equations.h"



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
double read_double(FILE* infile)
{
    double value_double = 0.0;
    fscanf(infile, "%lf", &value_double);
    return value_double;
}

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
int read_integer(FILE* infile)
{
    int value_int = 0;
    fscanf(infile, "%d", &value_int);
    return value_int;
}

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
double calculate_sum(double number1, double number2, double number3, double number4, double number5)
{
    double sum = 0.0;
    sum = number1 + number2 + number3 + number4 + number5;
    return sum;
}

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
double calculate_mean(double sum, int number)
{
    double mean = 0.0;
    mean = sum / number;
    return mean;
}

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
double calculate_deviation(double number, double mean)
{
    double deviation = 0.0;
    deviation = number - mean;
    return deviation;
}

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
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number)
{
    double variance = 0.0;
    variance = ((((deviation1) * (deviation1)) + ((deviation2) * (deviation2)) + ((deviation3) * (deviation3)) + ((deviation4) * (deviation4)) + ((deviation5) * (deviation5))) / number);
    return variance;
}

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
double calculate_standard_deviation(double variance)
{
    double std_dev = 0.0;
    std_dev = sqrt(variance);
    return std_dev;
}

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
double find_max(double number1, double number2, double number3, double number4, double number5)
{
    double max = number1;

    if (number2 > max)
    {
        max = number2;
    }
    if (number3 > max)
    {
        max = number3;
    }
    if (number4 > max)
    {
        max = number4;
    }
    if (number5 > max)
    {
        max = number5;
    }

    return max;
}

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
double find_min(double number1, double number2, double number3, double number4, double number5)
{
    double min = number1;

    if (number2 < min)
    {
        min = number2;
    }
    if (number3 < min)
    {
        min = number3;
    }
    if (number4 < min)
    {
        min = number4;
    }
    if (number5 < min)
    {
        min = number5;
    }

    return min;
}

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
void print_double(FILE* outfile, double number)
{
    fprintf(outfile, "%.2lf\n", number);
}
