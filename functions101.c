//Samuel Bishop ID 12539500
//Williams
//Computer Science
//21 November, 2017

//CS 1050 LAB 4 FUNCTIONS101

//Packages
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

//Prototypes
int menu(void);
int getInput(void);
int checkPrime(int);
int addDigits(int);
int rngLoop(int);

//Main Function
int main(void)
{
	bool inMenu = true;
	int userNumber;
	int userOptionChoice;
	int RNGValues;
	printf("Please enter an integer between 0 and 1000: ");
	userNumber = getInput();
	while (inMenu)
	{
		menu();
		userOptionChoice = getInput();
		if (userOptionChoice < 1 || userOptionChoice > 4)
		{
			printf("Invalid selection! Returning to main menu...\n");
		}
		switch(userOptionChoice)
		{
			//Checks Prime Numbers
			case 1:
				printf("%d ", userNumber);
				if (checkPrime(userNumber) == 1)
				{
					printf("is a prime number.\n");
				}
				else
				{
					printf("is not a prime number.\n");
				}
				break;
			case 2:
				printf("The sum of the digits of ");
				printf("%d ", userNumber);
				printf("is %d.\n", addDigits(userNumber));
				break;
			case 3:
				RNGValues = userNumber;
				rngLoop(RNGValues);
				break;
			case 4:
				inMenu = false;
				break;
		}
	}
	return 0;
}

//getInput
int getInput(void)
{
	int input;
	scanf("%d", &input);
	while(input < 0 || input > 1000)
	{
		printf("Error! Please enter an integer such that 0 < int < 1000: ");
		scanf("%d", &input);
	}
	return input;
}

//checkPrime
int checkPrime(int checkNum)
{
	int i, prime;
	for (i = 2; i < checkNum; i++)
	{
		if (checkNum % i == 0 && i != checkNum)
		{
			prime = 0;
			return prime;
			break;
		}
	}
	prime = 1;
	return prime;
}

//addDigits
int addDigits(int num)
{
	int sum = 0;
	while (num > 0)
	{
		sum += num%10;
		num = num/10;
	}
	return sum; 
}

//rngLoop
int rngLoop(int number)
{
	srand(time(NULL));
	int rngLimit, j, temp;
	int evenNumbers = 0;
	int oddNumbers = 0;
	printf("Enter a limit for the RNG values between 0 and 100: ");
	rngLimit = getInput();
	while (rngLimit < 0 || rngLimit > 100)
	{
		printf("Error! Value must be between 0 and 100: ");
		scanf("%d", &rngLimit);
	}
	for (j = 0; j < number; j++)
	{
		temp = rand() %  rngLimit;
		if (temp % 2 == 0)
		{
			evenNumbers++;
		}
		else
		{
			oddNumbers++;
		}
		printf("%d ", temp);
	}
	printf("\n%d even values and %d odd values generated.\n", evenNumbers, oddNumbers);
	return 0;
}

//menu
int menu(void)
{
	printf("\n");
	printf("***** MAIN MENU *****\n");
	printf("1) Check prime number\n");
	printf("2) Add up individual digits\n");
	printf("3) Generate random values\n");
	printf("4) Exit\n");
	return 0;	
}
