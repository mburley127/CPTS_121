#include <stdio.h>
#include <string.h>
#define MAX_SIZE 7

int is_duplicate(int num[], int num_elements);

int main(void)
{
    int num[] = { 0, 2, 2, 6, 7, 17, 5, 3 };
    int duplicates = 0;

    duplicates = is_duplicate(num, 7);
    printf("\nIf a duplicate exists, should have 1: %d", duplicates);

    return 0;
}

int is_duplicate(int num[], int num_elements)
{
    int i, j, temp = 0;
    int duplicates = 0;

    for (i = 0; i <= num_elements; i++) // loop over array elements to extract values
    {
        printf("\nElement: %d in i is: %d", i, num[i]); // print values stored in num[i] at each index
        for (j = i; j <= num_elements; j++) // create duplicate array by looping over and storing same elements beginning at index i
        {
            printf("\nElement: %d in j is: %d", j, num[j]); // print values stored in num[j] at each index

            if (num[i] == num[j]) // compares values to look for duplicates at each index
            {
                temp = 1;
                break;
            }

            else
            {
                temp = 0;
                break;
            }
        }
    }

    return temp;
}
