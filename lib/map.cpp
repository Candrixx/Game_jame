#include<iostream>
#include<conio.h>
#include "../include/map.h"
#include "../include/map_objects.h"
#include "../include/objects.h"
#define ACTION 'e'
#define ACTION2 'E'
#define ESC 27
#define CLEAR_SCREEN system("cls")

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

void ENTRY_EXITS::delete_(char** map){
    map[entry_exit_x][entry_exit_y] = ' ';
}

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

bool ENTRY_EXITS_MAP_PRUEBA::interact_entry(){
    char key;
    std::cout << std::endl << std::endl;
    std:: cout << "\t\t\t\tLa puerta parece estar abierta." << std::endl << std::endl;
    std:: cout << "\t\t\t\tQuieres entrar al Mapa de Prueba"<< std::endl << std::endl;
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
    mo->push_back(new TABLE(45, 15, 59, 17));
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

bool ENTRY_EXITS_MAP_PRUEBA2::interact_entry(){
    char key;
    char edges[52];
    char ed = 186;
    if(get_acces()){
        std::cout << std::endl << std::endl;
        std:: cout << "\t\t\t\tLa puerta parece estar abierta." << std::endl << std::endl;
        std:: cout << "\t\t\t\tQuieres entrar al Mapa de Prueba 2"<< std::endl << std::endl;
        std:: cout << "\t\t\t\tSI: E      NO: ESC";
        while(true){
            if(kbhit()){
                key = getch();
                if(key == ACTION || key == ACTION2) return true;
                else if(key == ESC) return false;
            }
        }
    }
    else{
        std::string code; 
        std::cout << std::endl << std::endl;
        std:: cout << "\t\t\t\tLa puerta parece nececitar un codigo." << std::endl << std::endl;
        std:: cout << "\t\t\t\tQuieres intentar"<< std::endl << std::endl;
        std:: cout << "\t\t\t\tSI: E      NO: ESC";
        for(int i=0; i < 52; i++){
            edges[i] = 205;
        }
        edges[0] = 201;
        edges[51] = 187;
        while(true){
            if(kbhit()){
                key = getch();
                if(key == ACTION || key == ACTION2){
                    CLEAR_SCREEN;
                    std::cout << std::endl << std::endl << std::endl << std::endl;
                    std::cout << "\t\t\t\t";
                    for(int i=0; i < 52; i++){
                        std::cout << edges[i];
                    }
                    std::cout << std::endl;
                    std::cout << "\t\t\t\t" << ed << "\t\tINGRESAR CODIGO\t\t\t   " << ed << std::endl;
                    std::cout << "\t\t\t\t";
                    edges[0] = 200;
                    edges[51] = 188;
                    for(int i=0; i < 52; i++){
                        std::cout << edges[i];
                    }
                    std::cout << std::endl << "\t\t\t\tCodigo: ";
                    getline(std::cin, code);
                    if(code == "1234"){
                        set_acces(true);
                        return true;
                    }
                    else return false;
                }
                else if(key == ESC) return false;
            }
        }
    }
    return false;
}

MAP_PRUEBA2::MAP_PRUEBA2():MAP(60, 25, "Mapa Prueba 2"){
    fill_map();
    std::list<ENTRY_EXITS*>* e = get_entries_exits();
    std::list<ENTRY_EXITS*>::iterator itE;
    e->push_back(new ENTRY_EXITS_MAP_PRUEBA2(get_width()-3, 16));
    char ** m = get_map_matriz();
    for(itE = e->begin(); itE != e->end(); itE++){
        (*itE)->print(m);
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