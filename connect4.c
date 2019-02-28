//Samuel Bishop ID 12539500
//Williams
//Computer Science 1050
//12 October, 2017

//Packages
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

//Defintions

//Prototypes
char getCounter(void);
char game(char, char);
void printBoard(void);
int turn(char, int);
int victory(char, int);

//Global Variables
char board[6][7] =     {{ '-', '-', '-', '-', '-', '-', '-'},
			{ '-', '-', '-', '-', '-', '-', '-'},
			{ '-', '-', '-', '-', '-', '-', '-'},
			{ '-', '-', '-', '-', '-', '-', '-'},
			{ '-', '-', '-', '-', '-', '-', '-'},
			{ '-', '-', '-', '-', '-', '-', '-'},};

//Main Function
int main(void)
{
	char player1Letter;
	char player2Letter;
	char winner;
	printf("Player 1, enter your letter (A-Z): ");
	player1Letter = getCounter();
	printf("Player 2, enter your letter (A-Z): ");
	player2Letter = getCounter();
	winner = game(player1Letter, player2Letter);
	printf("Player %c wins the game!", winner);
	return 0;	
}

char getCounter(void)
{
	char playerLetter = '1';
	scanf("%c", &playerLetter);
	return playerLetter;
}

char game(char player1Letter, char player2Letter)
{
	int indexOfColumn;
	while(1)
	{
		printf("%c, your turn. Enter a column to drop into: ", player1Letter);
		scanf("%d", &indexOfColumn);
		if(turn(player1Letter, indexOfColumn) == 1){
			printBoard();
			return player1Letter;
			break;}
		else {printBoard();}
                printf("%c, your turn. Enter a column to drop into: ", player2Letter);
                scanf("%d", &indexOfColumn);
                if(turn(player2Letter, indexOfColumn) == 1){
			printBoard();
			return player2Letter;
                        break;}
		else {printBoard();}
	}
}

void printBoard(void)
{
	int i, j;
	for (i = 0; i < 7; i++){
		printf("[");
		for (j = 0; j < 8; j++){
			printf("%c ", board[i][j]);
		}
		printf("]\n");
	}
}

int turn(char turnLetter, int indexOfColumn)
{
	int i;
	for (i = 0; i < 6; i++)
	{
		if (board[indexOfColumn][i] != '-')
		{
			board[indexOfColumn][i-1] = turnLetter;
		}
	}
	return victory(turnLetter, indexOfColumn);
}

int victory(char playerLetter, int columnMostRecent)
{
	int counter1 = 0;
	int counter2 = 0;
	int returner = 0;
	int i, j;
	//verticle
	for(i = 0; i < 6; i++){
		if (board[columnMostRecent][i] == playerLetter){
			counter1++;
		}
	}
	//horizontal
	for(j = 0; j < 6; j++){
		if(board[j][columnMostRecent] == playerLetter){
			counter2++;
		}
	}
	if (counter1 == 4 || counter2 == 4)
	{
		returner = 1;
	}
	return returner;
}


