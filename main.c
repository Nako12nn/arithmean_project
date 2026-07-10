#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(void) {
    
    char my_buff[65];

    FILE* flop = fopen("created_file.txt", "r");
    if(flop == NULL) {
        printf("error: %d\n", errno);
        perror("created_file.txt");
        return 1;
    }

    while(fgets(my_buff, sizeof(my_buff), flop)) {
        char *ptr = strchr(my_buff, '\n');

        if(ptr)
            *ptr = '\0';
            
        puts(my_buff);
    }

    fclose(flop);
    return 0;
}