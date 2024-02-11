#include "equations.h"

/***************************************************************************************************************************************
* Function: calculate_newtons_2nd_law(double mass, double acceleration)
* Date Created: Feb 6, 2021
* Date Last Modified: Feb 8, 2021
* Description: This function gets user input floating point values for mass and acceleration, and multiplies them together to get the
*			   value of Force through Newton's Second Law (F = m * a).
* Input Parameters: Mass and acceleration
* Returns: Floating-point value for Force
* Preconditions: Mass and acceleration are floating-point values
* Postconditions: Force value is returned
***************************************************************************************************************************************/
double calculate_newtons_2nd_law(double mass, double acc)
{
    double F = 0.0;

    F = (mass * acc);

    return F;
}


/***************************************************************************************************************************************
* Function: calculate_volume_cylinder(double radius, double height)
* Date Created: Feb 6, 2021
* Date Last Modified: Feb 8, 2021
* Description: This function This function gets user input floating point values for radius and height, and computes the volume of a cylinder
*			   and displays the result.
* Input Parameters: Radius and height
* Returns: Floating-point value for Volume of a cylinder is returned
* Preconditions: radius and height are floating-point values
* Postconditions: The value for the computed volume of a cylinder is a floating-point value
***************************************************************************************************************************************/
double calculate_volume_cylinder(double r, double h)
{
    double volume_cylinder = 0.0;

    volume_cylinder = (PI * (r * r) * h);

    return volume_cylinder;
}


/***************************************************************************************************************************************
* Function: char calculate_encoded_character(char plaintext_character, int shift_int)
* Date Created: Feb 6, 2021
* Date Last Modified: Feb 8, 2021
* Description: This function computes the endoded character by solving the equation and assigning the result to an ASCII table character table
*			   value and displaying the resulting character.
* Input Parameters: plaintext_character and integer value for shift_int
* Returns: encoded_character char value is returned
* Preconditions: plaintext_character is a char, and shift_int is an integer value
* Postconditions: The value for the endoded character equation is a char
***************************************************************************************************************************************/
char calculate_encoded_character(char plaintext_character, int shift_int)
{
    char encoded_character = '\0';

    encoded_character = (plaintext_character - 'a') + 'A' - shift_int;

    return encoded_character;
}


/***************************************************************************************************************************************
* Function: double calculate_distance(double x1, double x2, double y1, double y2)
* Date Created: Feb 6, 2021
* Date Last Modified: Feb 8, 2021
* Description: This function computes the distance between two points by solving the equation and assigning the result to a floating-point
*			   value and displaying the result.
* Input Parameters: Floating-point values for x1, x2, y1, y2
* Returns: The floating-point distance between 2 points is returned
* Preconditions: Floating-point values for x1, x2, y1, y2
* Postconditions: The value for the endoded character equation is a floating-point value
***************************************************************************************************************************************/
double calculate_distance(double x1, double x2, double y1, double y2)
{
    double distance = 0.0;

    distance = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));

    return distance;
}


/***************************************************************************************************************************************
* Function: double calculate_tangent(double theta)
* Date Created: Feb 6, 2021
* Date Last Modified: Feb 8, 2021
* Description: This function computes the tangent by computing sin(theta)/cos(theta) and assigning the result to an floating-point
*			   value and displaying the result.
* Input Parameters: Floating-point value theta
* Returns: The floating-point value of tangent is returned
* Preconditions: The floating-point value theta
* Postconditions: The value for the tangent equation is a floating-point value
***************************************************************************************************************************************/
double calculate_tangent(double theta)
{
    double tan_theta = 0.0;

    tan_theta = sin(theta) / cos(theta);

    return tan_theta;
}


/***************************************************************************************************************************************
* Function: double calculate_parallel_resistance(int R1, int R2, int R3)
* Date Created: Feb 6, 2021
* Date Last Modified: Feb 8, 2021
* Description: This function computes the parallel resistance by solving the equation and assigning the result to a floating-point
*			   value and displaying the resulting character.
* Input Parameters: Integer values for R1, R2, R3
* Returns: Floating-point value for the parallel resistance is returned
* Preconditions: Integer values for R1, R2, R3
* Postconditions: The value for the parallel-resistance equation is a floating-point value
***************************************************************************************************************************************/
double calculate_parallel_resistance(int R1, int R2, int R3)
{
    double parallel_resistance = 0.0;

    parallel_resistance = ((double)1 / (((double)1 / R1) + ((double)1 / R2) + ((double)1 / R3)));

    return parallel_resistance;
}


/***************************************************************************************************************************************
* Function: double calculate_general_solution(int a, double x, double z)
* Date Created: Feb 6, 2021
* Date Last Modified: Feb 8, 2021
* Description: This function computes the general equation by solving the equation for y and assigning the result to a floating-point
*			   resulting value and displaying the result.
* Input Parameters: The integer value for a, floating-point values for x and z
* Returns: Floating-point value for y is returned
* Preconditions: The integer value for a, floating-point values for x and z
* Postconditions: Floating-point value for y
***************************************************************************************************************************************/
double calculate_general_solution(int a, double x, double z)
{
    double y = 0.0;

    y = ((y / ((double)3 / 17)) - z + (x / (a % 2)) + PI);

    return y;
}
