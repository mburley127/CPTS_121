#include "equations.c"


int main (void)
{
    int R1 = 0, R2 = 0, R3 = 0;
    int shift_int = 0, a = 0; 
    char plaintext_character = '\0', encoded_character = '\0';
    double F = 0.0, mass = 0.0, acc = 0.0;
    double r = 0.0, h = 0.0, volume_cylinder = 0.0;
    double x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0, distance = 0.0;
    double theta = 0.0, tan_theta = 0.0;
    double parallel_resistance = 0.0;
    double x = 0.0, y = 0.0, z = 0.0;
    

// Q1 computes Newton’s Second Law of Motion
    printf("Enter a floating-point mass value: ");
    scanf("%lf", &mass);
    printf("Enter a floating-point acceleration value: ");
    scanf("%lf", &acc);

    F = calculate_newtons_2nd_law(mass, acc);
    printf("Newton's Second Law (Force = mass *  acceleration): %.2lf\n", F);

// Q2 computes the Volume of a Cylinder
    printf("Enter a floating-point radius value: ");
    scanf("%lf", &r);
    printf("Enter a floating-point height value: ");
    scanf("%lf", &h);

    volume_cylinder = calculate_volume_cylinder (r, h);
    printf("Volume of a cylinder: volume_cylinder = PI * radius^2 * height: %.2lf\n", volume_cylinder);

// Q3 creates an encoded character
    printf("Enter a plaintext character: ");
    scanf(" %c", &plaintext_character);
    printf("Enter an integer value for shift_int: ");
    scanf("%d", &shift_int);
    
    encoded_character = calculate_encoded_character (plaintext_character, shift_int);
    printf("The solution to the encoded character equation (encoded_character = (plaintext_character - 'a') + 'A' - shift_int) is: %c\n", encoded_character);

// Q4 computes the distance between 2 points using math.h 
    printf("Enter floating-point distances for x1, x2, y1, y2: ");
    scanf("%lf %lf %lf %lf", &x1, &x2, &y1, &y2);
    
    distance = calculate_distance (x1, x2, y1, y2);
    printf("Distance Equation (distance = sqrt((x1 - x2)^2 + ((y1 - y2)^2) is: %.2lf\n", distance);

// Q5 computes the value of tangent using math.h
     printf("Enter a floating-point value for theta: ");
     scanf("%lf", &theta);

     tan_theta = calculate_tangent(theta);
     printf("The value of tan(theta) = sin(theta) / cos(theta) is: %.2lf radians\n", tan_theta);

// Q6 computes the total parallel resistance of 3 resistors
    printf("Enter integer values for R1, R2, and R3: ");
    scanf("%d %d %d", &R1, &R2, &R3);

    parallel_resistance = calculate_parallel_resistance (R1, R2, R3);
    printf("The parallel resistance (1 / ((1 / R1) + (1 / R2) + (1 / R3)) is: %.2lf\n", parallel_resistance);

// Q7 solves the general equation
    printf("Enter an integer value for a: ");
    scanf("%d", &a);

    printf("Enter floating-point values for x, y, and z: ");
    scanf("%lf %lf %lf", &x, &y, &z);

    y = calculate_general_solution (a, x, z);
    printf("The solution to the general equation y = (2 / 3) - y + z * x / (a mod 2) + PI is: %.2lf\n", y); 

    return 0;
} 
