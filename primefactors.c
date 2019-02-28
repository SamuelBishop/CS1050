//Samuel Bishop (ID 12539500)
//Williams
//Computer Science 1050
//14 November, 2017

//PRIMEFACTORS LAB3 PROGRAM

//Packages Included
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//Main Function
int main(void)
{
	//Local Variables
	int i, j;
	int f;
	int prime = 1;
	int userNumberChoice;
	int userOptionChoice = 3;
	bool askAgain = true;
	bool inMenu = true;
	//Start of Proformance Code
	
	//Gets User's Number
	while (askAgain)
	{
		printf("Enter a number between 0 and 100: ");
		scanf("%d", &userNumberChoice);
		if (userNumberChoice < 0 || userNumberChoice > 100)
		{
			printf("That number is outside the acceptable range!\n");
		}
		else
		{
			askAgain = false;
		}
	}

	//Switches the User Option to the Correct Code
	while (inMenu)
	{
		//Pre-Bonus Code
		printf("Please select an option from the following choices.\n");
		printf("1) List all prime numbers\n");
		printf("2) Factorize the integer\n");
		printf("0) Exit\n");
		scanf("%d", &userOptionChoice);
		if (userOptionChoice < 0 || userOptionChoice > 2)
		{
			printf("That is not a valid option! Returning to menu...\n");
		}
		switch(userOptionChoice) //To get rid of bonus enter userOptionChoice in the parameter
		{
			//Quits the program
			case 0:
				inMenu = false;
				break;

			//Lists all the prime numbers
			case 1:
				for (i = 2; i < userNumberChoice; i++)
				{
					for (j = 2; j < i; j++)
					{
						if (i % j == 0)
						{
							prime = 0;
						}
					}
					if (prime == 1)
					{
						printf("%d ", i);
					}
					prime = 1;
				}
				printf("\n");
				break;

			//Factorizes the integer
			case 2:
				printf("Factors of %d:\n", userNumberChoice);
				for (f = 1; f <= userNumberChoice; f++)
				{
					if (userNumberChoice % f == 0)
					{
						printf("%d ", f);
					}
				}
				printf("\n");
				break;
		}
	}
	return 0;
}

//Experimental Bonus
/*
int menu(void)
{
	bool inMenu = true
	int userOptionChoice;
	
	while (inMenu)
        {
                printf("Please select an option from the following choices.\n");
                printf("1) List all prime numbers\n");
                printf("2) Factorize the integer\n");
                printf("0) Exit\n");
                scanf("%d", &userOptionChoice);
                if (userOptionChoice < 0 || userOptionChoice > 2)
                {
                        printf("That is not a valid option! Returning to menu...\n");
                }
		else
		{
			inMenu = false;
		}
        }
	return userOptionChoice;
}
*/
