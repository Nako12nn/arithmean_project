#include <stdio.h>

int main() {
    
    signed short number = 4903;
    signed short divider = 2;

    while(1==1){
        if (divider > number || divider <= 1) break;
        if((number % divider) == 0){
            signed short mult_one = number / divider;
            printf("%hd = %hd * %hd\n", number, divider, mult_one);
        }
        ++divider;
    }

    return 0;
}