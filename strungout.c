//Samuuel Bishop Pawprint: sjbc35 Student ID: 12539500
//Williams
//CS 1050 G
//12 October, 2017

//Strungout LAB

//Packages
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

//Prototypes
int length(char[]);
int replace(char[], int);
void concatenate(char[], char[]);
void sort(char[]);

//Definitions
#define Maximum 25

//Main Function
int main(void)
{	
	//All of the first array work
	char array1[Maximum];
	
	printf("Enter your first string: ");
	scanf("%s", array1);
	printf("The first string is: %s\n", array1);

	int lengt = length(array1);
	printf("The length of the first string is: %d\n\n", lengt);

	int position;
	printf("Enter a replacement operation position between 1 and 5: ");
	scanf("%d", &position);

	int change = replace(array1, position);
	while(change == 0)
	{
		printf("Position invald! Enter a number between 1 and 5: ");
		scanf("%d", &position);
		change = replace(array1, position);
	}
	
	printf("Here is array 1 after the replacement operation: %s\n\n", array1);

	//All of the second array work
	char array2[Maximum];

	printf("Enter your secocnd string: ");
	scanf("%s", array2);

	//Putting both of the character arrays together
	concatenate(array1, array2);
	printf("After the concatenation of the two strings the output is: %s\n\n", array1);

	//Sorting
	printf("Concatenated array before sorting: %s\n", array1);
	sort(array1);
	printf("Concatenated array after sorting: %s\n", array1);
	
	//Finish
	return 0;
}

int length(char array[])
{
	int lengt = 0;
	int i = 0;
	for(i = 0; array[i] != '\0'; i++)
	{
		lengt = lengt + 1;
	}
	return lengt;
}

int replace(char array[], int position)
{
	if(array[position - 1] == '\0')
	{
		return 0;
	}
	else
	{
		array[position - 1] = '#';
	}
	return 1;
}

void concatenate(char array1[], char array2[])
{	
	int i = 0;
	int j = 0;
	while(array1[i] != '\0')
	{
		i++;
	}
	while(array2[j] != '\0')
	{
		array1[i] = array2[j];
		j++;
		i++;
	}
	array1[i] = '\0';
}

void sort(char array[])
{
	int i, j, temp;
	int lengt = length(array);
	for(i = 1; i < lengt; i++)
	{
		for(j = 0; j < lengt - 1; j++)
		{ 
			if(array[j]>array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}
