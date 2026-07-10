#include <stdio.h>
#include <stdlib.h>

struct Cords
{
    double x;
    double y;
};

struct Cords* return_sth(double x, double y)
{
    struct Cords* var = malloc(sizeof(struct Cords));
    var->x = x;
    var->y = y;

    return var;
};

int main(void) {

    // struct Cords vector = {4.0, 2.0};
    // struct Cords *ptr_vec = &vector;

    // (*ptr_vec).x = 1.0; // == ptr_vec->x = 7.5 
    // printf("%.1f\n", (*ptr_vec).x);

    // double show_y = (*ptr_vec).y;
    // printf("%.1f\n", show_y);

    // ptr_vec->x = 6.5;
    // printf("%.1f\n", ptr_vec->x);

    // struct Cords *ptr_cords = malloc(sizeof(struct Cords));

    // ptr_cords->x = 4.7;
    // ptr_cords->y = 3.8;

    // printf("x = %.1f\ny = %.1f\n", ptr_cords->x, ptr_cords->y);

    // free(ptr_cords); // FREE!


    struct Cords* tempo = return_sth(2.2, 3.3);
    printf("%.1f\n%.1f\n", tempo->x, tempo->y);

    free(tempo);
    return 0;
}