#include <iostream>
#include <conio.h>
#include<chrono>
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define ESC 27
#define SPACE 32
#define CLEAR_SCREEN system("cls")
#define ACTION 'e'
#define ACTION2 'E'


class LightsOut {
    public:

    int xPos = 0;
    int yPos = 0;
    char lastChar;

    char lights_mat[5][23] = {{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
                              {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
                              {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
                              {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
                              {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'} };
    
    void print_lights_out() {

        std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
        for (int i = 0; i < 5; i++) {
            std::cout << "\t\t\t\t\t\t";
            for (int j = 0; j < 23; j++) {
                if (xPos == j && yPos == i) {
                    std::cout << '^';
                }
                else
                    std::cout << lights_mat[i][j];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl << std::endl << std::endl << "Arriba: W\tAbajo: S\tDerecha: D\tIzquierda: A\tAccion: Espacio\tSalir: E/Esc";
    }

    void reset_lights_out() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 23; j++) {
            lights_mat[i][j] = 'X';
        }
    }   
}

} lightsOut;

bool lights_out(char key) {

    bool Oflag = true;
    
    lightsOut.print_lights_out();

    if (key == UP && lightsOut.yPos > 0) {
        lightsOut.yPos--;
    }
    else if (key == RIGHT && lightsOut.xPos < 22) {
        lightsOut.xPos++;
    }
    else if (key == DOWN && lightsOut.yPos < 4) {
        lightsOut.yPos++;
    }
    else if (key == LEFT && lightsOut.xPos > 0) {
        lightsOut.xPos--;
    }
    else if (key == SPACE) {
        if (lightsOut.xPos > 0 && lightsOut.lights_mat[lightsOut.yPos][lightsOut.xPos-1] == 'X') {
            lightsOut.lights_mat[lightsOut.yPos][lightsOut.xPos-1] = 'O';    }
        else if (lightsOut.xPos > 0 && lightsOut.lights_mat[lightsOut.yPos][lightsOut.xPos-1] == 'O') {
            lightsOut.lights_mat[lightsOut.yPos][lightsOut.xPos-1] = 'X';    }
        if (lightsOut.xPos < 22 && lightsOut.lights_mat[lightsOut.yPos][lightsOut.xPos+1] == 'X') {
            lightsOut.lights_mat[lightsOut.yPos][lightsOut.xPos+1] = 'O';    }
        else if (lightsOut.xPos < 22 && lightsOut.lights_mat[lightsOut.yPos][lightsOut.xPos+1] == 'O') {
            lightsOut.lights_mat[lightsOut.yPos][lightsOut.xPos+1] = 'X';    }
        if (lightsOut.yPos < 4 && lightsOut.lights_mat[lightsOut.yPos+1][lightsOut.xPos] == 'X') {
            lightsOut.lights_mat[lightsOut.yPos+1][lightsOut.xPos] = 'O';    }
        else if (lightsOut.yPos < 4 && lightsOut.lights_mat[lightsOut.yPos+1][lightsOut.xPos] == 'O') {
            lightsOut.lights_mat[lightsOut.yPos+1][lightsOut.xPos] = 'X';    }
        if (lightsOut.yPos > 0 && lightsOut.lights_mat[lightsOut.yPos-1][lightsOut.xPos] == 'X') {
            lightsOut.lights_mat[lightsOut.yPos-1][lightsOut.xPos] = 'O';    }
        else if (lightsOut.yPos > 0 && lightsOut.lights_mat[lightsOut.yPos-1][lightsOut.xPos] == 'O') {
            lightsOut.lights_mat[lightsOut.yPos-1][lightsOut.xPos] = 'X';    }
        if (lightsOut.lights_mat[lightsOut.yPos][lightsOut.xPos] == 'O')
            lightsOut.lights_mat[lightsOut.yPos][lightsOut.xPos] = 'X';
        else
            lightsOut.lights_mat[lightsOut.yPos][lightsOut.xPos] = 'O';
    }


    CLEAR_SCREEN;
    lightsOut.print_lights_out();

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 23; j++) {
            if (lightsOut.lights_mat[i][j] != 'O')
                Oflag = false;
        }
    } 

    if (Oflag)
        return true;
    else
        return false;
            
}

int main() {

    char minigame_key;
    bool lights_out_flag = false;

    while (true) {
        if (lights_out_flag == false)
            lightsOut.print_lights_out();
        while (true) {   
        minigame_key = getch();

        CLEAR_SCREEN;

        if (minigame_key == ESC || minigame_key == ACTION || minigame_key == ACTION2) {
            lights_out_flag = true;
            lightsOut.reset_lights_out();
        }

        if (lights_out_flag)
            return 0;
        }
    }
    return 0;
}