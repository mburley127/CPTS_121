#include <stdio.h>
#include <string.h>

int binary_search (int list[][], int *target);

int main (void)
{
    char my_array[15][100] = {"C", "P", "T", "S", "1", "2", "1", "I", "S", "G", "R", "E", "A", "T", "!"};
    int found = 0, pos = 0;
    found = binary_search (my_array, 2);
    printf("found: %d, pos: %d", found, pos);

    return 0;
}

int binary_search (char list[][100], int *target_str)
{
    int size = 0, *pos_ptr = 0;
    int left_index = 0, right_index = size - 1, mid_index = 0;
    int row_index = 0;

    int found = 0;

    *pos_ptr = -1;
    *target_str = -1;

    while (!found && left_index <= right_index)
    {
        mid_index = (right_index + left_index) / 2;

        if (list[row_index][mid_index] == target_str) // target = item, set found to true (1)
        {
            found = 1;
            *pos_ptr = mid_index;
        }
        else if (list[row_index][mid_index] > target_str)
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
