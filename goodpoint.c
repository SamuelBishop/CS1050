//Samuel Bishop
//Williams
//CS 1050G
//19 October, 2017

//LAB 9

//Definitons

//Packages
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Global Variables

//Prototypes
float* addValues(float*, int);
float* sort(float*, int);
void calculations(float*, int);
//MAIN
int main(void)
{
	int size;
	printf("Please enter the number of values you wish to input: ");
	scanf("%d", &size);
	while(size < 1)
	{
		printf("Try again! Value must be a positive integer: ");
		scanf("%d", &size);
	}
	float array[size];
	float* pointer = addValues(array, size);
	pointer = sort(pointer, size);
	calculations(pointer, size);
	return 0;
}

float* addValues(float* pointer, int size)
{
	float temp;
	int i;
	for(i = 0; i < size; i++)
	{
		printf("Enter a value: ");
		scanf("%f", &temp );
		*(pointer + i) = temp;
	}
	return pointer;
}

float* sort(float* pointer, int size)
{
	int i, j, k; //counter values
	float hold = 0; //the swap value for pointer
	for(i = 0; i < size-1; i++)
	{
		for(j = i+1; j< size; j++)
		{
			if(*(pointer+j) > *(pointer+i) ) 
			{
				hold = *(pointer+i);
				*(pointer+i) = *(pointer+j);
				*(pointer+j) = hold;
			}
		}
	}
	//Print out values in decending order
	printf("Sorted values in descending order:\n");
	for(k = 0; k < size; k++)
	{
		printf("%.2f\t", pointer[k]);
	}
	printf("\n");
	return pointer;
}

void calculations(float* orderedPointer, int size)
{
	float mean, median, range, sum, largest, smallest, differ, varSum, variance, standardDeviation;
	int i, j, k, l;
	//Mean
	sum = 0;
	for(i = 0; i<size; i++)
	{
		sum += orderedPointer[i];
	}
	mean = (float)sum/size;
	printf("Mean of the data set: %.6f\n", mean);
	//Median
	for(j = 0; j<size; j++)
	{
		if (size % 2 == 0)
		{
			median = (orderedPointer[j/2] + orderedPointer[(j/2)+1])/2;
		}
		else
		{
			median = orderedPointer[j/2];
		}

	}
	printf("Median of the data set: %.6f\n", median);
	//Range
	largest = orderedPointer[0];
	smallest = orderedPointer[0];
	for(k = 1; k<size; k++)
	{
		if(orderedPointer[k] > largest)
		{
			largest = orderedPointer[k];
		}
		if(orderedPointer[k] < smallest)
		{
			smallest = orderedPointer[k];
		}
	}
	range = largest - smallest;
	printf("Range of the data set: %.6f\n", range);
	//Standard Deviation
	varSum = 0;
	for(l = 0; l<size; l++)
	{
		differ = orderedPointer[l] - mean;
		varSum = varSum + pow(differ,2);
		
	}
	variance = varSum/ (float)size;
	standardDeviation = sqrt(variance);
	printf("*** BONUS: Standard deviation of the data set: %.6f\n", standardDeviation);
}
