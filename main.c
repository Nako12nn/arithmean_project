#include <stdio.h>
#include <string.h>

int main(void) { 
// string comparison
    // char first_str[20] = "chose an option";
    // char second_str[18] = "chose an option";

    // const char *ptr_first = first_str;
    // const char *ptr_second = second_str;
    // size_t size_second = sizeof(second_str);
    // short counter = 0;
    
    // for (int i = 0; i < size_second;) {
    //     if(ptr_first[i] == ptr_second[i]){
    //         i++;
    //         counter++;
    //     }
    //     else 
    //     {
    //         printf("Strings are not the same\n");
    //         return 0;
    //     }

    //     if (counter == (size_second))
    //     printf("Strings are the same\n");
    // }



    // short i = 0;

    // for (; ptr_first[i] != '\0' && ptr_second[i] != '\0'; ++i) {
    //     if (ptr_first[i] != ptr_second[i]){
    //         puts("The strings are not the same");
    //         return 0;
    //     }
    // }

    // if (ptr_first[i] != ptr_second[i]) {
    //     puts("Strings are not the same...");
    //     return 0;
    // }
    // puts("Strings are the same");
   


    // short max_len = sizeof(second_str);
    // strncmp(first_str, second_str, max_len); checks if the 2 items are equal and take the length to check

    // if (strncmp(first_str, second_str, max_len) == 0)
    //     puts("Strings are equal");
    // else
    //     puts("Strings are not equal");


    const char* my_strings[] = {"Nakonechnyi", "Nako", "Max", "Niko", "Narrow", "Nail", "Magnus", "Nice"};
// my_strings[0] -> "Nakonechnyi" etc

    int temp = sizeof(my_strings) / sizeof(*my_strings);

    for (int i = 0; i < temp; ++i) {
        if (strncmp(my_strings[i], "Na", 2) == 0)
            puts(my_strings[i]);
    }


    char jdk_str[] = "172634!-_JkD@#$;:";
    char *ptr_jdk = strpbrk(jdk_str, "$#*");

    printf("jdk adress = %p\nptr = %p\n", jdk_str, ptr_jdk);

    if (ptr_jdk != NULL)
    {
        printf("The sign \"%s\" was foundn\n", ptr_jdk);
    }
    

    return 0;
}