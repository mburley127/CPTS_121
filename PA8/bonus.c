#include "bonus.h"



// Code for string cat function
// Broke down and had Dan Rouhana help... he and I came up with the contents inside the for loop, then I adjusted it to work
char* my_str_n_cat(char* dest, const char* src, int n) // Appends n number of elements from source to the end of dest
{
    //while (*dest != '\0')
    //{
    //    dest++;
    //}

    //while (*src != '\0')
    //{
    //    // Loop to only copy n number of elements from source
    //    for (int i = 0; i < n; i++)
    //    {
    //        src++;
    //        dest++;
    //        dest[i] = src[i];
    //    }
    //}

    // Loop to only copy n number of elements from source
    for (int i = 0; i < n; i++)
    {
        *(dest + i) = *(src + i);
    }
    
    printf("\ndest: %s", dest);
    printf("\nsrc: %s", src);

    return dest;
}

// Code for Binary Search used from in class notes
int binary_search(int list[], int size, int target, int* pos_ptr)
{
    int left_index = 0, right_index = size - 1, mid_index = 0;
    int found = 0;

    *pos_ptr = -1;

    while (!found && left_index <= right_index)
    {
        mid_index = (right_index + left_index) / 2;

        if (list[mid_index] == target)
        {
            found = 1;
            *pos_ptr = mid_index;
        }
        else if (list[mid_index] > target)
        {
            right_index = mid_index - 1;
        }
        else
        {
            left_index = mid_index + 1;
        }
    }
    return found;
}

// Bubble sorting strings
void bubble_sort(char* cars[], int num)
{
    // int index = 0, passes = 0, temp = 0;
    // Converted "passes" and "index" from in class bubble sort to i and j

    for (int i = 1; i < num; ++i) // controls number of passes (i)
    {
        for (int j = 0; j < num - i; ++j) // controls the interation through the array (j)
        {
            // if the item at "C" is less than the item to its left, exchange the two items
            // Returns 1 if first string (cars[j]) is less than second string [STRING TO THE LEFT] (cars[j + 1])
            if (strcmp(cars[j], cars[j + 1]) > 0) // Shift item left (j + 1)
            {
                // swap occurs here
                const char* temp = cars[j];
                cars[j] = cars[j + 1];
                cars[j + 1] = temp;
            }
        }
    }
}

// Test if a number is prime, code help from (https://www.programiz.com/c-programming/examples/prime-number) - Credit Nate Burley for the idea
int is_prime(int num)
{
    int check_prime = 1;

    for (int i = 2; i <= num / 2; i++) // Must start at 2
    {
        if (num % i == 0)
        {
            // Not prime 
            check_prime = 0;
        }
    }

    return check_prime;
}

// Recursive Sum Primes
int sum_primes_rec(unsigned int num)
{
    int check_prime = 0;
    int sum = 0;

    check_prime = is_prime(num);
    // Base Case
    if (num < 2)
    {
        return 0; // Must return 0 for base case, because 1 is NOT a prime number
    }

    // If the number is NOT prime, sum = 0
    if (check_prime == 0)
    {
        sum = 0;
    }

    // If the number is prime, sum = the prime number
    if (check_prime == 1)
    {
        sum = num;
    }

    // must return recursive statement - Nate Burley helped here
    return sum + sum_primes_rec(num - 1);
}
