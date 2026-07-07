#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *append(short *data, size_t *length, size_t *capacity, short value) 
{
    if(*length >= *capacity) {
        (*capacity) *= 2;
        
        short *ar = realloc(data, sizeof(short) * *capacity);
        if(ar == NULL) return data;

        data = ar;
    }

    data[*length] = value;
    (*length)++;

    return data;
}

int main(void) {

    size_t capacity = 10;
    size_t length = 0;

    short *data = malloc(sizeof(short) * capacity);

    for(int i = 0; i < 9; ++i) {
        data = append(data, &length, &capacity, rand() % 40 - 20);
    }

    printf("length = %zu\ncapacity = %zu\n", length, capacity);

    for (int i = 0; i < length; i++)
        printf("%d ", data[i]);

    
    free(data);


    return 0;
}