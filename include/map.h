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
    virtual void delete_(char** &map) = 0;
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
    void delete_(char** &map) override;
};

class ENTRY_EXITS_MAP_PRUEBA2: public ENTRY_EXITS{
public:
    ENTRY_EXITS_MAP_PRUEBA2(int entry_exit_x, int entry_exit_y);
    void print(char** &m) override;
    bool interact_entry(std::list<OBJECT*>* &o) override;
    void delete_(char** &map) override;
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

class EXIT_TUTORIAL_ENTRY_ROOM1: public ENTRY_EXITS{
public:
    EXIT_TUTORIAL_ENTRY_ROOM1(int entry_exit_x, int entry_exit_y);
    void print(char** &m) override;
    bool interact_entry(std::list<OBJECT*>* &o) override;
    void delete_(char** &map) override;
};

class EXIT_ROOM1_ENTRY_TUTORIAL: public ENTRY_EXITS{
public:
    EXIT_ROOM1_ENTRY_TUTORIAL(int entry_exit_x, int entry_exit_y);
    void print(char** &m) override;
    bool interact_entry(std::list<OBJECT*>* &o) override;
    void delete_(char** &map) override;
};

class EXIT_ROOM1_ENTRY_ROOM2: public ENTRY_EXITS{
public:
    EXIT_ROOM1_ENTRY_ROOM2(int entry_exit_x, int entry_exit_y);
    void print(char** &m) override;
    bool interact_entry(std::list<OBJECT*>* &o) override;
    void delete_(char** &map) override;
};

class EXIT_ROOM1_ENTRY_HALLWAY: public ENTRY_EXITS{
public:
    EXIT_ROOM1_ENTRY_HALLWAY(int entry_exit_x, int entry_exit_y);
    void print(char** &m) override;
    bool interact_entry(std::list<OBJECT*>* &o) override;
    void delete_(char** &map) override;
};

class EXIT_ROOM1_ENTRY_ROOM5: public ENTRY_EXITS{
public:
    EXIT_ROOM1_ENTRY_ROOM5(int entry_exit_x, int entry_exit_y);
    void print(char** &m) override;
    bool interact_entry(std::list<OBJECT*>* &o) override;
    void delete_(char** &map) override;
};

class TUTORIAL:public MAP{
public:
    TUTORIAL();
    void fill_map() override;
};

class ROOM1:public MAP{
public:
    ROOM1();
    void fill_map() override;
};

class EXIT_ROOM2_ENTRY_ROOM1: public ENTRY_EXITS{
public:
    EXIT_ROOM2_ENTRY_ROOM1(int entry_exit_x, int entry_exit_y);
    void print(char** &m) override;
    bool interact_entry(std::list<OBJECT*>* &o) override;
    void delete_(char** &map) override;
};

class EXIT_ROOM2_ENTRY_BASEMENT: public ENTRY_EXITS{
public:
    EXIT_ROOM2_ENTRY_BASEMENT(int entry_exit_x, int entry_exit_y);
    void print(char** &m) override;
    bool interact_entry(std::list<OBJECT*>* &o) override;
    void delete_(char** &map) override;
};

class ROOM2:public MAP{
public:
    ROOM2();
    void fill_map() override;
};

class EXIT_BASEMENT_ENTRY_ROOM2: public ENTRY_EXITS{
public:
    EXIT_BASEMENT_ENTRY_ROOM2(int entry_exit_x, int entry_exit_y);
    void print(char** &m) override;
    bool interact_entry(std::list<OBJECT*>* &o) override;
    void delete_(char** &map) override;
};

class BASEMENT:public MAP{
public:
    BASEMENT();
    void fill_map() override;
};

class EXIT_HALLWAY_ENTRY_ROOM1: public ENTRY_EXITS{
public:
    EXIT_HALLWAY_ENTRY_ROOM1(int entry_exit_x, int entry_exit_y);
    void print(char** &m) override;
    bool interact_entry(std::list<OBJECT*>* &o) override;
    void delete_(char** &map) override;
};

class EXIT_HALLWAY_ENTRY_ROOM3: public ENTRY_EXITS{
public:
    EXIT_HALLWAY_ENTRY_ROOM3(int entry_exit_x, int entry_exit_y);
    void print(char** &m) override;
    bool interact_entry(std::list<OBJECT*>* &o) override;
    void delete_(char** &map) override;
};

class HALLWAY:public MAP{
public:
    HALLWAY();
    void fill_map() override;
};

class EXIT_ROOM3_ENTRY_HALLWAY: public ENTRY_EXITS{
public:
    EXIT_ROOM3_ENTRY_HALLWAY(int entry_exit_x, int entry_exit_y);
    void print(char** &m) override;
    bool interact_entry(std::list<OBJECT*>* &o) override;
    void delete_(char** &map) override;
};

class EXIT_ROOM3_ENTRY_ROOM4: public ENTRY_EXITS{
public:
    EXIT_ROOM3_ENTRY_ROOM4(int entry_exit_x, int entry_exit_y);
    void print(char** &m) override;
    bool interact_entry(std::list<OBJECT*>* &o) override;
    void delete_(char** &map) override;
};

class EXIT_ROOM3_ENTRY_ROOM6: public ENTRY_EXITS{
public:
    EXIT_ROOM3_ENTRY_ROOM6(int entry_exit_x, int entry_exit_y);
    void print(char** &m) override;
    bool interact_entry(std::list<OBJECT*>* &o) override;
    void delete_(char** &map) override;
};

class EXIT_ROOM6_ENTRY_ROOM3: public ENTRY_EXITS{
public:
    EXIT_ROOM6_ENTRY_ROOM3(int entry_exit_x, int entry_exit_y);
    void print(char** &m) override;
    bool interact_entry(std::list<OBJECT*>* &o) override;
    void delete_(char** &map) override;
};

class ROOM3:public MAP{
public:
    ROOM3();
    void fill_map() override;
};

class EXIT_ROOM4_ENTRY_ROOM3: public ENTRY_EXITS{
public:
    EXIT_ROOM4_ENTRY_ROOM3(int entry_exit_x, int entry_exit_y);
    void print(char** &m) override;
    bool interact_entry(std::list<OBJECT*>* &o) override;
    void delete_(char** &map) override;
};

class ROOM4:public MAP{
public:
    ROOM4();
    void fill_map() override;
};

class EXIT_ROOM5_ENTRY_ROOM1: public ENTRY_EXITS{
public:
    EXIT_ROOM5_ENTRY_ROOM1(int entry_exit_x, int entry_exit_y);
    void print(char** &m) override;
    bool interact_entry(std::list<OBJECT*>* &o) override;
    void delete_(char** &map) override;
};

class ROOM5:public MAP{
public:
    ROOM5();
    void fill_map() override;
};

class EXIT_ROOM5_1_ENTRY_ROOM1: public ENTRY_EXITS{
public:
    EXIT_ROOM5_1_ENTRY_ROOM1(int entry_exit_x, int entry_exit_y);
    void print(char** &m) override;
    bool interact_entry(std::list<OBJECT*>* &o) override;
    void delete_(char** &map) override;
};

class ROOM5_1:public MAP{
public:
    ROOM5_1();
    void fill_map() override;
};

class ROOM6:public MAP{
public:
    ROOM6();
    void fill_map() override;
};

void print_panel(char p[][51]);

#endif