#include <stdio.h>
#include <math.h>
#define MAX_SIZE  5

int get_array(double array[], int size) {
    double input_element = 0.0;
    int counter = 0;

    while(counter < size && scanf("%lf", &input_element) == 1) {
        array[counter++] = input_element;
    }

    return counter;
}

void print_array(double array[], int counter) {
    
    for(int i = 0; i < counter; i++) {
        printf("%.2lf ", array[i]);
    }
    printf("\n");
    printf("\n");
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
    int recursive_counter = counter;
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
    
    //double input_element = 0.0;
    int counter = 0.0;

    // gets a Number of input elements 
    counter = get_array(set_of_elements, size_of_array);
    // printf("%d\n", counter);

    printf("\n");
    printf("Your set =========>\n");
    print_array(set_of_elements, counter);

    double arithmetic_mean = get_arithmetic_mean(set_of_elements, counter);
    printf("The arithmetic mean ===> %.2lf\n", arithmetic_mean);
    printf("\n");

    double standard_deviation = get_standard_deviation(set_of_elements, arithmetic_mean, counter);
    printf("The standard deviation ===> %.2lf\n", standard_deviation);
    //printf("Or square root of ===> %.2lf / %.2f\n", standard_deviation, (double)counter);

    
    return 0;
}
