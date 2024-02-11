#include <time.h>
#include <windows.h>

/*
Plan A Customers:
	Up to 1000 minutes of talk for $35; $0.50 per minute thereafter (overage)
	Up to 10 GB of data for $25; $0.25 per MB thereafter (overage)
	Monthly charge: $60, excluding extra charges for overages

Plan B Customers:
	Up to 2000 minutes of talk for $55; $0.40 per minute thereafter (overage)
	Up to 20 GB of data for $30; $0.15 per MB thereafter (overage)
	Monthly charge: $85, excluding extra charges for overages
*/

typedef struct profile
{
	char name[100];     // customer's name - last, first
	char plan;          // plan 'A' or 'B'
	int talk_minutes;   // number of minutes used for talking
	int data_MB;        // amount of data used in MB
	double charges;     // total charges for this customer – you will compute!
} Profile;

int read_and_store(Profile customers[100], FILE* infile);

void name_sort(Profile customers[100], FILE* infile);

double sum_customer_charges(Profile customers[100], int count);

double avg_charges(double sum, int count);

double max_charge(Profile customers[100]);

double min_charge(Profile customers[100]);

#endif
