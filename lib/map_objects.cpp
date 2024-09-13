#include<iostream>
#include<string.h>
#include<list>
#include "../include/map_objects.h"

MAP_OBJECT::MAP_OBJECT(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y, std::string name){
    this->up_left_x = left_up_x;
    this->up_left_y = left_up_y;
    this->bot_right_x = bot_right_x;
    this->bot_right_y = bot_right_y;
}

int MAP_OBJECT::get_up_left_x(){ return up_left_x; }
int MAP_OBJECT::get_up_left_y(){ return up_left_y; }
int MAP_OBJECT::get_bot_right_x(){ return bot_right_x; }
int MAP_OBJECT::get_bot_right_y(){ return bot_right_y; }

void MAP_OBJECT::set_up_left_x(int _x){
    this->up_left_x = _x;
}
void MAP_OBJECT::set_up_left_y(int _y){
    this->up_left_y = _y;
}
void MAP_OBJECT::set_bot_right_x(int _x){
    this->bot_right_x = _x;
}
void MAP_OBJECT::set_bot_right_y(int _y){
    this->bot_right_y = _y;
}

std::list<int>* MAP_OBJECT::get_objects(){
    return &objects;
}

CUPBOARD::CUPBOARD(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Cupboard"){

}

void CUPBOARD::print(char** &map){
    map[get_up_left_y()][get_up_left_x()] = 218;
    map[get_up_left_y()][get_bot_right_x()] = 191;
    map[get_bot_right_y()][get_bot_right_x()] = 217;
    map[get_bot_right_y()][get_up_left_x()] = 192;
    map[get_up_left_y()+1][get_up_left_x()] = 124;
    map[get_up_left_y()+1][get_bot_right_x()] = 124;
    map[get_up_left_y()+2][get_up_left_x()] = 124;
    map[get_up_left_y()+2][get_bot_right_x()] = 124;
    map[get_bot_right_y()][get_up_left_x()+1] = 196;
    map[get_up_left_y()][get_up_left_x()+1] = 196;
    map[get_bot_right_y()][get_up_left_x()+2] = 196;
    map[get_up_left_y()][get_up_left_x()+2] = 196;
    map[get_up_left_y()+1][get_up_left_x()+1] = 46;
    map[get_up_left_y()+1][get_up_left_x()+2] = 46;
    map[get_bot_right_y()-1][get_bot_right_x()-1] = 32;
    map[get_bot_right_y()-1][get_bot_right_x()-2] = 32;
}