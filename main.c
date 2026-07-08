#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void) {

    char *my_arr = malloc(10); // points to this data
    int *ptr_int_mem = malloc(sizeof(int)); // gives us 4 bytes of mamory
    short *ptr_shtr_mem = malloc(7 * sizeof(short));

    free(my_arr);
    free(ptr_int_mem);
    free(ptr_shtr_mem);

    return 0;
}