#include<iostream>
#include<conio.h>
#include<list>
#include "../include/map.h"
#include "../include/avatar.h"
#define CLEAR_SCREEN system("cls")
#define ARRIBA 'w'
#define ABAJO 's'
#define IZQUIERDA 'a'
#define DERECHA 'd'

void draw_map(CAMERA &c, AVATAR &a, MAP &m){
    
    a.print_standar(m);
    
    for(int i = c.get_y(); i<12; i++){
        for(int j = c.get_x(); j<52; j++){
            if(i >= 0 && j >= 0 && i < m.get_heigth() && j < m.get_width()){
                std::cout << m.get_map(i, j);
            }
            else{
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

void move_avatar(char key, AVATAR &a, CAMERA &c, MAP &m){

    a.delte_(m);

    if(key == ARRIBA && a.get_y()-4 >= 0){
        a.set_y(a.get_y()-1);
        a.set_dir(1);
    }
    if(key == ABAJO && a.get_y() < m.get_heigth()){
        a.set_y(a.get_y()+1);
        a.set_dir(3);
    }
    if(key == IZQUIERDA && a.get_x() >= 0){
        a.set_x(a.get_x()-1);
        a.set_dir(4);
    }
    if(key == DERECHA && a.get_x() < m.get_width()){
        a.set_y(a.get_x()+1);
        a.set_dir(2);
    }

    a.print_animation(m);
    draw_map(c, a, m);

    if(key == ARRIBA && a.get_y()-4 >= 0){
        a.set_y(a.get_y()-1);
        a.set_dir(1);
    }
    if(key == ABAJO && a.get_y() < m.get_heigth()){
        a.set_y(a.get_y()+1);
        a.set_dir(3);
    }
    if(key == IZQUIERDA && a.get_x() >= 0){
        a.set_x(a.get_x()-1);
        a.set_dir(4);
    }
    if(key == DERECHA && a.get_x() < m.get_width()){
        a.set_y(a.get_x()+1);
        a.set_dir(2);
    }

    a.print_standar(m);
    draw_map(c, a, m);

}


int main(){

    MAP* map = new MAP_PRUEBA();
    AVATAR a = AVATAR(26, 6);
    CAMERA c = CAMERA(0, 0);

     draw_map(c, a, *map);
     std::cin.get();
    // while(true){
    //     draw_map(c, a, *map);
    //     if(kbhit()){
    //         char key = getch();
    //         move_avatar(key, a, c, *map);
    //     }
    //     CLEAR_SCREEN;
    // }

    return 0;
}