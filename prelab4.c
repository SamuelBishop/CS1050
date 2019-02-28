//Samuel Bishop
//Williams
//Computer Sciencec 1050
//9 September, 2017

//PRELAB 4
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Prototypes
int getInput(void);
int rngLoop(int);

//Global Variables

//Main
int main(void)
{
	int input;
	input = getInput();
	rngLoop(input);
	return 0;
	
}

//getInput Function
int getInput(void)
{
	int input = 1;
	printf("Please enter an integer between 0 and 100: ");
	scanf("%d", &input);
	while(input < 0 && input > 100)
	{
		printf("\nError! Valid number are from 1-99!\n");
		scanf("%d", &input);
	}
	return input;
}

//rngLoop Function
int rngLoop(int numbers)
{
	int j;
	printf("Randomly generated values:\n");
	for (j = 0; j < numbers; j++)
	{
		printf("%d ", rand() % 100);
	}
	printf("\n");
	return 0;
}
