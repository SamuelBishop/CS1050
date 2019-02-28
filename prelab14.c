#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int idNum;
    char make[10];
    char model[10];
}car;

//Prototypes
int partiton(car *cars, int low, int high);
void quickSort(car *cars, int low, int high);
car *load_sructdata(char *filename, car *cars, int size);
int highestInArray(char *filename, int size);
int lowestInArray(char *filename, int size);
void printArray(car *cars, char *filename);
void swap(car *a, car *b);
int getLines(char* filename);

//Definitions
#define MAX 50
                
//Global Variables
//car *carArray[MAX];

//Main
int main(int numargs, char **filename){
	int size;
	size = getLines(filename[1]);
	car *carArray = malloc(sizeof(car) *size);
        carArray = load_sructdata(filename[1], carArray, 3);
	int n = sizeof(carArray)/sizeof(carArray[1]);
        quickSort(carArray, 0, n - 1);
        printArray(carArray, filename[1]);
	free(carArray);
        return 0;
}

int partition(car *cars, int low, int high){ //Review this a lot
	srand(time(NULL));
        int index = (cars[rand()%(high-low+1) + low]).idNum;
        //int index = cars[high].idNum;
        int i = (low - 1);

        for (int j = low; j <= high- 1; j++) 
        { 
        	// If current element is smaller than or 
        	// equal to pivot 
                if (cars[j].idNum <= index) 
                { 
                	i++;    // increment index of smaller element 
                        swap(&cars[i], &cars[j]); 
                } 
        } 
        swap(&cars[i + 1], &cars[high]);
	return (i+1);
}

void quickSort(car *cars, int low, int high){
	if(low < high)
	{
		int part = partition(cars, low, high);
		quickSort(cars, low, part - 1);
		quickSort(cars, part + 1, high);
	}
}
		

void swap(car *a, car *b){    
	car temp = *a;
        a = b; 
        b = &temp; 
}

car* load_sructdata(char *filename, car *cars, int size){
	int i = 0;
	FILE *fptr;
	fptr = fopen(filename, "r");
        if(fptr == NULL){
        	printf("Cannot open file \n");
                exit(0);
	}
	while(fscanf(fptr, "%d %s %s", &cars[i].idNum, cars[i].make, cars[i].model) != EOF){
		i++;
	}	   
	fclose(fptr);
	return cars;
}

int getLines(char *filename){
	int size = 0;
	char ch;
	FILE *fptr;
	fptr = fopen(filename, "r");
	if(fptr == NULL){
		printf("Cannot open file\n");
		exit(0);
	}
	while((ch = fgetc(fptr)) != EOF){
		if(ch == '\n'){
			size++;
		}
	}
	fclose(fptr);
	return size;
}

void printArray(car *cars, char *filename){
	for(int i = 0; i < getLines(filename); i++){
		printf("Id Number: %d Make: %s Model: %s\n", cars[i].idNum, cars[i].make, cars[i].model);
	}
}
