#include <stdio.h>
#include <errno.h>
#include <string.h>

enum {name_size=10, max_points=40};

typedef struct
{
    char name[name_size];
    double x, y;
} POINT;


int main(void) {
    
    POINT vectors[max_points];
    int length = 0;

    FILE* created_file = fopen("created_file.txt", "rb");
    
    if(created_file == NULL) {
        perror("created_file.txt");
        return 1;
    }

    while(fread(&vectors[length], sizeof(POINT), 1, created_file) == 1)
        length++;
    
    fclose(created_file);

    
    for (int i = 0; i < length; i++)
    {
        printf("%s (%.2f %.2f)\n", vectors[i].name, vectors[i].x, vectors[i].y);
    }
    
    return 0;
}