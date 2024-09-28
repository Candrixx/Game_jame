#include<iostream>
#include<string.h>
#include<conio.h>
#include "../include/map.h"
#include "../include/map_objects.h"
#include "../include/objects.h"
#include "../include/re_door.h"

#define ACTION 'e'
#define ACTION2 'E'
#define ESC 27
#define CLEAR_SCREEN system("cls")

void print_panel(char p[][51]){
    std::cout << std::endl << std::endl << std::endl << std::endl;
    for(int i=0; i<11; i++){
        std::cout << "\t\t\t\t";
        for(int j=0; j<51; j++){
            std::cout << p[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\tCERRAR: ESC                 BORRAR: P";
}

ENTRY_EXITS::ENTRY_EXITS(int entry_exit_x, int entry_exit_y, int code, int heigth, int width, bool acces){
    this->entry_exit_x = entry_exit_x;
    this->entry_exit_y = entry_exit_y;
    this->code = code;
    this->acces = acces;
    this->heigth = heigth;
    this->width = width;
}

int ENTRY_EXITS::get_entry_exit_x(){ return entry_exit_x; }
int ENTRY_EXITS::get_entry_exit_y(){ return entry_exit_y; }
int ENTRY_EXITS::get_code(){ return code; }
bool ENTRY_EXITS::get_acces(){ return acces; }
int ENTRY_EXITS::get_heigth(){ return heigth; }
int ENTRY_EXITS::get_width(){ return width; }

void ENTRY_EXITS::set_acces(bool a){
    this->acces = a;
}

MAP::MAP(int width, int heigth, std::string name){
     this->map = new char* [heigth];
     for(int i=0; i<heigth; i++){
        this->map[i] = new char[width];
     }
     this->width = width;
     this->heigth = heigth;
     this->name = name;
}

MAP::~MAP(){
    for(int i=0; i<heigth; i++){
        delete [] map[i];
    }
    delete [] map;
}

std::list<MAP_OBJECT*>* MAP::get_map_objects(){ return &map_objects; }
std::list<OBJECT*>* MAP::get_player_objects(){ return &player_objects; }
std::list<ENTRY_EXITS*>* MAP::get_entries_exits(){ return &entries_exits; }

void MAP::print_elements_map(){
    char** m = get_map_matriz();
    std::list<ENTRY_EXITS*>::iterator itE;
    for(itE = entries_exits.begin(); itE!= entries_exits.end(); itE++){
        (*itE)->print(m);
    }
    std::list<OBJECT*>::iterator itO;
    for(itO = player_objects.begin(); itO!= player_objects.end(); itO++){
        (*itO)->print(m);
    }
    std::list<MAP_OBJECT*>::iterator itMO;
    for(itMO = map_objects.begin(); itMO != map_objects.end(); itMO++){
        (*itMO)->print(m);
    }
}

int MAP::get_width(){ return width; }
int MAP::get_heigth(){ return heigth; }
char MAP::get_map(int _x, int _y){
    return this->map[_y][_x]; 
}

char** MAP::get_map_matriz(){
    return map;
}

void MAP::set_map(int _x, int _y ,char c){
    this->map[_y][_x] = c;
}

ENTRY_EXITS_MAP_PRUEBA::ENTRY_EXITS_MAP_PRUEBA(int entry_exit_x, int entry_exit_y):ENTRY_EXITS(entry_exit_x, entry_exit_y, 12, 2, 2, true){}

void ENTRY_EXITS_MAP_PRUEBA::print(char** &m){
    m[get_entry_exit_y()][get_entry_exit_x()] = 240; m[get_entry_exit_y()][get_entry_exit_x()+1] = 240;
    m[get_entry_exit_y()+1][get_entry_exit_x()] = 240; m[get_entry_exit_y()+1][get_entry_exit_x()+1] = 240;
}

bool ENTRY_EXITS_MAP_PRUEBA::interact_entry(std::list<OBJECT*>* &o){
    char key;
    std::cout << std::endl << std::endl;
    std:: cout << "\t\t\t\tLa puerta parece estar abierta." << std::endl << std::endl;
    std:: cout << "\t\t\t\t" << question << "Quieres entrar al Mapa Prueba?"<< std::endl << std::endl;
    std:: cout << "\t\t\t\tSI: E      NO: ESC";
    while(true){
        if(kbhit()){
            key = getch();
            if(key == ACTION || key == ACTION2) return true;
            else if(key == ESC) return false;
        }
    }
    return false;
}

void ENTRY_EXITS_MAP_PRUEBA::delete_(char** &m){}

MAP_PRUEBA::MAP_PRUEBA(): MAP(100, 30, "Mapa Prueba"){
    fill_map();
    std::list<ENTRY_EXITS*>* e = get_entries_exits();
    std::list<ENTRY_EXITS*>::iterator itE;
    char ** m = get_map_matriz();
    e->push_back(new ENTRY_EXITS_MAP_PRUEBA(1, 19));
    for(itE = e->begin(); itE != e->end(); itE++){
        (*itE)->print(m);
    }
    std::list<MAP_OBJECT*>* mo = get_map_objects();
    std::list<MAP_OBJECT*>::iterator itMO;
    mo->push_back(new CUPBOARD(12, 3, 15, 4));
    mo->push_back(new CUPBOARD(34, 3, 37, 4));
    mo->push_back(new CUPBOARD_ESPECIAL(45, 3, 48, 4));
    mo->push_back(new CUPBOARD(34, 12, 37, 13));
    mo->push_back(new CUPBOARD_2(38, 12, 47, 13));
    mo->push_back(new CUPBOARD_3(48, 12, 57, 13));
    mo->push_back(new TABLE(45, 15, 59, 17));
    mo->push_back(new SHELF_1(80, 15, 93, 16));
    mo->push_back(new SHELF_2(66, 15, 79, 16));
    mo->push_back(new SHELF_3(66, 10, 79, 11));
    mo->push_back(new CUPBOARD_SIDE(66, 19, 69, 20));
    mo->push_back(new DESK(70, 19, 74, 20));
    mo->push_back(new CUPBOARD_3_SIDE(77, 19, 80, 20));
    mo->push_back(new BIG_BOX(72, 3, 76, 4));
    for(itMO = mo->begin(); itMO != mo->end(); itMO++){
        (*itMO)->print(m);
    } 
}

void MAP_PRUEBA::fill_map(){

    for(int j = 0; j<get_width(); j++){
        set_map(j, 0, char(238));
        set_map(j, 1, char(32));
        set_map(j, 2, char(32));
        set_map(j, 3, char(205));
        set_map(j, get_heigth()-1, char(205));
        set_map(j, get_heigth()-2, char(32));
        set_map(j, get_heigth()-3, char(32));
        set_map(j, get_heigth()-4, char(205));
    }

    for(int i = 0; i < get_heigth(); i++){
        set_map(0, i, char(124));
        set_map(get_width()-1, i, char(124));
    }

    for(int i = 4; i<get_heigth()-4; i++){
        for(int j = 1; j<get_width()-1; j++){
            set_map(j, i, char(32));
        }
    }
    
}

ENTRY_EXITS_MAP_PRUEBA2::ENTRY_EXITS_MAP_PRUEBA2(int entry_exit_x, int entry_exit_y):ENTRY_EXITS(entry_exit_x, entry_exit_y, 13, 2, 2, false){}

void ENTRY_EXITS_MAP_PRUEBA2::print(char** &m){
    m[get_entry_exit_y()][get_entry_exit_x()] = 240; m[get_entry_exit_y()][get_entry_exit_x()+1] = 240;
    m[get_entry_exit_y()+1][get_entry_exit_x()] = 240; m[get_entry_exit_y()+1][get_entry_exit_x()+1] = 240;
}

bool ENTRY_EXITS_MAP_PRUEBA2::interact_entry(std::list<OBJECT*>* &o){
    char panel[11][51];
    for(int i=0; i<51 ; i++){
        panel[0][i] = 205;
        panel[10][i] = 205;
    }
    for(int i=0; i<11 ; i++){
        panel[i][0] = 186;
        panel[i][50] = 186;
    }
    for(int i = 1; i<10; i++){
        for(int j=1; j<50; j++){
            panel[i][j] = 32;
        }
    }
    panel[0][0] = 201; panel[0][50] = 187; panel[10][0] = 200; panel[10][50] = 188;
    panel[4][13] = 201; panel[4][14] = 205; panel[4][15] = 187;
    panel[5][13] = 186;                     panel[5][15] = 186;
    panel[6][13] = 200; panel[6][14] = 205; panel[6][15] = 188; 
    panel[4][20] = 201; panel[4][21] = 205; panel[4][22] = 187;
    panel[5][20] = 186;                     panel[5][22] = 186;
    panel[6][20] = 200; panel[6][21] = 205; panel[6][22] = 188; 
    panel[4][27] = 201; panel[4][28] = 205; panel[4][29] = 187;
    panel[5][27] = 186;                     panel[5][29] = 186;
    panel[6][27] = 200; panel[6][28] = 205; panel[6][29] = 188; 
    panel[4][34] = 201; panel[4][35] = 205; panel[4][36] = 187;
    panel[5][34] = 186;                     panel[5][36] = 186;
    panel[6][34] = 200; panel[6][35] = 205; panel[6][36] = 188;
    if(!get_acces()){
        std::string code = "";
        int count = 0;
        char key;
        std::cout << std::endl << std::endl;
        std:: cout << "\t\t\t\tLa puerta parece necesitar un codigo." << std::endl << std::endl;
        std:: cout << "\t\t\t\t" << question << "Quieres intentarlo?"<< std::endl << std::endl;
        std:: cout << "\t\t\t\tSI: E      NO: ESC";
        while(true){
            if(kbhit()){
                key = getch();
                if(key == ACTION || key == ACTION2){
                    CLEAR_SCREEN;
                    print_panel(panel);
                    while(true){
                        if(kbhit()){
                            key = getch();
                            if(49 <= key && key <= 57 && count < 28){
                                panel[5][14+count] = key;
                                count += 7;
                                code = code + key;
                                CLEAR_SCREEN;
                                print_panel(panel);
                                if(code == "1234"){
                                    set_acces(true);
                                    return true;
                                } 
                            }
                            else if((key == 'p' || key == 'P') && count > 0){
                                count -= 7;
                                panel[5][14+count] = 32;
                                code.pop_back();
                                CLEAR_SCREEN;
                                print_panel(panel);
                            }
                            else if(key == ESC) return false;
                        }
                    }
                }
                else if(key == ESC) return false;
            }
        }
    }
    else{
        char key;
        std::cout << std::endl << std::endl;
        std:: cout << "\t\t\t\tLa puerta parece estar abierta." << std::endl << std::endl;
        std:: cout << "\t\t\t\t" << question << "Quieres entrar al Mapa Prueba?"<< std::endl << std::endl;
        std:: cout << "\t\t\t\tSI: E      NO: ESC";
        while(true){
            if(kbhit()){
                key = getch();
                if(key == ACTION || key == ACTION2) return true;
                else if(key == ESC) return false;
            }
        }
        return false;
    }
    return false;
}

void ENTRY_EXITS_MAP_PRUEBA2::delete_(char** &m){}

MAP_PRUEBA2::MAP_PRUEBA2():MAP(60, 25, "Mapa Prueba 2"){
    fill_map();
    std::list<ENTRY_EXITS*>* e = get_entries_exits();
    std::list<ENTRY_EXITS*>::iterator itE;
    e->push_back(new ENTRY_EXITS_MAP_PRUEBA2(get_width()-3, 16));
    char ** m = get_map_matriz();
    for(itE = e->begin(); itE != e->end(); itE++){
        (*itE)->print(m);
    }
    std::list<OBJECT*>* o = get_player_objects();
    std::list<OBJECT*>::iterator itO;
    o->push_back(new LETTER_PRUEBA(58, 12));
    for(itO = o->begin(); itO != o->end(); itO++){
        (*itO)->print(m);
    }
    std::list<MAP_OBJECT*>* mo = get_map_objects();
    std::list<MAP_OBJECT*>::iterator itMO;
    mo->push_back(new BOX(12, 2, 17, 4));
    mo->push_back(new CUPBOARD_PUZLE(18, 3, 24, 4));
    mo->push_back(new LEVER_1(43, 14, 45, 15));
    mo->push_back(new LEVER_2(34, 14, 38, 15));
    mo->push_back(new LEVER_3(10, 14, 12, 15));
    mo->push_back(new LEVER_4(23, 14, 27, 15));
    mo->push_back(new LEVER_5(32, 8, 34, 9));
    mo->push_back(new PICTURE_1(26, 2, 30, 2));
    mo->push_back(new PICTURE_2(31, 2, 40, 2));
    mo->push_back(new PICTURE_ESPECIAL(41, 2, 45, 2));
    for(itMO = mo->begin(); itMO != mo->end(); itMO++){
        (*itMO)->print(m);
    }
}

void MAP_PRUEBA2::fill_map(){

    for(int j = 0; j<get_width(); j++){
        set_map(j, 0, char(238));
        set_map(j, 1, char(32));
        set_map(j, 2, char(32));
        set_map(j, 3, char(205));
        set_map(j, get_heigth()-1, char(205));
        set_map(j, get_heigth()-2, char(32));
        set_map(j, get_heigth()-3, char(32));
        set_map(j, get_heigth()-4, char(205));
    }

    for(int i = 0; i < get_heigth(); i++){
        set_map(0, i, char(124));
        set_map(get_width()-1, i, char(124));
    }

    for(int i = 4; i<get_heigth()-4; i++){
        for(int j = 1; j<get_width()-1; j++){
            set_map(j, i, char(32));
        }
    }
}

EXIT_TUTORIAL_ENTRY_ROOM1::EXIT_TUTORIAL_ENTRY_ROOM1(int entry_exit_x, int entry_exit_y):ENTRY_EXITS(entry_exit_x, entry_exit_y, 1, 2, 2, true){}

void EXIT_TUTORIAL_ENTRY_ROOM1::print(char** &m){
    m[get_entry_exit_y()][get_entry_exit_x()] = 240; m[get_entry_exit_y()][get_entry_exit_x()+1] = 240;
    m[get_entry_exit_y()+1][get_entry_exit_x()] = 240; m[get_entry_exit_y()+1][get_entry_exit_x()+1] = 240;
}

bool EXIT_TUTORIAL_ENTRY_ROOM1::interact_entry(std::list<OBJECT*>* &o){ return false; }

void EXIT_TUTORIAL_ENTRY_ROOM1::delete_(char** &m){}

EXIT_ROOM1_ENTRY_TUTORIAL::EXIT_ROOM1_ENTRY_TUTORIAL(int entry_exit_x, int entry_exit_y):ENTRY_EXITS(entry_exit_x, entry_exit_y, 2, 2, 2, true){}

void EXIT_ROOM1_ENTRY_TUTORIAL::print(char** &m){
    m[get_entry_exit_y()][get_entry_exit_x()] = 240; m[get_entry_exit_y()][get_entry_exit_x()+1] = 240;
    m[get_entry_exit_y()+1][get_entry_exit_x()] = 240; m[get_entry_exit_y()+1][get_entry_exit_x()+1] = 240;
}

bool EXIT_ROOM1_ENTRY_TUTORIAL::interact_entry(std::list<OBJECT*>* &o){
    char key;
    std::cout << std::endl << std::endl;
    std:: cout << "\t\t\t\tLa puerta parece estar abierta." << std::endl << std::endl;
    std:: cout << "\t\t\t\t" << question << "Quieres abrir la puerta?"<< std::endl << std::endl;
    std:: cout << "\t\t\t\tSI: E      NO: ESC";
    while(true){
        if(kbhit()){
            key = getch();
            if(key == ACTION || key == ACTION2) return true;
            else if(key == ESC) return false;
        }
    }
    return false;
 }

void EXIT_ROOM1_ENTRY_TUTORIAL::delete_(char** &m){
    m[get_entry_exit_y()][get_entry_exit_x()] = ' '; m[get_entry_exit_y()][get_entry_exit_x()+1] = ' ';
    m[get_entry_exit_y()+1][get_entry_exit_x()] = ' '; m[get_entry_exit_y()+1][get_entry_exit_x()+1] = ' ';
}

TUTORIAL::TUTORIAL():MAP(50, 16, "?????"){
    fill_map();
    std::list<ENTRY_EXITS*>* e = get_entries_exits();
    std::list<ENTRY_EXITS*>::iterator itE;
    e->push_back(new EXIT_TUTORIAL_ENTRY_ROOM1(47,6));
    char ** m = get_map_matriz();
    for(itE = e->begin(); itE != e->end(); itE++){
        (*itE)->print(m);
    }
    std::list<OBJECT*>* o = get_player_objects();
    std::list<OBJECT*>::iterator itO;
    for(itO = o->begin(); itO != o->end(); itO++){
        (*itO)->print(m);
    }
    std::list<MAP_OBJECT*>* mo = get_map_objects();
    std::list<MAP_OBJECT*>::iterator itMO;
    mo->push_back(new TABLE_TUTORIAL(17, 7, 28, 9));
    mo->push_back(new WINDOW(19, 1, 24, 2));
    mo->push_back(new BOX_TUTORIAL(46, 7, 48, 8));
    for(itMO = mo->begin(); itMO != mo->end(); itMO++){
        (*itMO)->print(m);
    }
}

void TUTORIAL::fill_map(){

    for(int j = 0; j<get_width(); j++){
        set_map(j, 0, char(238));
        set_map(j, 1, char(32));
        set_map(j, 2, char(32));
        set_map(j, 3, char(205));
        set_map(j, get_heigth()-1, char(205));
        set_map(j, get_heigth()-2, char(32));
        set_map(j, get_heigth()-3, char(32));
        set_map(j, get_heigth()-4, char(238));
    }

    for(int i = 0; i < get_heigth(); i++){
        set_map(0, i, char(124));
        set_map(get_width()-1, i, char(124));
    }

    for(int i = 4; i<get_heigth()-4; i++){
        for(int j = 1; j<get_width()-1; j++){
            set_map(j, i, char(32));
        }
    }
    set_map(3, 1, char(254)); set_map(4, 1, char(254)); set_map(2, 2, char(254)); set_map(11, 1, char(254)); set_map(12, 2, char(254));
    set_map(16, 2, char(254)); set_map(17, 2, char(254)); set_map(28, 1, char(254)); set_map(29, 1, char(254)); set_map(30, 2, char(254));
    set_map(31, 2, char(254)); set_map(35, 1, char(220)); set_map(40, 2, char(254)); set_map(45, 1, char(254)); set_map(46, 1, char(254));
    set_map(2, get_heigth()-2, char(254)); set_map(8, get_heigth()-3, char(254)); set_map(9, get_heigth()-3, char(254)); set_map(11, get_heigth()-2, char(254)); set_map(12, get_heigth()-2, char(254));
    set_map(18, get_heigth()-3, char(254)); set_map(19, get_heigth()-3, char(254)); set_map(24, get_heigth()-2, char(254)); set_map(25, get_heigth()-2, char(254)); set_map(27, get_heigth()-3, char(254));
    set_map(32, get_heigth()-3, char(254)); set_map(33, get_heigth()-3, char(254)); set_map(35, get_heigth()-2, char(254)); set_map(36, get_heigth()-2, char(254)); set_map(42, get_heigth()-2, char(254));
    set_map(44, get_heigth()-3, char(254)); set_map(45, get_heigth()-3, char(254)); 
}

EXIT_ROOM1_ENTRY_ROOM2::EXIT_ROOM1_ENTRY_ROOM2(int entry_exit_x, int entry_exit_y):ENTRY_EXITS(entry_exit_x, entry_exit_y, 18, 2, 3, true){}

void EXIT_ROOM1_ENTRY_ROOM2::print(char** &m){
    m[get_entry_exit_y()][get_entry_exit_x()] = 218; m[get_entry_exit_y()][get_entry_exit_x()+1] = 196; m[get_entry_exit_y()][get_entry_exit_x()+2] = 191;
    m[get_entry_exit_y()+1][get_entry_exit_x()] = 124; m[get_entry_exit_y()+1][get_entry_exit_x()+1] = 32; m[get_entry_exit_y()+1][get_entry_exit_x()+2] = 124;
}

bool EXIT_ROOM1_ENTRY_ROOM2::interact_entry(std::list<OBJECT*>* &o){ 
    char key;
    std::cout << std::endl << std::endl;
    std:: cout << "\t\t\t\tLa puerta parece estar abierta." << std::endl << std::endl;
    std:: cout << "\t\t\t\t" << question << "Quieres entrar a la habitacion?"<< std::endl << std::endl;
    std:: cout << "\t\t\t\tSI: E      NO: ESC";
    while(true){
        if(kbhit()){
            key = getch();
            if(key == ACTION || key == ACTION2) return true;
            else if(key == ESC) return false;
        }
    }
    return false;
}

void EXIT_ROOM1_ENTRY_ROOM2::delete_(char** &m){
    m[get_entry_exit_y()][get_entry_exit_x()] = 32; m[get_entry_exit_y()][get_entry_exit_x()+1] = 32; m[get_entry_exit_y()][get_entry_exit_x()+2] = 32;
    m[get_entry_exit_y()+1][get_entry_exit_x()] = 32; m[get_entry_exit_y()+1][get_entry_exit_x()+1] =32; m[get_entry_exit_y()+1][get_entry_exit_x()+2] = 32;
}

EXIT_ROOM1_ENTRY_ROOM5::EXIT_ROOM1_ENTRY_ROOM5(int entry_exit_x, int entry_exit_y):ENTRY_EXITS(entry_exit_x, entry_exit_y, 15, 2, 3, true){}

void EXIT_ROOM1_ENTRY_ROOM5::print(char** &m){
    m[get_entry_exit_y()][get_entry_exit_x()] = 218; m[get_entry_exit_y()][get_entry_exit_x()+1] = 196; m[get_entry_exit_y()][get_entry_exit_x()+2] = 191;
    m[get_entry_exit_y()+1][get_entry_exit_x()] = 124; m[get_entry_exit_y()+1][get_entry_exit_x()+1] = 32; m[get_entry_exit_y()+1][get_entry_exit_x()+2] = 124;
    
}

bool EXIT_ROOM1_ENTRY_ROOM5::interact_entry(std::list<OBJECT*>* &o){ 
    char key;
    std::cout << std::endl << std::endl;
    std:: cout << "\t\t\t\tLa puerta parece estar abierta." << std::endl << std::endl;
    std:: cout << "\t\t\t\t" << question << "Quieres entrar a la habitacion?"<< std::endl << std::endl;
    std:: cout << "\t\t\t\tSI: E      NO: ESC";
    while(true){
        if(kbhit()){
            key = getch();
            if(key == ACTION || key == ACTION2) return true;
            else if(key == ESC) return false;
        }
    }
    return false;
}

void EXIT_ROOM1_ENTRY_ROOM5::delete_(char** &m){
    m[get_entry_exit_y()][get_entry_exit_x()] = 32; m[get_entry_exit_y()][get_entry_exit_x()+1] = 32; m[get_entry_exit_y()][get_entry_exit_x()+2] = 32;
    m[get_entry_exit_y()+1][get_entry_exit_x()] = 32; m[get_entry_exit_y()+1][get_entry_exit_x()+1] =32; m[get_entry_exit_y()+1][get_entry_exit_x()+2] = 32;
}

EXIT_ROOM1_ENTRY_HALLWAY::EXIT_ROOM1_ENTRY_HALLWAY(int entry_exit_x, int entry_exit_y):ENTRY_EXITS(entry_exit_x, entry_exit_y, 34, 2, 2, true){}

void EXIT_ROOM1_ENTRY_HALLWAY::print(char** &m){
    m[get_entry_exit_y()][get_entry_exit_x()] = 240; m[get_entry_exit_y()][get_entry_exit_x()+1] = 240;
    m[get_entry_exit_y()+1][get_entry_exit_x()] = 240; m[get_entry_exit_y()+1][get_entry_exit_x()+1] = 240;
}

bool EXIT_ROOM1_ENTRY_HALLWAY::interact_entry(std::list<OBJECT*>* &o){
    char key;
    std::cout << std::endl << std::endl;
    std:: cout << "\t\t\t\tLa puerta parece estar abierta." << std::endl << std::endl;
    std:: cout << "\t\t\t\t" << question << "Quieres abrir la puerta?"<< std::endl << std::endl;
    std:: cout << "\t\t\t\tSI: E      NO: ESC";
    while(true){
        if(kbhit()){
            key = getch();
            if(key == ACTION || key == ACTION2) return true;
            else if(key == ESC) return false;
        }
    }
    return false;
 }

void EXIT_ROOM1_ENTRY_HALLWAY::delete_(char** &m){
    m[get_entry_exit_y()][get_entry_exit_x()] = ' '; m[get_entry_exit_y()][get_entry_exit_x()+1] = ' ';
    m[get_entry_exit_y()+1][get_entry_exit_x()] = ' '; m[get_entry_exit_y()+1][get_entry_exit_x()+1] = ' ';
}


ROOM1::ROOM1():MAP(74, 20, "Salon"){
    fill_map();
    std::list<ENTRY_EXITS*>* e = get_entries_exits();
    std::list<ENTRY_EXITS*>::iterator itE;
    e->push_back(new EXIT_ROOM1_ENTRY_TUTORIAL(1,4));
    e->push_back(new EXIT_ROOM1_ENTRY_ROOM2(51, 18));
    e->push_back(new EXIT_ROOM1_ENTRY_ROOM5(21, 2));
    e->push_back(new EXIT_ROOM1_ENTRY_HALLWAY(71, 8));
    char ** m = get_map_matriz();
    for(itE = e->begin(); itE != e->end(); itE++){
        (*itE)->print(m);
    }
    std::list<OBJECT*>* o = get_player_objects();
    std::list<OBJECT*>::iterator itO;
    for(itO = o->begin(); itO != o->end(); itO++){
        (*itO)->print(m);
    }
    std::list<MAP_OBJECT*>* mo = get_map_objects();
    std::list<MAP_OBJECT*>::iterator itMO;
    mo->push_back(new CUPBOARD_2(9, 3, 18, 4));
    mo->push_back(new FLOWER(33, 3, 35, 4));
    mo->push_back(new SHELF_1(36, 3, 49, 4));
    mo->push_back(new CUPBOARD_3_SIDE(69, 4, 72, 5));
    mo->push_back(new CUPBOARD_PUZLE(47, 7, 53, 9));
    mo->push_back(new CUPBOARD_1_SIDE_ESPECIAL(1, 12, 4, 13));
    for(itMO = mo->begin(); itMO != mo->end(); itMO++){
        (*itMO)->print(m);
    }
}

void ROOM1::fill_map(){

    for(int j = 0; j<get_width(); j++){
        set_map(j, 0, char(238));
        set_map(j, 1, char(32));
        set_map(j, 2, char(32));
        set_map(j, 3, char(205));
        set_map(j, get_heigth()-1, char(205));
        set_map(j, get_heigth()-2, char(32));
        set_map(j, get_heigth()-3, char(32));
        set_map(j, get_heigth()-4, char(238));
    }

    for(int i = 0; i < get_heigth(); i++){
        set_map(0, i, char(124));
        set_map(get_width()-1, i, char(124));
    }

    for(int i = 4; i<get_heigth()-4; i++){
        for(int j = 1; j<get_width()-1; j++){
            set_map(j, i, char(32));
        }
    }
    for(int i = 15; i<64; i++){
        set_map(i, 7, char(205));
        set_map(i, 13, char(205));
    }
    for(int i = 7; i<14; i++){
        set_map(15, i, char(186));
        set_map(63, i, char(186));
    }
    for(int i =18; i<64; i+=6){
        set_map(i, 8, char(42));
        set_map(i, 10, char(42));
        set_map(i, 12, char(42));
    }
    set_map(15, 7, char(201)); set_map(15, 13, char(200)); set_map(63, 7, char(187)); set_map(63, 13, char(188));

    set_map(2, 1, char(196)); set_map(3, 1, char(196)); set_map(17, 2, char(196)); set_map(18, 2, char(196));
    set_map(29, 1, char(196)); set_map(30, 1, char(196)); set_map(31, 1, char(196)); set_map(56, 2, char(196));
    set_map(58, 1, char(196)); set_map(66, 2, char(196)); set_map(67, 2, char(196)); set_map(68, 2, char(196));
    set_map(8, 17, char(196)); set_map(9, 17, char(196)); set_map(19, 18, char(196)); set_map(24, 17, char(196));
    set_map(25, 17, char(196)); set_map(26, 17, char(196)); set_map(40, 18, char(196)); set_map(41, 18, char(196));
    set_map(42, 18, char(196)); set_map(43, 18, char(196)); set_map(57, 17, char(196)); set_map(58, 17, char(196));
    set_map(65, 18, char(196)); set_map(66, 18, char(196)); set_map(70, 17, char(196));
}

EXIT_ROOM2_ENTRY_ROOM1::EXIT_ROOM2_ENTRY_ROOM1(int entry_exit_x, int entry_exit_y):ENTRY_EXITS(entry_exit_x, entry_exit_y, 19, 2, 3, true){}

void EXIT_ROOM2_ENTRY_ROOM1::print(char** &m){
    m[get_entry_exit_y()][get_entry_exit_x()] = 218; m[get_entry_exit_y()][get_entry_exit_x()+1] = 196; m[get_entry_exit_y()][get_entry_exit_x()+2] = 191;
    m[get_entry_exit_y()+1][get_entry_exit_x()] = 124; m[get_entry_exit_y()+1][get_entry_exit_x()+1] = 32; m[get_entry_exit_y()+1][get_entry_exit_x()+2] = 124;
}

bool EXIT_ROOM2_ENTRY_ROOM1::interact_entry(std::list<OBJECT*>* &o){ 
    char key;
    std::cout << std::endl << std::endl;
    std:: cout << "\t\t\t\tLa puerta parece estar abierta." << std::endl << std::endl;
    std:: cout << "\t\t\t\t" << question << "Quieres entrar a la habitacion?"<< std::endl << std::endl;
    std:: cout << "\t\t\t\tSI: E      NO: ESC";
    while(true){
        if(kbhit()){
            key = getch();
            if(key == ACTION || key == ACTION2) return true;
            else if(key == ESC) return false;
        }
    }
    return false;
}

void EXIT_ROOM2_ENTRY_ROOM1::delete_(char** &m){
    m[get_entry_exit_y()][get_entry_exit_x()] = 32; m[get_entry_exit_y()][get_entry_exit_x()+1] = 32; m[get_entry_exit_y()][get_entry_exit_x()+2] = 32;
    m[get_entry_exit_y()+1][get_entry_exit_x()] = 32; m[get_entry_exit_y()+1][get_entry_exit_x()+1] =32; m[get_entry_exit_y()+1][get_entry_exit_x()+2] = 32;
}

EXIT_ROOM2_ENTRY_BASEMENT::EXIT_ROOM2_ENTRY_BASEMENT(int entry_exit_x, int entry_exit_y):ENTRY_EXITS(entry_exit_x, entry_exit_y, 48, 2, 4, true){}

void EXIT_ROOM2_ENTRY_BASEMENT::print(char** &m){
    m[get_entry_exit_y()][get_entry_exit_x()] = 218; m[get_entry_exit_y()][get_entry_exit_x()+1] = 196; m[get_entry_exit_y()][get_entry_exit_x()+2] = 196; m[get_entry_exit_y()][get_entry_exit_x()+3] = 191;
    m[get_entry_exit_y()+1][get_entry_exit_x()] = 192; m[get_entry_exit_y()+1][get_entry_exit_x()+1] = 196; m[get_entry_exit_y()+1][get_entry_exit_x()+2] = 196; m[get_entry_exit_y()+1][get_entry_exit_x()+3] = 217;
}

bool EXIT_ROOM2_ENTRY_BASEMENT::interact_entry(std::list<OBJECT*>* &o){ 
    char key;
    std::cout << std::endl << std::endl;
    std:: cout << "\t\t\t\tLa compuerta parece estar abierta." << std::endl << std::endl;
    std:: cout << "\t\t\t\t" << question << "Quieres entrar a la habitacion?"<< std::endl << std::endl;
    std:: cout << "\t\t\t\tSI: E      NO: ESC";
    while(true){
        if(kbhit()){
            key = getch();
            if(key == ACTION || key == ACTION2) return true;
            else if(key == ESC) return false;
        }
    }
    return false;
}

void EXIT_ROOM2_ENTRY_BASEMENT::delete_(char** &m){
    m[get_entry_exit_y()][get_entry_exit_x()] = 32; m[get_entry_exit_y()][get_entry_exit_x()+1] = 32; m[get_entry_exit_y()][get_entry_exit_x()+2] = 32; m[get_entry_exit_y()][get_entry_exit_x()+3] = 32;
    m[get_entry_exit_y()+1][get_entry_exit_x()] = 32; m[get_entry_exit_y()+1][get_entry_exit_x()+1] = 32; m[get_entry_exit_y()+1][get_entry_exit_x()+2] = 32; m[get_entry_exit_y()+1][get_entry_exit_x()+3] = 32;
}

ROOM2::ROOM2():MAP(54, 30, "Taller"){
    fill_map();
    std::list<ENTRY_EXITS*>* e = get_entries_exits();
    std::list<ENTRY_EXITS*>::iterator itE;
    char ** m = get_map_matriz();
    e->push_back(new EXIT_ROOM2_ENTRY_ROOM1(34, 2));
    for(itE = e->begin(); itE != e->end(); itE++){
        (*itE)->print(m);
    }
    std::list<OBJECT*>* o = get_player_objects();
    std::list<OBJECT*>::iterator itO;
    o->push_back(new NOTE2(2, 6));
    for(itO = o->begin(); itO != o->end(); itO++){
        (*itO)->print(m);
    }
    std::list<MAP_OBJECT*>* mo = get_map_objects();
    std::list<MAP_OBJECT*>::iterator itMO;
    mo->push_back(new BOX(3, 2, 8, 4));
    mo->push_back(new SHELF_3(10, 3, 23, 4));
    mo->push_back(new CUPBOARD_3(43, 3, 46, 4));
    mo->push_back(new CUPBOARD_3(47, 3, 50, 4));
    mo->push_back(new LEVER_2(10, 7, 14, 8));
    mo->push_back(new LEVER_1(43, 7, 45, 8));
    mo->push_back(new CHAIR(43, 11, 46, 12));
    mo->push_back(new DESK(48, 12, 52, 13));
    mo->push_back(new CHAIR(43, 15, 46, 16));
    mo->push_back(new DESK(48, 16, 52, 17));
    mo->push_back(new CHAIR(43, 19, 46, 20));
    mo->push_back(new DESK(48, 20, 52, 21));
    mo->push_back(new LEVER_5(29, 15, 31, 16));
    mo->push_back(new LEVER_3(9, 17, 11, 18));
    mo->push_back(new LEVER_4(34, 23, 38, 24));
    mo->push_back(new BOX(1, 23, 6, 25));
    for(itMO = mo->begin(); itMO != mo->end(); itMO++){
        (*itMO)->print(m);
    }
}

void ROOM2::fill_map(){

    for(int j = 0; j<get_width(); j++){
        set_map(j, 0, char(238));
        set_map(j, 1, char(32));
        set_map(j, 2, char(32));
        set_map(j, 3, char(205));
        set_map(j, get_heigth()-1, char(205));
        set_map(j, get_heigth()-2, char(32));
        set_map(j, get_heigth()-3, char(32));
        set_map(j, get_heigth()-4, char(238));
    }

    for(int i = 0; i < get_heigth(); i++){
        set_map(0, i, char(124));
        set_map(get_width()-1, i, char(124));
    }

    for(int i = 4; i<get_heigth()-4; i++){
        for(int j = 1; j<get_width()-1; j++){
            set_map(j, i, char(32));
        }
    }
}

EXIT_BASEMENT_ENTRY_ROOM2::EXIT_BASEMENT_ENTRY_ROOM2(int entry_exit_x, int entry_exit_y):ENTRY_EXITS(entry_exit_x, entry_exit_y, 49, 2, 3, true){}

void EXIT_BASEMENT_ENTRY_ROOM2::print(char** &m){
    m[get_entry_exit_y()-3][get_entry_exit_x()] = 195; m[get_entry_exit_y()-3][get_entry_exit_x()+1] = 196; m[get_entry_exit_y()-3][get_entry_exit_x()+2] = 180;
    m[get_entry_exit_y()-2][get_entry_exit_x()] = 195; m[get_entry_exit_y()-2][get_entry_exit_x()+1] = 196; m[get_entry_exit_y()-2][get_entry_exit_x()+2] = 180;
    m[get_entry_exit_y()-1][get_entry_exit_x()] = 195; m[get_entry_exit_y()-1][get_entry_exit_x()+1] = 196; m[get_entry_exit_y()-1][get_entry_exit_x()+2] = 180;
    m[get_entry_exit_y()][get_entry_exit_x()] = 195; m[get_entry_exit_y()][get_entry_exit_x()+1] = 196; m[get_entry_exit_y()][get_entry_exit_x()+2] = 180;
    m[get_entry_exit_y()+1][get_entry_exit_x()] = 195; m[get_entry_exit_y()+1][get_entry_exit_x()+1] = 196; m[get_entry_exit_y()+1][get_entry_exit_x()+2] = 180;
}

bool EXIT_BASEMENT_ENTRY_ROOM2::interact_entry(std::list<OBJECT*>* &o){ 
    char key;
    std::cout << std::endl << std::endl;
    std:: cout << "\t\t\t\tLa compuerta parece estar abierta." << std::endl << std::endl;
    std:: cout << "\t\t\t\t" << question << "Quieres entrar a la habitacion?"<< std::endl << std::endl;
    std:: cout << "\t\t\t\tSI: E      NO: ESC";
    while(true){
        if(kbhit()){
            key = getch();
            if(key == ACTION || key == ACTION2) return true;
            else if(key == ESC) return false;
        }
    }
    return false;
}

void EXIT_BASEMENT_ENTRY_ROOM2::delete_(char** &m){
    m[get_entry_exit_y()-3][get_entry_exit_x()] = 32; m[get_entry_exit_y()-3][get_entry_exit_x()+1] = 32; m[get_entry_exit_y()-3][get_entry_exit_x()+2] = 32;
    m[get_entry_exit_y()-2][get_entry_exit_x()] = 32; m[get_entry_exit_y()-2][get_entry_exit_x()+1] = 32; m[get_entry_exit_y()-2][get_entry_exit_x()+2] = 32;
    m[get_entry_exit_y()-1][get_entry_exit_x()] = 32; m[get_entry_exit_y()-1][get_entry_exit_x()+1] = 32; m[get_entry_exit_y()-1][get_entry_exit_x()+2] = 32;
    m[get_entry_exit_y()][get_entry_exit_x()] = 32; m[get_entry_exit_y()][get_entry_exit_x()+1] = 32; m[get_entry_exit_y()][get_entry_exit_x()+2] = 32;
    m[get_entry_exit_y()+1][get_entry_exit_x()] = 32; m[get_entry_exit_y()+1][get_entry_exit_x()+1] = 32; m[get_entry_exit_y()+1][get_entry_exit_x()+2] = 32;
}

BASEMENT::BASEMENT():MAP(45, 10, "Sotano"){
    fill_map();
    std::list<ENTRY_EXITS*>* e = get_entries_exits();
    std::list<ENTRY_EXITS*>::iterator itE;
    char ** m = get_map_matriz();
    e->push_back(new EXIT_BASEMENT_ENTRY_ROOM2(4, 3));
    for(itE = e->begin(); itE != e->end(); itE++){
        (*itE)->print(m);
    }
    std::list<OBJECT*>* o = get_player_objects();
    std::list<OBJECT*>::iterator itO;
    o->push_back(new KEY_TO_THREE(19, 4));
    for(itO = o->begin(); itO != o->end(); itO++){
        (*itO)->print(m);
    }
    std::list<MAP_OBJECT*>* mo = get_map_objects();
    std::list<MAP_OBJECT*>::iterator itMO;
    mo->push_back(new BIG_BOX(17, 3, 21, 4));
    mo->push_back(new BODY_DEAD(30, 2, 32, 4));
    for(itMO = mo->begin(); itMO != mo->end(); itMO++){
        (*itMO)->print(m);
    }
}

void BASEMENT::fill_map(){

    for(int j = 0; j<get_width(); j++){
        set_map(j, 0, char(238));
        set_map(j, 1, char(32));
        set_map(j, 2, char(32));
        set_map(j, 3, char(205));
        set_map(j, get_heigth()-1, char(205));
        set_map(j, get_heigth()-2, char(32));
        set_map(j, get_heigth()-3, char(32));
        set_map(j, get_heigth()-4, char(238));
    }

    for(int i = 0; i < get_heigth(); i++){
        set_map(0, i, char(124));
        set_map(get_width()-1, i, char(124));
    }

    for(int i = 4; i<get_heigth()-4; i++){
        for(int j = 1; j<get_width()-1; j++){
            set_map(j, i, char(32));
        }
    }
    set_map(1, 0, char(88)); set_map(2, 0, char(88)); set_map(1, 2, char(88)); set_map(1, 3, char(88));
    set_map(2, 3, char(88)); set_map(42, 0, char(88)); set_map(43, 0, char(88)); set_map(41, 1, char(88));
    set_map(42, 1, char(88)); set_map(43, 1, char(88)); set_map(43, 2, char(88)); set_map(24, 1, char(92));
    set_map(25, 2, char(92)); set_map(26, 2, char(47)); set_map(27, 2, char(92)); set_map(28, 2, char(47));
    set_map(29, 1, char(47)); set_map(30, 1, char(124)); set_map(33, 1, char(124)); set_map(33, 2, char(180));
    set_map(34, 1, char(92)); set_map(35, 1, char(95)); set_map(36, 1, char(47)); set_map(35, 2, char(47));
}

EXIT_HALLWAY_ENTRY_ROOM1::EXIT_HALLWAY_ENTRY_ROOM1(int entry_exit_x, int entry_exit_y):ENTRY_EXITS(entry_exit_x, entry_exit_y, 35, 2, 2, false){}

void EXIT_HALLWAY_ENTRY_ROOM1::print(char** &m){
    m[get_entry_exit_y()][get_entry_exit_x()] = 240; m[get_entry_exit_y()][get_entry_exit_x()+1] = 240;
    m[get_entry_exit_y()+1][get_entry_exit_x()] = 240; m[get_entry_exit_y()+1][get_entry_exit_x()+1] = 240;
}

bool EXIT_HALLWAY_ENTRY_ROOM1::interact_entry(std::list<OBJECT*>* &o){
    std::list<OBJECT*>::iterator itO;
    bool if_key = false;
    char key;
    if(!get_acces()){
        for(itO = o->begin(); itO != o->end(); itO++){
            if((*itO)->get_code() == 222){
                if_key = true;
                break;;
            }
        }
        if(if_key){
            std::cout << std::endl << std::endl;
            std::cout << "\t\t\t\t" << question << "Quieres usar la Llave oxidada para abrir la puerta?" << std::endl << std::endl;
            std::cout << "\t\t\t\tSI: E              NO: ESC";
            while(true){
                if(kbhit()){
                    key = getch();
                    if(key == ACTION || key == ACTION2){
                        set_acces(true);
                        return true;
                    }
                    else if(key == ESC) return false;
                }
            }
        }
        else{
            std::cout << std::endl << std::endl;
            std::cout << "\t\t\t\tEsta cerrada, parece necesitar una llave." << std::endl << std::endl;
            std::cout << "\t\t\t\tCERRAR: ESC";
            while(true){
                if(kbhit()){
                    key = getch();
                    if(key == ESC) return false;
                }
            }
            return false;
        }
    }
    else{
        std::cout << std::endl << std::endl;
        std:: cout << "\t\t\t\tLa puerta parece estar abierta." << std::endl << std::endl;
        std:: cout << "\t\t\t\t" << question << "Quieres abrir la puerta?"<< std::endl << std::endl;
        std:: cout << "\t\t\t\tSI: E      NO: ESC";
        while(true){
            if(kbhit()){
                key = getch();
                if(key == ACTION || key == ACTION2) return true;
                else if(key == ESC) return false;
            }
        }
        return false;
    }
    return false;
 }

void EXIT_HALLWAY_ENTRY_ROOM1::delete_(char** &m){
    m[get_entry_exit_y()][get_entry_exit_x()] = ' '; m[get_entry_exit_y()][get_entry_exit_x()+1] = ' ';
    m[get_entry_exit_y()+1][get_entry_exit_x()] = ' '; m[get_entry_exit_y()+1][get_entry_exit_x()+1] = ' ';
}

EXIT_HALLWAY_ENTRY_ROOM3::EXIT_HALLWAY_ENTRY_ROOM3(int entry_exit_x, int entry_exit_y):ENTRY_EXITS(entry_exit_x, entry_exit_y, 72, 2, 2, true){}

void EXIT_HALLWAY_ENTRY_ROOM3::print(char** &m){
    m[get_entry_exit_y()][get_entry_exit_x()] = 240; m[get_entry_exit_y()][get_entry_exit_x()+1] = 240;
    m[get_entry_exit_y()+1][get_entry_exit_x()] = 240; m[get_entry_exit_y()+1][get_entry_exit_x()+1] = 240;
}

bool EXIT_HALLWAY_ENTRY_ROOM3::interact_entry(std::list<OBJECT*>* &o){
    char key;
    std::cout << std::endl << std::endl;
    std:: cout << "\t\t\t\tLa puerta parece estar abierta." << std::endl << std::endl;
    std:: cout << "\t\t\t\t" << question << "Quieres abrir la puerta?"<< std::endl << std::endl;
    std:: cout << "\t\t\t\tSI: E      NO: ESC";
    while(true){
        if(kbhit()){
            key = getch();
            if(key == ACTION || key == ACTION2) return true;
            else if(key == ESC) return false;
        }
    }
    return false;
 }

void EXIT_HALLWAY_ENTRY_ROOM3::delete_(char** &m){
    m[get_entry_exit_y()][get_entry_exit_x()] = ' '; m[get_entry_exit_y()][get_entry_exit_x()+1] = ' ';
    m[get_entry_exit_y()+1][get_entry_exit_x()] = ' '; m[get_entry_exit_y()+1][get_entry_exit_x()+1] = ' ';
}

HALLWAY::HALLWAY():MAP(82, 13, "Pasillo"){
    fill_map();
    std::list<ENTRY_EXITS*>* e = get_entries_exits();
    std::list<ENTRY_EXITS*>::iterator itE;
    char ** m = get_map_matriz();
    e->push_back(new EXIT_HALLWAY_ENTRY_ROOM1(1, 6));
    e->push_back(new EXIT_HALLWAY_ENTRY_ROOM3(79, 6));
    for(itE = e->begin(); itE != e->end(); itE++){
        (*itE)->print(m);
    }
    std::list<OBJECT*>* o = get_player_objects();
    std::list<OBJECT*>::iterator itO;
    for(itO = o->begin(); itO != o->end(); itO++){
        (*itO)->print(m);
    }
    std::list<MAP_OBJECT*>* mo = get_map_objects();
    std::list<MAP_OBJECT*>::iterator itMO;
    mo->push_back(new CUPBOARD_2(3, 3, 12, 4));
    mo->push_back(new PICTURE_1(17, 2, 21, 2));
    mo->push_back(new PICTURE_2(24, 2, 33, 2));
    mo->push_back(new FLOWER(40, 3, 42, 4));
    mo->push_back(new CUPBOARD_2(44, 3, 53, 4));
    mo->push_back(new PICTURE_ESPECIAL(57, 2, 61, 2));
    mo->push_back(new PICTURE_1(65, 2, 69, 2));
    mo->push_back(new FLOWER(76, 3, 78, 4));
    for(itMO = mo->begin(); itMO != mo->end(); itMO++){
        (*itMO)->print(m);
    }
}

void HALLWAY::fill_map(){

    for(int j = 0; j<get_width(); j++){
        set_map(j, 0, char(238));
        set_map(j, 1, char(32));
        set_map(j, 2, char(32));
        set_map(j, 3, char(205));
        set_map(j, get_heigth()-1, char(205));
        set_map(j, get_heigth()-2, char(32));
        set_map(j, get_heigth()-3, char(32));
        set_map(j, get_heigth()-4, char(238));
    }

    for(int i = 0; i < get_heigth(); i++){
        set_map(0, i, char(124));
        set_map(get_width()-1, i, char(124));
    }

    for(int i = 4; i<get_heigth()-4; i++){
        for(int j = 1; j<get_width()-1; j++){
            set_map(j, i, char(32));
        }
    }
    for(int i=6; i<76; i++){
        set_map(i, 5, char(196));
        set_map(i, 8, char(196));
    }
    for(int i=5; i<9; i++){
        set_map(6, i, char(124));
        set_map(75, i, char(124));
    }
    set_map(6, 5, char(218)); set_map(6, 8, char(192)); set_map(75, 5, char(191)); set_map(75, 8, char(217));
}

EXIT_ROOM3_ENTRY_HALLWAY::EXIT_ROOM3_ENTRY_HALLWAY(int entry_exit_x, int entry_exit_y):ENTRY_EXITS(entry_exit_x, entry_exit_y, 73, 2, 2, true){}

void EXIT_ROOM3_ENTRY_HALLWAY::print(char** &m){
    m[get_entry_exit_y()][get_entry_exit_x()] = 240; m[get_entry_exit_y()][get_entry_exit_x()+1] = 240;
    m[get_entry_exit_y()+1][get_entry_exit_x()] = 240; m[get_entry_exit_y()+1][get_entry_exit_x()+1] = 240;
}

bool EXIT_ROOM3_ENTRY_HALLWAY::interact_entry(std::list<OBJECT*>* &o){
    char key;
    std::cout << std::endl << std::endl;
    std:: cout << "\t\t\t\tLa puerta parece estar abierta." << std::endl << std::endl;
    std:: cout << "\t\t\t\t" << question << "Quieres abrir la puerta?"<< std::endl << std::endl;
    std:: cout << "\t\t\t\tSI: E      NO: ESC";
    while(true){
        if(kbhit()){
            key = getch();
            if(key == ACTION || key == ACTION2) return true;
            else if(key == ESC) return false;
        }
    }
    return false;
 }

void EXIT_ROOM3_ENTRY_HALLWAY::delete_(char** &m){
    m[get_entry_exit_y()][get_entry_exit_x()] = ' '; m[get_entry_exit_y()][get_entry_exit_x()+1] = ' ';
    m[get_entry_exit_y()+1][get_entry_exit_x()] = ' '; m[get_entry_exit_y()+1][get_entry_exit_x()+1] = ' ';
}

EXIT_ROOM3_ENTRY_ROOM4::EXIT_ROOM3_ENTRY_ROOM4(int entry_exit_x, int entry_exit_y):ENTRY_EXITS(entry_exit_x, entry_exit_y, 81, 2, 3, true){}

void EXIT_ROOM3_ENTRY_ROOM4::print(char** &m){
    m[get_entry_exit_y()][get_entry_exit_x()] = 218; m[get_entry_exit_y()][get_entry_exit_x()+1] = 196; m[get_entry_exit_y()][get_entry_exit_x()+2] = 191;
    m[get_entry_exit_y()+1][get_entry_exit_x()] = 124; m[get_entry_exit_y()+1][get_entry_exit_x()+1] = 32; m[get_entry_exit_y()+1][get_entry_exit_x()+2] = 124;
}

bool EXIT_ROOM3_ENTRY_ROOM4::interact_entry(std::list<OBJECT*>* &o){ 
    char key;
    std::cout << std::endl << std::endl;
    std:: cout << "\t\t\t\tLa puerta parece estar abierta." << std::endl << std::endl;
    std:: cout << "\t\t\t\t" << question << "Quieres entrar a la habitacion?"<< std::endl << std::endl;
    std:: cout << "\t\t\t\tSI: E      NO: ESC";
    while(true){
        if(kbhit()){
            key = getch();
            if(key == ACTION || key == ACTION2) return true;
            else if(key == ESC) return false;
        }
    }
    return false;
}

void EXIT_ROOM3_ENTRY_ROOM4::delete_(char** &m){
    m[get_entry_exit_y()][get_entry_exit_x()] = 32; m[get_entry_exit_y()][get_entry_exit_x()+1] = 32; m[get_entry_exit_y()][get_entry_exit_x()+2] = 32;
    m[get_entry_exit_y()+1][get_entry_exit_x()] = 32; m[get_entry_exit_y()+1][get_entry_exit_x()+1] =32; m[get_entry_exit_y()+1][get_entry_exit_x()+2] = 32;
}

EXIT_ROOM3_ENTRY_ROOM6::EXIT_ROOM3_ENTRY_ROOM6(int entry_exit_x, int entry_exit_y):ENTRY_EXITS(entry_exit_x, entry_exit_y, 90, 2, 3, true){}

void EXIT_ROOM3_ENTRY_ROOM6::print(char** &m){
    m[get_entry_exit_y()][get_entry_exit_x()] = 218; m[get_entry_exit_y()][get_entry_exit_x()+1] = 196; m[get_entry_exit_y()][get_entry_exit_x()+2] = 191;
    m[get_entry_exit_y()+1][get_entry_exit_x()] = 124; m[get_entry_exit_y()+1][get_entry_exit_x()+1] = 32; m[get_entry_exit_y()+1][get_entry_exit_x()+2] = 124;
}

bool EXIT_ROOM3_ENTRY_ROOM6::interact_entry(std::list<OBJECT*>* &o){ return false; }

void EXIT_ROOM3_ENTRY_ROOM6::delete_(char** &m){
    m[get_entry_exit_y()][get_entry_exit_x()] = 32; m[get_entry_exit_y()][get_entry_exit_x()+1] = 32; m[get_entry_exit_y()][get_entry_exit_x()+2] = 32;
    m[get_entry_exit_y()+1][get_entry_exit_x()] = 32; m[get_entry_exit_y()+1][get_entry_exit_x()+1] =32; m[get_entry_exit_y()+1][get_entry_exit_x()+2] = 32;
}

EXIT_ROOM6_ENTRY_ROOM3::EXIT_ROOM6_ENTRY_ROOM3(int entry_exit_x, int entry_exit_y):ENTRY_EXITS(entry_exit_x, entry_exit_y, 91, 2, 3, true){}

void EXIT_ROOM6_ENTRY_ROOM3::print(char** &m){
    m[get_entry_exit_y()][get_entry_exit_x()] = 218; m[get_entry_exit_y()][get_entry_exit_x()+1] = 196; m[get_entry_exit_y()][get_entry_exit_x()+2] = 191;
    m[get_entry_exit_y()+1][get_entry_exit_x()] = 124; m[get_entry_exit_y()+1][get_entry_exit_x()+1] = 32; m[get_entry_exit_y()+1][get_entry_exit_x()+2] = 124;
}

bool EXIT_ROOM6_ENTRY_ROOM3::interact_entry(std::list<OBJECT*>* &o){ 
    std::list<OBJECT*>::iterator itO;
    int count = 0;
    for(itO = o->begin(); itO != o->end(); itO++){
        if((*itO)->get_code() / 100 == 3) count++;
    }
    if(count == 9){
        char key;
        std::cout << std::endl << std::endl;
        std:: cout << "\t\t\t\tLa puerta esta cerrada, hay una ranura donde va la cerradura." << std::endl << std::endl;
        std:: cout << "\t\t\t\tPareces tener todas las piezas." << std::endl << std::endl;
        std:: cout << "\t\t\t\t" << question << "Quieres intentar repararla?"<< std::endl << std::endl;
        std:: cout << "\t\t\t\tSI: E      NO: ESC";
        while(true){
            if(kbhit()){
                key = getch();
                if(key == ACTION || key == ACTION2){
                    if(run_re_door()) return true;
                    else return false;
                }
                else if(key == ESC) return false;
            }
        }
    }
    else{
        char key;
        std::cout << std::endl << std::endl;
        std:: cout << "\t\t\t\tLa puerta esta cerrada, hay una ranura donde va la cerradura." << std::endl << std::endl;
        std:: cout << "\t\t\t\tParece que te faltan piezas." << std::endl << std::endl;
        std:: cout << "\t\t\t\tCERRAR: ESC";
        while(true){
            if(kbhit()){
                key = getch();
                if(key == ESC) return false;
            }
        }
    }
    return false;
}

void EXIT_ROOM6_ENTRY_ROOM3::delete_(char** &m){
    m[get_entry_exit_y()][get_entry_exit_x()] = 32; m[get_entry_exit_y()][get_entry_exit_x()+1] = 32; m[get_entry_exit_y()][get_entry_exit_x()+2] = 32;
    m[get_entry_exit_y()+1][get_entry_exit_x()] = 32; m[get_entry_exit_y()+1][get_entry_exit_x()+1] =32; m[get_entry_exit_y()+1][get_entry_exit_x()+2] = 32;
}

ROOM3::ROOM3():MAP(54, 17, "Sala de Acustica"){
    fill_map();
    std::list<ENTRY_EXITS*>* e = get_entries_exits();
    std::list<ENTRY_EXITS*>::iterator itE;
    char ** m = get_map_matriz();
    e->push_back(new EXIT_ROOM3_ENTRY_HALLWAY(1, 4));
    e->push_back(new EXIT_ROOM3_ENTRY_ROOM4(36, 15));
    e->push_back(new EXIT_ROOM3_ENTRY_ROOM6(26, 2));
    for(itE = e->begin(); itE != e->end(); itE++){
        (*itE)->print(m);
    }
    std::list<OBJECT*>* o = get_player_objects();
    std::list<OBJECT*>::iterator itO;
    for(itO = o->begin(); itO != o->end(); itO++){
        (*itO)->print(m);
    }
    std::list<MAP_OBJECT*>* mo = get_map_objects();
    std::list<MAP_OBJECT*>::iterator itMO;
    mo->push_back(new PIANO(21, 7, 33, 8));
    mo->push_back(new FLOWER(21, 3, 23, 4));
    mo->push_back(new FLOWER(31, 3, 33, 4));
    for(itMO = mo->begin(); itMO != mo->end(); itMO++){
        (*itMO)->print(m);
    }
}

void ROOM3::fill_map(){

    for(int j = 0; j<get_width(); j++){
        set_map(j, 0, char(238));
        set_map(j, 1, char(32));
        set_map(j, 2, char(32));
        set_map(j, 3, char(205));
        set_map(j, get_heigth()-1, char(205));
        set_map(j, get_heigth()-2, char(32));
        set_map(j, get_heigth()-3, char(32));
        set_map(j, get_heigth()-4, char(238));
    }

    for(int i = 0; i < get_heigth(); i++){
        set_map(0, i, char(124));
        set_map(get_width()-1, i, char(124));
    }

    for(int i = 4; i<get_heigth()-4; i++){
        for(int j = 1; j<get_width()-1; j++){
            set_map(j, i, char(32));
        }
    }
    for(int i=7; i<47; i++){
        set_map(i, 6, char(205));
        set_map(i, 10, char(205));
    }
    for(int i=6; i<11; i++){
        set_map(7, i, char(186));
        set_map(46, i, char(186));
    }
    for(int i=9; i<47; i+=5){
        set_map(i, 7, char(42));
        set_map(i, 9, char(42));
    }
    set_map(7, 6, char(201)); set_map(7, 10, char(200)); set_map(46, 6, char(187)); set_map(46, 10, char(188));
}

EXIT_ROOM4_ENTRY_ROOM3::EXIT_ROOM4_ENTRY_ROOM3(int entry_exit_x, int entry_exit_y):ENTRY_EXITS(entry_exit_x, entry_exit_y, 82, 2, 3, true){}

void EXIT_ROOM4_ENTRY_ROOM3::print(char** &m){
    m[get_entry_exit_y()][get_entry_exit_x()] = 218; m[get_entry_exit_y()][get_entry_exit_x()+1] = 196; m[get_entry_exit_y()][get_entry_exit_x()+2] = 191;
    m[get_entry_exit_y()+1][get_entry_exit_x()] = 124; m[get_entry_exit_y()+1][get_entry_exit_x()+1] = 32; m[get_entry_exit_y()+1][get_entry_exit_x()+2] = 124;
}

bool EXIT_ROOM4_ENTRY_ROOM3::interact_entry(std::list<OBJECT*>* &o){ 
    char key;
    std::cout << std::endl << std::endl;
    std:: cout << "\t\t\t\tLa puerta parece estar abierta." << std::endl << std::endl;
    std:: cout << "\t\t\t\t" << question << "Quieres entrar a la habitacion?"<< std::endl << std::endl;
    std:: cout << "\t\t\t\tSI: E      NO: ESC";
    while(true){
        if(kbhit()){
            key = getch();
            if(key == ACTION || key == ACTION2) return true;
            else if(key == ESC) return false;
        }
    }
    return false;
}

void EXIT_ROOM4_ENTRY_ROOM3::delete_(char** &m){
    m[get_entry_exit_y()][get_entry_exit_x()] = 32; m[get_entry_exit_y()][get_entry_exit_x()+1] = 32; m[get_entry_exit_y()][get_entry_exit_x()+2] = 32;
    m[get_entry_exit_y()+1][get_entry_exit_x()] = 32; m[get_entry_exit_y()+1][get_entry_exit_x()+1] =32; m[get_entry_exit_y()+1][get_entry_exit_x()+2] = 32;
}

ROOM4::ROOM4():MAP(57, 16, "Sala de Acustica"){
    fill_map();
    std::list<ENTRY_EXITS*>* e = get_entries_exits();
    std::list<ENTRY_EXITS*>::iterator itE;
    char ** m = get_map_matriz();
    e->push_back(new EXIT_ROOM4_ENTRY_ROOM3(27, 2));
    for(itE = e->begin(); itE != e->end(); itE++){
        (*itE)->print(m);
    }
    std::list<OBJECT*>* o = get_player_objects();
    std::list<OBJECT*>::iterator itO;
    for(itO = o->begin(); itO != o->end(); itO++){
        (*itO)->print(m);
    }
    std::list<MAP_OBJECT*>* mo = get_map_objects();
    std::list<MAP_OBJECT*>::iterator itMO;
    mo->push_back(new SHELF_1(6, 3, 19, 4));
    mo->push_back(new SHELF_2(37, 3, 50, 4));
    mo->push_back(new CUPBOARD_SIDE(1, 7, 4, 8));
    mo->push_back(new CUPBOARD_SIDE(1, 9, 4, 10));
    mo->push_back(new CHAIR(46, 7, 49, 8));
    mo->push_back(new DESK(51, 8, 55, 9));
    for(itMO = mo->begin(); itMO != mo->end(); itMO++){
        (*itMO)->print(m);
    }
}

void ROOM4::fill_map(){

    for(int j = 0; j<get_width(); j++){
        set_map(j, 0, char(238));
        set_map(j, 1, char(32));
        set_map(j, 2, char(32));
        set_map(j, 3, char(205));
        set_map(j, get_heigth()-1, char(205));
        set_map(j, get_heigth()-2, char(32));
        set_map(j, get_heigth()-3, char(32));
        set_map(j, get_heigth()-4, char(238));
    }

    for(int i = 0; i < get_heigth(); i++){
        set_map(0, i, char(124));
        set_map(get_width()-1, i, char(124));
    }

    for(int i = 4; i<get_heigth()-4; i++){
        for(int j = 1; j<get_width()-1; j++){
            set_map(j, i, char(32));
        }
    }
    set_map(15, 5, char(95)); set_map(16, 5, char(95)); set_map(14, 6, char(47)); set_map(15, 6, char(95)); set_map(16, 6, char(47));
    set_map(32, 4, char(95)); set_map(33, 4, char(95)); set_map(31, 5, char(47)); set_map(32, 5, char(95)); set_map(33, 5, char(47));
    set_map(22, 7, char(95)); set_map(23, 7, char(95)); set_map(22, 8, char(92)); set_map(23, 8, char(95)); set_map(24, 8, char(92));
    set_map(10, 9, char(95)); set_map(11, 9, char(95)); set_map(10, 10, char(92)); set_map(11, 10, char(95)); set_map(12, 10, char(92));
    set_map(35, 9, char(95)); set_map(36, 9, char(95)); set_map(34, 10, char(47)); set_map(35, 10, char(95)); set_map(36, 10, char(47));
}
