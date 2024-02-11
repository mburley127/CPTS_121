#include "LabFinal.h"



int read_and_store(Profile customers[100], FILE* infile)
{
    int i = 0;
    char line = '\0';

    while (!feof(infile) && i < 100)
    {
        fscanf(infile, "%s", &customers[i].name);
        fscanf(infile, " %c", &customers[i].plan);
        fscanf(infile, "%d", &customers[i].talk_minutes);
        fscanf(infile, "%d", &customers[i].data_MB);

        i++;
    }

    printf("\ni: %d", i);
    return i;
}

void name_sort(Profile customers[100], int count) // Sorts Customer names from Z-A, bubble sort deals with alphabetical order
{
    char temp[50] = { '\0' }; // Initialize string of random large size 50

    for (int i = 1; i < count; ++i) // controls number of passes (i)
    {
        for (int j = 0; j < count - i; ++j) // controls the interation through the array (j)
        {
            // if the item is less than the item to its right, exchange the two item
            if (strcmp(customers[j + 1].name, customers[j].name) > 0) // Shift item right (j)
            {
                // swap occurs here, use string copy as values cannot directly equal each other (error)
                strcpy(temp, customers[j + 1].name);
                strcpy(customers[j + 1].name, customers[j].name);
                strcpy(customers[j].name, temp);
            }
        }
    }
}

// Computes charges for each individual customer
double sum_customer_charges(Profile customers[100], int count) // count is the customer (1, 2, 3, 4)
{
    double sum = 0;

    for (int i = 0; i < count; i++) // Count is the number of customers
    {
        if (customers[i].plan == 'A')
        {
            if (customers[i].talk_minutes >= 1000) // 10 GB = 10,000 MB
            {
                if (customers[i].data_MB >= 10000)
                {
                    // Base Fee + Minutes overage charges + Data overage charges
                    // Trump
                    customers[i].charges = ((35.0 + (((double)customers[i].talk_minutes - 1000.0) * 0.5)) + ((25.0 + ((double)customers[i].data_MB - 10000.0) * 0.25)));
                    // printf("\nTrump: %lf", customers[i].charges);
                }

                if (customers[i].data_MB < 10000)
                {
                    // Base Fee + Minutes overage charges + Base data charge
                    customers[i].charges = (((35.0 + ((double)customers[i].talk_minutes - 1000.0) * 0.5)) + (25.0));
                }
            }

            if (customers[i].talk_minutes < 1000) // 10 GB = 10,000 MB
            {
                if (customers[i].data_MB >= 10000)
                {
                    // Base Fee + Base Minutes Charge + Data overage charges
                    customers[i].charges = (60.0 + (35.0) + ((25.0 + ((double)customers[i].data_MB - 10000.0) * 0.25)));
                }

                if (customers[i].data_MB < 10000)
                {
                    // Base Fee + Base Minutes Charge + Base data charge
                    // Biden
                    customers[i].charges = ((35.0) + (25.0));
                    // printf("\nBiden: %lf", customers[i].charges);
                }
            }
        }

        if (customers[i].plan == 'B')
        {
            if (customers[i].talk_minutes >= 2000) // 20 GB = 20,000 MB
            {
                if (customers[i].data_MB >= 20000)
                {
                    // Base Fee + Minutes overage charges + Data overage charges
                    // Obama
                    customers[i].charges = (((55.0 + ((double)customers[i].talk_minutes - 2000.0) * 0.4)) + ((30.0 + ((double)customers[i].data_MB - 20000.0) * 0.15)));
                    // printf("\nObama: %lf", customers[i].charges);
                }

                if (customers[i].data_MB < 20000)
                {
                    // Base Fee + Minutes overage charges + Base data charge
                    customers[i].charges = (((55.0 + ((double)customers[i].talk_minutes - 2000.0) * 0.4)) + (30.0));
                }
            }

            if (customers[i].talk_minutes < 2000) // 20 GB = 20,000 MB
            {
                if (customers[i].data_MB >= 20000)
                {
                    // Base Fee + Base Minutes Charge + Data overage charges
                    customers[i].charges = ((55.0) + ((30.0 + ((double)customers[i].data_MB - 20000.0) * 0.15)));
                }

                if (customers[i].data_MB < 20000)
                {
                    // Base Fee + Base Minutes Charge + Base data charge
                    // Hillary
                    customers[i].charges = ((55.0) + (30.0));
                    // printf("\nHillary: %lf", customers[i].charges);
                }
            }
        }

        sum += customers[i].charges;
    }

    return sum;
}

double avg_charges(double sum, int count)
{
    double avg_charges = 0.0;

    avg_charges = sum / count;

    return avg_charges;
}

double max_charge(Profile customers[100], int count)
{
    double max = 0.0;

    // If we let max = customers[0].charges outside of for loop, must set it here and start i = 1 in for loop (An idea)
    max = customers[0].charges;

    // Loop over customers[i].charges and check for max
    for (int i = 1; i < count; i++)
    {
        if (customers[i].charges > max)
        {
            max = customers[i].charges;
        }
    }

    return max;
}

double min_charge(Profile customers[100], int count)
{
    double min = 0.0;

    // If we let min = customers[0].charges outside of for loop, must set it here and start i = 1 in for loop (An idea)
    min = customers[0].charges;

    // Loop over customers[i].charges and check for min
    for (int i = 1; i < count; i++)
    {
        if (customers[i].charges < min)
        {
            min = customers[i].charges;
        }
    }

    return min;
}
