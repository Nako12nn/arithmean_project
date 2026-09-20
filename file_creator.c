#include <stdio.h>
#include <string.h>

/* fgetc(FILE* stream) - for reading one byte
   fputc(int ch, FILE* stream) - for writing one byte 
*/

int main() {

/* You write your string here to have it in a new file
   fopen("mydata.dat", "w") in mode "w" => CREATES a new file if didnt find the enterned one OR
   DELETES everything in existing file and writes this string in it
*/

    char str[] = "145 155 200 178 165 134 155 143 123 124 134 114 200 195"
                 " 200 134 143 155 200 133 144 166 123 108 163 145 164 167 145 178 156 134 189 178 143 132 145 167 154 178";
    size_t len_of_str = strlen(str); //gets size of arr(128 elements, but size is 127, cause last elem is \0)
    
    FILE* myf = fopen("mydata.dat", "w"); // open and check if it opened successfully
    if(myf == NULL)
        return 1;

    for(int i = 0; i < len_of_str; i++)
        fputc(str[i], myf);

    fclose(myf); // close!!!

    FILE* file_read = fopen("mydata.txt", "r");
    if(file_read == NULL)
        return 1;

    char buffer[++len_of_str];
    int counter = 0;
    char character;

/* here we have a buffer with size of len_of_str + 1
   cause below we write a characters in buffer,
   it fills up and we need one more space 
   for filling it with \0 
*/

    while((character = fgetc(file_read)) != EOF) //writes every byte in a buffer
        buffer[counter++] = character;
    buffer[counter] = '\0';

    puts(buffer); // reads the buffer

    fclose(file_read); // close opened stream
    return 0;
}