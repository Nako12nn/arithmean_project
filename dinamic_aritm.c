#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// as parameters it takes pointers so we need type*, except the last one
double* append(double* storage, size_t* capacity, size_t* length, double value) {
    
/* if we have a trouble in malloc at 14/15 line then if we return storage -
   main thinks everyth ok and there is a false condition of memory
   so we have to return NULL as a sign that append returned nothing
*/

    if(*length >= *capacity) {
        double* arr = malloc(sizeof(double) * 2 * (*capacity)); // locate 2x more memory
        if(arr == NULL)
            return NULL;
        
        (*capacity) *= 2;                   // make this var. 2x bigger as we did uppper
        for(int i = 0; i < *length; ++i)   // *capacity - Number, capacity - memory ADRESS 
            arr[i] = storage[i];          // copy every element from storage to arr

        free(storage);
        storage = arr;
    }
    storage[(*length)++] = value;    // first use *length (value in it), after make it +1
    return storage;
}

void show_arr(double* storage, size_t length) {
    for(size_t i = 0; i < length; ++i) { // keep i and length both same type
        if(i % 10 == 0) printf("\n");   // NOT int i < unsigned long length
        if(i==0) system("clear");      // clear console
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

    for(int i = 0; i < 50; ++i) {
        storage = append(storage, &capacity_of_storage, &length_of_storage, rand() % 101);
    }

    show_arr(storage, length_of_storage);

    free(storage);
    return 0; 
}