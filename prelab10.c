//Samuel Bishop
//Gwilliam, Gunn
//CS 1050G
//8 November, 2017

//Packages
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//Prototypes
char* getPass(char *);
int checkPass(char *);
//Definitions

//Main
int main(int argc, char **argv)
{
	char *fileName = argv[1];
	char *password = getPass(fileName);
	printf("%s\n", password);
	return 0;
}

char* getPass(char* file)
{
	FILE *cfPtr;
	char *password = (char*)malloc(sizeof(char)*20);
	if ((cfPtr = fopen(file, "r")) == NULL)
	{
		printf("File not opened\n");
		return NULL;
	}
	else
	{
		fscanf(cfPtr, "%s", password);
	}
	return password;
}

int checkPass(char* password)
{
	int low = 0, up = 0, num = 0, punct = 0;
	int i;
	int len = strlen(password);
	for (i = 0; i < len; i++)
	{
		if(islower(*(password + i)))
		{
			low++;
		}
		if(isupper(*(password + i)))
		{
			up++;
		}
		if(isdigit(*(password + i)))
		{
			num++;
		}
		if(ispunct(*(password + i)))
		{
			punct++;
		}
	}
	if(i > 7 && i < 13 && punct > 0 && low > 0 && up > 0)
	{
		return 1;
	}
	return 0;
}
