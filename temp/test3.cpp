#include <iostream>
#include <conio.h>
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define ESC 27
#define SPACE 32
#define CLEAR_SCREEN system("cls")
#define UP2 'W'
#define DOWN2 'S'
#define LEFT2 'A'
#define RIGHT2 'D'
#define ACTION 'e'
#define ACTION2 'E'

char game_mat[21][53];



void draw_mat(char game_mat[][53]) {
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 53; j++) {
            if (i == 0)
                game_mat[i][j] = '_';
            else if ((i >= 1 && i <= 20) && (j == 0 || j == 52))
                game_mat[i][j] = '|';
            else if (i == 5 && (j >= 15 && j <= 36))
                game_mat[i][j] = '_';
            else if (i == 5 && (j == 0 || j == 52))
                game_mat[i][j] = '|';
            else if ((i >= 6 && i <= 15) && (j == 15 || j == 36))
                game_mat[i][j] = '|';
            else if (i == 15 && j >= 16 && j <= 36)
                game_mat[i][j] = '_';
            else if (i == 20 && j >= 1 && j <= 52)
                game_mat[i][j] = '_';
            else
                game_mat[i][j] = ' ';
       }
    }
}

int main() {

    draw_mat(game_mat);

    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 53; j++) {
            std::cout << game_mat[i][j];
        }
        std::cout << std::endl;
    }
    
    return 0;
}