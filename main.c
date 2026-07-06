#include <stdio.h>
#define SIZE    7

void filter (int new_ar[], size_t size_new,
            const int source_arr[], size_t size_source,
            int (*is_correct) (int))
{
    for (int i = 0; i < size_new; ++i)
        new_ar[i] = 0;
    

    for (int i = 0, j = 0; i < size_new; ++i) {
        if (is_correct(source_arr[i]))
            new_ar[j++] = source_arr[i];
    }
}

int is_even(int a) 
{
    return a % 2 == 0;
}

int is_odd(int a)
{
    return a % 2 != 0;
}

int is_positive(int a)
{
    return a > 0;
}

int is_negative(int a)
{
    return a < 0;
}


int main (void) {

    int numbers[] = {2, 5, 3, 6, 5, 9, -2, 0, 5, 4};
    int reslt[SIZE];
    int (*criterials[]) (int) = {is_even, is_odd, is_positive, is_negative}; // array of ptrs to functions

    filter(reslt, SIZE, numbers, sizeof(numbers) / sizeof(*numbers), criterials[1]);

    for (int i = 0; i < SIZE; ++i) 
        printf("%d ", reslt[i]);

    return 0;
}
