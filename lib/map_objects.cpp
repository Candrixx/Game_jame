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

void MAP_OBJECT::set_moved(bool m){
    this->moved = m;
}

std::list<OBJECT*>* MAP_OBJECT::get_objects(){
    return &objects;
}

CUPBOARD::CUPBOARD(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Armario", left_up_y-2){}

void CUPBOARD::print_front(char** &map){

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

void CUPBOARD::print_side(char** &m){}

void CUPBOARD::delete_(char** &m){}

void CUPBOARD::move(char** &m, int const &dir, int const &higth, int const &width){}

void CUPBOARD::get_interact_empty(){
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\tParece un Armario Ordinario de Madera";
}

CUPBOARD_ESPECIAL::CUPBOARD_ESPECIAL(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Armario", left_up_y-2){
    std::list<OBJECT*>* o = get_objects();
    o->push_back(new LETTER_PRUEBA(0,0));
    o->push_back(new LETTER_PRUEBA(0,0));
    o->push_back(new LETTER_PRUEBA(0,0));
}

void CUPBOARD_ESPECIAL::print_front(char** &map){
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

void CUPBOARD_ESPECIAL::print_side(char** &m){}

void CUPBOARD_ESPECIAL::delete_(char** &m){}

void CUPBOARD_ESPECIAL::move(char** &m, int const &dir, int const &higth, int const &width){}

void CUPBOARD_ESPECIAL::get_interact_empty(){
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\tParece que el Armario esta vacio";
}

TABLE::TABLE(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y,"Cupboard", left_up_y-1){}

void TABLE::print_front(char** &map){
    map[get_up_left_y()-1][get_up_left_x()] = 32; map[get_up_left_y()-1][get_up_left_x()+1] = 32; map[get_up_left_y()-1][get_up_left_x()+2] = 47; map[get_up_left_y()-1][get_up_left_x()+3] = 238; map[get_up_left_y()-1][get_up_left_x()+4] = 238; map[get_up_left_y()-1][get_up_left_x()+5] = 238; map[get_up_left_y()-1][get_up_left_x()+6] = 238; map[get_up_left_y()-1][get_up_left_x()+7] = 238; map[get_up_left_y()-1][get_up_left_x()+8] = 238; map[get_up_left_y()-1][get_up_left_x()+9] = 238; map[get_up_left_y()-1][get_up_left_x()+10] = 238; map[get_up_left_y()-1][get_up_left_x()+11] = 238; map[get_up_left_y()-1][get_up_left_x()+12] = 92; map[get_up_left_y()-1][get_up_left_x()+13] = 32; map[get_up_left_y()-1][get_up_left_x()+14] = 32;
    map[get_up_left_y()][get_up_left_x()] = 32; map[get_up_left_y()][get_up_left_x()+1] = 47; map[get_up_left_y()][get_up_left_x()+2] = 32; map[get_up_left_y()][get_up_left_x()+3] = 32; map[get_up_left_y()][get_up_left_x()+4] = 32; map[get_up_left_y()][get_up_left_x()+5] = 32; map[get_up_left_y()][get_up_left_x()+6] = 32; map[get_up_left_y()][get_up_left_x()+7] = 32; map[get_up_left_y()][get_up_left_x()+8] = 32; map[get_up_left_y()][get_up_left_x()+9] = 32; map[get_up_left_y()][get_up_left_x()+10] = 32; map[get_up_left_y()][get_up_left_x()+11] = 32; map[get_up_left_y()][get_up_left_x()+12] = 32; map[get_up_left_y()][get_up_left_x()+13] = 92; map[get_up_left_y()][get_up_left_x()+14] = 32;
    map[get_up_left_y()+1][get_up_left_x()] = 47; map[get_up_left_y()+1][get_up_left_x()+1] = 95; map[get_up_left_y()+1][get_up_left_x()+2] = 95; map[get_up_left_y()+1][get_up_left_x()+3] = 95; map[get_up_left_y()+1][get_up_left_x()+4] = 95; map[get_up_left_y()+1][get_up_left_x()+5] = 95; map[get_up_left_y()+1][get_up_left_x()+6] = 95; map[get_up_left_y()+1][get_up_left_x()+7] = 95; map[get_up_left_y()+1][get_up_left_x()+8] = 95; map[get_up_left_y()+1][get_up_left_x()+9] = 95; map[get_up_left_y()+1][get_up_left_x()+10] = 95; map[get_up_left_y()+1][get_up_left_x()+11] = 95; map[get_up_left_y()+1][get_up_left_x()+12] = 95; map[get_up_left_y()+1][get_up_left_x()+13] = 95; map[get_up_left_y()+1][get_up_left_x()+14] = 92;
    map[get_up_left_y()+2][get_up_left_x()] = 32; map[get_up_left_y()+2][get_up_left_x()+1] = 124; map[get_up_left_y()+2][get_up_left_x()+2] = 32; map[get_up_left_y()+2][get_up_left_x()+3] = 32; map[get_up_left_y()+2][get_up_left_x()+4] = 32; map[get_up_left_y()+2][get_up_left_x()+5] = 32; map[get_up_left_y()+2][get_up_left_x()+6] = 32; map[get_up_left_y()+2][get_up_left_x()+7] = 32; map[get_up_left_y()+2][get_up_left_x()+8] = 32; map[get_up_left_y()+2][get_up_left_x()+9] = 32; map[get_up_left_y()+2][get_up_left_x()+10] = 32; map[get_up_left_y()+2][get_up_left_x()+11] = 32; map[get_up_left_y()+2][get_up_left_x()+12] = 32; map[get_up_left_y()+2][get_up_left_x()+13] = 124; map[get_up_left_y()+2][get_up_left_x()+14] = 32;
}

void TABLE::print_side(char** &m){}

void TABLE::delete_(char** &m){}

void TABLE::move(char** &m, int const &dir, int const &higth, int const &width){}

void TABLE::get_interact_empty(){
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\tParece una Mesa de madera sin nada especial";
}

BOX::BOX(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y):MAP_OBJECT(left_up_x, left_up_y, bot_right_x, bot_right_y, "CAJA", left_up_y-1){}

void BOX::print_front(char** &m){
    m[get_up_left_y()-1][get_up_left_x()] = 218; m[get_up_left_y()-1][get_up_left_x()+1] = 196; m[get_up_left_y()-1][get_up_left_x()+2] = 196; m[get_up_left_y()-1][get_up_left_x()+3] = 196; m[get_up_left_y()-1][get_up_left_x()+4] = 196; m[get_up_left_y()-1][get_up_left_x()+5] = 191;
    m[get_up_left_y()][get_up_left_x()] = 195; m[get_up_left_y()][get_up_left_x()+1] = 196; m[get_up_left_y()][get_up_left_x()+2] = 196; m[get_up_left_y()][get_up_left_x()+3] = 196; m[get_up_left_y()][get_up_left_x()+4] = 196; m[get_up_left_y()][get_up_left_x()+5] = 180;
    m[get_up_left_y()+1][get_up_left_x()] = 124; m[get_up_left_y()+1][get_up_left_x()+1] = 42; m[get_up_left_y()+1][get_up_left_x()+2] = 46; m[get_up_left_y()+1][get_up_left_x()+3] = 42; m[get_up_left_y()+1][get_up_left_x()+4] = 46; m[get_up_left_y()+1][get_up_left_x()+5] = 124;
    m[get_up_left_y()+2][get_up_left_x()] = 192; m[get_up_left_y()+2][get_up_left_x()+1] = 196; m[get_up_left_y()+2][get_up_left_x()+2] = 196; m[get_up_left_y()+2][get_up_left_x()+3] = 196; m[get_up_left_y()+2][get_up_left_x()+4] = 196; m[get_up_left_y()+2][get_up_left_x()+5] = 217;
}

void BOX::print_side(char** &m){}

void BOX::delete_(char** &m){
    m[get_up_left_y()-1][get_up_left_x()] = 32; m[get_up_left_y()-1][get_up_left_x()+1] = 32; m[get_up_left_y()-1][get_up_left_x()+2] = 32; m[get_up_left_y()-1][get_up_left_x()+3] = 32; m[get_up_left_y()-1][get_up_left_x()+4] = 32; m[get_up_left_y()-1][get_up_left_x()+5] = 32;
    m[get_up_left_y()][get_up_left_x()] = 32; m[get_up_left_y()][get_up_left_x()+1] = 32; m[get_up_left_y()][get_up_left_x()+2] = 32; m[get_up_left_y()][get_up_left_x()+3] = 32; m[get_up_left_y()][get_up_left_x()+4] = 32; m[get_up_left_y()][get_up_left_x()+5] = 32;
    m[get_up_left_y()+1][get_up_left_x()] = 32; m[get_up_left_y()+1][get_up_left_x()+1] = 32; m[get_up_left_y()+1][get_up_left_x()+2] = 32; m[get_up_left_y()+1][get_up_left_x()+3] = 32; m[get_up_left_y()+1][get_up_left_x()+4] = 32; m[get_up_left_y()+1][get_up_left_x()+5] = 32;
    m[get_up_left_y()+2][get_up_left_x()] = 32; m[get_up_left_y()+2][get_up_left_x()+1] = 32; m[get_up_left_y()+2][get_up_left_x()+2] = 32; m[get_up_left_y()+2][get_up_left_x()+3] = 32; m[get_up_left_y()+2][get_up_left_x()+4] = 32; m[get_up_left_y()+2][get_up_left_x()+5] = 32;
}

void BOX::get_interact_empty(){
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\tUna caja con un decorado en el frente, parece ligera";
}

void BOX::move(char** &m, int const &dir, int const &higth, int const &width){
    delete_(m);
    if(get_moved()) return;
    if(dir == 1 && get_up_left_y()-2 > 3){
        set_up_left_y(get_up_left_y()-2);
        set_bot_right_y(get_bot_right_y()-2);
    }
    else if(dir == 2 && get_bot_right_x()+2 < width){
        set_up_left_x(get_up_left_x()+2);
        set_bot_right_x(get_bot_right_x()+2);
    }
    else if(dir == 3 && get_bot_right_y()+2 < higth){
        set_up_left_y(get_up_left_y()+2);
        set_bot_right_y(get_bot_right_y()+2);
    }
    else if(dir == 4 && get_up_left_x()-2 > 0){
        set_up_left_x(get_up_left_x()-2);
        set_bot_right_x(get_bot_right_x()-2);
    }
    print_front(m);
    set_moved(true);
}

