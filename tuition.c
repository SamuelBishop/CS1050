//Samuel Bishop, sjbc35, 12539500
//Williams
//Computer Science 1050
//7 September, 2017

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

//Homework Tuition Cost Program, Homework #1
int main(void)
{
	//Variables Section
	float studentID;
	float BTT; //Base Tuition Total
	float creditHours;
	float engineeringCreditHours;
	float grantMoney;
	float TGT; //Tuition Grand Total
	int outState;
	bool digitOne = false;
	bool eightLong = false;

	//Student ID Prompt
	printf("Enter a student ID number (8 digits beginning with '1'): \n");
	scanf("%f", &studentID);
	if ((studentID / 10000000) < 2 && (studentID / 10000000) >= 1)
	{
		eightLong = true;
	}
	if (((int)studentID / 10000000) == 1)
	{
		digitOne = true;
	}
	while (!digitOne && !eightLong)
	{
		printf("Please enter a valid student ID number: \n");
		scanf("%f", &studentID);
		//Determines if it meets the correct parameters
		if ((studentID / 10000000) < 2 && (studentID / 10000000) >= 1)
		{
			eightLong = true;
		}
		if (((int)studentID / 10000000) == 1)
		{
			digitOne = true;
		}
	}
	
	//How Many Credit Hours a Student Has Prompt
	printf("How many credit hours is this student enrolled in? \n");
	scanf("%f", &creditHours);
	printf("Is this student an out-of state resident? '1' if yes any other value if no: \n");
	scanf("%d", &outState);
	BTT = creditHours * 282;
	if (outState == 1)
	{
		BTT += creditHours * 557.30;
	}
	
	//How Many Engineering Credit Hours a Student is Taking Prompt
	printf("How many credit hours are within the College of Engineering?\n");
	scanf("%f", &engineeringCreditHours);
	while(engineeringCreditHours > creditHours)
	{
		printf("The engineering class hours cannot exceed the total number of class hours.\n");
		printf("How many credit hours are within the College of Engineering?\n");
		scanf("%f", &engineeringCreditHours);
	}
	BTT += engineeringCreditHours * 90;
	
	//Grant/Scholarship Money
	printf("Total grant or scholarship fund for this student (dollars):\n");
	scanf("%f", &grantMoney);
	while (grantMoney> BTT)
	{
		printf("The scholarship total cannot exceed the tuition total.\n");
		printf("Total grant or scholarship fund for this student (dollars):\n");
		scanf("%f", &grantMoney);
	}
	TGT = BTT - grantMoney;

	//Tuiton Statement
	printf("***** TUITION STATEMENT *****\n");
	printf("Student ID: %.0f\n", studentID);
	printf("Credit hours: %.0f\n", creditHours);
	printf("*****\n");
	printf("Base tuition: $%.2f\n", BTT);
	printf("Scholarships and grants: $%.2f\n", grantMoney);
	printf("*****\n");
	printf("TUITION GRAND TOTAL: $%.2f\n", TGT);
	printf("sjc35@tc.rnet.missouri.edu ~]$\n");
	return 0;
}		
