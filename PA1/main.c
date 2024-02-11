/*******************************************************************************************
* Programmer: Matthew Burley
* Class: CptS 121, Spring 2021; Lab Section 1
* Programming Assignment: PA1
* Date: January 30, 2020
* Description: This program takes in user input and solves various tasks given input values
*******************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS // necessary to ignore scanf_s () warnings

#include <stdio.h>
#include <math.h>
#define PI 3.1415



int main (void)
{
    int R1 = 0, R2 = 0, R3 = 0;
    int shift_int = 0, a = 0; 
    char plaintext_character = '\0', encoded_character = '\0';
    double sqrt(double); //sqrt, sin, cos must be declared as a double 
    double sin(double);
    double cos(double);
    double F, mass, acc;
    double r, h, volume_cylinder;
    double x1, x2, y1, y2, distance;
    double theta, tan_theta;
    double parallel_resistance;
    double x, y, z;
    

// Q1 computes Newton’s Second Law of Motion
    printf("Enter a floating-point mass value: ");
    scanf("%lf", &mass);
    printf("Enter a floating-point acceleration value: ");
    scanf("%lf", &acc);

    F = mass * acc;
    printf("Newton's Second Law (Force = mass *  acceleration): %lf\n", F);

// Q2 computes the Volume of a Cylinder
    printf("Enter a floating-point radius value: ");
    scanf("%lf", &r);
    printf("Enter a floating-point height value: ");
    scanf("%lf", &h);

    volume_cylinder = PI * (r*r) * h;
    printf("Volume of a cylinder: volume_cylinder = PI * radius^2 * height: %lf\n", volume_cylinder);

// Q3 creates an encoded character
    printf("Enter a plaintext character: ");
    scanf(" %c", &plaintext_character);
    printf("Enter an integer value for shift_int: ");
    scanf("%d", &shift_int);
    printf("Enter an integer value for a: ");
    scanf("%d", &a);
    
    encoded_character = (plaintext_character - 'a') + 'A' - shift_int;
    printf("The solution to the encoded character equation (encoded_character = (plaintext_character - 'a') + 'A' - shift_int) is: %c\n", encoded_character);

// Q4 computes the distance between 2 points using math.h 
    printf("Enter floating-point distances for x1, x2, y1, y2: ");
    scanf("%lf %lf %lf %lf", &x1, &x2, &y1, &y2);
    
    distance = sqrt(((x1 - x2)*(x1 - x2)) + ((y1 - y2)*(y1 - y2)));
    printf("Distance Equation (distance = sqrt((x1 - x2)^2 + ((y1 - y2)^2) is: %f\n", distance);

// Q5 computes the value of tangent using math.h
     printf("Enter a floating-point value for theta: ");
     scanf("%lf", &theta);

     tan_theta = sin(theta) / cos(theta);
     printf("The value of tan(theta) = sin(theta) / cos(theta) is: %f radians\n", tan_theta);

// Q6 computes the total parallel resistance of 3 resistors
    printf("Enter integer values for R1, R2, and R3: ");
    scanf("%d %d %d", &R1, &R2, &R3);

    parallel_resistance = ((float)1 / (((float)1 / R1) + ((float)1 / R2) + ((float)1 / R3)));
    printf("The parallel resistance (1 / ((1 / R1) + (1 / R2) + (1 / R3)) is: %lf\n", parallel_resistance);

// Q7 solves the general equation
    printf("Enter an integer value for a: ");
    scanf("%d", &a);

    printf("Enter floating-point values for x, y, and z: ");
    scanf("%lf %lf %lf", &x, &y, &z);

    y = ((y / ((float)2/3)) - z + (x / (a % 2)) + PI); 
    printf("The solution to the general equation y = (2 / 3) - y + z * x / (a mod 2) + PI is: %lf\n", y); 

    return 0;
} 
