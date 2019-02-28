//Samuel Bishop
//Williams
//CS 1050G
//26 October, 2017

//Bank Accounts LAB9

//Packages
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

//Definions

//Prototypes
void createAccounts(int*, float*, int);
int deposit(int*, float*, int);
int withdraw(int*, float*, int);
void summary(int*, float*, int);
double interestPayment(float*, int, float);

//MAIN
int main(void)
{
	int numAccounts, userOptionChoice;
	float APR;
	bool inMenu = true;
	printf("How many accounts are to be created? ");
	scanf("%d", &numAccounts);
	while(numAccounts < 1)
	{
		printf("Please enter an int that is at least 1: ");
		scanf("%d", &numAccounts);
	}
	int* accountPins = (int*)malloc(sizeof(numAccounts));
	float* accountBalances = (float*)malloc(sizeof(numAccounts));
	createAccounts(accountPins, accountBalances, numAccounts);
	printf("\n");
	while (inMenu)
	{
		printf("*** MENU ***\n");
		printf("1) Deposit funds\n");
		printf("2) Withdraw funds\n");
		printf("3) BONUS: Make an interest payment\n");
		printf("4) Print active account summary\n");
		printf("5) Exit\n");
		printf("\n");
		scanf("%d", &userOptionChoice);
		printf("\n");
		if (userOptionChoice < 1 || userOptionChoice > 5)
		{
			printf("That is not a valid option! Returning to menu...\n");
		}
		switch(userOptionChoice)
		{
			//Deposits funds
			case 1:
				deposit(accountPins, accountBalances, numAccounts);
				break;
			//Withdraws funds
			case 2:
				withdraw(accountPins, accountBalances, numAccounts);
				break;
			//Makes an interest payment
			case 3:
				printf("Annual percentage rate (decimal): ");
				scanf("%f", &APR);
				printf("Total interest payments: %.2f\n\n", interestPayment(accountBalances, numAccounts, APR));
				break;
			//Prints account summary
			case 4:
				summary(accountPins, accountBalances, numAccounts);
				break;
			//Exits the program
			case 5:
				inMenu = false;
				summary(accountPins, accountBalances, numAccounts);
				break;
		}
	}
	return 0;
}

void createAccounts(int* accountPins, float* accountBalances, int numAccounts)
{
	int i;
	for (i = 0; i<numAccounts; i++)
	{
		printf("Account #%d PIN: ", i + 1);
		scanf("%d", &accountPins[i]);
		while(accountPins[i] < 1000 || accountPins[i] > 9999)
		{
			printf("Please enter a 4 digit pin: ");
			scanf("%d", &accountPins[i]);
		}
		printf("Account #%d inital balance: ", i + 1);
		scanf("%f", &accountBalances[i]);
		while(accountBalances[i] < 1.00)
		{
			printf("Inital balance must be at least one dollar: ");
			scanf("%f", &accountBalances[i]);
		}
	}
}

int deposit(int* accountPins, float* accountBalances, int numAccounts)
{
	int i, pinChecker;
	float depositAmount;
	printf("Account PIN: ");
	scanf("%d", &pinChecker);
	printf("Deposit amount: ");
	scanf("%f", &depositAmount);
	if (depositAmount < 0)
	{
		printf("Deposit error! Enter a value greater than 0!\n");
		return 0;
	}
	for(i = 0; i < numAccounts; i++)
	{
		if(pinChecker == accountPins[i])
		{
			accountBalances[i] = accountBalances[i] + depositAmount;
			printf("Deposit succcessful!\n\n");
			return 1;
		}
	}
	printf("Deposit error! Verify the account PIN and the deposited amount?\n\n");
	return 0;
}

int withdraw(int* accountPins, float* accountBalances, int numAccounts)
{
	int i, pinChecker;
	float withdrawAmount;
	printf("Account PIN: ");
	scanf("%d", &pinChecker);
	printf("Withdraw amount: ");
	scanf("%f", &withdrawAmount);
	if (withdrawAmount < 0)
	{
		printf("Withdraw error! Enter a value greater than 0!\n\n");
		return 0;
	}
	for(i = 0; i < numAccounts; i++)
	{
		if(pinChecker == accountPins[i])
		{
			if (accountBalances[i] - withdrawAmount < 0)
			{
				printf("Verify the available balance is larger than withdraw amount!\n\n");
				return 0;
			}
			else
			{
				accountBalances[i] = accountBalances[i] - withdrawAmount;
				printf("Withdraw successful!\n\n");
				return 1;
			}
		}
	}
	printf("Withdraw error! Verify the account PIN and available balance?\n\n");
	return 0;

}

void summary(int* accountPins, float* accountBalances, int numAccounts)
{
	int i;
	printf("**************************\n");
	printf("Active account summary:\n");
	printf("**************************\n");
	for(i = 0; i < numAccounts; i++)
	{
		printf("%d\t%.2f\n", accountPins[i], accountBalances[i]);
	}
	printf("\n");
}

double interestPayment(float* accountBalances, int numAccounts, float APR)
{
	int i;
	float simpleInterest;
	double totalInterestPayments = 0;
	float t = (float)1/(float)12;
	float r = APR;
	for(i = 0; i < numAccounts; i++)
	{
		simpleInterest = accountBalances[i] * r * t;
		totalInterestPayments += simpleInterest;
		accountBalances[i] = accountBalances[i] + simpleInterest;
	}
	return totalInterestPayments;
}
