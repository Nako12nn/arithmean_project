#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) { 

    double width = 1.5, length = 2.4, height = 3.3;
    char product_name[] = "Desktop";

    size_t size_opt = strlen(product_name) + 35;
    
    char *option = malloc(size_opt);// take memory
    const char buff[] = "[%s: %.2f x %.2f x %.2f]";
    
    sprintf(option, buff, product_name, width, length, height);// where, how, what
    puts(option);
    puts("");
    free(option);// gives it back



    int tpr_num = -240;
    char storage_num[11];

    sprintf(storage_num, "%d", tpr_num);

    puts(storage_num);// its represented as string
    puts("");



    int got_nums = atoi("12345");
    long a = atol("-300000000");
    long long s = atoll("40000000000000");
    double d = atof("3.1415962535");

    printf("got_nums = %d\na = %ld\ns = %lld\nd = %.10f\n", got_nums, a, s, d);

    return 0;
}