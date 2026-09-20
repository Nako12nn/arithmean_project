#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double* append(double* storage, size_t* capacity, size_t* length, double value) {
    if(*length >= *capacity) { // below is type matching (double*)
        double* temporary_pointer = (double*) realloc(storage, sizeof(double) * (*capacity * 2));
        if(temporary_pointer == NULL) {
            return NULL;
        } 
        *capacity *= 2;
        storage = temporary_pointer;
    }

    storage[(*length)++] = value;    // first use *length (value in it), after make it +1
    return storage;
}

double get_arithmetic_mean(double* arr, size_t length) {
    
    double arithmetic_mean = 0.0;
    for(size_t i = 0; i < length; i++) {
        arithmetic_mean += arr[i];
    }
    arithmetic_mean /= length;

    return arithmetic_mean;
}

double get_standard_deviation(double* arr, double arithmetic_mean, size_t length) {
    double target = 0.0;
    for(size_t i = 0; i < length; i++) {
        double summa = (arr[i] - arithmetic_mean);
        target += summa * summa; // func pow() is very heavy 
    }

    target = sqrt((target / length));
    return target;
}

void show_arr(const double* storage, size_t length) { // use const to protect from possible changes
    for(size_t i = 0; i < length; ++i) { // keep i and length both same type
        if(i % 10 == 0 && i != 0) printf("\n");   // NOT int i < unsigned long length
        printf("%6.2lf ", storage[i]);
    }
}



int main() {
    size_t capacity_of_storage = 2;
    size_t length_of_storage = 0;

    double* storage = malloc(sizeof(double) * capacity_of_storage);
    if(storage == NULL) {
        printf("Memory location error\n");
        return 1;
    }
    
    double input_element = 0.0;
    while(scanf("%lf", &input_element) == 1) {
        double* temp = append(storage, &capacity_of_storage, &length_of_storage, input_element);
        if(temp == NULL) {
            fprintf(stderr, "Memory location error\n");
            break;
        }
        storage = temp;
    }

    if(length_of_storage == 0) {
        printf("File is empty\n");
        free(storage);
        return 1;
    }

    double arithmetic_mean = get_arithmetic_mean(storage, length_of_storage);
    printf("Arithmetic mean: %.2lf\n\n", arithmetic_mean);

    if(length_of_storage != 1) { // if len == 1
        double standard_deviation = get_standard_deviation(storage, arithmetic_mean, length_of_storage);
        printf("Standard deviation: %.2lf\n\n", standard_deviation);
    }

    printf("Your data:");
    show_arr(storage, length_of_storage);

    free(storage);
    return 0; 
}