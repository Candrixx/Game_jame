#include<iostream>
#include<algorithm>
#include "C:\Users\USER\Documents\ProyectoTutorialC++\GameJam\include/map.h"

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