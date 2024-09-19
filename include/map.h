#ifndef MAPA_H
#define MAPA_H
#include<list>
#include<iostream>
#include<string.h>
#include "../include/map_objects.h"

class ENTRY_EXITS{
    int entry_exit_x, entry_exit_y;
    int code;
    int heigth, width;
    bool acces;
public:
    ENTRY_EXITS(int entry_exit_x, int entry_exit_y, int code, int heigth, int width, bool acces);
    int get_entry_exit_x();
    int get_entry_exit_y();
    int get_code();
    bool get_acces();
    void set_acces(bool a);
    int get_heigth();
    int get_width();
    virtual void print(char **&m) = 0;
    virtual bool interact_entry(std::list<OBJECT*>* &o) = 0;
    void delete_(char** map);
};

class MAP{
    char ** map;
    int width, heigth;
    std::string name; 
    std::list<MAP_OBJECT*> map_objects;
    std::list<OBJECT*> player_objects;
    std::list<ENTRY_EXITS*> entries_exits;
public:
    MAP(int width, int heigth, std::string _name);
    ~MAP();
    char ** get_map_matriz();
    char get_map(int _x, int _y);
    std::string get_name(){ return name; }
    void set_map(int _x, int _y ,char c);
    void print_elements_map();
    virtual void fill_map() = 0; 
    std::list<MAP_OBJECT*>* get_map_objects();
    std::list<OBJECT*>* get_player_objects();
    std::list<ENTRY_EXITS*>* get_entries_exits();
    int get_width();
    int get_heigth();
};

class ENTRY_EXITS_MAP_PRUEBA: public ENTRY_EXITS{
public:
    ENTRY_EXITS_MAP_PRUEBA(int entry_exit_x, int entry_exit_y);
    void print(char** &m) override;
    bool interact_entry(std::list<OBJECT*>* &o) override;
};

class ENTRY_EXITS_MAP_PRUEBA2: public ENTRY_EXITS{
public:
    ENTRY_EXITS_MAP_PRUEBA2(int entry_exit_x, int entry_exit_y);
    void print(char** &m) override;
    bool interact_entry(std::list<OBJECT*>* &o) override;
};

class MAP_PRUEBA:public MAP{
public:
    MAP_PRUEBA();
    void fill_map() override;
};

class MAP_PRUEBA2:public MAP{
public:
    MAP_PRUEBA2();
    void fill_map() override;
};

#endif