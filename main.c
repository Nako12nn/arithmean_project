#include <stdio.h>

void replace(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int sum_arr(const short array[], int length)// length parameter is strictly required const short *array == const short array[]
{
    int result = 0;
    for (int i = 0; i < length; ++i)
        result += array[i];
    
    return result;
}

const char* find_space(const char* buff)
{
    while(*buff != '\0') {
        if (*buff == ' ') 
            return buff;
        buff++;
    }
    return buff;
}

void show_arr2D(const short (*arr)[3], int rows)
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d ", arr[i][j]);
        }
        putchar('\n');
    }
}

int main(void) { 

    int a = 7, b = 12;
    replace(&a, &b);
    printf("%d %d\n", a, b);


    short my_arr[] = {1020, 1200, 1500, 1000, 1340, 930, 990, 1100, 1700, 1500, 1300, 1750};
    int arr_length = (sizeof(my_arr) / sizeof(*my_arr));

    int sum = sum_arr(my_arr, arr_length);
    printf("Year's bill for electrycity = %d\n", sum);


    char mystr[] = "Thatisgonna_be-nice day";
    const char* res = find_space(mystr);

    printf("adress \' \' sign = %p\n\n", res);


    short new_arr[][3] = {{7, 8, 5}, {3, 4, 1}};

    show_arr2D(new_arr, sizeof(new_arr) / sizeof(*new_arr));


    return 0;
}
