#include <stdio.h>
#include <math.h>

double find_smallest_number(double n1, double n2)
{
    return (n1 < n2) ? n1 : n2;
}

double min_3(double n1, double n2, double n3)
{
    //return (n1 < n2) ? ((n1 < n3) ? n1 : n3) : ((n2 < n3) ? n2 : n3);
    double min_2 = find_smallest_number(n1, n2);
    return (min_2 < n3) ? min_2 : n3;
}


int main(void) { 

    printf("%.3f\n", find_smallest_number(-4.2, -2.2));
    printf("%.3f\n", min_3(3, 4, 5));
    double x = 1;
    printf("%.2f\n", find_smallest_number(++x, x));



    return 0;
}