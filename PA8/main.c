#include "bonus.h"


int main(void)
{
    char destination[8] = { 'C','p','t','s',' ','i','s','\0' };
    char source[5] = { ' ','f','u','n','\0' };
    int my_array[4] = { 5, 6, 8, 10 }, pos = 0, found = 0; //Initialized array with max 10 elements, unused spots in array = 0
    char* cars[5] = { "ford", "ferrari", "chevy", "jeep", "porsche" };
    int num = 0, sum = 0, check = 0;

    // Test strncat, Copy from source array to the end of the destination array
    /*int n = 0;
    printf("\nEnter the number of elements you want to append to dest from source: ");
    scanf("%d", &n);*/

    //my_str_n_cat(destination, source, n);

    // Test binary search
    found = binary_search(my_array, 4, 8, &pos);
    printf("\nThe position of 8 is: %d", pos);

    // Test bubble sort
    bubble_sort(cars, 5);
    // Loop over new cars array to get results of sort
    for (int i = 0; i < 5; i++)
    {
        printf("\nstring %d is: %s", i, cars[i]);
    }

    // Test Recursive Sum Primes
    printf("\nEnter a number: "); // Entering 21 should give NOT PRIME and 77
    scanf("%d", &num);

    // Check to see the number input by user is prime
    check = is_prime(num);
    if (check == 1)
    {
        printf("\nThe number you entered is prime!");
    }
    if (check == 0)
    {
        printf("\nThe number you entered is NOT prime!");
    }

    sum = sum_primes_rec(num);
    printf("\nThe sum of all the recursive numbers up to %d is: %d", num, sum);

    return 0;
}
