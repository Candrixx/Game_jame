#ifndef PAUSE_MENU_H
#define PAUSE_MENU_H
#include <iostream>
#include <conio.h>
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define UP2 'W'
#define DOWN2 'S'
#define LEFT2 'A'
#define RIGHT2 'D'
#define ACTION 'e'
#define ACTION2 'E'
#define ESC 27
#define SPACE 32
#define CLEAR_SCREEN system("cls")

int yPos = 0;

void draw_pause_menu() {

    std::cout << std::endl << "\t\t\t\t\t\t\t    PAUSA" << std::endl << std::endl << std::endl << std::endl;

    
    if (yPos == 0) {
        std::cout << "\t\t\t\t\t\t\t";
        std::cout << "* ";
        std::cout << "Continuar" << std::endl << std::endl;
    }
    else {
       std::cout << "\t\t\t\t\t\t\t  Continuar" << std::endl << std::endl; 
    }
    if (yPos == 1) {
        std::cout << "\t\t\t\t\t\t\t";
        std::cout << "* ";
        std::cout << "Controles" << std::endl << std::endl;
    }
    else {
       std::cout << "\t\t\t\t\t\t\t  Controles" << std::endl << std::endl; 
    }
    if (yPos == 2) {
        std::cout << "\t\t\t\t\t\t\t";
        std::cout << "* ";
        std::cout << "  Salir" << std::endl << std::endl;
    }
    else {
       std::cout << "\t\t\t\t\t\t\t    Salir" << std::endl << std::endl; 
    }
}

void controls_menu() {

    char key;

    while (true) {

        CLEAR_SCREEN;
        std::cout << std::endl << "\t\t\t\t\t\t          CONTROLES" << std::endl << std::endl << std::endl << std::endl;
        std::cout << "\t\t\t\t\t\t          Arriba: W" << std::endl << std::endl;
        std::cout << "\t\t\t\t\t\t          Derecha: D" << std::endl << std::endl;
        std::cout << "\t\t\t\t\t\t           Abajo: S" << std::endl << std::endl;
        std::cout << "\t\t\t\t\t\t         Izquierda: A" << std::endl << std::endl;
        std::cout << "\t\t\t\t\t\t    Accion/Inspeccionar: E" << std::endl << std::endl;
        std::cout << "\t\t\t\t\t\t          Empujar: R" << std::endl << std::endl;
        std::cout << "\t\t\t\t\t\t         Inventario: I" << std::endl << std::endl;
        std::cout << "\t\t\t\t\t\t          * Volver" << std::endl << std::endl;

        key = getch();

        if (key == ESC || key == ACTION || key == ACTION2) {
            break;
        }
   }
}

int run_pause_menu() {

    char key;

    while(true) {
        CLEAR_SCREEN;
        draw_pause_menu();
        
        key = getch();

        if ((key == UP || key == UP2) && yPos > 0) {
            yPos--;
            continue;
        }
        if ((key == DOWN || key == DOWN2) && yPos < 2) {
            yPos++;
            continue;
        }
        if (key == SPACE || key == ACTION || key == ACTION2) {
            if (yPos == 0)
                break;
            if (yPos == 2) {
                CLEAR_SCREEN;
                return 1;
            }
            if (yPos == 1) {
                controls_menu();
                continue;
            }
        }
        if (key == ESC) {
            break;
        }
    }
    CLEAR_SCREEN;

    return 0;
}

#endif