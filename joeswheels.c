//Samuel Bishop
//Guilliams/Gunn
//Computer Science 1050G
//17 November, 2017

//Homework 3 (Guilliam's Sleazy Wheels)

//Packages
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//Prototypes
void getCars(int*, float*, int*, char*);
float reserve(int*, float*, int, int);
void printInventory(int*, float*, int*, int);
void writeToFile(int*, float*, int*, char*, int);

//Definitions

//Main
int main(int argc, char** argv)
{
	//Variables Specific to Main
	float profit = 0;
	bool askRental = true;
	bool notInSystem = true;
	int invSize = 12;
	int rentalID;
	int i;

	//Variables Specific to getCars
	char *carFile = *(argv + 1);
	int *IDs = (int*)malloc(sizeof(int)*20);
	float *prices = (float*)malloc(sizeof(float)*20);
	int *mileage = (int*)malloc(sizeof(int)*20);

	//Variables Specific to reserve
	FILE *reservationsFile;
	int *requestedIDs = (int*)malloc(sizeof(int)*20);

	//Variables Specific to printInventory
	
	//Variable Specific to writeToFile
	char *output = *(argv + 4);

	getCars(IDs, prices, mileage, carFile); //Sets the values in the pointers to values in the cars.txt file	
	printInventory(IDs, prices, mileage, invSize); //Prints out these values unchanged
	
	printf("\nProcessing reservations...\n");

	if ((reservationsFile = fopen(*(argv+3), "r")) == NULL)
	{
		printf("Reservations file cannot be read.\n");
		return 0;
	}
	else
	{
		while(!feof(reservationsFile))
		{
			fscanf(reservationsFile, "%d", requestedIDs); //Reads the 4 requested IDs in reservations.txt
			profit += reserve(IDs, prices, *(requestedIDs), invSize); //Reserves the car and returns how much it will be rented for
		}
	}

	printInventory(IDs, prices, mileage, invSize); //prints inventory after all cars have been reserved
	printf("\n");

	while(askRental)
	{
		printf("Enter the ID for the desired rental (0 to exit): ");
		scanf("%d", &rentalID);
		printf("\n");
		for (i = 0; i < invSize; i++)
		{
			if (rentalID == *(IDs + i))
			{
				notInSystem = false;
			}
		}
		while(notInSystem && rentalID != 0)
		{
			printf("That vehicle is not in our inventory!\n");
			printf("Enter the ID for the desired rental (0 to exit): ");
			scanf("%d", &rentalID);
			printf("\n");
			for(i = 0; i < invSize; i++)
			{
				if (rentalID == *(IDs + i))
				{
					notInSystem = false;
				}
			}
		}
		if(notInSystem == false && rentalID != 0)
		{
			profit += reserve(IDs, prices, rentalID, invSize);
			printInventory(IDs, prices, mileage, invSize);
		}
		if(rentalID == 0)
		{
			askRental = false;
		}
	}

	printf("Total Profit: %.2f\n", profit);
	printf("Writing remaining inventory to inventory.txt\n");
	writeToFile(IDs, prices, mileage, output, invSize);
	printf("Freeing memory and exiting\n");
	free(IDs);
	free(prices);
	free(mileage);
	free(requestedIDs);
	fclose(reservationsFile);
	return 0;
}

void getCars(int* IDs, float* prices, int* mileage, char* fileName)
{
	FILE *inputFile;
	int count = 0;
	if((inputFile = fopen(fileName, "r")) == NULL)
	{
		printf("Cars file cannot be read.\n");
	}
	else
	{
		while(!feof(inputFile))
		{
			fscanf(inputFile, "%d%f%d", (IDs + count), (prices + count), (mileage + count));
			count++;
		}
	}
	fclose(inputFile);
}

float reserve(int* IDs, float* prices, int requestedID, int invSize)
{
	int i;
	for(i = 0; i < invSize; i++)
	{
		if (requestedID == *(IDs + i))
		{
			//printf("Car %d rented\n", *(IDs + i));
			*(IDs + i) = 0;
			invSize--;
			return *(prices + i);
		}
	}
	return 0;
}

void printInventory(int* IDs, float* prices, int* mileage, int invSize)
{
	int i;
	printf("*** Current inventory ***\n");
	for (i = 0; i < invSize; i++)
	{
		if(*(IDs + i) == 0)
		{
			continue;
		}
		else
		{
			printf("%d\t$%.2f\t%d\n", *(IDs + i), *(prices + i), *(mileage + i));
		}
	}
}

void writeToFile(int* IDs, float* prices, int* mileage, char* output, int invSize)
{
	int i;
	FILE *outputFile;
	if ((outputFile = fopen(output, "w")) == NULL)
	{
		printf("Output file not opened\n");
	}
	else
	{
		fprintf(outputFile, "IDs\tPrices\tMileage\tInventory Size\n");
		for(i = 0; i < invSize; i++)
		{
			if(*(IDs + i) != 0)
			{
				fprintf(outputFile, "%d\t%.2f\t%d\n", *(IDs + i), *(prices + i), *(mileage + i));
			}		
		}
		fprintf(outputFile, "\t\t\t\t%d", 6);
	}
	fclose(outputFile);
}
