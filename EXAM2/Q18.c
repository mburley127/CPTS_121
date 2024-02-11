void int_to_string(int num, char* str_ptr);

int main(void)
{
    char str[100];
    int num = 0;
    char str_ptr = NULL;

    printf("Enter a number greater than 0: ");
    scanf_s("%d", &num);

    str_ptr = &str;

    int_to_string(num, str_ptr);

    return 0;
}

void int_to_string(int num, char* str_ptr)
{
    int i, count, temp = 0;
    int last_digit = 0;

    for (count = 0; num != 0; count++) // loop continues until number of digits remaining is 0 
    {
        last_digit = num % 10; // extracts last digit
        num = num / 10; // removes last digit
        printf("\nlast_digit: %d", last_digit);

        for (i = 0; i <= count; i++)
        {
            str_ptr[i] = last_digit;
            printf("%d", str_ptr[i]);
        }
    }

    printf("\ncount = %d", count);
}
