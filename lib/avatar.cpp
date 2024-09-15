#include "../include/avatar.h"
#include "../include/map.h"
#include "../include/map_objects.h"
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

void CAMERA::set_x(int _x){
    this->x = _x;
}

void CAMERA::set_y(int _y){
    this->y = _y;
}

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

bool AVATAR::collides(MAP &m){
    std::list<MAP_OBJECT*>* mo = m.get_map_objects();
    std::list<MAP_OBJECT*>::iterator itMO;
    for(itMO = mo->begin(); itMO!=mo->end(); itMO++){
        switch(get_dir()){
            case 1:
            if(get_y()-1 == (*itMO)->get_bot_right_y() && (*itMO)->get_up_left_x() <= get_x() && get_x() <= (*itMO)->get_bot_right_x()){
                return true;
            }
            break;
            case 2:
            if(get_x()+1 == (*itMO)->get_up_left_x() && (*itMO)->get_up_left_y() <= get_y() && get_y() <= (*itMO)->get_bot_right_y()){
                return true;
            }
            break;
            case 3:
            if(get_y()+1 == (*itMO)->get_up_left_y() && (*itMO)->get_up_left_x() <= get_x() && get_x() <= (*itMO)->get_bot_right_x()){
                return true;
            }
            break;
            case 4:
            if(get_x()-1 == (*itMO)->get_bot_right_x() && (*itMO)->get_up_left_y() <= get_y() && get_y() <= (*itMO)->get_bot_right_y()){
                return true;
            }
            break;
        }
    }

    return false;
}

bool AVATAR::is_behind(MAP &m, int c){
    std::list<MAP_OBJECT*>* mo = m.get_map_objects();
    std::list<MAP_OBJECT*>::iterator itMO;
    for(itMO = mo->begin(); itMO != mo->end(); itMO++){
        if((*itMO)->get_up_left_y() > get_y() - c && get_y() - c >= (*itMO)->get_object_heigth() && (*itMO)->get_up_left_x() <= get_x() && get_x() <= (*itMO)->get_bot_right_x()){
            return true;
        }
    }

    return false;
}

void AVATAR::open_inventory(){
    inventory.inventory_interface();
}

