//Skyler Gunn
//CS1050 Section H homework 1
// 9/9/2016
#include<stdio.h>
#include<math.h>
#define PI 3.14159
//prototyes for the user defined functions
void optionList();
void circleCalc();
void rectCalc();
void triCalc();
void trapCalc();
void sphereCalc();
float power(float num, int remainingTimes);
int main(void) { // driver function
    int calcChoice = 0; //variable for what function the user wishes to perform
    while(calcChoice != 6) {
        optionList(calcChoice);
        scanf("%d", &calcChoice);
        while(calcChoice <= 0 || calcChoice > 6) { //Check for valid choice
            printf("Please enter a valid number \n");
            optionList();
            scanf("%d", &calcChoice);
        }

        //process option entered
        if (calcChoice == 1) {
            circleCalc();
        }
        if (calcChoice == 2) 
            rectCalc();
        if (calcChoice == 3)
            triCalc();
        if (calcChoice == 4)
            trapCalc();
        if (calcChoice == 5)
            sphereCalc();
    }
     return 0;
}
//Homemade power function, uses recursion and an int to get the power of a number passed in
float power(float num, int remainingTimes) {
    if (remainingTimes <= 1) {
        return num;
    } else {
       num = power(num*num, remainingTimes-1);
    }
    return num;
}
//Function to print options
void optionList() {
    printf("GEOMETRY CALCULATOR\n");
    printf("1.) Calculate the Area of a Circle\n");
    printf("2.) Calculate the Area of a Rectangle\n");
    printf("3.) Calculate the Area of a Triangle\n");
    printf("4.) Calculate the Area of a Trapezoid\n");
    printf("5.) Calculate the Area of a Sphere\n");
    printf("6.) Exit\n");
    printf("Please enter a choice (1-6) \n");
}
//Function to calc area of a circle
void circleCalc() {
    printf("Circle area\n");
    float radius = 0;
    printf("Enter a value for the radius of the circle\n");
    scanf("%f", &radius);
    while(radius <= 0) {
        printf("radius cannot be negative, please enter a new value for radius\n");
        scanf("%f", &radius);
    }
    printf("The area is %.2f units\n", ((float) PI * power(radius, 2)));
}
//Function to get area of a rectangle
void rectCalc() {
    printf("rectangle area\n");
    int length = 0;
    int width = 0;
    printf("enter a value for the length and width of a rectangle \n");
    scanf("%d", &length);
    scanf("%d", &width);
    while(length <= 0 || width <= 0) {
        printf("please enter non negative values\n");
        scanf("%d", &length);
        scanf("%d", &width);
    }
    printf("The area is %.2f units\n", ( (float) length * width));
}
//Function to get area of a triangle
void triCalc() {
    printf("triangle area\n");
    int height = 0;
    int base = 0;
    printf("enter a value for the height and base of the triangle \n");
    scanf("%d ", &height);
    scanf("%d", &base);
    while(height <= 0 || base <= 0) {
        printf("please enter non negative values \n");
        scanf("%d", &height);
        scanf("%d", &base);
    }
    printf("The area is %.2f units\n", ( (float) base * height/2));
}
//Function to get area of a trapezoid
void trapCalc() {
    printf("trapezoid area\n");
    int base1 = 0;
    int base2 = 0;
    int height = 0;
    printf("enter a value for the first base, second base, and height of the trapezoid\n");
    scanf("%d", &base1);
    scanf("%d", &base2);
    scanf("%d", &height);
    while ((base1 <= 0) || (base2 <= 0 || height <= 0)) {
        printf("please enter non negative values \n");
        scanf("%d", &base1);
        scanf("%d", &base2);
        scanf("%d", &height);
    }
    printf("The area is %.2f units\n", ( (float) ((base1 + base2) / 2) * height));
}
//Function to get area of a sphere
void sphereCalc() {
    printf("sphere calc\n");
    float radius = 0;
    printf("enter a value for the radius of the sphere\n");
    scanf("%f", &radius);
    while (radius <= 0) {
        printf("please enter a non negative number\n");
        scanf("%f", &radius);
    }
    printf("The area is %.2f units\n", ( (float)( PI * 4 * power(radius, 2))));
}
    
