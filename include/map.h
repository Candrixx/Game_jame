#ifndef MAPA_H
#define MAPA_H
#include<list>

class ENTRY_EXITS{
    int entry_x, entry_y;
    int exit_x, exit_y;
    char c;
public:
    ENTRY_EXITS(int entry_x, int entry_y, int exit_x, int exit_y);
    int get_entry_x();
    int get_entry_y();
    int get_exit_x();
    int get_exit_y();
    void print(char **map);
    void delete_(char** map);
};

class MAP{
    char ** map;
    int width, heigth;
    std::list<int> map_objects;
    std::list<int> player_objects;
    std::list<ENTRY_EXITS*> entries_exits;
public:
    MAP(int width, int heigth);
    ~MAP();
    char **get_map();
    virtual void fill_map() = 0; 
    std::list<int>* get_map_objects();
    std::list<int>* get_player_objects();
    std::list<ENTRY_EXITS*>* get_entries_exits();
    int get_width();
    int get_heigth();
};

class MAP_PRUEBA:MAP{
public:
    MAP_PRUEBA();
};

#endif