#ifndef INVENTORY_H
#define INVENTORY_H
#include<iostream>
#include<list>
#include "../include/objects.h"

class INVENTORY{
    std::list<OBJECT*> objects;
    int cord_marker;
    int cor_cam;
    int cant_letters, cant_others;
    bool page;
public:
    INVENTORY();
    void inventory_interface();
    void draw_interface();
    void count_cant_letters();
    void include_item(OBJECT* &item);
    void delete_item(OBJECT &item);
    void move_marker(char key);
    void inventory_interaction();
};

#endif