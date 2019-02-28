//Samuel Bishop
//Williams
//CS 1050 G
//4 October, 2017
//
//PRELAB #6

//Packages
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

//Prototypes

//Global Variables

//Main Function
int main(void)
{
	int array[100];
	bool meetsRequirements = false;
	int arraySize;
	printf("Enter the size of the array to be generated: ");
        scanf("%d", &arraySize);
	if (arraySize > 0 && arraySize < 101)
	{
		meetsRequirements = true;
	}
	while(meetsRequirements == false)
	{
		printf("\nInvalid number! Enter a maximum random value between 0 and 100: ");
		scanf("%d", &arraySize);
		if (arraySize > 0 && arraySize < 101)
       		{
               		meetsRequirements = true;
       		}
	}
	return 0;
}

int initalizeArray(int size, int randomValues)
{
	int sally[size];
	int i;
	for (int i = 0; i < size; i++)
	{
		//fill with random values from RNG function (sally[i] = rng();)
	}
	return sally;
}


//EASY, YOU CAN DO THIS IN A LAB ANY DAY, THERE IS NO NEED TO FINISH THIS

