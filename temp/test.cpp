#include <iostream>
#include <conio.h>
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define ESC 27
#define SPACE 32
#define CLEAR_SCREEN system("cls")


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
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 23; j++) {
                if (xPos == j && yPos == i) {
                    std::cout << '^';
                }
                else
                    std::cout << lights_mat[i][j];
            }
            std::cout << std::endl;
        }   
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

    char minigame_key, main_key;
    bool lights_up_flag = false;

    while (true) {
        if (lights_up_flag == false)
            lightsOut.print_lights_out();
        while (true) {   
        minigame_key = getch();
        CLEAR_SCREEN;

        if (minigame_key == ESC) {
            lights_up_flag = true;
            lightsOut.reset_lights_out();
        }

        if (lights_up_flag || lights_out(minigame_key))
            break;
        }

        std::cout << "Menu" << std::endl;
        main_key = getch();
        if (main_key == ESC)
            break;
    }
    return 0;
}