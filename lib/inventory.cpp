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
#define LEFT 'a'
#define RIGHT 'd'
#define LEFT2 'A'
#define RIGHT2 'D'
#define ESC 27

INVENTORY::INVENTORY(){
    this->cord_marker = 0;
    this->cor_cam = 0;
    this->cant_letters = 0;
    this->cant_others = 0;
    this->page = false;
    count_cant_letters();
}

void INVENTORY::draw_interface(){
    char l = 111, j = 42;
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
        if(page){
            for(itO = objects.begin(); itO!=objects.end(); itO++){
                if((*itO)->get_code() / 100 == 1 || (*itO)->get_code() / 100 == 4){
                    if( cor_cam <= i && i <= cor_cam + 17){
                        std::cout << "\t\t\t\t"; i == cord_marker ? std::cout << '*' : std::cout << "o"; std::cout << "  " << (*itO)->get_name(); std::cout << "\t\t"; i == cord_marker ? std::cout << (*itO)->get_description() : std::cout << ""; std::cout << std::endl;
                    }
                    i++;
                }    
            }
            std::cout << std::endl << "\t\t\t\tINSPECCIONAR: E";
            std::cout << std::endl << "\t\t\t\t\t\t\t" << l << " " << j ;
        }
        else if(!page){
            for(itO = objects.begin(); itO!=objects.end(); itO++){
                if((*itO)->get_code() / 100 != 1 && (*itO)->get_code() / 100 != 4){
                    if(cor_cam <= i && i <= cor_cam + 17){
                        std::cout << "\t\t\t\t"; i == cord_marker ? std::cout << '*' : std::cout << "o"; std::cout << "  " << (*itO)->get_name(); std::cout << "\t\t"; i == cord_marker ? std::cout << (*itO)->get_description() : std::cout << ""; std::cout << std::endl;
                    }
                    i++;
                }    
            }
            std::cout << std::endl << "\t\t\t\tINSPECCIONAR: E";
            std::cout << std::endl << "\t\t\t\t\t\t\t" << j << " " << l ;
        }
        
    }
}

void INVENTORY::move_marker(char key){
    
    if(!page){
        if((key == UP || key == UP2) && cord_marker > 0){
            cord_marker--;
            if(cord_marker < cor_cam || cord_marker > cor_cam + 17) cor_cam--;
        }
        else if((key == DOWN || key == DOWN2) && cord_marker < objects.size()-1 && cord_marker < cant_others-1){
            cord_marker++;
            if(cord_marker < cor_cam || cord_marker > cor_cam + 17) cor_cam++;
        }
    }
    else if(page){
        if((key == UP || key == UP2) && cord_marker > 0){
            cord_marker--;
            if(cord_marker < cor_cam || cord_marker > cor_cam + 17) cor_cam--;
        }
        else if((key == DOWN || key == DOWN2) && cord_marker < objects.size()-1 && cord_marker < cant_letters-1){
            cord_marker++;
            if(cord_marker < cor_cam || cord_marker > cor_cam + 17) cor_cam++;
        }
    }
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
            else if(key == LEFT || key == LEFT2 || key == RIGHT || key == RIGHT2){
                page = !page;
                cord_marker = 0;
                CLEAR_SCREEN;
                draw_interface();
            }
        }
    }
}

void INVENTORY::include_item(OBJECT* &item){
    std::list<OBJECT*>::iterator itO;
    for(itO = objects.begin(); itO!=objects.end(); itO++){
        if(item->get_code() == (*itO)->get_code()) return;
    }
    if(item->get_code() / 100 == 1 || item->get_code() / 100 == 4) cant_letters+=1;
    else cant_others+=1;
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
    if(objects.empty()) return;
    if(page){
            for(itO = objects.begin(); itO!=objects.end(); itO++){
                if((*itO)->get_code() / 100 == 1 || (*itO)->get_code() / 100 == 4){
                    if( cor_cam <= i && i <= cor_cam + 17){
                        if(cord_marker == i){
                            (*itO)->content();
                            return;
                        }
                    }
                    i++;
                }    
            }
        }
        else if(!page){
            for(itO = objects.begin(); itO!=objects.end(); itO++){
                if((*itO)->get_code() / 100 != 1 && (*itO)->get_code() / 100 != 4){
                    if(cor_cam <= i && i <= cor_cam + 17){
                        if(cord_marker == i){
                            (*itO)->content();
                            return;
                        }
                    }
                    i++;
                }    
            }
        }
}

void INVENTORY::count_cant_letters(){
    std::list<OBJECT*>::iterator itO;
    for(itO = objects.begin(); itO != objects.end(); itO++){
        if((*itO)->get_code() / 100 == 1 || (*itO)->get_code() / 100 == 4){
            cant_letters+=1;
        }
        else if ((*itO)->get_code() / 100 != 1 && (*itO)->get_code() / 100 != 4){
            cant_others+=1;
        }
    }
}