#include<iostream>
#include<string.h>
#include<conio.h>
#include "../include/objects.h"
#define CLEAR_SCREEN system("cls")
#define ACTION 'e'
#define ACTION2 'E'
#define ESC 27

OBJECT::OBJECT(int _x, int _y, std::string _name, std::string _des, int _code){
    this->x = _x;
    this->y = _y;
    this->name = _name;
    this->description = _des;
    this->code = _code;
}

int OBJECT::get_x(){ return x; }
int OBJECT::get_y(){ return y; }
int OBJECT::get_code(){ return code; }

void OBJECT::print(char** &m){
    m[y][x] = '+';
}

void OBJECT::delete_(char** &m){
    m[y][x] = ' ';
}

void OBJECT::set_x(int _x){
    this->x = _x;
}

void OBJECT::set_y(int _y){
    this->y = _y;
}

void OBJECT::set_interact_text(std::string text){
    this->interac_text = text;
}

LETTER_PRUEBA::LETTER_PRUEBA(int _x, int _y): OBJECT(_x, _y, "Carta de Prueba", "Carta escrita por una persona anonima", 111){
    std::string text = "Has recogido una Carta de Prueba";
    set_interact_text(text);
}

void LETTER_PRUEBA::content(){
    std::string text = "Contenido de prueba para probar como seria una carta/nota etc.\n\t\t\t\t........................................................\n\t\t\t\t.....................................................\n\t\t\t\t..............................................\n\t\t\t\t....................................\n\t\t\t\t................................";
    CLEAR_SCREEN;
    std::cout << std::endl << std::endl << std::endl << std::endl;
    std::cout << "\t\t\t\t" << text;
    while(true){
        if(kbhit()){
            char key = getch();
            if(key == ACTION || key == ACTION2 || key == ESC) return;
        }
    }    
}

KEY_PRUEBA::KEY_PRUEBA(int _x, int _y): OBJECT(_x, _y, "Lave de Prueba", "Llave que habre una cerradura", 211){
    std::string text = "Has recogido una Llave de Prueba";
    set_interact_text(text);
}

void KEY_PRUEBA::content(){
}