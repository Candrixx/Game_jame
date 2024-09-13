#include<iostream>
#include<string.h>
#include "../include/objects.h"

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

void OBJECT::set_x(int _x){
    this->x = _x;
}

void OBJECT::set_y(int _y){
    this->y = _y;
}

LETTER_PRUEBA::LETTER_PRUEBA(int _x, int _y): OBJECT(_x, _y, "Carta de Prueb", "Carta escrita por una persona anonima", 111){

}

std::string LETTER_PRUEBA::content(){
    std::string text = "\t-Contenido de prueba para probar como seria una carta/nota etc.\n\t\t........................................................\n\t\t.....................................................\n\t\t..............................................\n\t\t....................................\n\t\t................................";
    return text;
}