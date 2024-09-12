#include "../include/avatar.h"
#include "../include/map.h"
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
    head = 'O';
    low_body = 'A';
}

int AVATAR::get_x(){ return x; }
int AVATAR::get_y(){ return y; }
char AVATAR::get_head(){ return head; }
char AVATAR::get_lowbody(){ return low_body; }

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

void AVATAR::print_animation(){
    head = 'O';
    low_body = '|';
}

void AVATAR::print_standar(){
    head = 'O';
    low_body = 'A';
}

bool AVATAR::colision(MAP &m){
    return true;
}

