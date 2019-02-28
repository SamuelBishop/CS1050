//LAB 2
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(void){
	
	int firstInt;
	int secondInt;
	int sum;
	int difference;
	int product;
	int power;
	bool doesNotMeetRequirements1;
	bool doesNotMeetRequirements2;

	doesNotMeetRequirements1 = true;
	doesNotMeetRequirements2 = true;

	
	//STEP 1
	printf("Enter your first Integer \n");
	scanf("%d", &firstInt);
	while (doesNotMeetRequirements1)
	{
		if (firstInt < 0 || firstInt > 10)
		{
			printf("First integer does not meet requirements. Please enter a valid integer \n");
			scanf("%d", &firstInt);
		}
		else
		{
			doesNotMeetRequirements1 = false;
		}
	}

	printf("Enter your second Integer \n");
	scanf("%d", &secondInt);
	while (doesNotMeetRequirements2)
	{
		if (secondInt < 0 || secondInt > 10)
		{
			printf("Second integer does not meet requirements. Please enter a valid integer \n");
			scanf("%d", &secondInt);
		}
		else
		{
			doesNotMeetRequirements2 = false;
		}
	}

	//STEP 2
	sum = firstInt + secondInt;
	if (firstInt > secondInt){
		difference = firstInt - secondInt;}
	else{
		difference = secondInt - firstInt;}
	product = firstInt * secondInt;
	printf("The sum of the two integers is %d \n", sum);
	printf("The difference of the two integers is %d \n", difference);
	printf("The product of the two integers is %d \n", product);

	//STEP 3
	if ((product % 2) == 0){
		printf("The product of the two integers is even. \n");}
	else{
		printf("The product of the two integers is odd. \n");}

	//STEP 4
	if (firstInt > secondInt){
		printf("First integer is greater than the second integer \n");}
	if (secondInt > firstInt){
		printf("Second integer is greater than first integer \n");}
	if (firstInt == secondInt){
		printf("The two integers are equal \n");}

	//BONUS
	power = pow(firstInt, secondInt);
	printf("The first integer to the power of the second integer is %d \n", power);
	return 0;
}
