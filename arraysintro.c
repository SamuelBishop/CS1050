//Samuel Bishop Pawprint: sjbc35 Student ID: 12539500
//Williams
//CS 1050 G
//5 October, 2017

//Arrays Intro LAB

//Packages
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

//Prototypes
int getInput(void);
int rngMax(void);
void initalizeArray(int, int);
int arrayMin(int[], int);
int arrayMax(int[], int);
double arrayAvg(int[], int);

//Definitons

//Main Function
int main(void)
{
	int arraySize, rngMax1;
	arraySize = getInput();
	rngMax1 = rngMax();
	initalizeArray(arraySize, rngMax1);
	return 0;
}

int getInput(void)
{
	int input;
	printf("Enter the size of the array to be generated: ");
	scanf("%d", &input);
	while(input < 1 || input > 99)
	{
		printf("Invalid number! Enter an array size between 0 and 100: ");
		scanf("%d", &input);
	}
	return input;
}

int rngMax(void)
{
	int rngLimit;
	printf("Enter the maximum random value to be inseted in the array: ");
	scanf("%d", &rngLimit);
	while(rngLimit < 1 || rngLimit > 99)
        {
                printf("Invalid number! Enter a maximum random value between 0 and 100: ");
                scanf("%d", &rngLimit);
        }
	return rngLimit;
	
}

void initalizeArray(int arraySize, int rngMax)
{
	srand(time(NULL));
	int array[arraySize];
	int i;
	for (i = 0; i <arraySize; i++)
	{
		array[i] = rand() % rngMax;
	}
	//Eventually call arrayMin, arrayMax, arrayAvg - from here
	printf("The minimum value is %d and occurs at index %d.\n", array[arrayMin(array, arraySize)], arrayMin(array, arraySize));
	printf("The maximum value is %d and occurs at index %d.\n", array[arrayMax(array, arraySize)], arrayMax(array, arraySize));
	printf("The mean of the data set is %.2f\n", arrayAvg(array, arraySize));
}

int arrayMin(int array[], int arraySize)
{
	int smallest = array[0];
	int i, index;
	for (i = 0; i < arraySize; i++)
	{
		if (array[i] < smallest)
		{
			smallest = array[i];
			index = i;
		}
	}
	return index;
}

int arrayMax(int array[], int arraySize)
{
	int biggest = array[0];
	int i, index;
	for (i = 0; i < arraySize; i++)
	{
		if (array[i] > biggest)
		{
			biggest = array[i];
			index = i;
		}
	}
	return index;
}

double arrayAvg(int array[], int arraySize)
{
	double average;
	int i, sum;
	for (i = 0; i<arraySize; i++)
	{
		sum += array[i];
	}
	average = (double)sum/i;
	return average;
}
