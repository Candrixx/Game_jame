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

KEY_PRUEBA::KEY_PRUEBA(int _x, int _y): OBJECT(_x, _y, "Lave de Prueba", "Llave que abre una cerradura", 211){
    std::string text = "Has recogido una Llave de Prueba";
    set_interact_text(text);
}

void KEY_PRUEBA::content(){
}

LETTER_TUTORIAL::LETTER_TUTORIAL(int _x, int _y): OBJECT(_x, _y, "Carta sin Remitente", "Una carta dirigida a nosotros?", 222){
}

void LETTER_TUTORIAL::content(){
    std::string text = "-Hola de nuevo XXXXX o como sea que te llames ahora,\n\t\t\t\tdiria que ya te sabes las reglas pero ese no es el\n\t\t\t\tcaso, en fin empecemos desde el principio, en este\n\t\t\t\tmomento estas ATRAPADO (vaya novedad), salir? depen-\n\t\t\t\tdera de tus habilidades, en este lugar encontraras\n\t\t\t\tdistintos enigmas aun por desvelar, tu trabajo es encontrar\n\t\t\t\tla manera de salir de este lugar (si puedes).\n\t\t\t\tUn consejo: Todo lo que encuentres tiene una razon.\n\n\t\t\t\t Att: El JUEZ";
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