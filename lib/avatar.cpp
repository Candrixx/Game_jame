#include "C:\Users\USER\Documents\ProyectoTutorialC++\GameJam\include/avatar.h"
#define ARRIBA 'w'
#define ABAJO 's'
#define IZQUIERDA 'a'
#define DERECHA 'd'


CAMERA::CAMERA(int _x, int _y){
    x = _x;
    y = _y;
}

int CAMERA::get_x(){ return x; }
int CAMERA::get_y(){ return y; }

AVATAR::AVATAR(int _x, int _y){
    x = _x;
    y = _y;
    dir = 0;
}

int AVATAR::get_x(){ return x; }
int AVATAR::get_y(){ return y; }
void AVATAR::set_x(int x){
    this->x = x;
}
void AVATAR::set_y(int y){
    this->y = y;
}
int AVATAR::get_dir(){ return dir; }
void AVATAR::set_dir(int dir){
    this->dir = dir; 
}

void AVATAR::print_standar(MAP &m){
    m.get_map()[x][y-1] = 'O';
    m.get_map()[x][y] = 'A';
}

void AVATAR::print_animation(MAP &m){
    m.get_map()[x][y-1] = 'O';
    m.get_map()[x][y] = '|';
}

void AVATAR::delte_(MAP &m){
    m.get_map()[x][y-1] = ' ';
    m.get_map()[x][y] = ' ';
}

bool AVATAR::colision(MAP &m){
    return true;
}

