#include "../include/map.h"
#include "../include/map_objects.h"

ENTRY_EXITS::ENTRY_EXITS(int entry_x, int entry_y, int exit_x, int exit_y){
    this->entry_x = entry_x;
    this->entry_y = entry_y;
    this->exit_x = exit_x;
    this->exit_y = exit_y;
}

int ENTRY_EXITS::get_entry_x(){ return entry_x; }
int ENTRY_EXITS::get_entry_y(){ return entry_y; }
int ENTRY_EXITS::get_exit_x(){ return exit_x; }
int ENTRY_EXITS::get_exit_y(){ return exit_y; }

void ENTRY_EXITS::print(char **&m){
    m[exit_y][exit_x] = '_';
}

void ENTRY_EXITS::delete_(char** map){
    map[exit_y][exit_x] = ' ';
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
std::list<int>* MAP::get_player_objects(){ return &player_objects; }
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

MAP_PRUEBA::MAP_PRUEBA(): MAP(140, 30, "Mapa Prueba"){
    fill_map();
    std::list<ENTRY_EXITS*>* e = get_entries_exits();
    e->push_back(new ENTRY_EXITS(0, 0, 1, 12));
    e->push_back(new ENTRY_EXITS(0, 0, get_width()-2, 12));
    std::list<ENTRY_EXITS*>::iterator itE;
    itE = e->begin();
    char ** m = get_map_matriz();
    (*itE)->print(m);
    itE++;
    (*itE)->print(m);
    std::list<MAP_OBJECT*>* mo = get_map_objects();
    std::list<MAP_OBJECT*>::iterator itMO;
    mo->push_back(new CUPBOARD(12, 3, 15, 4));
    mo->push_back(new CUPBOARD(34, 3, 37, 4));
    mo->push_back(new CUPBOARD(45, 3, 48, 4));
    mo->push_back(new CUPBOARD(34, 12, 37, 13));
    itMO = mo->begin();
    (*itMO)->print(m);
    itMO++;
    (*itMO)->print(m);
    itMO++;
    (*itMO)->print(m);
    itMO++;
    (*itMO)->print(m);  
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