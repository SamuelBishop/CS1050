//Samuel Bishop
//Williams
//Computer Science 1050
//10 September, 2017

//PRELAB 3 (Using for loops)
#include <stdio.h>
#include <math.h>

int main(void)
{
	int userChoice;
	int i;

	printf("Please enter an integer between 1-99: ");
	scanf("%d\n", &userChoice);
	while(userChoice < 1 || userChoice > 99)
	{
		printf("Invalid number! Re-enter a valid integer between 1-99: ");
		scanf("%d\n", &userChoice);
	}
	for (i = 0; i < userChoice; i = i + 1)
	{
		printf("%d ", i);
	}
	if (userChoice % 2 == 0)
	{
		printf("The integer is even.\n");
	}
	else 
	{
		printf("The integer is odd.\n");
	}
	return 0;
}
