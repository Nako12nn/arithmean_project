#include <stdio.h>

float rectangle_area(float length, float width) // name of func is ptr to this func
{
    return length * width;
}


float rectangle_perymetr(float length, float width)
{
    return 2 * (length + width);
}

void put_greet(void)
{
    printf("Get after.");
    puts("");
}


int main (void) {

    float (*rect_ptr) (float, float);
    rect_ptr = rectangle_perymetr;

    void (*ptr_put) (void);
    ptr_put = put_greet;

    ptr_put();

    float result = rect_ptr(2.5, 2.0);

    printf("rect_ptr = %.2f\n", result);

    return 0;
}
