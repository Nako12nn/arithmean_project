#include <stdio.h>
#define N   8

void show_game_field(const char (*arr_ptr)[N])
{
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            printf("%c ", (arr_ptr[i][j] == 0) ? '#' : '0');
        }
        puts("");
    }
}

void open_zeroes(const char (*private_ptr)[N], char (*public_ptr)[N], int i, int j)
{
    if (private_ptr[i][j] != 0 || public_ptr[i][j] == 1)
        return;
    
    public_ptr[i][j] = 1;

    if ((i-1) >= 0 && private_ptr[i-1][j] == 0) open_zeroes(private_ptr, public_ptr, i-1, j);
    if ((i+1) < N && private_ptr[i+1][j] == 0) open_zeroes(private_ptr, public_ptr, i+1, j);
    if ((j-1) >= 0 && private_ptr[i][j-1] == 0) open_zeroes(private_ptr, public_ptr, i, j-1);
    if ((j+1) < N && private_ptr[i][j+1] == 0) open_zeroes(private_ptr, public_ptr, i-1, j+1);
}

int main(void) {

    char private_feild[N][N] = {
                {1, 1, 1, 1, 1, 1, 1, 1},
                {1, 0, 0, 1, 1, 0, 0, 1},
                {1, 0, 0, 1, 1, 0, 0, 1},
                {1, 1, 0, 0, 0, 0, 1, 1},
                {1, 1, 0, 1, 1, 0, 1, 1},
                {1, 1, 0, 1, 1, 0, 1, 1},
                {1, 1, 0, 0, 0, 0, 1, 1},
                {0, 0, 0, 1, 1, 0, 0, 0},
    };

    char public_field[N][N] = {0};
    show_game_field(public_field);

    puts("-----------------------");

    open_zeroes(private_feild, public_field, 7, 7);

    show_game_field(public_field);

    return 0;
}