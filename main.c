#include <stdio.h>
#include <math.h>
#define MAX_SIZE  40 // if in file is more than 40 elements - change this

/* Use: gcc main.c -o srednia.out => got compiled file, and in terminal:
   ./srednia.out < mydata.dat OR
   cat mydata.dat | ./srednia.out
*/


/* When scanf successfully reads a number, it returns 1;
   when it reads a character, it returns 0;
   when it reaches the end of the file (EOF (Ctrl+D)), it returns -1.
*/

int get_array(double array[], int size) {
    double input_element = 0.0;
    int counter = 0;

    while(counter < size && scanf("%lf", &input_element) == 1) {
        array[counter++] = input_element;
    }

    return counter; // this function returns the number of read elements 
}

void print_array(double array[], int counter) {
    
    for(int i = 0; i < counter; i++) {
        if(i % 10 == 0) printf("\n"); // every 10 elements \n
        printf("%.2lf ", array[i]);
    }
}

double get_arithmetic_mean(double array[], int counter) {
    
    double arithmetic_mean = 0.0;
    for(int i = 0; i < counter; i++) {
        arithmetic_mean += array[i];
    }
    arithmetic_mean /= counter;

    return arithmetic_mean;
}

double get_standard_deviation(double array[], double arithmetic_mean, int counter) {
    
    double target = 0.0;
    for(int i = 0; i < counter; i++) {
        double summa = (array[i] - arithmetic_mean);
        target += pow(summa, 2);
    }

    target = sqrt((target / counter));
    return target;
}



int main() {
    
    double set_of_elements[MAX_SIZE] = {0.0};
    int size_of_array = sizeof(set_of_elements) / sizeof(set_of_elements[0]);
    int counter = 0;

    counter = get_array(set_of_elements, size_of_array);
    if(counter == 0) {
        printf("The file is empty\n");
        return 1; // check if file is empty
    }

    printf("\n");
    printf("Your set:\n");
    print_array(set_of_elements, counter);
    printf("\n");
    printf("\n");

    double arithmetic_mean = get_arithmetic_mean(set_of_elements, counter);
    printf("The arithmetic mean: %.2lf\n", arithmetic_mean);
    printf("\n");

    double standard_deviation = get_standard_deviation(set_of_elements, arithmetic_mean, counter);
    printf("The standard deviation: %.2lf\n", standard_deviation);
    
    return 0;
}
