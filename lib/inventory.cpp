#include<iostream>
#include<list>
#include<conio.h>
#include "../include/objects.h"
#include "../include/inventory.h"
#define CLEAR_SCREEN system("cls")
#define UP 'w'
#define DOWN 's'
#define UP2 'W'
#define DOWN2 'S'
#define ACTION 'e'
#define ACTION2 'E'
#define ESC 27

INVENTORY::INVENTORY(){
    this->cord_marker = 0;
}

void INVENTORY::draw_interface(){
    CLEAR_SCREEN;
    std::list<OBJECT*>::iterator itO;
    int i = 0;
    std::cout << std::endl << std::endl << std:: endl << std::endl;
    if(objects.empty()){
        std::cout << "\t\t\t\tINVENTARIO\t\t\tDESCRIPCION" << std::endl << std::endl;
        std::cout << "\t\t\t\tInventario Vacio";
    }
    else{
        std::cout << "\t\t\t\tINVENTARIO\t\t\tDESCRIPCION" << std::endl << std::endl;
        for(itO = objects.begin(); itO!=objects.end(); itO++, i++){
            std::cout << "\t\t\t\t"; i == cord_marker ? std::cout << '*' : std::cout << "o"; std::cout << "  " << (*itO)->get_name(); std::cout << "\t\t"; i == cord_marker ? std::cout << (*itO)->get_description() : std::cout << ""; std::cout << std::endl;    
        }
    }
}

void INVENTORY::move_marker(char key){
    if((key == UP || key == UP2) && cord_marker > 0) cord_marker--;
    else if((key == DOWN || key == DOWN2) && cord_marker < objects.size()-1) cord_marker++;
    CLEAR_SCREEN;
    draw_interface();
}

void INVENTORY::inventory_interface(){
    draw_interface();
    char key;
    while(true){
        if(kbhit()){
            key = getch();
            if(key == ESC) return;
            else if (key == ACTION || key == ACTION2){
                inventory_interaction();
                CLEAR_SCREEN;
                draw_interface();
            }
            else if(key == UP || key == UP2 || key == DOWN || key == DOWN2) move_marker(key);
        }
    }
}

void INVENTORY::include_item(OBJECT* &item){
    objects.push_back(item);
}

void INVENTORY::delete_item(OBJECT &item){
    std::list<OBJECT*>::iterator itO;
    for(itO = objects.begin(); itO!=objects.end(); itO++){
        if((*itO)->get_code() == item.get_code()){
            delete(*itO);
            itO = objects.erase(itO);
            return;
        }
    }
}

void INVENTORY::inventory_interaction(){
    std::list<OBJECT*>::iterator itO;
    int i = 0;
    for(itO = objects.begin(); itO != objects.end(); itO++, i++){
        if(i == cord_marker){
            (*itO)->content();
            return;
        }
    }
}