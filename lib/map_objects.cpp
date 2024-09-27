#include<iostream>
#include<string.h>
#include<list>
#include "../include/map_objects.h"
#include "../include/objects.h"
#include "../include/lights_out.h"
#include "../include/timer.h"
#define ACTION 'e'
#define ACTION2 'E'

bool lights_out_flag = false;
bool lever_1_flag = false;
bool lever_2_flag = false;
bool lever_3_flag = false;
bool lever_4_flag = false;
bool lever_5_flag = false;
bool error_order_levers_flag = false;
bool picture_flag = false;


MAP_OBJECT::MAP_OBJECT(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y, std::string name, int object_heigth){
    this->up_left_x = left_up_x;
    this->up_left_y = left_up_y;
    this->bot_right_x = bot_right_x;
    this->bot_right_y = bot_right_y;
    this->object_heigth = object_heigth;
    this->name = name;
    this->moved = false;
}

int MAP_OBJECT::get_up_left_x(){ return up_left_x; }
int MAP_OBJECT::get_up_left_y(){ return up_left_y; }
int MAP_OBJECT::get_bot_right_x(){ return bot_right_x; }
int MAP_OBJECT::get_bot_right_y(){ return bot_right_y; }
int MAP_OBJECT::get_object_heigth(){ return object_heigth; }
bool MAP_OBJECT::get_moved(){ return moved; }

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

void MAP_OBJECT::set_object_heigth(int _heigth){
    this->object_heigth = _heigth;
}

void MAP_OBJECT::set_moved(bool m){
    this->moved = m;
}

std::list<OBJECT*>* MAP_OBJECT::get_objects(){
    return &objects;
}

CUPBOARD::CUPBOARD(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Armario", left_up_y-2){}

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

void CUPBOARD::delete_(char** &map){
    map[get_up_left_y()][get_up_left_x()] = 32;
    map[get_up_left_y()][get_up_left_x()+1] =32;
    map[get_up_left_y()][get_up_left_x()+2] =32;
    map[get_up_left_y()][get_up_left_x()+3] = 32;
    map[get_bot_right_y()][get_bot_right_x()] = 32;
    map[get_bot_right_y()][get_bot_right_x()-1] = 32;
    map[get_bot_right_y()][get_bot_right_x()-2] = 32;
    map[get_bot_right_y()][get_bot_right_x()-3] = 32;
    map[get_up_left_y()-1][get_up_left_x()] = 32;
    map[get_up_left_y()-1][get_up_left_x()+1] =32;
    map[get_up_left_y()-1][get_up_left_x()+2] =32;
    map[get_up_left_y()-1][get_up_left_x()+3] = 32;
    map[get_up_left_y()-2][get_up_left_x()] = 32;
    map[get_up_left_y()-2][get_up_left_x()+1] = 32;
    map[get_up_left_y()-2][get_up_left_x()+2] = 32;
    map[get_up_left_y()-2][get_up_left_x()+3] = 32;
}

void CUPBOARD::move(char** &m, int const &dir, int const &higth, int const &width){}

void CUPBOARD::get_interact_empty(char** &map){
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\tParece un Armario Ordinario de Madera";
}

CUPBOARD_ESPECIAL::CUPBOARD_ESPECIAL(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Armario", left_up_y-2){
    std::list<OBJECT*>* o = get_objects();
    o->push_back(new LETTER_PRUEBA(0,0));
    o->push_back(new LETTER_PRUEBA(0,0));
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

void CUPBOARD_ESPECIAL::delete_(char** &m){}

void CUPBOARD_ESPECIAL::move(char** &m, int const &dir, int const &higth, int const &width){}

void CUPBOARD_ESPECIAL::get_interact_empty(char** &map){
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\tParece que el Armario esta vacio";
}

TABLE::TABLE(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Cupboard", left_up_y-1){}

void TABLE::print(char** &map){
    map[get_up_left_y()-1][get_up_left_x()] = 32; map[get_up_left_y()-1][get_up_left_x()+1] = 32; map[get_up_left_y()-1][get_up_left_x()+2] = 47; map[get_up_left_y()-1][get_up_left_x()+3] = 238; map[get_up_left_y()-1][get_up_left_x()+4] = 238; map[get_up_left_y()-1][get_up_left_x()+5] = 238; map[get_up_left_y()-1][get_up_left_x()+6] = 238; map[get_up_left_y()-1][get_up_left_x()+7] = 238; map[get_up_left_y()-1][get_up_left_x()+8] = 238; map[get_up_left_y()-1][get_up_left_x()+9] = 238; map[get_up_left_y()-1][get_up_left_x()+10] = 238; map[get_up_left_y()-1][get_up_left_x()+11] = 238; map[get_up_left_y()-1][get_up_left_x()+12] = 92; map[get_up_left_y()-1][get_up_left_x()+13] = 32; map[get_up_left_y()-1][get_up_left_x()+14] = 32;
    map[get_up_left_y()][get_up_left_x()] = 32; map[get_up_left_y()][get_up_left_x()+1] = 47; map[get_up_left_y()][get_up_left_x()+2] = 32; map[get_up_left_y()][get_up_left_x()+3] = 32; map[get_up_left_y()][get_up_left_x()+4] = 32; map[get_up_left_y()][get_up_left_x()+5] = 32; map[get_up_left_y()][get_up_left_x()+6] = 32; map[get_up_left_y()][get_up_left_x()+7] = 32; map[get_up_left_y()][get_up_left_x()+8] = 32; map[get_up_left_y()][get_up_left_x()+9] = 32; map[get_up_left_y()][get_up_left_x()+10] = 32; map[get_up_left_y()][get_up_left_x()+11] = 32; map[get_up_left_y()][get_up_left_x()+12] = 32; map[get_up_left_y()][get_up_left_x()+13] = 92; map[get_up_left_y()][get_up_left_x()+14] = 32;
    map[get_up_left_y()+1][get_up_left_x()] = 47; map[get_up_left_y()+1][get_up_left_x()+1] = 95; map[get_up_left_y()+1][get_up_left_x()+2] = 95; map[get_up_left_y()+1][get_up_left_x()+3] = 95; map[get_up_left_y()+1][get_up_left_x()+4] = 95; map[get_up_left_y()+1][get_up_left_x()+5] = 95; map[get_up_left_y()+1][get_up_left_x()+6] = 95; map[get_up_left_y()+1][get_up_left_x()+7] = 95; map[get_up_left_y()+1][get_up_left_x()+8] = 95; map[get_up_left_y()+1][get_up_left_x()+9] = 95; map[get_up_left_y()+1][get_up_left_x()+10] = 95; map[get_up_left_y()+1][get_up_left_x()+11] = 95; map[get_up_left_y()+1][get_up_left_x()+12] = 95; map[get_up_left_y()+1][get_up_left_x()+13] = 95; map[get_up_left_y()+1][get_up_left_x()+14] = 92;
    map[get_up_left_y()+2][get_up_left_x()] = 32; map[get_up_left_y()+2][get_up_left_x()+1] = 124; map[get_up_left_y()+2][get_up_left_x()+2] = 32; map[get_up_left_y()+2][get_up_left_x()+3] = 32; map[get_up_left_y()+2][get_up_left_x()+4] = 32; map[get_up_left_y()+2][get_up_left_x()+5] = 32; map[get_up_left_y()+2][get_up_left_x()+6] = 32; map[get_up_left_y()+2][get_up_left_x()+7] = 32; map[get_up_left_y()+2][get_up_left_x()+8] = 32; map[get_up_left_y()+2][get_up_left_x()+9] = 32; map[get_up_left_y()+2][get_up_left_x()+10] = 32; map[get_up_left_y()+2][get_up_left_x()+11] = 32; map[get_up_left_y()+2][get_up_left_x()+12] = 32; map[get_up_left_y()+2][get_up_left_x()+13] = 124; map[get_up_left_y()+2][get_up_left_x()+14] = 32;
}

void TABLE::delete_(char** &m){}

void TABLE::move(char** &m, int const &dir, int const &higth, int const &width){}

void TABLE::get_interact_empty(char** &map){
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\tParece una Mesa de madera sin nada especial";
}

BOX::BOX(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y, "Caja", left_up_y-1){}

void BOX::print(char** &m){
    m[get_up_left_y()-1][get_up_left_x()] = 218; m[get_up_left_y()-1][get_up_left_x()+1] = 196; m[get_up_left_y()-1][get_up_left_x()+2] = 196; m[get_up_left_y()-1][get_up_left_x()+3] = 196; m[get_up_left_y()-1][get_up_left_x()+4] = 196; m[get_up_left_y()-1][get_up_left_x()+5] = 191;
    m[get_up_left_y()][get_up_left_x()] = 195; m[get_up_left_y()][get_up_left_x()+1] = 196; m[get_up_left_y()][get_up_left_x()+2] = 196; m[get_up_left_y()][get_up_left_x()+3] = 196; m[get_up_left_y()][get_up_left_x()+4] = 196; m[get_up_left_y()][get_up_left_x()+5] = 180;
    m[get_up_left_y()+1][get_up_left_x()] = 124; m[get_up_left_y()+1][get_up_left_x()+1] = 42; m[get_up_left_y()+1][get_up_left_x()+2] = 46; m[get_up_left_y()+1][get_up_left_x()+3] = 42; m[get_up_left_y()+1][get_up_left_x()+4] = 46; m[get_up_left_y()+1][get_up_left_x()+5] = 124;
    m[get_up_left_y()+2][get_up_left_x()] = 192; m[get_up_left_y()+2][get_up_left_x()+1] = 196; m[get_up_left_y()+2][get_up_left_x()+2] = 196; m[get_up_left_y()+2][get_up_left_x()+3] = 196; m[get_up_left_y()+2][get_up_left_x()+4] = 196; m[get_up_left_y()+2][get_up_left_x()+5] = 217;
}

void BOX::delete_(char** &m){
    m[get_up_left_y()-1][get_up_left_x()] = 32; m[get_up_left_y()-1][get_up_left_x()+1] = 32; m[get_up_left_y()-1][get_up_left_x()+2] = 32; m[get_up_left_y()-1][get_up_left_x()+3] = 32; m[get_up_left_y()-1][get_up_left_x()+4] = 32; m[get_up_left_y()-1][get_up_left_x()+5] = 32;
    m[get_up_left_y()][get_up_left_x()] = 32; m[get_up_left_y()][get_up_left_x()+1] = 32; m[get_up_left_y()][get_up_left_x()+2] = 32; m[get_up_left_y()][get_up_left_x()+3] = 32; m[get_up_left_y()][get_up_left_x()+4] = 32; m[get_up_left_y()][get_up_left_x()+5] = 32;
    m[get_up_left_y()+1][get_up_left_x()] = 32; m[get_up_left_y()+1][get_up_left_x()+1] = 32; m[get_up_left_y()+1][get_up_left_x()+2] = 32; m[get_up_left_y()+1][get_up_left_x()+3] = 32; m[get_up_left_y()+1][get_up_left_x()+4] = 32; m[get_up_left_y()+1][get_up_left_x()+5] = 32;
    m[get_up_left_y()+2][get_up_left_x()] = 32; m[get_up_left_y()+2][get_up_left_x()+1] = 32; m[get_up_left_y()+2][get_up_left_x()+2] = 32; m[get_up_left_y()+2][get_up_left_x()+3] = 32; m[get_up_left_y()+2][get_up_left_x()+4] = 32; m[get_up_left_y()+2][get_up_left_x()+5] = 32;
}

void BOX::get_interact_empty(char** &map){
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\tUna caja con un decorado en el frente";
}

void BOX::move(char** &m, int const &dir, int const &higth, int const &width){}

TABLE_TUTORIAL::TABLE_TUTORIAL(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Mesa", left_up_y-1){
    std::list<OBJECT*>* o = get_objects();
    o->push_back(new LETTER_TUTORIAL(0,0));
}

void TABLE_TUTORIAL::print(char** &map){
    map[get_up_left_y()-1][get_up_left_x()] = 32; map[get_up_left_y()-1][get_up_left_x()+1] = 32; map[get_up_left_y()-1][get_up_left_x()+2] = 47; map[get_up_left_y()-1][get_up_left_x()+3] = 238; map[get_up_left_y()-1][get_up_left_x()+4] = 238; map[get_up_left_y()-1][get_up_left_x()+5] = 238; map[get_up_left_y()-1][get_up_left_x()+6] = 238; map[get_up_left_y()-1][get_up_left_x()+7] = 238; map[get_up_left_y()-1][get_up_left_x()+8] = 238; map[get_up_left_y()-1][get_up_left_x()+9] = 92; map[get_up_left_y()-1][get_up_left_x()+10] = 32; map[get_up_left_y()-1][get_up_left_x()+11] = 32;
    map[get_up_left_y()][get_up_left_x()] = 32; map[get_up_left_y()][get_up_left_x()+1] = 47; map[get_up_left_y()][get_up_left_x()+2] = 32; map[get_up_left_y()][get_up_left_x()+3] = 32; map[get_up_left_y()][get_up_left_x()+4] = 32; map[get_up_left_y()][get_up_left_x()+5] = 32; map[get_up_left_y()][get_up_left_x()+6] = 32; map[get_up_left_y()][get_up_left_x()+7] = 32; map[get_up_left_y()][get_up_left_x()+8] = 32; map[get_up_left_y()][get_up_left_x()+9] = 32; map[get_up_left_y()][get_up_left_x()+10] = 92; map[get_up_left_y()][get_up_left_x()+11] = 32;
    map[get_up_left_y()+1][get_up_left_x()] = 47; map[get_up_left_y()+1][get_up_left_x()+1] = 95; map[get_up_left_y()+1][get_up_left_x()+2] = 95; map[get_up_left_y()+1][get_up_left_x()+3] = 95; map[get_up_left_y()+1][get_up_left_x()+4] = 95; map[get_up_left_y()+1][get_up_left_x()+5] = 95; map[get_up_left_y()+1][get_up_left_x()+6] = 95; map[get_up_left_y()+1][get_up_left_x()+7] = 95; map[get_up_left_y()+1][get_up_left_x()+8] = 95; map[get_up_left_y()+1][get_up_left_x()+9] = 95; map[get_up_left_y()+1][get_up_left_x()+10] = 95; map[get_up_left_y()+1][get_up_left_x()+11] = 92; 
    map[get_up_left_y()+2][get_up_left_x()] = 32; map[get_up_left_y()+2][get_up_left_x()+1] = 124; map[get_up_left_y()+2][get_up_left_x()+2] = 32; map[get_up_left_y()+2][get_up_left_x()+3] = 32; map[get_up_left_y()+2][get_up_left_x()+4] = 32; map[get_up_left_y()+2][get_up_left_x()+5] = 32; map[get_up_left_y()+2][get_up_left_x()+6] = 32; map[get_up_left_y()+2][get_up_left_x()+7] = 32; map[get_up_left_y()+2][get_up_left_x()+8] = 32; map[get_up_left_y()+2][get_up_left_x()+9] = 32; map[get_up_left_y()+2][get_up_left_x()+10] = 124; map[get_up_left_y()+2][get_up_left_x()+11] = 32;
}

void TABLE_TUTORIAL::delete_(char** &m){}

void TABLE_TUTORIAL::move(char** &m, int const &dir, int const &higth, int const &width){}

void TABLE_TUTORIAL::get_interact_empty(char** &map){
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\tParece una Mesa de madera normal, tiene algunas marcas pero sin sentido";
}

WINDOW::WINDOW(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Armario", left_up_y-1){}

void WINDOW::print(char** &map){
    map[get_up_left_y()][get_up_left_x()] = 201; map[get_up_left_y()][get_up_left_x()+1] = 205; map[get_up_left_y()][get_up_left_x()+2] = 205; map[get_up_left_y()][get_up_left_x()+3] = 205; map[get_up_left_y()][get_up_left_x()+4] = 205; map[get_up_left_y()][get_up_left_x()+5] = 187;
    map[get_up_left_y()+1][get_up_left_x()] = 200; map[get_up_left_y()+1][get_up_left_x()+1] = 205; map[get_up_left_y()+1][get_up_left_x()+2] = 205; map[get_up_left_y()+1][get_up_left_x()+3] = 205; map[get_up_left_y()+1][get_up_left_x()+4] = 205; map[get_up_left_y()+1][get_up_left_x()+5] = 188;
}

void WINDOW::delete_(char** &m){}

void WINDOW::move(char** &m, int const &dir, int const &higth, int const &width){}

void WINDOW::get_interact_empty(char** &map){
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\tHay una neblina que no deja ver mas alla";
}

BOX_TUTORIAL::BOX_TUTORIAL(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y, "CAJA", left_up_y-1){}

void BOX_TUTORIAL::print(char** &map){
    map[get_up_left_y()-1][get_up_left_x()] = 218; map[get_up_left_y()-1][get_up_left_x()+1] = 196; map[get_up_left_y()-1][get_up_left_x()+2] = 191;
    map[get_up_left_y()][get_up_left_x()] = 195; map[get_up_left_y()][get_up_left_x()+1] = 196; map[get_up_left_y()][get_up_left_x()+2] = 180;
    map[get_up_left_y()+1][get_up_left_x()] = 192; map[get_up_left_y()+1][get_up_left_x()+1] = 196; map[get_up_left_y()+1][get_up_left_x()+2] = 217;
}

void BOX_TUTORIAL::delete_(char** &map){
    map[get_up_left_y()-1][get_up_left_x()] = ' '; map[get_up_left_y()-1][get_up_left_x()+1] = ' '; map[get_up_left_y()-1][get_up_left_x()+2] = ' ';
    map[get_up_left_y()][get_up_left_x()] = ' '; map[get_up_left_y()][get_up_left_x()+1] = ' '; map[get_up_left_y()][get_up_left_x()+2] = ' ';
    map[get_up_left_y()+1][get_up_left_x()] = ' '; map[get_up_left_y()+1][get_up_left_x()+1] = ' '; map[get_up_left_y()+1][get_up_left_x()+2] = ' ';
}

void BOX_TUTORIAL::get_interact_empty(char** &map){
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\tUna caja de carton, parece ligera";
}

void BOX_TUTORIAL::move(char** &m, int const &dir, int const &higth, int const &width){
    delete_(m);
    if(get_moved()) return;
    if(dir == 1 && get_up_left_y()-3 > 3){
        set_up_left_y(get_up_left_y()-3);
        set_bot_right_y(get_bot_right_y()-3);
        set_object_heigth(get_up_left_y()-1);
        set_moved(true);
    }
    else if(dir == 2 && get_bot_right_x()+2 < width){
        set_up_left_x(get_up_left_x()+2);
        set_bot_right_x(get_bot_right_x()+2);
        set_object_heigth(get_up_left_y()-1);
        set_moved(true);
    }
    else if(dir == 3 && get_bot_right_y()+2 < higth){
        set_up_left_y(get_up_left_y()+2);
        set_bot_right_y(get_bot_right_y()+2);
        set_object_heigth(get_up_left_y()-1);
        set_moved(true);
    }
    else if(dir == 4 && get_up_left_x()-2 > 0){
        set_up_left_x(get_up_left_x()-2);
        set_bot_right_x(get_bot_right_x()-2);
        set_object_heigth(get_up_left_y()-1);
        set_moved(true);
    }
}

CUPBOARD_PUZLE::CUPBOARD_PUZLE(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Armario con Mecanismo", left_up_y-2){}

void CUPBOARD_PUZLE::print(char** &map){
    map[get_up_left_y()-2][get_up_left_x()] = 218; map[get_up_left_y()-2][get_up_left_x()+1] = 196; map[get_up_left_y()-2][get_up_left_x()+2] = 196; map[get_up_left_y()-2][get_up_left_x()+3] = 196; map[get_up_left_y()-2][get_up_left_x()+4] = 196; map[get_up_left_y()-2][get_up_left_x()+5] = 196; map[get_up_left_y()-2][get_up_left_x()+6] = 191;
    map[get_up_left_y()-1][get_up_left_x()] = 124; map[get_up_left_y()-1][get_up_left_x()+1] = 32; map[get_up_left_y()-1][get_up_left_x()+2] = 218; map[get_up_left_y()-1][get_up_left_x()+3] = 196; map[get_up_left_y()-1][get_up_left_x()+4] = 191; map[get_up_left_y()-1][get_up_left_x()+5] = 32; map[get_up_left_y()-1][get_up_left_x()+6] = 124;
    map[get_up_left_y()][get_up_left_x()] = 124; map[get_up_left_y()][get_up_left_x()+1] = 32; map[get_up_left_y()][get_up_left_x()+2] = 192; map[get_up_left_y()][get_up_left_x()+3] = 196; map[get_up_left_y()][get_up_left_x()+4] = 217; map[get_up_left_y()][get_up_left_x()+5] = 32; map[get_up_left_y()][get_up_left_x()+6] = 124;
    map[get_up_left_y()+1][get_up_left_x()] = 124; map[get_up_left_y()+1][get_up_left_x()+1] = 32; map[get_up_left_y()+1][get_up_left_x()+2] = 111; map[get_up_left_y()+1][get_up_left_x()+3] = 32; map[get_up_left_y()+1][get_up_left_x()+4] = 111; map[get_up_left_y()+1][get_up_left_x()+5] = 32; map[get_up_left_y()+1][get_up_left_x()+6] = 124;
    map[get_up_left_y()+2][get_up_left_x()] = 192; map[get_up_left_y()+2][get_up_left_x()+1] = 196; map[get_up_left_y()+2][get_up_left_x()+2] = 196; map[get_up_left_y()+2][get_up_left_x()+3] = 196; map[get_up_left_y()+2][get_up_left_x()+4] = 196; map[get_up_left_y()+2][get_up_left_x()+5] = 196; map[get_up_left_y()+2][get_up_left_x()+6] = 217;
}

void CUPBOARD_PUZLE::delete_(char** &map){
    map[get_up_left_y()-2][get_up_left_x()] = ' '; map[get_up_left_y()-2][get_up_left_x()+1] = ' '; map[get_up_left_y()-2][get_up_left_x()+2] = ' '; map[get_up_left_y()-2][get_up_left_x()+3] = ' '; map[get_up_left_y()-2][get_up_left_x()+4] = ' '; map[get_up_left_y()-2][get_up_left_x()+5] = ' '; map[get_up_left_y()-2][get_up_left_x()+6] = ' ';
    map[get_up_left_y()-1][get_up_left_x()] = ' '; map[get_up_left_y()-1][get_up_left_x()+1] = ' '; map[get_up_left_y()-1][get_up_left_x()+2] = ' '; map[get_up_left_y()-1][get_up_left_x()+3] = ' '; map[get_up_left_y()-1][get_up_left_x()+4] = ' '; map[get_up_left_y()-1][get_up_left_x()+5] = ' '; map[get_up_left_y()-1][get_up_left_x()+6] = ' ';
    map[get_up_left_y()][get_up_left_x()] = ' '; map[get_up_left_y()][get_up_left_x()+1] = ' '; map[get_up_left_y()][get_up_left_x()+2] = ' '; map[get_up_left_y()][get_up_left_x()+3] = ' '; map[get_up_left_y()][get_up_left_x()+4] = ' '; map[get_up_left_y()][get_up_left_x()+5] = ' '; map[get_up_left_y()][get_up_left_x()+6] = ' ';
    map[get_up_left_y()+1][get_up_left_x()] = ' '; map[get_up_left_y()+1][get_up_left_x()+1] = ' '; map[get_up_left_y()+1][get_up_left_x()+2] = ' '; map[get_up_left_y()+1][get_up_left_x()+3] = ' '; map[get_up_left_y()+1][get_up_left_x()+4] = ' '; map[get_up_left_y()+1][get_up_left_x()+5] = ' '; map[get_up_left_y()+1][get_up_left_x()+6] = ' ';
    map[get_up_left_y()+2][get_up_left_x()] = ' '; map[get_up_left_y()+2][get_up_left_x()+1] = ' '; map[get_up_left_y()+2][get_up_left_x()+2] = ' '; map[get_up_left_y()+2][get_up_left_x()+3] = ' '; map[get_up_left_y()+2][get_up_left_x()+4] = ' '; map[get_up_left_y()+2][get_up_left_x()+5] = ' '; map[get_up_left_y()+2][get_up_left_x()+6] = ' ';
}

void CUPBOARD_PUZLE::move(char** &m, int const &dir, int const &higth, int const &width){}

void CUPBOARD_PUZLE::get_interact_empty(char** &map){
    std::list<OBJECT*>* o = get_objects();
    char key;
    if(!lights_out_flag){
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tParece haber un mecanismo que no deja abrir el armario.";
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tQuieres intentar desbloquearlo?";
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tSI: E         NO: ESC";
        while(true){
            if(kbhit()){
                key = getch();
                if(key == ACTION || key == ACTION2){
                    if(run_lights_out()){
                        o->push_back(new LOG3(0,0));
                        o->push_back(new PIECE6(0,0));
                        std::cout << std::endl << std::endl << std::endl << std::endl;
                        std::cout << "\t\t\t\t";
                        std::string text = "*Se escucha algo desbloqueandose*";
                        std::string text2 = "El Armario parece estar abierto";
                        std::string text3 = "Pero...";
                        std::string text4 = "Porque siento que esto ya lo he hecho antes";
                        std::string* t_pointer = &text;
                        int count = 0;
                        while(true){
                            for(int i=0; i< t_pointer->length(); i++){
                                std::cout << (*t_pointer)[i];
                                Timer t;
                                while(true){
                                    if(t.get_elapsed_time() >= 0.05) break;
                                }
                            }
                            std::cout << std::endl << std::endl;
                            std::cout << "\t\t\t\t";
                            Timer t;
                            while(true){
                                if(t.get_elapsed_time() >= 1) break;
                            }
                            count++;
                            if(count == 1) t_pointer = &text2;
                            else if(count == 2) t_pointer = &text3;
                            else if(count == 3) t_pointer = &text4;
                            else break;
                        }
                        lights_out_flag = true;
                        map[get_up_left_y()-1][get_up_left_x()+2] = 32; map[get_up_left_y()-1][get_up_left_x()+3] = 32; map[get_up_left_y()-1][get_up_left_x()+4] = 32;
                        map[get_up_left_y()][get_up_left_x()+2] = 32; map[get_up_left_y()][get_up_left_x()+3] = 32; map[get_up_left_y()][get_up_left_x()+4] = 32;
                        return;
                    }
                    else return;
                }
                else if(key == ESC) return;
            }
        }
    }
    else{
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tEl Armario ya esta abierto pero vacio";
    }
}

LEVER_1::LEVER_1(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Palanca", left_up_y-2){}

void LEVER_1::print(char** &map){
    map[get_up_left_y()-2][get_up_left_x()] = 218; map[get_up_left_y()-2][get_up_left_x()+1] = 196; map[get_up_left_y()-2][get_up_left_x()+2] = 191; 
    map[get_up_left_y()-1][get_up_left_x()] = 124; map[get_up_left_y()-1][get_up_left_x()+1] = 194; map[get_up_left_y()-1][get_up_left_x()+2] = 124; 
    map[get_up_left_y()][get_up_left_x()] = 124; map[get_up_left_y()][get_up_left_x()+1] = 238; map[get_up_left_y()][get_up_left_x()+2] = 124; 
    map[get_up_left_y()+1][get_up_left_x()] = 192; map[get_up_left_y()+1][get_up_left_x()+1] = 196; map[get_up_left_y()+1][get_up_left_x()+2] = 217; 
}

void LEVER_1::delete_(char** &map){
    map[get_up_left_y()-2][get_up_left_x()] = ' '; map[get_up_left_y()-2][get_up_left_x()+1] = ' '; map[get_up_left_y()-2][get_up_left_x()+2] = ' '; 
    map[get_up_left_y()-1][get_up_left_x()] = ' '; map[get_up_left_y()-1][get_up_left_x()+1] = ' '; map[get_up_left_y()-1][get_up_left_x()+2] = ' '; 
    map[get_up_left_y()][get_up_left_x()] = ' '; map[get_up_left_y()][get_up_left_x()+1] = ' '; map[get_up_left_y()][get_up_left_x()+2] = ' '; 
    map[get_up_left_y()+1][get_up_left_x()] = ' '; map[get_up_left_y()+1][get_up_left_x()+1] = ' '; map[get_up_left_y()+1][get_up_left_x()+2] = ' ';
}

void LEVER_1::move(char** &m, int const &dir, int const &higth, int const &width){}

void LEVER_1::get_interact_empty(char** &map){
    char key;
    if(!lever_1_flag){
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tParece que la palanca no esta activada";
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tQuieres Activarla?";
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tSI: E              NO: ESC";
        while(true){
            if(kbhit()){
                key = getch();
                if(key == ACTION || key == ACTION2){
                    if(!lever_2_flag && !lever_3_flag && !lever_4_flag && !lever_5_flag){
                        lever_1_flag = true;
                        map[get_up_left_y()-1][get_up_left_x()+1] = 95;
                        map[get_up_left_y()][get_up_left_x()+1] = 193;
                        return;
                    }
                    else{
                        error_order_levers_flag = true;
                        lever_1_flag = false;
                        lever_2_flag = false;
                        lever_3_flag = false;
                        lever_4_flag = false;
                        lever_5_flag = false;
                        return;
                    }
                    
                }
                else if(key == ESC) return;
            }
        }
    }
    else{
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tEsta palanca ya esta activada";
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tCERRAR: ESC";
        while(true){
            if(kbhit()){
                key = getch();
                if(key == ESC) return;
            }
        }
    }
}

LEVER_2::LEVER_2(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Palanca", left_up_y-2){}

void LEVER_2::print(char** &map){
    map[get_up_left_y()-2][get_up_left_x()] = 95; map[get_up_left_y()-2][get_up_left_x()+1] = 32; map[get_up_left_y()-2][get_up_left_x()+2] = 218; map[get_up_left_y()-2][get_up_left_x()+3] = 196; map[get_up_left_y()-2][get_up_left_x()+4] = 191; 
    map[get_up_left_y()-1][get_up_left_x()] = 32; map[get_up_left_y()-1][get_up_left_x()+1] = 92; map[get_up_left_y()-1][get_up_left_x()+2] = 124; map[get_up_left_y()-1][get_up_left_x()+3] = 32; map[get_up_left_y()-1][get_up_left_x()+4] = 124; 
    map[get_up_left_y()][get_up_left_x()] = 32; map[get_up_left_y()][get_up_left_x()+1] = 32; map[get_up_left_y()][get_up_left_x()+2] = 124; map[get_up_left_y()][get_up_left_x()+3] = 32; map[get_up_left_y()][get_up_left_x()+4] = 124; 
    map[get_up_left_y()+1][get_up_left_x()] = 32; map[get_up_left_y()+1][get_up_left_x()+1] = 32; map[get_up_left_y()+1][get_up_left_x()+2] = 192; map[get_up_left_y()+1][get_up_left_x()+3] = 196; map[get_up_left_y()+1][get_up_left_x()+4] = 217; 
}

void LEVER_2::delete_(char** &map){
    map[get_up_left_y()-2][get_up_left_x()] = 32; map[get_up_left_y()-2][get_up_left_x()+1] = 32; map[get_up_left_y()-2][get_up_left_x()+2] = 32; map[get_up_left_y()-2][get_up_left_x()+3] = 32; map[get_up_left_y()-2][get_up_left_x()+4] = 32; 
    map[get_up_left_y()-1][get_up_left_x()] = 32; map[get_up_left_y()-1][get_up_left_x()+1] = 32; map[get_up_left_y()-1][get_up_left_x()+2] = 32; map[get_up_left_y()-1][get_up_left_x()+3] = 32; map[get_up_left_y()-1][get_up_left_x()+4] = 32; 
    map[get_up_left_y()][get_up_left_x()] = 32; map[get_up_left_y()][get_up_left_x()+1] = 32; map[get_up_left_y()][get_up_left_x()+2] = 32; map[get_up_left_y()][get_up_left_x()+3] = 32; map[get_up_left_y()][get_up_left_x()+4] = 32; 
    map[get_up_left_y()+1][get_up_left_x()] = 32; map[get_up_left_y()+1][get_up_left_x()+1] = 32; map[get_up_left_y()+1][get_up_left_x()+2] = 32; map[get_up_left_y()+1][get_up_left_x()+3] = 32; map[get_up_left_y()+1][get_up_left_x()+4] = 32; 
}

void LEVER_2::move(char** &m, int const &dir, int const &higth, int const &width){}

void LEVER_2::get_interact_empty(char** &map){
    char key;
    if(!lever_2_flag){
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tParece que la palanca no esta activada";
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tQuieres Activarla?";
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tSI: E              NO: ESC";
        while(true){
            if(kbhit()){
                key = getch();
                if(key == ACTION || key == ACTION2){
                    if(lever_1_flag && !lever_3_flag && !lever_4_flag && !lever_5_flag){
                        lever_2_flag = true;
                        map[get_up_left_y()-2][get_up_left_x()] = 32;
                         map[get_up_left_y()+1][get_up_left_x()] = 238;
                         map[get_up_left_y()-1][get_up_left_x()+1] = 32;
                         map[get_up_left_y()][get_up_left_x()+1] = 47;
                         return;
                    }
                    else{
                        error_order_levers_flag = true;
                        lever_1_flag = false;
                        lever_2_flag = false;
                        lever_3_flag = false;
                        lever_4_flag = false;
                        lever_5_flag = false;
                        return;
                    }
                }
                else if(key == ESC) return;
            }
        }
    }
    else{
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tEsta palanca ya esta activada";
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tCERRAR: ESC";
        while(true){
            if(kbhit()){
                key = getch();
                if(key == ESC) return;
            }
        }
    }
}

LEVER_3::LEVER_3(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Palanca", left_up_y-2){}

void LEVER_3::print(char** &map){
    map[get_up_left_y()-2][get_up_left_x()] = 218; map[get_up_left_y()-2][get_up_left_x()+1] = 196; map[get_up_left_y()-2][get_up_left_x()+2] = 191; 
    map[get_up_left_y()-1][get_up_left_x()] = 124; map[get_up_left_y()-1][get_up_left_x()+1] = 194; map[get_up_left_y()-1][get_up_left_x()+2] = 124; 
    map[get_up_left_y()][get_up_left_x()] = 124; map[get_up_left_y()][get_up_left_x()+1] = 238; map[get_up_left_y()][get_up_left_x()+2] = 124; 
    map[get_up_left_y()+1][get_up_left_x()] = 192; map[get_up_left_y()+1][get_up_left_x()+1] = 196; map[get_up_left_y()+1][get_up_left_x()+2] = 217; 
}

void LEVER_3::delete_(char** &map){
    map[get_up_left_y()-2][get_up_left_x()] = ' '; map[get_up_left_y()-2][get_up_left_x()+1] = ' '; map[get_up_left_y()-2][get_up_left_x()+2] = ' '; 
    map[get_up_left_y()-1][get_up_left_x()] = ' '; map[get_up_left_y()-1][get_up_left_x()+1] = ' '; map[get_up_left_y()-1][get_up_left_x()+2] = ' '; 
    map[get_up_left_y()][get_up_left_x()] = ' '; map[get_up_left_y()][get_up_left_x()+1] = ' '; map[get_up_left_y()][get_up_left_x()+2] = ' '; 
    map[get_up_left_y()+1][get_up_left_x()] = ' '; map[get_up_left_y()+1][get_up_left_x()+1] = ' '; map[get_up_left_y()+1][get_up_left_x()+2] = ' ';
}

void LEVER_3::move(char** &m, int const &dir, int const &higth, int const &width){}

void LEVER_3::get_interact_empty(char** &map){
    char key;
    if(!lever_3_flag){
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tParece que la palanca no esta activada";
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tQuieres Activarla?";
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tSI: E              NO: ESC";
        while(true){
            if(kbhit()){
                key = getch();
                if(key == ACTION || key == ACTION2){
                    if(lever_1_flag && lever_2_flag && !lever_4_flag && !lever_5_flag){
                        lever_3_flag = true;
                        map[get_up_left_y()-1][get_up_left_x()+1] = 95;
                        map[get_up_left_y()][get_up_left_x()+1] = 193;
                        return;
                    }
                    else{
                        error_order_levers_flag = true;
                        lever_1_flag = false;
                        lever_2_flag = false;
                        lever_3_flag = false;
                        lever_4_flag = false;
                        lever_5_flag = false;
                        return;
                    }
                    
                }
                else if(key == ESC) return;
            }
        }
    }
    else{
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tEsta palanca ya esta activada";
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tCERRAR: ESC";
        while(true){
            if(kbhit()){
                key = getch();
                if(key == ESC) return;
            }
        }
    }
}

LEVER_4::LEVER_4(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Palanca", left_up_y-2){}

void LEVER_4::print(char** &map){
    map[get_up_left_y()-2][get_up_left_x()] = 218; map[get_up_left_y()-2][get_up_left_x()+1] = 196; map[get_up_left_y()-2][get_up_left_x()+2] = 191; map[get_up_left_y()-2][get_up_left_x()+3] = 32; map[get_up_left_y()-2][get_up_left_x()+4] = 95; 
    map[get_up_left_y()-1][get_up_left_x()] = 124; map[get_up_left_y()-1][get_up_left_x()+1] = 32; map[get_up_left_y()-1][get_up_left_x()+2] = 124; map[get_up_left_y()-1][get_up_left_x()+3] = 47; map[get_up_left_y()-1][get_up_left_x()+4] = 32; 
    map[get_up_left_y()][get_up_left_x()] = 124; map[get_up_left_y()][get_up_left_x()+1] = 32; map[get_up_left_y()][get_up_left_x()+2] = 124; map[get_up_left_y()][get_up_left_x()+3] = 32; map[get_up_left_y()][get_up_left_x()+4] = 32; 
    map[get_up_left_y()+1][get_up_left_x()] = 192; map[get_up_left_y()+1][get_up_left_x()+1] = 196; map[get_up_left_y()+1][get_up_left_x()+2] = 217; map[get_up_left_y()+1][get_up_left_x()+3] = 32; map[get_up_left_y()+1][get_up_left_x()+4] = 32; 
}

void LEVER_4::delete_(char** &map){
    map[get_up_left_y()-2][get_up_left_x()] = 32; map[get_up_left_y()-2][get_up_left_x()+1] = 32; map[get_up_left_y()-2][get_up_left_x()+2] = 32; map[get_up_left_y()-2][get_up_left_x()+3] = 32; map[get_up_left_y()-2][get_up_left_x()+4] = 32; 
    map[get_up_left_y()-1][get_up_left_x()] = 32; map[get_up_left_y()-1][get_up_left_x()+1] = 32; map[get_up_left_y()-1][get_up_left_x()+2] = 32; map[get_up_left_y()-1][get_up_left_x()+3] = 32; map[get_up_left_y()-1][get_up_left_x()+4] = 32; 
    map[get_up_left_y()][get_up_left_x()] = 32; map[get_up_left_y()][get_up_left_x()+1] = 32; map[get_up_left_y()][get_up_left_x()+2] = 32; map[get_up_left_y()][get_up_left_x()+3] = 32; map[get_up_left_y()][get_up_left_x()+4] = 32; 
    map[get_up_left_y()+1][get_up_left_x()] = 32; map[get_up_left_y()+1][get_up_left_x()+1] = 32; map[get_up_left_y()+1][get_up_left_x()+2] = 32; map[get_up_left_y()+1][get_up_left_x()+3] = 32; map[get_up_left_y()+1][get_up_left_x()+4] = 32; 
}

void LEVER_4::move(char** &m, int const &dir, int const &higth, int const &width){}

void LEVER_4::get_interact_empty(char** &map){
    char key;
    if(!lever_4_flag){
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tParece que la palanca no esta activada";
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tQuieres Activarla?";
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tSI: E              NO: ESC";
        while(true){
            if(kbhit()){
                key = getch();
                if(key == ACTION || key == ACTION2){
                    if(lever_1_flag && lever_2_flag && lever_3_flag &&  !lever_5_flag){
                        lever_4_flag = true;
                        map[get_up_left_y()-1][get_up_left_x()+3] = 32;
                        map[get_up_left_y()][get_up_left_x()+3] = 92;
                        map[get_up_left_y()-2][get_up_left_x()+4] = 32; 
                        map[get_up_left_y()+1][get_up_left_x()+4] = 238; 
                        return;
                    }
                    else{
                        error_order_levers_flag = true;
                        lever_1_flag = false;
                        lever_2_flag = false;
                        lever_3_flag = false;
                        lever_4_flag = false;
                        lever_5_flag = false;
                        return;
                    }
                }
                else if(key == ESC) return;
            }
        }
    }
    else{
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tEsta palanca ya esta activada";
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tCERRAR: ESC";
        while(true){
            if(kbhit()){
                key = getch();
                if(key == ESC) return;
            }
        }
    }
}

LEVER_5::LEVER_5(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Palanca", left_up_y-2){}

void LEVER_5::print(char** &map){
    map[get_up_left_y()-2][get_up_left_x()] = 218; map[get_up_left_y()-2][get_up_left_x()+1] = 196; map[get_up_left_y()-2][get_up_left_x()+2] = 191; 
    map[get_up_left_y()-1][get_up_left_x()] = 124; map[get_up_left_y()-1][get_up_left_x()+1] = 194; map[get_up_left_y()-1][get_up_left_x()+2] = 124; 
    map[get_up_left_y()][get_up_left_x()] = 124; map[get_up_left_y()][get_up_left_x()+1] = 238; map[get_up_left_y()][get_up_left_x()+2] = 124; 
    map[get_up_left_y()+1][get_up_left_x()] = 192; map[get_up_left_y()+1][get_up_left_x()+1] = 196; map[get_up_left_y()+1][get_up_left_x()+2] = 217; 
}

void LEVER_5::delete_(char** &map){
    map[get_up_left_y()-2][get_up_left_x()] = ' '; map[get_up_left_y()-2][get_up_left_x()+1] = ' '; map[get_up_left_y()-2][get_up_left_x()+2] = ' '; 
    map[get_up_left_y()-1][get_up_left_x()] = ' '; map[get_up_left_y()-1][get_up_left_x()+1] = ' '; map[get_up_left_y()-1][get_up_left_x()+2] = ' '; 
    map[get_up_left_y()][get_up_left_x()] = ' '; map[get_up_left_y()][get_up_left_x()+1] = ' '; map[get_up_left_y()][get_up_left_x()+2] = ' '; 
    map[get_up_left_y()+1][get_up_left_x()] = ' '; map[get_up_left_y()+1][get_up_left_x()+1] = ' '; map[get_up_left_y()+1][get_up_left_x()+2] = ' ';
}

void LEVER_5::move(char** &m, int const &dir, int const &higth, int const &width){}

void LEVER_5::get_interact_empty(char** &map){
    char key;
    if(!lever_5_flag){
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tParece que la palanca no esta activada";
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tQuieres Activarla?";
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tSI: E              NO: ESC";
        while(true){
            if(kbhit()){
                key = getch();
                if(key == ACTION || key == ACTION2){
                    if(lever_1_flag && lever_2_flag && lever_3_flag && lever_4_flag){
                        lever_5_flag = true;
                        map[get_up_left_y()-1][get_up_left_x()+1] = 95;
                        map[get_up_left_y()][get_up_left_x()+1] = 193;
                        return;
                    }
                    else{
                        error_order_levers_flag = true;
                        lever_1_flag = false;
                        lever_2_flag = false;
                        lever_3_flag = false;
                        lever_4_flag = false;
                        lever_5_flag = false;
                        return;
                    }
                    
                }
                else if(key == ESC) return;
            }
        }
    }
    else{
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tEsta palanca ya esta activada";
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tCERRAR: ESC";
        while(true){
            if(kbhit()){
                key = getch();
                if(key == ESC) return;
            }
        }
    }
}

SHELF_1::SHELF_1(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Estante", left_up_y-3){}

void SHELF_1::print(char** &map){
    map[get_up_left_y()-3][get_up_left_x()] = 218; map[get_up_left_y()-3][get_up_left_x()+1] = 196; map[get_up_left_y()-3][get_up_left_x()+2] = 196; map[get_up_left_y()-3][get_up_left_x()+3] = 196; map[get_up_left_y()-3][get_up_left_x()+4] = 196; map[get_up_left_y()-3][get_up_left_x()+5] = 196; map[get_up_left_y()-3][get_up_left_x()+6] = 196; map[get_up_left_y()-3][get_up_left_x()+7] = 196; map[get_up_left_y()-3][get_up_left_x()+8] = 196; map[get_up_left_y()-3][get_up_left_x()+9] = 196; map[get_up_left_y()-3][get_up_left_x()+10] = 196; map[get_up_left_y()-3][get_up_left_x()+11] = 196; map[get_up_left_y()-3][get_up_left_x()+12] = 196; map[get_up_left_y()-3][get_up_left_x()+13] = 191;
    map[get_up_left_y()-2][get_up_left_x()] = 195; map[get_up_left_y()-2][get_up_left_x()+1] = 186; map[get_up_left_y()-2][get_up_left_x()+2] = 186; map[get_up_left_y()-2][get_up_left_x()+3] = 186; map[get_up_left_y()-2][get_up_left_x()+4] = 186; map[get_up_left_y()-2][get_up_left_x()+5] = 196; map[get_up_left_y()-2][get_up_left_x()+6] = 196; map[get_up_left_y()-2][get_up_left_x()+7] = 196; map[get_up_left_y()-2][get_up_left_x()+8] = 196; map[get_up_left_y()-2][get_up_left_x()+9] = 196; map[get_up_left_y()-2][get_up_left_x()+10] = 196; map[get_up_left_y()-2][get_up_left_x()+11] = 196; map[get_up_left_y()-2][get_up_left_x()+12] = 196; map[get_up_left_y()-2][get_up_left_x()+13] = 180;
    map[get_up_left_y()-1][get_up_left_x()] = 195; map[get_up_left_y()-1][get_up_left_x()+1] = 196; map[get_up_left_y()-1][get_up_left_x()+2] = 196; map[get_up_left_y()-1][get_up_left_x()+3] = 196; map[get_up_left_y()-1][get_up_left_x()+4] = 196; map[get_up_left_y()-1][get_up_left_x()+5] = 196; map[get_up_left_y()-1][get_up_left_x()+6] = 196; map[get_up_left_y()-1][get_up_left_x()+7] = 196; map[get_up_left_y()-1][get_up_left_x()+8] = 196; map[get_up_left_y()-1][get_up_left_x()+9] = 196; map[get_up_left_y()-1][get_up_left_x()+10] = 196; map[get_up_left_y()-1][get_up_left_x()+11] = 196; map[get_up_left_y()-1][get_up_left_x()+12] = 196; map[get_up_left_y()-1][get_up_left_x()+13] = 180;
    map[get_up_left_y()][get_up_left_x()] = 195; map[get_up_left_y()][get_up_left_x()+1] = 196; map[get_up_left_y()][get_up_left_x()+2] = 196; map[get_up_left_y()][get_up_left_x()+3] = 196; map[get_up_left_y()][get_up_left_x()+4] = 196; map[get_up_left_y()][get_up_left_x()+5] = 196; map[get_up_left_y()][get_up_left_x()+6] = 196; map[get_up_left_y()][get_up_left_x()+7] = 196; map[get_up_left_y()][get_up_left_x()+8] = 196; map[get_up_left_y()][get_up_left_x()+9] = 196; map[get_up_left_y()][get_up_left_x()+10] = 196; map[get_up_left_y()][get_up_left_x()+11] = 196; map[get_up_left_y()][get_up_left_x()+12] = 196; map[get_up_left_y()][get_up_left_x()+13] = 180;
    map[get_up_left_y()+1][get_up_left_x()] = 195; map[get_up_left_y()+1][get_up_left_x()+1] = 196; map[get_up_left_y()+1][get_up_left_x()+2] = 196; map[get_up_left_y()+1][get_up_left_x()+3] = 196; map[get_up_left_y()+1][get_up_left_x()+4] = 196; map[get_up_left_y()+1][get_up_left_x()+5] = 196; map[get_up_left_y()+1][get_up_left_x()+6] = 196; map[get_up_left_y()+1][get_up_left_x()+7] = 196; map[get_up_left_y()+1][get_up_left_x()+8] = 196; map[get_up_left_y()+1][get_up_left_x()+9] = 186; map[get_up_left_y()+1][get_up_left_x()+10] = 186; map[get_up_left_y()+1][get_up_left_x()+11] = 186; map[get_up_left_y()+1][get_up_left_x()+12] = 186; map[get_up_left_y()+1][get_up_left_x()+13] = 180;
}

void SHELF_1::delete_(char** &map){
    map[get_up_left_y()-3][get_up_left_x()] = 32; map[get_up_left_y()-3][get_up_left_x()+1] = 32; map[get_up_left_y()-3][get_up_left_x()+2] = 32; map[get_up_left_y()-3][get_up_left_x()+3] = 32; map[get_up_left_y()-3][get_up_left_x()+4] = 32; map[get_up_left_y()-3][get_up_left_x()+5] = 32; map[get_up_left_y()-3][get_up_left_x()+6] = 32; map[get_up_left_y()-3][get_up_left_x()+7] = 32; map[get_up_left_y()-3][get_up_left_x()+8] = 32; map[get_up_left_y()-3][get_up_left_x()+9] = 32; map[get_up_left_y()-3][get_up_left_x()+10] = 32; map[get_up_left_y()-3][get_up_left_x()+11] = 32; map[get_up_left_y()-3][get_up_left_x()+12] = 32; map[get_up_left_y()-3][get_up_left_x()+13] = 32;
    map[get_up_left_y()-2][get_up_left_x()] = 32; map[get_up_left_y()-2][get_up_left_x()+1] = 32; map[get_up_left_y()-2][get_up_left_x()+2] = 32; map[get_up_left_y()-2][get_up_left_x()+3] = 32; map[get_up_left_y()-2][get_up_left_x()+4] = 32; map[get_up_left_y()-2][get_up_left_x()+5] = 32; map[get_up_left_y()-2][get_up_left_x()+6] = 32; map[get_up_left_y()-2][get_up_left_x()+7] = 32; map[get_up_left_y()-2][get_up_left_x()+8] = 32; map[get_up_left_y()-2][get_up_left_x()+9] = 32; map[get_up_left_y()-2][get_up_left_x()+10] = 32; map[get_up_left_y()-2][get_up_left_x()+11] = 32; map[get_up_left_y()-2][get_up_left_x()+12] = 32; map[get_up_left_y()-2][get_up_left_x()+13] = 32;
    map[get_up_left_y()-1][get_up_left_x()] = 32; map[get_up_left_y()-1][get_up_left_x()+1] = 32; map[get_up_left_y()-1][get_up_left_x()+2] = 32; map[get_up_left_y()-1][get_up_left_x()+3] = 32; map[get_up_left_y()-1][get_up_left_x()+4] = 32; map[get_up_left_y()-1][get_up_left_x()+5] = 32; map[get_up_left_y()-1][get_up_left_x()+6] = 32; map[get_up_left_y()-1][get_up_left_x()+7] = 32; map[get_up_left_y()-1][get_up_left_x()+8] = 32; map[get_up_left_y()-1][get_up_left_x()+9] = 32; map[get_up_left_y()-1][get_up_left_x()+10] = 32; map[get_up_left_y()-1][get_up_left_x()+11] = 32; map[get_up_left_y()-1][get_up_left_x()+12] = 32; map[get_up_left_y()-1][get_up_left_x()+13] = 32;
    map[get_up_left_y()][get_up_left_x()] = 32; map[get_up_left_y()][get_up_left_x()+1] = 32; map[get_up_left_y()][get_up_left_x()+2] = 32; map[get_up_left_y()][get_up_left_x()+3] = 32; map[get_up_left_y()][get_up_left_x()+4] = 32; map[get_up_left_y()][get_up_left_x()+5] = 32; map[get_up_left_y()][get_up_left_x()+6] = 32; map[get_up_left_y()][get_up_left_x()+7] = 32; map[get_up_left_y()][get_up_left_x()+8] = 32; map[get_up_left_y()][get_up_left_x()+9] = 32; map[get_up_left_y()][get_up_left_x()+10] = 32; map[get_up_left_y()][get_up_left_x()+11] = 32; map[get_up_left_y()][get_up_left_x()+12] = 32; map[get_up_left_y()][get_up_left_x()+13] = 32;
    map[get_up_left_y()+1][get_up_left_x()] = 32; map[get_up_left_y()+1][get_up_left_x()+1] = 32; map[get_up_left_y()+1][get_up_left_x()+2] = 32; map[get_up_left_y()+1][get_up_left_x()+3] = 32; map[get_up_left_y()+1][get_up_left_x()+4] = 32; map[get_up_left_y()+1][get_up_left_x()+5] = 32; map[get_up_left_y()+1][get_up_left_x()+6] = 32; map[get_up_left_y()+1][get_up_left_x()+7] = 32; map[get_up_left_y()+1][get_up_left_x()+8] = 32; map[get_up_left_y()+1][get_up_left_x()+9] = 32; map[get_up_left_y()+1][get_up_left_x()+10] = 32; map[get_up_left_y()+1][get_up_left_x()+11] = 32; map[get_up_left_y()+1][get_up_left_x()+12] = 32; map[get_up_left_y()+1][get_up_left_x()+13] = 32;
}

void SHELF_1::move(char** &m, int const &dir, int const &higth, int const &width){}

void SHELF_1::get_interact_empty(char** &map){
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\tUn estante de madera con libros sobre leyes";
}

SHELF_2::SHELF_2(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Estante", left_up_y-3){}

void SHELF_2::print(char** &map){
    map[get_up_left_y()-3][get_up_left_x()] = 218; map[get_up_left_y()-3][get_up_left_x()+1] = 196; map[get_up_left_y()-3][get_up_left_x()+2] = 196; map[get_up_left_y()-3][get_up_left_x()+3] = 196; map[get_up_left_y()-3][get_up_left_x()+4] = 196; map[get_up_left_y()-3][get_up_left_x()+5] = 196; map[get_up_left_y()-3][get_up_left_x()+6] = 196; map[get_up_left_y()-3][get_up_left_x()+7] = 196; map[get_up_left_y()-3][get_up_left_x()+8] = 196; map[get_up_left_y()-3][get_up_left_x()+9] = 196; map[get_up_left_y()-3][get_up_left_x()+10] = 196; map[get_up_left_y()-3][get_up_left_x()+11] = 196; map[get_up_left_y()-3][get_up_left_x()+12] = 196; map[get_up_left_y()-3][get_up_left_x()+13] = 191;
    map[get_up_left_y()-2][get_up_left_x()] = 195; map[get_up_left_y()-2][get_up_left_x()+1] = 196; map[get_up_left_y()-2][get_up_left_x()+2] = 196; map[get_up_left_y()-2][get_up_left_x()+3] = 196; map[get_up_left_y()-2][get_up_left_x()+4] = 186; map[get_up_left_y()-2][get_up_left_x()+5] = 196; map[get_up_left_y()-2][get_up_left_x()+6] = 196; map[get_up_left_y()-2][get_up_left_x()+7] = 186; map[get_up_left_y()-2][get_up_left_x()+8] = 186; map[get_up_left_y()-2][get_up_left_x()+9] = 186; map[get_up_left_y()-2][get_up_left_x()+10] = 196; map[get_up_left_y()-2][get_up_left_x()+11] = 196; map[get_up_left_y()-2][get_up_left_x()+12] = 196; map[get_up_left_y()-2][get_up_left_x()+13] = 180;
    map[get_up_left_y()-1][get_up_left_x()] = 195; map[get_up_left_y()-1][get_up_left_x()+1] = 196; map[get_up_left_y()-1][get_up_left_x()+2] = 196; map[get_up_left_y()-1][get_up_left_x()+3] = 196; map[get_up_left_y()-1][get_up_left_x()+4] = 196; map[get_up_left_y()-1][get_up_left_x()+5] = 196; map[get_up_left_y()-1][get_up_left_x()+6] = 196; map[get_up_left_y()-1][get_up_left_x()+7] = 196; map[get_up_left_y()-1][get_up_left_x()+8] = 196; map[get_up_left_y()-1][get_up_left_x()+9] = 196; map[get_up_left_y()-1][get_up_left_x()+10] = 196; map[get_up_left_y()-1][get_up_left_x()+11] = 196; map[get_up_left_y()-1][get_up_left_x()+12] = 196; map[get_up_left_y()-1][get_up_left_x()+13] = 180;
    map[get_up_left_y()][get_up_left_x()] = 195; map[get_up_left_y()][get_up_left_x()+1] = 196; map[get_up_left_y()][get_up_left_x()+2] = 196; map[get_up_left_y()][get_up_left_x()+3] = 196; map[get_up_left_y()][get_up_left_x()+4] = 196; map[get_up_left_y()][get_up_left_x()+5] = 196; map[get_up_left_y()][get_up_left_x()+6] = 196; map[get_up_left_y()][get_up_left_x()+7] = 196; map[get_up_left_y()][get_up_left_x()+8] = 196; map[get_up_left_y()][get_up_left_x()+9] = 196; map[get_up_left_y()][get_up_left_x()+10] = 196; map[get_up_left_y()][get_up_left_x()+11] = 196; map[get_up_left_y()][get_up_left_x()+12] = 196; map[get_up_left_y()][get_up_left_x()+13] = 180;
    map[get_up_left_y()+1][get_up_left_x()] = 195; map[get_up_left_y()+1][get_up_left_x()+1] = 196; map[get_up_left_y()+1][get_up_left_x()+2] = 186; map[get_up_left_y()+1][get_up_left_x()+3] = 186; map[get_up_left_y()+1][get_up_left_x()+4] = 186; map[get_up_left_y()+1][get_up_left_x()+5] = 186; map[get_up_left_y()+1][get_up_left_x()+6] = 196; map[get_up_left_y()+1][get_up_left_x()+7] = 196; map[get_up_left_y()+1][get_up_left_x()+8] = 196; map[get_up_left_y()+1][get_up_left_x()+9] = 196; map[get_up_left_y()+1][get_up_left_x()+10] = 196; map[get_up_left_y()+1][get_up_left_x()+11] = 196; map[get_up_left_y()+1][get_up_left_x()+12] = 196; map[get_up_left_y()+1][get_up_left_x()+13] = 180;
}

void SHELF_2::delete_(char** &map){
    map[get_up_left_y()-3][get_up_left_x()] = 32; map[get_up_left_y()-3][get_up_left_x()+1] = 32; map[get_up_left_y()-3][get_up_left_x()+2] = 32; map[get_up_left_y()-3][get_up_left_x()+3] = 32; map[get_up_left_y()-3][get_up_left_x()+4] = 32; map[get_up_left_y()-3][get_up_left_x()+5] = 32; map[get_up_left_y()-3][get_up_left_x()+6] = 32; map[get_up_left_y()-3][get_up_left_x()+7] = 32; map[get_up_left_y()-3][get_up_left_x()+8] = 32; map[get_up_left_y()-3][get_up_left_x()+9] = 32; map[get_up_left_y()-3][get_up_left_x()+10] = 32; map[get_up_left_y()-3][get_up_left_x()+11] = 32; map[get_up_left_y()-3][get_up_left_x()+12] = 32; map[get_up_left_y()-3][get_up_left_x()+13] = 32;
    map[get_up_left_y()-2][get_up_left_x()] = 32; map[get_up_left_y()-2][get_up_left_x()+1] = 32; map[get_up_left_y()-2][get_up_left_x()+2] = 32; map[get_up_left_y()-2][get_up_left_x()+3] = 32; map[get_up_left_y()-2][get_up_left_x()+4] = 32; map[get_up_left_y()-2][get_up_left_x()+5] = 32; map[get_up_left_y()-2][get_up_left_x()+6] = 32; map[get_up_left_y()-2][get_up_left_x()+7] = 32; map[get_up_left_y()-2][get_up_left_x()+8] = 32; map[get_up_left_y()-2][get_up_left_x()+9] = 32; map[get_up_left_y()-2][get_up_left_x()+10] = 32; map[get_up_left_y()-2][get_up_left_x()+11] = 32; map[get_up_left_y()-2][get_up_left_x()+12] = 32; map[get_up_left_y()-2][get_up_left_x()+13] = 32;
    map[get_up_left_y()-1][get_up_left_x()] = 32; map[get_up_left_y()-1][get_up_left_x()+1] = 32; map[get_up_left_y()-1][get_up_left_x()+2] = 32; map[get_up_left_y()-1][get_up_left_x()+3] = 32; map[get_up_left_y()-1][get_up_left_x()+4] = 32; map[get_up_left_y()-1][get_up_left_x()+5] = 32; map[get_up_left_y()-1][get_up_left_x()+6] = 32; map[get_up_left_y()-1][get_up_left_x()+7] = 32; map[get_up_left_y()-1][get_up_left_x()+8] = 32; map[get_up_left_y()-1][get_up_left_x()+9] = 32; map[get_up_left_y()-1][get_up_left_x()+10] = 32; map[get_up_left_y()-1][get_up_left_x()+11] = 32; map[get_up_left_y()-1][get_up_left_x()+12] = 32; map[get_up_left_y()-1][get_up_left_x()+13] = 32;
    map[get_up_left_y()][get_up_left_x()] = 32; map[get_up_left_y()][get_up_left_x()+1] = 32; map[get_up_left_y()][get_up_left_x()+2] = 32; map[get_up_left_y()][get_up_left_x()+3] = 32; map[get_up_left_y()][get_up_left_x()+4] = 32; map[get_up_left_y()][get_up_left_x()+5] = 32; map[get_up_left_y()][get_up_left_x()+6] = 32; map[get_up_left_y()][get_up_left_x()+7] = 32; map[get_up_left_y()][get_up_left_x()+8] = 32; map[get_up_left_y()][get_up_left_x()+9] = 32; map[get_up_left_y()][get_up_left_x()+10] = 32; map[get_up_left_y()][get_up_left_x()+11] = 32; map[get_up_left_y()][get_up_left_x()+12] = 32; map[get_up_left_y()][get_up_left_x()+13] = 32;
    map[get_up_left_y()+1][get_up_left_x()] = 32; map[get_up_left_y()+1][get_up_left_x()+1] = 32; map[get_up_left_y()+1][get_up_left_x()+2] = 32; map[get_up_left_y()+1][get_up_left_x()+3] = 32; map[get_up_left_y()+1][get_up_left_x()+4] = 32; map[get_up_left_y()+1][get_up_left_x()+5] = 32; map[get_up_left_y()+1][get_up_left_x()+6] = 32; map[get_up_left_y()+1][get_up_left_x()+7] = 32; map[get_up_left_y()+1][get_up_left_x()+8] = 32; map[get_up_left_y()+1][get_up_left_x()+9] = 32; map[get_up_left_y()+1][get_up_left_x()+10] = 32; map[get_up_left_y()+1][get_up_left_x()+11] = 32; map[get_up_left_y()+1][get_up_left_x()+12] = 32; map[get_up_left_y()+1][get_up_left_x()+13] = 32;
}

void SHELF_2::move(char** &m, int const &dir, int const &higth, int const &width){}

void SHELF_2::get_interact_empty(char** &map){
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\tUn estante de madera con libros sobre leyes";
}

SHELF_3::SHELF_3(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Estante", left_up_y-3){}

void SHELF_3::print(char** &map){
    map[get_up_left_y()-3][get_up_left_x()] = 218; map[get_up_left_y()-3][get_up_left_x()+1] = 196; map[get_up_left_y()-3][get_up_left_x()+2] = 196; map[get_up_left_y()-3][get_up_left_x()+3] = 196; map[get_up_left_y()-3][get_up_left_x()+4] = 196; map[get_up_left_y()-3][get_up_left_x()+5] = 196; map[get_up_left_y()-3][get_up_left_x()+6] = 196; map[get_up_left_y()-3][get_up_left_x()+7] = 196; map[get_up_left_y()-3][get_up_left_x()+8] = 196; map[get_up_left_y()-3][get_up_left_x()+9] = 196; map[get_up_left_y()-3][get_up_left_x()+10] = 196; map[get_up_left_y()-3][get_up_left_x()+11] = 196; map[get_up_left_y()-3][get_up_left_x()+12] = 196; map[get_up_left_y()-3][get_up_left_x()+13] = 191;
    map[get_up_left_y()-2][get_up_left_x()] = 195; map[get_up_left_y()-2][get_up_left_x()+1] = 186; map[get_up_left_y()-2][get_up_left_x()+2] = 186; map[get_up_left_y()-2][get_up_left_x()+3] = 186; map[get_up_left_y()-2][get_up_left_x()+4] = 196; map[get_up_left_y()-2][get_up_left_x()+5] = 196; map[get_up_left_y()-2][get_up_left_x()+6] = 186; map[get_up_left_y()-2][get_up_left_x()+7] = 186; map[get_up_left_y()-2][get_up_left_x()+8] = 186; map[get_up_left_y()-2][get_up_left_x()+9] = 196; map[get_up_left_y()-2][get_up_left_x()+10] = 196; map[get_up_left_y()-2][get_up_left_x()+11] = 196; map[get_up_left_y()-2][get_up_left_x()+12] = 196; map[get_up_left_y()-2][get_up_left_x()+13] = 180;
    map[get_up_left_y()-1][get_up_left_x()] = 195; map[get_up_left_y()-1][get_up_left_x()+1] = 196; map[get_up_left_y()-1][get_up_left_x()+2] = 196; map[get_up_left_y()-1][get_up_left_x()+3] = 196; map[get_up_left_y()-1][get_up_left_x()+4] = 196; map[get_up_left_y()-1][get_up_left_x()+5] = 196; map[get_up_left_y()-1][get_up_left_x()+6] = 196; map[get_up_left_y()-1][get_up_left_x()+7] = 196; map[get_up_left_y()-1][get_up_left_x()+8] = 196; map[get_up_left_y()-1][get_up_left_x()+9] = 196; map[get_up_left_y()-1][get_up_left_x()+10] = 196; map[get_up_left_y()-1][get_up_left_x()+11] = 196; map[get_up_left_y()-1][get_up_left_x()+12] = 196; map[get_up_left_y()-1][get_up_left_x()+13] = 180;
    map[get_up_left_y()][get_up_left_x()] = 195; map[get_up_left_y()][get_up_left_x()+1] = 196; map[get_up_left_y()][get_up_left_x()+2] = 186; map[get_up_left_y()][get_up_left_x()+3] = 196; map[get_up_left_y()][get_up_left_x()+4] = 186; map[get_up_left_y()][get_up_left_x()+5] = 186; map[get_up_left_y()][get_up_left_x()+6] = 196; map[get_up_left_y()][get_up_left_x()+7] = 196; map[get_up_left_y()][get_up_left_x()+8] = 196; map[get_up_left_y()][get_up_left_x()+9] = 196; map[get_up_left_y()][get_up_left_x()+10] = 196; map[get_up_left_y()][get_up_left_x()+11] = 196; map[get_up_left_y()][get_up_left_x()+12] = 196; map[get_up_left_y()][get_up_left_x()+13] = 180;
    map[get_up_left_y()+1][get_up_left_x()] = 195; map[get_up_left_y()+1][get_up_left_x()+1] = 196; map[get_up_left_y()+1][get_up_left_x()+2] = 196; map[get_up_left_y()+1][get_up_left_x()+3] = 196; map[get_up_left_y()+1][get_up_left_x()+4] = 196; map[get_up_left_y()+1][get_up_left_x()+5] = 196; map[get_up_left_y()+1][get_up_left_x()+6] = 196; map[get_up_left_y()+1][get_up_left_x()+7] = 196; map[get_up_left_y()+1][get_up_left_x()+8] = 196; map[get_up_left_y()+1][get_up_left_x()+9] = 196; map[get_up_left_y()+1][get_up_left_x()+10] = 186; map[get_up_left_y()+1][get_up_left_x()+11] = 186; map[get_up_left_y()+1][get_up_left_x()+12] = 196; map[get_up_left_y()+1][get_up_left_x()+13] = 180;
}

void SHELF_3::delete_(char** &map){
    map[get_up_left_y()-3][get_up_left_x()] = 32; map[get_up_left_y()-3][get_up_left_x()+1] = 32; map[get_up_left_y()-3][get_up_left_x()+2] = 32; map[get_up_left_y()-3][get_up_left_x()+3] = 32; map[get_up_left_y()-3][get_up_left_x()+4] = 32; map[get_up_left_y()-3][get_up_left_x()+5] = 32; map[get_up_left_y()-3][get_up_left_x()+6] = 32; map[get_up_left_y()-3][get_up_left_x()+7] = 32; map[get_up_left_y()-3][get_up_left_x()+8] = 32; map[get_up_left_y()-3][get_up_left_x()+9] = 32; map[get_up_left_y()-3][get_up_left_x()+10] = 32; map[get_up_left_y()-3][get_up_left_x()+11] = 32; map[get_up_left_y()-3][get_up_left_x()+12] = 32; map[get_up_left_y()-3][get_up_left_x()+13] = 32;
    map[get_up_left_y()-2][get_up_left_x()] = 32; map[get_up_left_y()-2][get_up_left_x()+1] = 32; map[get_up_left_y()-2][get_up_left_x()+2] = 32; map[get_up_left_y()-2][get_up_left_x()+3] = 32; map[get_up_left_y()-2][get_up_left_x()+4] = 32; map[get_up_left_y()-2][get_up_left_x()+5] = 32; map[get_up_left_y()-2][get_up_left_x()+6] = 32; map[get_up_left_y()-2][get_up_left_x()+7] = 32; map[get_up_left_y()-2][get_up_left_x()+8] = 32; map[get_up_left_y()-2][get_up_left_x()+9] = 32; map[get_up_left_y()-2][get_up_left_x()+10] = 32; map[get_up_left_y()-2][get_up_left_x()+11] = 32; map[get_up_left_y()-2][get_up_left_x()+12] = 32; map[get_up_left_y()-2][get_up_left_x()+13] = 32;
    map[get_up_left_y()-1][get_up_left_x()] = 32; map[get_up_left_y()-1][get_up_left_x()+1] = 32; map[get_up_left_y()-1][get_up_left_x()+2] = 32; map[get_up_left_y()-1][get_up_left_x()+3] = 32; map[get_up_left_y()-1][get_up_left_x()+4] = 32; map[get_up_left_y()-1][get_up_left_x()+5] = 32; map[get_up_left_y()-1][get_up_left_x()+6] = 32; map[get_up_left_y()-1][get_up_left_x()+7] = 32; map[get_up_left_y()-1][get_up_left_x()+8] = 32; map[get_up_left_y()-1][get_up_left_x()+9] = 32; map[get_up_left_y()-1][get_up_left_x()+10] = 32; map[get_up_left_y()-1][get_up_left_x()+11] = 32; map[get_up_left_y()-1][get_up_left_x()+12] = 32; map[get_up_left_y()-1][get_up_left_x()+13] = 32;
    map[get_up_left_y()][get_up_left_x()] = 32; map[get_up_left_y()][get_up_left_x()+1] = 32; map[get_up_left_y()][get_up_left_x()+2] = 32; map[get_up_left_y()][get_up_left_x()+3] = 32; map[get_up_left_y()][get_up_left_x()+4] = 32; map[get_up_left_y()][get_up_left_x()+5] = 32; map[get_up_left_y()][get_up_left_x()+6] = 32; map[get_up_left_y()][get_up_left_x()+7] = 32; map[get_up_left_y()][get_up_left_x()+8] = 32; map[get_up_left_y()][get_up_left_x()+9] = 32; map[get_up_left_y()][get_up_left_x()+10] = 32; map[get_up_left_y()][get_up_left_x()+11] = 32; map[get_up_left_y()][get_up_left_x()+12] = 32; map[get_up_left_y()][get_up_left_x()+13] = 32;
    map[get_up_left_y()+1][get_up_left_x()] = 32; map[get_up_left_y()+1][get_up_left_x()+1] = 32; map[get_up_left_y()+1][get_up_left_x()+2] = 32; map[get_up_left_y()+1][get_up_left_x()+3] = 32; map[get_up_left_y()+1][get_up_left_x()+4] = 32; map[get_up_left_y()+1][get_up_left_x()+5] = 32; map[get_up_left_y()+1][get_up_left_x()+6] = 32; map[get_up_left_y()+1][get_up_left_x()+7] = 32; map[get_up_left_y()+1][get_up_left_x()+8] = 32; map[get_up_left_y()+1][get_up_left_x()+9] = 32; map[get_up_left_y()+1][get_up_left_x()+10] = 32; map[get_up_left_y()+1][get_up_left_x()+11] = 32; map[get_up_left_y()+1][get_up_left_x()+12] = 32; map[get_up_left_y()+1][get_up_left_x()+13] = 32;
}

void SHELF_3::move(char** &m, int const &dir, int const &higth, int const &width){}

void SHELF_3::get_interact_empty(char** &map){
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\tUn estante de madera con libros sobre leyes";
}

PICTURE_1::PICTURE_1(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Recuadro", left_up_y-3){}

void PICTURE_1::print(char** &map){
   map[get_up_left_y()-1][get_up_left_x()] = 218; map[get_up_left_y()-1][get_up_left_x()+1] = 196; map[get_up_left_y()-1][get_up_left_x()+2] = 196; map[get_up_left_y()-1][get_up_left_x()+3] = 196; map[get_up_left_y()-1][get_up_left_x()+4] = 191;
   map[get_up_left_y()][get_up_left_x()] = 124; map[get_up_left_y()][get_up_left_x()+1] = 95; map[get_up_left_y()][get_up_left_x()+2] = 95; map[get_up_left_y()][get_up_left_x()+3] = 95; map[get_up_left_y()][get_up_left_x()+4] = 124;
}

void PICTURE_1::delete_(char** &map){
    map[get_up_left_y()-1][get_up_left_x()] = 32; map[get_up_left_y()-1][get_up_left_x()+1] = 32; map[get_up_left_y()-1][get_up_left_x()+2] = 32; map[get_up_left_y()-1][get_up_left_x()+3] = 32; map[get_up_left_y()-1][get_up_left_x()+4] = 32;
   map[get_up_left_y()][get_up_left_x()] = 32; map[get_up_left_y()][get_up_left_x()+1] =32; map[get_up_left_y()][get_up_left_x()+2] =32; map[get_up_left_y()][get_up_left_x()+3] =32; map[get_up_left_y()][get_up_left_x()+4] = 32;
}

void PICTURE_1::move(char** &m, int const &dir, int const &higth, int const &width){}

void PICTURE_1::get_interact_empty(char** &map){
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\tUn retrado con personas que no conozco";
}

PICTURE_2::PICTURE_2(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Recuadro", left_up_y-3){}

void PICTURE_2::print(char** &map){
   map[get_up_left_y()-1][get_up_left_x()] = 218; map[get_up_left_y()-1][get_up_left_x()+1] = 196; map[get_up_left_y()-1][get_up_left_x()+2] = 196; map[get_up_left_y()-1][get_up_left_x()+3] = 196; map[get_up_left_y()-1][get_up_left_x()+4] = 196; map[get_up_left_y()-1][get_up_left_x()+5] = 196; map[get_up_left_y()-1][get_up_left_x()+6] = 196; map[get_up_left_y()-1][get_up_left_x()+7] = 196; map[get_up_left_y()-1][get_up_left_x()+8] = 196; map[get_up_left_y()-1][get_up_left_x()+9] = 191;
   map[get_up_left_y()][get_up_left_x()] = 124; map[get_up_left_y()][get_up_left_x()+1] = 95; map[get_up_left_y()][get_up_left_x()+2] = 95; map[get_up_left_y()][get_up_left_x()+3] = 95; map[get_up_left_y()][get_up_left_x()+4] = 95; map[get_up_left_y()][get_up_left_x()+5] = 95; map[get_up_left_y()][get_up_left_x()+6] = 95; map[get_up_left_y()][get_up_left_x()+7] = 95; map[get_up_left_y()][get_up_left_x()+8] = 95; map[get_up_left_y()][get_up_left_x()+9] = 124;
}

void PICTURE_2::delete_(char** &map){
    map[get_up_left_y()-1][get_up_left_x()] = 32; map[get_up_left_y()-1][get_up_left_x()+1] = 32; map[get_up_left_y()-1][get_up_left_x()+2] = 32; map[get_up_left_y()-1][get_up_left_x()+3] = 32; map[get_up_left_y()-1][get_up_left_x()+4] = 32;
   map[get_up_left_y()][get_up_left_x()] = 32; map[get_up_left_y()][get_up_left_x()+1] =32; map[get_up_left_y()][get_up_left_x()+2] =32; map[get_up_left_y()][get_up_left_x()+3] =32; map[get_up_left_y()][get_up_left_x()+4] = 32;
}

void PICTURE_2::move(char** &m, int const &dir, int const &higth, int const &width){}

void PICTURE_2::get_interact_empty(char** &map){
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\tUna pintura de algo parecido a una prision";
}

PICTURE_ESPECIAL::PICTURE_ESPECIAL(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Recuadro ", left_up_y-3){}

void PICTURE_ESPECIAL::print(char** &map){
   map[get_up_left_y()-1][get_up_left_x()] = 218; map[get_up_left_y()-1][get_up_left_x()+1] = 196; map[get_up_left_y()-1][get_up_left_x()+2] = 196; map[get_up_left_y()-1][get_up_left_x()+3] = 196; map[get_up_left_y()-1][get_up_left_x()+4] = 191;
   map[get_up_left_y()][get_up_left_x()] = 124; map[get_up_left_y()][get_up_left_x()+1] = 95; map[get_up_left_y()][get_up_left_x()+2] = 95; map[get_up_left_y()][get_up_left_x()+3] = 95; map[get_up_left_y()][get_up_left_x()+4] = 124;
}

void PICTURE_ESPECIAL::delete_(char** &map){
    map[get_up_left_y()-1][get_up_left_x()] = 32; map[get_up_left_y()-1][get_up_left_x()+1] = 32; map[get_up_left_y()-1][get_up_left_x()+2] = 32; map[get_up_left_y()-1][get_up_left_x()+3] = 32; map[get_up_left_y()-1][get_up_left_x()+4] = 32;
   map[get_up_left_y()][get_up_left_x()] = 32; map[get_up_left_y()][get_up_left_x()+1] =32; map[get_up_left_y()][get_up_left_x()+2] =32; map[get_up_left_y()][get_up_left_x()+3] =32; map[get_up_left_y()][get_up_left_x()+4] = 32;
}

void PICTURE_ESPECIAL::move(char** &m, int const &dir, int const &higth, int const &width){}

void PICTURE_ESPECIAL::get_interact_empty(char** &map){
    std::list<OBJECT*>* o = get_objects();
    char key;
    if(!picture_flag){
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tUn cuadro de un lugar que parece un tribunal";
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tParece haber algo que sobresale en el marco";
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tINVESTIGAR: E         CERRAR: ESC";
        while(true){
            if(kbhit()){
                key = getch();
                if(key == ACTION || key == ACTION2){
                    if(o->empty()){
                        o->push_back(new LETTER_PRUEBA(0,0));
                        picture_flag = true;
                        return;
                    }
                }
                else if(key == ESC) return;
            }
        }
    }
    else{
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tUn cuadro de un tribunal";
    }
}

CUPBOARD_2::CUPBOARD_2(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Gabinete", left_up_y-1){}

void CUPBOARD_2::print(char** &map){
    map[get_up_left_y()-1][get_up_left_x()] = 218; map[get_up_left_y()-1][get_up_left_x()+1] = 196; map[get_up_left_y()-1][get_up_left_x()+2] = 196; map[get_up_left_y()-1][get_up_left_x()+3] = 196; map[get_up_left_y()-1][get_up_left_x()+4] = 196; map[get_up_left_y()-1][get_up_left_x()+5] = 196; map[get_up_left_y()-1][get_up_left_x()+6] = 196; map[get_up_left_y()-1][get_up_left_x()+7] = 196; map[get_up_left_y()-1][get_up_left_x()+8] = 196; map[get_up_left_y()-1][get_up_left_x()+9] = 191;
    map[get_up_left_y()][get_up_left_x()] = 124; map[get_up_left_y()][get_up_left_x()+1] = 32; map[get_up_left_y()][get_up_left_x()+2] = 32; map[get_up_left_y()][get_up_left_x()+3] = 111; map[get_up_left_y()][get_up_left_x()+4] = 32; map[get_up_left_y()][get_up_left_x()+5] = 32; map[get_up_left_y()][get_up_left_x()+6] = 111; map[get_up_left_y()][get_up_left_x()+7] = 32; map[get_up_left_y()][get_up_left_x()+8] = 32; map[get_up_left_y()][get_up_left_x()+9] = 124;
    map[get_up_left_y()+1][get_up_left_x()] = 192; map[get_up_left_y()+1][get_up_left_x()+1] = 196; map[get_up_left_y()+1][get_up_left_x()+2] = 196; map[get_up_left_y()+1][get_up_left_x()+3] = 196; map[get_up_left_y()+1][get_up_left_x()+4] = 196; map[get_up_left_y()+1][get_up_left_x()+5] = 196; map[get_up_left_y()+1][get_up_left_x()+6] = 196; map[get_up_left_y()+1][get_up_left_x()+7] = 196; map[get_up_left_y()+1][get_up_left_x()+8] = 196; map[get_up_left_y()+1][get_up_left_x()+9] = 217;
}

void CUPBOARD_2::delete_(char** &map){
    map[get_up_left_y()-1][get_up_left_x()] = 32; map[get_up_left_y()-1][get_up_left_x()+1] = 32; map[get_up_left_y()-1][get_up_left_x()+2] = 32; map[get_up_left_y()-1][get_up_left_x()+3] = 32; map[get_up_left_y()-1][get_up_left_x()+4] = 32; map[get_up_left_y()-1][get_up_left_x()+5] = 32; map[get_up_left_y()-1][get_up_left_x()+6] = 32; map[get_up_left_y()-1][get_up_left_x()+7] = 32; map[get_up_left_y()-1][get_up_left_x()+8] = 32; map[get_up_left_y()-1][get_up_left_x()+9] = 32;
    map[get_up_left_y()][get_up_left_x()] = 32; map[get_up_left_y()][get_up_left_x()+1] =32; map[get_up_left_y()][get_up_left_x()+2] =32; map[get_up_left_y()][get_up_left_x()+3] = 32; map[get_up_left_y()][get_up_left_x()+4] =32; map[get_up_left_y()][get_up_left_x()+5] =32; map[get_up_left_y()][get_up_left_x()+6] = 32; map[get_up_left_y()][get_up_left_x()+7] =32; map[get_up_left_y()][get_up_left_x()+8] =32; map[get_up_left_y()][get_up_left_x()+9] = 32;
    map[get_up_left_y()+1][get_up_left_x()] = 32; map[get_up_left_y()+1][get_up_left_x()+1] =32; map[get_up_left_y()+1][get_up_left_x()+2] =32; map[get_up_left_y()+1][get_up_left_x()+3] =32; map[get_up_left_y()+1][get_up_left_x()+4] =32; map[get_up_left_y()+1][get_up_left_x()+5] =32; map[get_up_left_y()+1][get_up_left_x()+6] =32; map[get_up_left_y()+1][get_up_left_x()+7] =32; map[get_up_left_y()+1][get_up_left_x()+8] =32; map[get_up_left_y()+1][get_up_left_x()+9] = 32;
}

void CUPBOARD_2::move(char** &m, int const &dir, int const &higth, int const &width){}

void CUPBOARD_2::get_interact_empty(char** &map){
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\tParece un Gabinete Ordinario de Madera";
}

CUPBOARD_3::CUPBOARD_3(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Armario de una puerta", left_up_y-2){}

void CUPBOARD_3::print(char** &map){
    map[get_up_left_y()-2][get_up_left_x()] = 218; map[get_up_left_y()-2][get_up_left_x()+1] = 196; map[get_up_left_y()-2][get_up_left_x()+2] = 196; map[get_up_left_y()-2][get_up_left_x()+3] = 191;
    map[get_up_left_y()-1][get_up_left_x()] = 124; map[get_up_left_y()-1][get_up_left_x()+1] = 46; map[get_up_left_y()-1][get_up_left_x()+2] = 32; map[get_up_left_y()-1][get_up_left_x()+3] = 124;
    map[get_up_left_y()][get_up_left_x()] = 124; map[get_up_left_y()][get_up_left_x()+1] = 32; map[get_up_left_y()][get_up_left_x()+2] = 32; map[get_up_left_y()][get_up_left_x()+3] = 124;
    map[get_up_left_y()+1][get_up_left_x()] = 192; map[get_up_left_y()+1][get_up_left_x()+1] = 196; map[get_up_left_y()+1][get_up_left_x()+2] = 196; map[get_up_left_y()+1][get_up_left_x()+3] = 217;
}

void CUPBOARD_3::delete_(char** &map){
    map[get_up_left_y()-2][get_up_left_x()] = 32; map[get_up_left_y()-2][get_up_left_x()+1] = 32; map[get_up_left_y()-2][get_up_left_x()+2] = 32; map[get_up_left_y()-2][get_up_left_x()+3] = 32;
    map[get_up_left_y()-1][get_up_left_x()] = 32; map[get_up_left_y()-1][get_up_left_x()+1] =32; map[get_up_left_y()-1][get_up_left_x()+2] =32; map[get_up_left_y()-1][get_up_left_x()+3] = 32;
    map[get_up_left_y()][get_up_left_x()] = 32; map[get_up_left_y()][get_up_left_x()+1] =32; map[get_up_left_y()][get_up_left_x()+2] =32; map[get_up_left_y()][get_up_left_x()+3] = 32;
    map[get_up_left_y()+1][get_up_left_x()] = 32; map[get_up_left_y()+1][get_up_left_x()+1] = 32; map[get_up_left_y()+1][get_up_left_x()+2] = 32; map[get_up_left_y()+1][get_up_left_x()+3] = 32;
}

void CUPBOARD_3::move(char** &m, int const &dir, int const &higth, int const &width){}

void CUPBOARD_3::get_interact_empty(char** &map){
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\tParece un Armario de una puerta de Madera sin nada especial";
}

CUPBOARD_SIDE::CUPBOARD_SIDE(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Armario", left_up_y-3){}

void CUPBOARD_SIDE::print(char** &map){
    map[get_up_left_y()-3][get_up_left_x()] = 47; map[get_up_left_y()-3][get_up_left_x()+1] = 238; map[get_up_left_y()-3][get_up_left_x()+2] = 238; map[get_up_left_y()-3][get_up_left_x()+3] = 92;
    map[get_up_left_y()-2][get_up_left_x()] = 124; map[get_up_left_y()-2][get_up_left_x()+1] = 238; map[get_up_left_y()-2][get_up_left_x()+2] = 238; map[get_up_left_y()-2][get_up_left_x()+3] = 124;
    map[get_up_left_y()-1][get_up_left_x()] = 124; map[get_up_left_y()-1][get_up_left_x()+1] = 32; map[get_up_left_y()-1][get_up_left_x()+2] = 32; map[get_up_left_y()-1][get_up_left_x()+3] = 124;
    map[get_up_left_y()][get_up_left_x()] = 124; map[get_up_left_y()][get_up_left_x()+1] = 32; map[get_up_left_y()][get_up_left_x()+2] = 32; map[get_up_left_y()][get_up_left_x()+3] = 124;
    map[get_up_left_y()+1][get_up_left_x()] = 192; map[get_up_left_y()+1][get_up_left_x()+1] = 196; map[get_up_left_y()+1][get_up_left_x()+2] = 196; map[get_up_left_y()+1][get_up_left_x()+3] = 217;
}

void CUPBOARD_SIDE::delete_(char** &map){
    map[get_up_left_y()-3][get_up_left_x()] =32; map[get_up_left_y()-3][get_up_left_x()+1] = 32; map[get_up_left_y()-3][get_up_left_x()+2] = 32; map[get_up_left_y()-3][get_up_left_x()+3] =32;
    map[get_up_left_y()-2][get_up_left_x()] = 32; map[get_up_left_y()-2][get_up_left_x()+1] = 32; map[get_up_left_y()-2][get_up_left_x()+2] = 32; map[get_up_left_y()-2][get_up_left_x()+3] = 32;
    map[get_up_left_y()-1][get_up_left_x()] = 32; map[get_up_left_y()-1][get_up_left_x()+1] =32; map[get_up_left_y()-1][get_up_left_x()+2] =32; map[get_up_left_y()-1][get_up_left_x()+3] = 32;
    map[get_up_left_y()][get_up_left_x()] = 32; map[get_up_left_y()][get_up_left_x()+1] =32; map[get_up_left_y()][get_up_left_x()+2] =32; map[get_up_left_y()][get_up_left_x()+3] = 32;
    map[get_up_left_y()+1][get_up_left_x()] = 32; map[get_up_left_y()+1][get_up_left_x()+1] = 32; map[get_up_left_y()+1][get_up_left_x()+2] = 32; map[get_up_left_y()+1][get_up_left_x()+3] = 32;
}

void CUPBOARD_SIDE::move(char** &m, int const &dir, int const &higth, int const &width){}

void CUPBOARD_SIDE::get_interact_empty(char** &map){
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\tParece un Armario Ordinario de Madera";
}

DESK::DESK(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Gabinete", left_up_y-2){}

void DESK::print(char** &map){
    map[get_up_left_y()-2][get_up_left_x()] = 47; map[get_up_left_y()-2][get_up_left_x()+1] = 238; map[get_up_left_y()-2][get_up_left_x()+2] = 238; map[get_up_left_y()-2][get_up_left_x()+3] = 238; map[get_up_left_y()-2][get_up_left_x()+4] = 92;
    map[get_up_left_y()-1][get_up_left_x()] = 124; map[get_up_left_y()-1][get_up_left_x()+1] = 238; map[get_up_left_y()-1][get_up_left_x()+2] = 238; map[get_up_left_y()-1][get_up_left_x()+3] = 238; map[get_up_left_y()-1][get_up_left_x()+4] = 124;
    map[get_up_left_y()][get_up_left_x()] = 124; map[get_up_left_y()][get_up_left_x()+1] = 32; map[get_up_left_y()][get_up_left_x()+2] = 32; map[get_up_left_y()][get_up_left_x()+3] = 32; map[get_up_left_y()][get_up_left_x()+4] = 124;
    map[get_up_left_y()+1][get_up_left_x()] = 192; map[get_up_left_y()+1][get_up_left_x()+1] = 196; map[get_up_left_y()+1][get_up_left_x()+2] = 196; map[get_up_left_y()+1][get_up_left_x()+3] = 196; map[get_up_left_y()+1][get_up_left_x()+4] = 217;
}

void DESK::delete_(char** &map){
    map[get_up_left_y()-2][get_up_left_x()] =32; map[get_up_left_y()-2][get_up_left_x()+1] = 32; map[get_up_left_y()-2][get_up_left_x()+2] = 32; map[get_up_left_y()-2][get_up_left_x()+3] = 32; map[get_up_left_y()-2][get_up_left_x()+4] = 32; map[get_up_left_y()-2][get_up_left_x()+5] = 32; map[get_up_left_y()-2][get_up_left_x()+6] =32;
    map[get_up_left_y()-1][get_up_left_x()] = 32; map[get_up_left_y()-1][get_up_left_x()+1] = 32; map[get_up_left_y()-1][get_up_left_x()+2] = 32; map[get_up_left_y()-1][get_up_left_x()+3] = 32; map[get_up_left_y()-1][get_up_left_x()+4] = 32; map[get_up_left_y()-1][get_up_left_x()+5] = 32; map[get_up_left_y()-1][get_up_left_x()+6] = 32;
    map[get_up_left_y()][get_up_left_x()] = 32; map[get_up_left_y()][get_up_left_x()+1] =32; map[get_up_left_y()][get_up_left_x()+2] =32; map[get_up_left_y()][get_up_left_x()+3] =32; map[get_up_left_y()][get_up_left_x()+4] =32; map[get_up_left_y()][get_up_left_x()+5] =32; map[get_up_left_y()][get_up_left_x()+6] = 32;
    map[get_up_left_y()+1][get_up_left_x()] = 32; map[get_up_left_y()+1][get_up_left_x()+1] = 32; map[get_up_left_y()+1][get_up_left_x()+2] = 32; map[get_up_left_y()+1][get_up_left_x()+3] = 32; map[get_up_left_y()+1][get_up_left_x()+4] = 32; map[get_up_left_y()+1][get_up_left_x()+5] = 32; map[get_up_left_y()+1][get_up_left_x()+6] = 32;
}

void DESK::move(char** &m, int const &dir, int const &higth, int const &width){}

void DESK::get_interact_empty(char** &map){
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\tUn escritorio de madera sin mas.";
}

CUPBOARD_3_SIDE::CUPBOARD_3_SIDE(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Armario", left_up_y-3){}

void CUPBOARD_3_SIDE::print(char** &map){
    map[get_up_left_y()-3][get_up_left_x()] = 47; map[get_up_left_y()-3][get_up_left_x()+1] = 238; map[get_up_left_y()-3][get_up_left_x()+2] = 238; map[get_up_left_y()-3][get_up_left_x()+3] = 92;
    map[get_up_left_y()-2][get_up_left_x()] = 124; map[get_up_left_y()-2][get_up_left_x()+1] = 238; map[get_up_left_y()-2][get_up_left_x()+2] = 238; map[get_up_left_y()-2][get_up_left_x()+3] = 124;
    map[get_up_left_y()-1][get_up_left_x()] = 124; map[get_up_left_y()-1][get_up_left_x()+1] = 32; map[get_up_left_y()-1][get_up_left_x()+2] = 32; map[get_up_left_y()-1][get_up_left_x()+3] = 124;
    map[get_up_left_y()][get_up_left_x()] = 124; map[get_up_left_y()][get_up_left_x()+1] = 32; map[get_up_left_y()][get_up_left_x()+2] = 32; map[get_up_left_y()][get_up_left_x()+3] = 124;
    map[get_up_left_y()+1][get_up_left_x()] = 192; map[get_up_left_y()+1][get_up_left_x()+1] = 196; map[get_up_left_y()+1][get_up_left_x()+2] = 196; map[get_up_left_y()+1][get_up_left_x()+3] = 217;
}

void CUPBOARD_3_SIDE::delete_(char** &map){
    map[get_up_left_y()-3][get_up_left_x()] =32; map[get_up_left_y()-3][get_up_left_x()+1] = 32; map[get_up_left_y()-3][get_up_left_x()+2] = 32; map[get_up_left_y()-3][get_up_left_x()+3] =32;
    map[get_up_left_y()-2][get_up_left_x()] = 32; map[get_up_left_y()-2][get_up_left_x()+1] = 32; map[get_up_left_y()-2][get_up_left_x()+2] = 32; map[get_up_left_y()-2][get_up_left_x()+3] = 32;
    map[get_up_left_y()-1][get_up_left_x()] = 32; map[get_up_left_y()-1][get_up_left_x()+1] =32; map[get_up_left_y()-1][get_up_left_x()+2] =32; map[get_up_left_y()-1][get_up_left_x()+3] = 32;
    map[get_up_left_y()][get_up_left_x()] = 32; map[get_up_left_y()][get_up_left_x()+1] =32; map[get_up_left_y()][get_up_left_x()+2] =32; map[get_up_left_y()][get_up_left_x()+3] = 32;
    map[get_up_left_y()+1][get_up_left_x()] = 32; map[get_up_left_y()+1][get_up_left_x()+1] = 32; map[get_up_left_y()+1][get_up_left_x()+2] = 32; map[get_up_left_y()+1][get_up_left_x()+3] = 32;
}

void CUPBOARD_3_SIDE::move(char** &m, int const &dir, int const &higth, int const &width){}

void CUPBOARD_3_SIDE::get_interact_empty(char** &map){
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\tParece un Armario de una puerta de Madera sin nada especial";
}

BODY_DEAD::BODY_DEAD(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Armario", left_up_y){}

void BODY_DEAD::print(char** &map){
    map[get_up_left_y()][get_up_left_x()] = 32; map[get_up_left_y()][get_up_left_x()+1] = 79; map[get_up_left_y()][get_up_left_x()+2] = 32;
    map[get_up_left_y()][get_up_left_x()] = 47; map[get_up_left_y()][get_up_left_x()+1] = 124; map[get_up_left_y()][get_up_left_x()+2] = 92;
    map[get_up_left_y()][get_up_left_x()] = 32; map[get_up_left_y()][get_up_left_x()+1] = 94; map[get_up_left_y()][get_up_left_x()+2] = 32;
}

void BODY_DEAD::delete_(char** &map){
    map[get_up_left_y()][get_up_left_x()] =32; map[get_up_left_y()][get_up_left_x()+1] =32; map[get_up_left_y()][get_up_left_x()+2] =32;
    map[get_up_left_y()][get_up_left_x()] =32; map[get_up_left_y()][get_up_left_x()+1] =32; map[get_up_left_y()][get_up_left_x()+2] =32;
    map[get_up_left_y()][get_up_left_x()] =32; map[get_up_left_y()][get_up_left_x()+1] =32; map[get_up_left_y()][get_up_left_x()+2] =32;
}

void BODY_DEAD::move(char** &m, int const &dir, int const &higth, int const &width){}

void BODY_DEAD::get_interact_empty(char** &map){
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\tUn cuerpo recostado de la pared";
}

FLOWER::FLOWER(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Armario", left_up_y-2){}

void FLOWER::print(char** &map){
   map[get_up_left_y()-2][get_up_left_x()] = 32; map[get_up_left_y()-2][get_up_left_x()+1] = 64; map[get_up_left_y()-2][get_up_left_x()+2] = 32;
   map[get_up_left_y()-1][get_up_left_x()] = 32; map[get_up_left_y()-1][get_up_left_x()+1] = 124; map[get_up_left_y()-1][get_up_left_x()+2] = 32;
   map[get_up_left_y()][get_up_left_x()] = 47; map[get_up_left_y()][get_up_left_x()+1] = 238; map[get_up_left_y()][get_up_left_x()+2] = 92;
   map[get_up_left_y()+1][get_up_left_x()] = 92; map[get_up_left_y()+1][get_up_left_x()+1] = 95; map[get_up_left_y()+1][get_up_left_x()+2] = 47;
}

void FLOWER::delete_(char** &map){
   map[get_up_left_y()-2][get_up_left_x()] =32; map[get_up_left_y()-2][get_up_left_x()+1] =32; map[get_up_left_y()-2][get_up_left_x()+2] =32;
   map[get_up_left_y()-1][get_up_left_x()] =32; map[get_up_left_y()-1][get_up_left_x()+1] = 32; map[get_up_left_y()-1][get_up_left_x()+2] =32;
   map[get_up_left_y()][get_up_left_x()] =32; map[get_up_left_y()][get_up_left_x()+1] = 32; map[get_up_left_y()][get_up_left_x()+2] =32;
   map[get_up_left_y()+1][get_up_left_x()] =32; map[get_up_left_y()+1][get_up_left_x()+1] =32; map[get_up_left_y()+1][get_up_left_x()+2] =32;
}

void FLOWER::move(char** &m, int const &dir, int const &higth, int const &width){}

void FLOWER::get_interact_empty(char** &map){
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\tUna maceta con una flor que no reconozco";
}

CUPBOARD_1_SIDE_ESPECIAL::CUPBOARD_1_SIDE_ESPECIAL(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Armario", left_up_y-3){
    std::list<OBJECT*>* o = get_objects();
    o->push_back(new NOTE1(0,0));
}

void CUPBOARD_1_SIDE_ESPECIAL::print(char** &map){
    map[get_up_left_y()-3][get_up_left_x()] = 47; map[get_up_left_y()-3][get_up_left_x()+1] = 238; map[get_up_left_y()-3][get_up_left_x()+2] = 238; map[get_up_left_y()-3][get_up_left_x()+3] = 92;
    map[get_up_left_y()-2][get_up_left_x()] = 124; map[get_up_left_y()-2][get_up_left_x()+1] = 238; map[get_up_left_y()-2][get_up_left_x()+2] = 238; map[get_up_left_y()-2][get_up_left_x()+3] = 124;
    map[get_up_left_y()-1][get_up_left_x()] = 124; map[get_up_left_y()-1][get_up_left_x()+1] = 32; map[get_up_left_y()-1][get_up_left_x()+2] = 32; map[get_up_left_y()-1][get_up_left_x()+3] = 124;
    map[get_up_left_y()][get_up_left_x()] = 124; map[get_up_left_y()][get_up_left_x()+1] = 32; map[get_up_left_y()][get_up_left_x()+2] = 32; map[get_up_left_y()][get_up_left_x()+3] = 124;
    map[get_up_left_y()+1][get_up_left_x()] = 192; map[get_up_left_y()+1][get_up_left_x()+1] = 196; map[get_up_left_y()+1][get_up_left_x()+2] = 196; map[get_up_left_y()+1][get_up_left_x()+3] = 217;
}

void CUPBOARD_1_SIDE_ESPECIAL::delete_(char** &map){
    map[get_up_left_y()-3][get_up_left_x()] =32; map[get_up_left_y()-3][get_up_left_x()+1] = 32; map[get_up_left_y()-3][get_up_left_x()+2] = 32; map[get_up_left_y()-3][get_up_left_x()+3] =32;
    map[get_up_left_y()-2][get_up_left_x()] = 32; map[get_up_left_y()-2][get_up_left_x()+1] = 32; map[get_up_left_y()-2][get_up_left_x()+2] = 32; map[get_up_left_y()-2][get_up_left_x()+3] = 32;
    map[get_up_left_y()-1][get_up_left_x()] = 32; map[get_up_left_y()-1][get_up_left_x()+1] =32; map[get_up_left_y()-1][get_up_left_x()+2] =32; map[get_up_left_y()-1][get_up_left_x()+3] = 32;
    map[get_up_left_y()][get_up_left_x()] = 32; map[get_up_left_y()][get_up_left_x()+1] =32; map[get_up_left_y()][get_up_left_x()+2] =32; map[get_up_left_y()][get_up_left_x()+3] = 32;
    map[get_up_left_y()+1][get_up_left_x()] = 32; map[get_up_left_y()+1][get_up_left_x()+1] = 32; map[get_up_left_y()+1][get_up_left_x()+2] = 32; map[get_up_left_y()+1][get_up_left_x()+3] = 32;
}

void CUPBOARD_1_SIDE_ESPECIAL::move(char** &m, int const &dir, int const &higth, int const &width){}

void CUPBOARD_1_SIDE_ESPECIAL::get_interact_empty(char** &map){
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\tParece un Armario Ordinario de Madera";
}

CHAIR::CHAIR(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Silla", left_up_y-1){}

void CHAIR::print(char** &map){
    map[get_up_left_y()-1][get_up_left_x()] = 124; map[get_up_left_y()-1][get_up_left_x()+1] = 32; map[get_up_left_y()-1][get_up_left_x()+2] = 32; map[get_up_left_y()-1][get_up_left_x()+3] = 32;
    map[get_up_left_y()][get_up_left_x()] = 124; map[get_up_left_y()][get_up_left_x()+1] = 238; map[get_up_left_y()][get_up_left_x()+2] = 238; map[get_up_left_y()][get_up_left_x()+3] = 191; 
    map[get_up_left_y()+1][get_up_left_x()] = 47; map[get_up_left_y()+1][get_up_left_x()+1] = 238; map[get_up_left_y()+1][get_up_left_x()+2] = 238; map[get_up_left_y()+1][get_up_left_x()+3] = 92;
}

void CHAIR::delete_(char** &map){
    map[get_up_left_y()-1][get_up_left_x()] = 32; map[get_up_left_y()-1][get_up_left_x()+1] =32; map[get_up_left_y()-1][get_up_left_x()+2] =32; map[get_up_left_y()-1][get_up_left_x()+3] =32;
    map[get_up_left_y()][get_up_left_x()] = 32; map[get_up_left_y()][get_up_left_x()+1] = 32; map[get_up_left_y()][get_up_left_x()+2] = 32; map[get_up_left_y()][get_up_left_x()+3] = 32; 
    map[get_up_left_y()+1][get_up_left_x()] =32; map[get_up_left_y()+1][get_up_left_x()+1] = 32; map[get_up_left_y()+1][get_up_left_x()+2] = 32; map[get_up_left_y()+1][get_up_left_x()+3] =32;
}

void CHAIR::move(char** &m, int const &dir, int const &higth, int const &width){}

void CHAIR::get_interact_empty(char** &map){
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\tUna silla algo desgastada.";
}

