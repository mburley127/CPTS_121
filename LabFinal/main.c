#include "LabFinal.h"



int main(void)
{
	FILE* infile = NULL, * outfile = NULL;
	Profile customers[100];
	double sum = 0;
	double avg = 0.0;
	int count = 0;
	double max = 0.0, min = 0.0;

	// Open and closes files (input.dat)
	infile = fopen("customers.txt", "r"); // r stands for read
	outfile = fopen("charges.txt", "w"); // w outputs to another file

	// Call to read and store values into array
	count = read_and_store(customers, infile);
	printf("\ncount = %d", count);

	// Call to sort customer names from Z-A

	
	// Call to compute the total sum of all the customers charges
	sum = sum_customer_charges(customers, count);
	printf("\nThe sum or total charges is: %lf", sum);
	fprintf(outfile, "\nTotal: %lf", sum);

	// Call to compute the avg all the customers charges
	avg = avg_charges(sum, count);
	printf("\nThe average charge is: %lf", avg);
	fprintf(outfile, "\nAverage: %lf", avg);

	// Call to compute the Max charge
	max = max_charge(customers);
	printf("\nThe max charge is: %lf", max);
	fprintf(outfile, "\nMax: %lf", max);

	// Call to compute the Min charge
	min = min_charge(customers);
	printf("\nThe min charge is: %lf", min);
	fprintf(outfile, "\nMin: %lf", min);


	fclose(infile);
	fclose(outfile);

	return 0;
}
