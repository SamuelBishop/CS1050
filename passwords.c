//Samuel Bishop
//Gwilliams/Gunn
//Computer Science 1050G
//9 November, 2017

//LAB 10

//Packages
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//Prototypes
int getPass(char *, char *);
int checkPass(char *);
//Definitions

//Main
int main(int argc, char **argv)
{
	char *input = argv[1];
	char *output = argv[2];
	printf("There were %d valid passwords written to the output file.\n", getPass(input, output));
	return 0;
}

int getPass(char* input, char* output)
{
	int numValidPasswords;
        FILE *inputFile, *outputFile;
        char *password = (char*)malloc(sizeof(char)*20);
	if ((outputFile = fopen(output, "w")) == NULL)
	{
		return 0;
	}
        if ((inputFile = fopen(input, "r")) == NULL)
        {
                printf("Input file not opened\n");
                return 0;
        }
        else
        {
		while(!feof(inputFile))
		{
                	fscanf(inputFile, "%s", password);
			if(checkPass(password) == 1)
			{
				numValidPasswords++;
				fprintf(outputFile, "%s\n", password);
				
			}
		}
        }
	fclose(inputFile);
	fclose(outputFile);
	free(password);
        return numValidPasswords;
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
