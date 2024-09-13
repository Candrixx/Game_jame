#ifndef MAPA_H
#define MAPA_H
#include<list>
#include<iostream>
#include<string.h>

class ENTRY_EXITS{
    int entry_x, entry_y;
    int exit_x, exit_y;
public:
    ENTRY_EXITS(int entry_x, int entry_y, int exit_x, int exit_y);
    int get_entry_x();
    int get_entry_y();
    int get_exit_x();
    int get_exit_y();
    void print(char **&m);
    void delete_(char** map);
};

class MAP{
    char ** map;
    int width, heigth;
    std::string nombre; 
    std::list<int> map_objects;
    std::list<int> player_objects;
    std::list<ENTRY_EXITS*> entries_exits;
public:
    MAP(int width, int heigth, std::string _nombre);
    ~MAP();
    char get_map(int _x, int _y);
    std::string get_nombre();
    void set_map(int _x, int _y ,char c);
    virtual void fill_map() = 0; 
    std::list<int>* get_map_objects();
    std::list<int>* get_player_objects();
    std::list<ENTRY_EXITS*>* get_entries_exits();
    int get_width();
    int get_heigth();
};

class MAP_PRUEBA:public MAP{
public:
    MAP_PRUEBA();
    void fill_map() override;
};

#endif