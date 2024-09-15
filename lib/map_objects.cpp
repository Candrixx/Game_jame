#include<iostream>
#include<string.h>
#include<list>
#include "../include/map_objects.h"
#include "../include/objects.h"

MAP_OBJECT::MAP_OBJECT(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y, std::string name, int object_heigth){
    this->up_left_x = left_up_x;
    this->up_left_y = left_up_y;
    this->bot_right_x = bot_right_x;
    this->bot_right_y = bot_right_y;
    this->object_heigth = object_heigth;
    this->name = name;
}

int MAP_OBJECT::get_up_left_x(){ return up_left_x; }
int MAP_OBJECT::get_up_left_y(){ return up_left_y; }
int MAP_OBJECT::get_bot_right_x(){ return bot_right_x; }
int MAP_OBJECT::get_bot_right_y(){ return bot_right_y; }
int MAP_OBJECT::get_object_heigth(){ return object_heigth; }

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

std::list<OBJECT*>* MAP_OBJECT::get_objects(){
    return &objects;
}

CUPBOARD::CUPBOARD(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Armario", left_up_y-2){

}

void CUPBOARD::print(char** &map){
    map[get_up_left_y()][get_up_left_x()] = 124;
    map[get_up_left_y()][get_up_left_x()+1] = 32;
    map[get_up_left_y()][get_up_left_x()+2] = 32;
    map[get_up_left_y()][get_up_left_x()+3] = 124;
    map[get_bot_right_y()][get_bot_right_x()] = 217;
    map[get_bot_right_y()][get_bot_right_x()-1] = 196;
    map[get_bot_right_y()][get_bot_right_x()-2] = 196;
    map[get_bot_right_y()][get_bot_right_x()-3] = 192;
    map[get_up_left_y()-1][get_up_left_x()] = 124;
    map[get_up_left_y()-1][get_up_left_x()+1] = 46;
    map[get_up_left_y()-1][get_up_left_x()+2] = 46;
    map[get_up_left_y()-1][get_up_left_x()+3] = 124;
    map[get_up_left_y()-2][get_up_left_x()] = 218;
    map[get_up_left_y()-2][get_up_left_x()+1] = 196;
    map[get_up_left_y()-2][get_up_left_x()+2] = 196;
    map[get_up_left_y()-2][get_up_left_x()+3] = 191;
}

CUPBOARD_ESPECIAL::CUPBOARD_ESPECIAL(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Armario", left_up_y-2){
    std::list<OBJECT*>* o = get_objects();
    o->push_back(new LETTER_PRUEBA(0,0));
}

void CUPBOARD_ESPECIAL::print(char** &map){
    map[get_up_left_y()][get_up_left_x()] = 124;
    map[get_up_left_y()][get_up_left_x()+1] = 32;
    map[get_up_left_y()][get_up_left_x()+2] = 32;
    map[get_up_left_y()][get_up_left_x()+3] = 124;
    map[get_bot_right_y()][get_bot_right_x()] = 217;
    map[get_bot_right_y()][get_bot_right_x()-1] = 196;
    map[get_bot_right_y()][get_bot_right_x()-2] = 196;
    map[get_bot_right_y()][get_bot_right_x()-3] = 192;
    map[get_up_left_y()-1][get_up_left_x()] = 124;
    map[get_up_left_y()-1][get_up_left_x()+1] = 46;
    map[get_up_left_y()-1][get_up_left_x()+2] = 46;
    map[get_up_left_y()-1][get_up_left_x()+3] = 124;
    map[get_up_left_y()-2][get_up_left_x()] = 218;
    map[get_up_left_y()-2][get_up_left_x()+1] = 196;
    map[get_up_left_y()-2][get_up_left_x()+2] = 196;
    map[get_up_left_y()-2][get_up_left_x()+3] = 191;
}

TABLE::TABLE(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Cupboard", left_up_y-1){

}

void TABLE::print(char** &map){
    map[get_up_left_y()-1][get_up_left_x()] = 32; map[get_up_left_y()-1][get_up_left_x()+1] = 32; map[get_up_left_y()-1][get_up_left_x()+2] = 47; map[get_up_left_y()-1][get_up_left_x()+3] = 238; map[get_up_left_y()-1][get_up_left_x()+4] = 238; map[get_up_left_y()-1][get_up_left_x()+5] = 238; map[get_up_left_y()-1][get_up_left_x()+6] = 238; map[get_up_left_y()-1][get_up_left_x()+7] = 238; map[get_up_left_y()-1][get_up_left_x()+8] = 238; map[get_up_left_y()-1][get_up_left_x()+9] = 238; map[get_up_left_y()-1][get_up_left_x()+10] = 238; map[get_up_left_y()-1][get_up_left_x()+11] = 238; map[get_up_left_y()-1][get_up_left_x()+12] = 92; map[get_up_left_y()-1][get_up_left_x()+13] = 32; map[get_up_left_y()-1][get_up_left_x()+14] = 32;
    map[get_up_left_y()][get_up_left_x()] = 32; map[get_up_left_y()][get_up_left_x()+1] = 47; map[get_up_left_y()][get_up_left_x()+2] = 32; map[get_up_left_y()][get_up_left_x()+3] = 32; map[get_up_left_y()][get_up_left_x()+4] = 32; map[get_up_left_y()][get_up_left_x()+5] = 32; map[get_up_left_y()][get_up_left_x()+6] = 32; map[get_up_left_y()][get_up_left_x()+7] = 32; map[get_up_left_y()][get_up_left_x()+8] = 32; map[get_up_left_y()][get_up_left_x()+9] = 32; map[get_up_left_y()][get_up_left_x()+10] = 32; map[get_up_left_y()][get_up_left_x()+11] = 32; map[get_up_left_y()][get_up_left_x()+12] = 32; map[get_up_left_y()][get_up_left_x()+13] = 92; map[get_up_left_y()][get_up_left_x()+14] = 32;
    map[get_up_left_y()+1][get_up_left_x()] = 47; map[get_up_left_y()+1][get_up_left_x()+1] = 95; map[get_up_left_y()+1][get_up_left_x()+2] = 95; map[get_up_left_y()+1][get_up_left_x()+3] = 95; map[get_up_left_y()+1][get_up_left_x()+4] = 95; map[get_up_left_y()+1][get_up_left_x()+5] = 95; map[get_up_left_y()+1][get_up_left_x()+6] = 95; map[get_up_left_y()+1][get_up_left_x()+7] = 95; map[get_up_left_y()+1][get_up_left_x()+8] = 95; map[get_up_left_y()+1][get_up_left_x()+9] = 95; map[get_up_left_y()+1][get_up_left_x()+10] = 95; map[get_up_left_y()+1][get_up_left_x()+11] = 95; map[get_up_left_y()+1][get_up_left_x()+12] = 95; map[get_up_left_y()+1][get_up_left_x()+13] = 95; map[get_up_left_y()+1][get_up_left_x()+14] = 92;
    map[get_up_left_y()+2][get_up_left_x()] = 32; map[get_up_left_y()+2][get_up_left_x()+1] = 124; map[get_up_left_y()+2][get_up_left_x()+2] = 32; map[get_up_left_y()+2][get_up_left_x()+3] = 32; map[get_up_left_y()+2][get_up_left_x()+4] = 32; map[get_up_left_y()+2][get_up_left_x()+5] = 32; map[get_up_left_y()+2][get_up_left_x()+6] = 32; map[get_up_left_y()+2][get_up_left_x()+7] = 32; map[get_up_left_y()+2][get_up_left_x()+8] = 32; map[get_up_left_y()+2][get_up_left_x()+9] = 32; map[get_up_left_y()+2][get_up_left_x()+10] = 32; map[get_up_left_y()+2][get_up_left_x()+11] = 32; map[get_up_left_y()+2][get_up_left_x()+12] = 32; map[get_up_left_y()+2][get_up_left_x()+13] = 124; map[get_up_left_y()+2][get_up_left_x()+14] = 32;
}