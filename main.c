#include <stdio.h>
#include <string.h>

int main(void) { 

    // char initial[100] = "what a shot by devis";
    // char destination[12];

    // const char *ptr_init = initial;
    // char *ptr_dest = destination;
    // int size_destination = sizeof(destination);

    // while (*ptr_init != '\0' && size_destination-- > 1)
    //     *ptr_dest++ = *ptr_init++;
    // *ptr_dest = '\0';
    
    // puts(destination);



    char initial[100] = "what a shot by devis";
    char destination[12];
    const char *ptr_int = initial;

    // strcpy(destination, initial); // for this array we copy in must have enough size
    // puts(destination);

    // int size_dst = sizeof(destination) - 1;//the last - \0
    // strncpy(destination, initial, size_dst);
    // destination[size_dst] = '\0';
    
    // puts(destination);



    // int number_char = 0;
    // while (*ptr_int++)
    //     number_char++;

    // size_t length = strlen(initial); dont use it much as it use a loop

    // printf("Amount of characters = %zu\n", length);



    char str1[30] = {"Nakonechnyi"};
    char str2[22] = {"Maksym"};

    strcat(str1, str2);
    printf("%s", str1);
    printf("\n");

    size_t max_add = sizeof(str2) - strlen(str2) - 1;
    strncat(str2, str1, max_add);
    str2[sizeof(str2)-1] = '\0';
    
    printf("%s", str2);

    return 0;
}