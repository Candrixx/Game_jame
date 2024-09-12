#include "../include/map.h"

ENTRY_EXITS::ENTRY_EXITS(int entry_x, int entry_y, int exit_x, int exit_y){
    this->entry_x = entry_x;
    this->entry_y = entry_y;
    this->exit_x = exit_x;
    this->exit_y = exit_y;
    c = '_';
}

int ENTRY_EXITS::get_entry_x(){ return entry_x; }
int ENTRY_EXITS::get_entry_y(){ return entry_y; }
int ENTRY_EXITS::get_exit_x(){ return exit_x; }
int ENTRY_EXITS::get_exit_y(){ return exit_y; }

void ENTRY_EXITS::print(char** map){
    map[exit_x][exit_y] = c;
}

void ENTRY_EXITS::delete_(char** map){
    map[exit_x][exit_y] = ' ';
}



MAP::MAP(int width, int heigth){
     this->map = new char* [heigth];
     for(int i=0; i<heigth; i++){
        this->map[i] = new char[width];
     }
     this->width = width;
     this->heigth = heigth;
}

MAP::~MAP(){
    for(int i=0; i<heigth; i++){
        delete [] map[i];
    }
    delete [] map;
}

std::list<int>* MAP::get_map_objects(){ return &map_objects; }
std::list<int>* MAP::get_player_objects(){ return &player_objects; }
std::list<ENTRY_EXITS*>* MAP::get_entries_exits(){ return &entries_exits; }

int MAP::get_width(){ return width; }
int MAP::get_heigth(){ return heigth; }
char MAP::get_map(int _x, int _y){
    return map[_x][_y]; 
}

void MAP::set_map(int _x, int _y ,char c){
    map[_x][_y] = c;
}

MAP_PRUEBA::MAP_PRUEBA(): MAP(140, 30){
    std::list<ENTRY_EXITS*>* e = get_entries_exits();
    e->push_back(new ENTRY_EXITS(0, 0, 1, 12));
}

void MAP_PRUEBA::fill_map(){

    for(int i = 0; i<get_heigth(); i++){
        for(int j=0; j<get_width(); j++){
            set_map(i, j, 's');
        }
    }
}