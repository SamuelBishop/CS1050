//Samuel Bishop
//Williams
//CS 1050G
//19 October, 2017

//PRELAB #(

//Packages
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Definitions

//Prototypes
void deposit(int*, float*, int);
void summary(int*, float*, int);

//MAIN
int main(void)
{
	int numAccounts;
	printf("How many accounts are to be created? ");
	scanf("%d", &numAccounts);
	while(numAccounts < 1)
	{
		printf("Please enter an int that is at least 1: ");
		scanf("%d", &numAccounts);
	}
	int* accountPins = (int*)malloc(sizeof(numAccounts));
	float* accountBalances = (float*)malloc(sizeof(numAccounts));
	deposit(accountPins, accountBalances, numAccounts);
	summary(accountPins, accountBalances, numAccounts);
	return 0;
}

void deposit(int* accountPins, float* accountBalance, int numAccounts)
{
	int i;
	float dollas = 50.25;
	for (i = 0; i < numAccounts; i++)
	{
		scanf("%d", &accountPins[i]);
		accountBalance[i] = dollas;
		printf("%.2f\n", accountBalance[i]);
		accountBalance++;
		accountPins++;
		dollas++;
	}
}

void summary(int* accountPins, float* accountBalance, int numAccounts)
{
	int i;
	printf("*****************\n");
	printf("Active account summary:\n");	
	printf("*****************\n");
	for(i = 0; i < numAccounts; i++)
	{
		printf("%d    $ %.2f\n", accountPins[i], accountBalance[i]);
		accountPins++;
		accountBalance++;
	}
}
