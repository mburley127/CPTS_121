#include <stdio.h>
#include <string.h>

int main (void)
{
    char color[] = "red",  building[20] = "house";
    char name2[] = "jane", name3[100] = "";

    strcpy(building, color); 
    printf("\nstrcpy: %s", building);
    printf("\nstrcpy: %c", building[4]);

    printf("\nstring length: %lu", strlen(building));

    printf("\nstrcmp (): %d", strcmp(color, building));

    strncpy(color, "blue", 2);
    printf("\nstrncpy: %s", color);

    strcat(building, &color[1]);
    printf("\nstrcat(): %s", building);
    printf("\nstrcat(): %c", building[3]);

    // Testing
    printf("\nstring length: %lu", strlen(name2)); // returns length minus null character

    // name3 = name2;
    strcpy(name3, name2); // takes copy of name 2 and places it in memory of name 3, watch for destination size
    printf("\nstrcpy: %s", name3);

    printf("\nstrcmp (): %d", strcmp("dog", "cat"));

    strncpy(name3, &name2[2], 99); // starts name2 at index 2
    printf("\nstrncpy: %s", name2);
    
    char arr[5] = { 1, 2, 3, 4, 5 };
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("\narr[i] = %d", arr[i]);
		printf("\n(arr + i) = %d", (arr + i));
	}

    return 0;
}
