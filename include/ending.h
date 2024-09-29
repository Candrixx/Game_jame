#ifndef ENDING_H
#define ENDING_H
#include <chrono>
#include <iostream>
#include <string>
#include <stdlib.h>
#include<list>
#include "../include/timer.h"

#define CLEAR_SCREEN system("cls")

class CURTAIN{
public:
    int y;
    char body;
    CURTAIN(){
        y = 0;
        body = 42;
    }
};

class CREDITS{
public:
    int y;
    std::string credits;
    CREDITS(){
        y = 0;
        credits = "      Gracias por jugar esta demo\n\n     A la UCV por esta oportunidad\n\n\t       CREADORES\n\n\t     Carlos Arena\n\n\t    Ricardo Angulo";
    }
};

void print_camera(char c[][51]){
    std::cout << std::endl << std::endl << std::endl << std::endl;
    for(int i=0; i<11; i++){
        std::cout << "\t\t\t\t";
        for(int j=0; j<51; j++){
            std::cout << c[i][j];
        }
        std::cout << std::endl;
    }
}

int ending(char camera[][51]){
    CURTAIN curt;
    std::string text = "Fin de la Demo";
    print_camera(camera);
    while(true){
        for(int i=0; i<11; i++){
            for(int j=0; j<51; j++){
                if(i == curt.y){
                    camera[i][j] = curt.body;
                }
            }
        }
        Timer timer;
        while(true){
            if(timer.get_elapsed_time() >= 0.8) break;
        }
        curt.y += 1;
        CLEAR_SCREEN;
        print_camera(camera);
        if(curt.y >= 11) break;
    }


    CLEAR_SCREEN;
    print_camera(camera);
    Timer timer;
    while(true){
        if(timer.get_elapsed_time() >= 2) break;
    }
    CLEAR_SCREEN;
    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
    std::cout << "\t\t\t\t\t\t    ";
    for(int i = 0; i<text.length(); i++){
        std::cout << text[i];
        Timer time;
        while(true){
            if(time.get_elapsed_time() >= 0.03) break;
        }
    }
    Timer tim;
    while(true){
        if(tim.get_elapsed_time() >= 2) break;
    }
    CLEAR_SCREEN;
    CREDITS c;
    int count = 0;
    while(true){
        for(int i=0; i < 21; i++){
            std::cout << "\t\t\t\t\t";
            if(c.y <= i && i <= c.y+4){
                for(int j=count; j<c.credits.length(); j++){
                    if(c.credits[j] != '\n'){
                        std::cout << c.credits[j];
                    }
                    else{
                        count = j + 2;
                        std::cout << "\n\n";
                        break;
                    }
                }
            }
            else std::cout << "\n";
        }
        count = 0;
        c.y += 1;
        Timer tim;
        while(true){
            if(tim.get_elapsed_time() >= 0.8) break;
        }
        CLEAR_SCREEN;
        if(c.y > 21) return 0;
        
    }
    return 0;
}

#endif