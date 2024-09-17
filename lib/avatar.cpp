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

void AVATAR::take_object(OBJECT* &item){
    inventory.include_item(item);
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

bool AVATAR::interact_map_objects(MAP &m, MAP_OBJECT* &map_object){
    std::list<MAP_OBJECT*>* mo = m.get_map_objects();
    std::list<MAP_OBJECT*>::iterator itMO;
    for(itMO = mo->begin(); itMO != mo->end(); itMO++){
        if(get_y()-1 == (*itMO)->get_bot_right_y() && (*itMO)->get_up_left_x() <= get_x() && get_x() <= (*itMO)->get_bot_right_x()){
            map_object = (*itMO);
            return true;
        }
        else if(get_x()+1 == (*itMO)->get_up_left_x() && (*itMO)->get_up_left_y() <= get_y() && get_y() <= (*itMO)->get_bot_right_y()){
            map_object = (*itMO);
            return true;
        }
        else if(get_y()+1 == (*itMO)->get_up_left_y() && (*itMO)->get_up_left_x() <= get_x() && get_x() <= (*itMO)->get_bot_right_x()){
            map_object = (*itMO);
            return true;
        }
        else if(get_x()-1 == (*itMO)->get_bot_right_x() && (*itMO)->get_up_left_y() <= get_y() && get_y() <= (*itMO)->get_bot_right_y()){
            map_object = (*itMO);
            return true;
        }
    }

    return false;
}

bool AVATAR::interact_entrys_exits(MAP &m, ENTRY_EXITS* &entry_exit){
    std::list<ENTRY_EXITS*>* e = m.get_entries_exits();
    std::list<ENTRY_EXITS*>::iterator itE;
    for(itE = e->begin(); itE != e->end(); itE++){
        if((*itE)->get_entry_exit_y() <= get_y() && get_y() <= (*itE)->get_entry_exit_y() + (*itE)->get_heigth() && (*itE)->get_entry_exit_x() <= get_x() && get_x() <= (*itE)->get_entry_exit_x() + (*itE)->get_width()){
            entry_exit = (*itE);
            return true;
        }
    }

    return false;
}

bool AVATAR::interact_objects(MAP &m, OBJECT* &o){
    std::list<OBJECT*>* ob = m.get_player_objects();
    std::list<OBJECT*>::iterator itO;
    for(itO = ob->begin(); itO != ob->end(); itO++){
        if((get_y()+1 == (*itO)->get_y() && get_x() == (*itO)->get_x()) || (get_y()-1 == (*itO)->get_y() && get_x() == (*itO)->get_x()) || (get_y() == (*itO)->get_y() && get_x()+1 == (*itO)->get_x()) || (get_y() == (*itO)->get_y() && get_x()-1 == (*itO)->get_x()) || (get_y() == (*itO)->get_y() && get_x() == (*itO)->get_x())){
            o = (*itO);
            return true;
        }
    }

    return false;
}