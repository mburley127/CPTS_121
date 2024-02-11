#include "equations.h"



int main(void)
{
// Variable Declaration 
    FILE* infile = NULL, * outfile = NULL;
    int SID1 = 0, SID2 = 0, SID3 = 0, SID4 = 0, SID5 = 0;
    double GPA1 = 0.0, GPA2 = 0.0, GPA3 = 0.0, GPA4 = 0.0, GPA5 = 0.0;
    int class_stand1 = 0, class_stand2 = 0, class_stand3 = 0, class_stand4 = 0, class_stand5 = 0;
    double age1 = 0.0, age2 = 0.0, age3 = 0.0, age4 = 0.0, age5 = 0.0;
    double sum_gpa = 0.0, sum_class_standings = 0.0, sum_age = 0.0;
    double mean_gpa = 0.0, mean_class_standings = 0.0, mean_age = 0.0;
    double number_students = 5;
    double deviation1 = 0.0, deviation2 = 0.0, deviation3 = 0.0, deviation4 = 0.0, deviation5 = 0.0;
    double variance = 0.0;
    double std_dev = 0.0;
    double min_gpa = 0.0;
    double max_gpa = 0.0;


// Open and closes files (input.dat)
    infile = fopen("input.dat", "r"); //r stands for read
    outfile = fopen("output.dat", "w"); //w outputs to another file


// Reads five student records from the input file (input.dat); Use a combination of read_double() and read_integer() function calls
    // Student 1
    SID1 = read_integer(infile);
    printf("\nThe first student's ID in the file is: %d", SID1);
    
    GPA1 = read_double(infile);
    printf("\nThe first student's GPA in the file is: %lf", GPA1);
    
    class_stand1 = read_integer(infile);
    printf("\nThe first student's class standing in the file is: %d", class_stand1);

    age1 = read_double(infile);
    printf("\nThe first student's age in the file is: %lf", age1);

    // Student 2
    SID2 = read_integer(infile);
    printf("\nThe second student's ID in the file is: %d", SID2);

    GPA2 = read_double(infile);
    printf("\nThe second student's GPA in the file is: %lf", GPA2);

    class_stand2 = read_integer(infile);
    printf("\nThe second student's class standing in the file is: %d", class_stand2);

    age2 = read_double(infile);
    printf("\nThe second student's age in the file is: %lf", age2);

    // Student 3
    SID3 = read_integer(infile);
    printf("\nThe third student's ID in the file is: %d", SID3);

    GPA3 = read_double(infile);
    printf("\nThe third student's GPA in the file is: %lf", GPA3);

    class_stand3 = read_integer(infile);
    printf("\nThe third student's class standing in the file is: %d", class_stand3);

    age3 = read_double(infile);
    printf("\nThe third student's age in the file is: %lf", age3);

    // Student 4
    SID4 = read_integer(infile);
    printf("\nThe fourth student's ID in the file is: %d", SID4);

    GPA4 = read_double(infile);
    printf("\nThe fourth student's GPA in the file is: %lf", GPA4);

    class_stand4 = read_integer(infile);
    printf("\nThe fourth student's class standing in the file is: %d", class_stand4);

    age4 = read_double(infile);
    printf("\nThe fourth student's age in the file is: %lf", age4);

    // Student 5
    SID5 = read_integer(infile);
    printf("\nThe fifth student's ID in the file is: %d", SID5);

    GPA5 = read_double(infile);
    printf("\nThe fifth student's GPA in the file is: %lf", GPA5);

    class_stand5 = read_integer(infile);
    printf("\nThe fifth student's class standing in the file is: %d", class_stand5);

    age5 = read_double(infile);
    printf("\nThe fifth student's age in the file is: %lf", age5);


// Calculates the sum of the GPAs in input.dat and prints it
    sum_gpa = calculate_sum(GPA1, GPA2, GPA3, GPA4, GPA5);
    printf("\nThe sum of the GPA values are: %lf", sum_gpa);


// Calculates the sum of the class standings in input.dat and prints it
    sum_class_standings = calculate_sum(class_stand1, class_stand2, class_stand3, class_stand4, class_stand5);
    printf("\nThe sum of the class standing values are: %lf", sum_class_standings);


// Calculates the sum of the ages in input.dat and prints it
    sum_age = calculate_sum(age1, age2, age3, age4, age5);
    printf("\nThe sum of the age values are: %lf", sum_age);


// Calculates the mean of the GPAs, writing the result to the output file (output.dat)
    mean_gpa = calculate_mean(sum_gpa, number_students);
    printf("\nThe mean gpa is: %.2lf", mean_gpa);

// Calculates the mean of the class standings, writing the result to the output file (output.dat)
    mean_class_standings = calculate_mean(sum_class_standings, number_students);
    printf("\nThe mean class standings is: %.2lf", mean_class_standings);

// Calculates the mean of the ages, writing the result to the output file (output.dat)
    mean_age = calculate_mean(sum_age, number_students);
    printf("\nThe mean age is: %.2lf", mean_age);


// Calculates the deviation of student 1 GPA from the mean
    deviation1 = calculate_deviation(GPA1, mean_gpa);
    printf("\nThe deviation from the mean for student 1 is: %lf", deviation1);

// Calculates the deviation of student 2 GPA from the mean
    deviation2 = calculate_deviation(GPA2, mean_gpa);
    printf("\nThe deviation from the mean for student 2 is: %lf", deviation2);

// Calculates the deviation of student 3 GPA from the mean
    deviation3 = calculate_deviation(GPA3, mean_gpa);
    printf("\nThe deviation from the mean for student 3 is: %lf", deviation3);

// Calculates the deviation of student 4 GPA from the mean
    deviation4 = calculate_deviation(GPA4, mean_gpa);
    printf("\nThe deviation from the mean for student 4 is: %lf", deviation4);

// Calculates the deviation of student 5 GPA from the mean
    deviation5 = calculate_deviation(GPA5, mean_gpa);
    printf("\nThe deviation from the mean for student 5 is: %lf", deviation5);


// Calculates the variance of the GPAs
    variance = calculate_variance(deviation1, deviation2, deviation3, deviation4, deviation5, number_students);
    printf("\nThe deviation from the mean (variance) for the students is: %lf", variance);


// Calculates the standard deviation of the GPAs, writing the result to the output file (output.dat)
    std_dev = calculate_standard_deviation(variance);
    printf("\nThe standard deviation is: %.2lf", std_dev);


// Determines the min of the GPAs, writing the result to the output file (output.dat)
    min_gpa = find_min(GPA1, GPA2, GPA3, GPA4, GPA5);
    printf("\nThe min GPA is: %.2lf", min_gpa);


// Determines the max of the GPAs, writing the result to the output file (output.dat)
    max_gpa = find_max(GPA1, GPA2, GPA3, GPA4, GPA5);
    printf("\nThe max GPA is: %.2lf", max_gpa);
    

// Prints mean GPA
    print_double(outfile, mean_gpa);

// Prints mean Class Standing
    print_double(outfile, mean_class_standings);

// Prints mean Age
    print_double(outfile, mean_age);

// Prints GPA Standard Deviation
    print_double(outfile, std_dev);

// Prints GPA min
    print_double(outfile, min_gpa);

// Prints GPA Max
    print_double(outfile, max_gpa);

// Closes the input and output files (i.e. input.dat and output.dat)
    fclose(infile);
    fclose(outfile);


    return 0;
}
