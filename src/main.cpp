#include<iostream>
#include<conio.h>
#include<chrono>
#include<list>
#include "../include/map.h"
#include "../include/avatar.h"
#define CLEAR_SCREEN system("cls")
#define ARRIBA 'w'
#define ABAJO 's'
#define IZQUIERDA 'a'
#define DERECHA 'd'

class Timer {
public:
    Timer() : start_time_(std::chrono::steady_clock::now()) {}

    float get_elapsed_time() const {
        auto end_time = std::chrono::steady_clock::now();
        auto elapsed = end_time - start_time_;
        return static_cast<float>(std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count()) / 1000.0f;
    }

private:
    std::chrono::time_point<std::chrono::steady_clock> start_time_;
};

void draw_map(CAMERA &c, AVATAR &a, MAP &m){
        
   std::cout << std::endl << std::endl << std::endl << std::endl;
    for(int i = c.get_y(); i<12; i++){
        std::cout << "\t\t\t\t";
        for(int j = c.get_x(); j<52; j++){
            if(i >= 0 && j >= 0 && i < m.get_heigth() && j < m.get_width()){
                if(j == a.get_x() && i == a.get_y()) std::cout << a.get_lowbody();
                else if(j == a.get_x() && i == a.get_y()-1) std::cout << a.get_head();
                else std::cout << m.get_map(j, i);
            }
            else{
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

void move_avatar(char key, AVATAR &a, CAMERA &c, MAP &m){
    bool in_animation = false;
    Timer timer;
    while(true){
        if(!in_animation){
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
                a.set_x(a.get_x()+1);
                a.set_dir(2);
            }
            CLEAR_SCREEN;
            a.print_animation();
            draw_map(c, a, m);
            in_animation = true;
        }
        if(timer.get_elapsed_time() >= 0.2) break;
    }

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
        a.set_x(a.get_x()+1);
        a.set_dir(2);
    }
    CLEAR_SCREEN;
    a.print_standar();
    draw_map(c, a, m);
    

}


int main(){

    MAP* map = new MAP_PRUEBA();
    map->fill_map();
    AVATAR a = AVATAR(26, 6);
    CAMERA c = CAMERA(0, 0);
    draw_map(c, a, *map);
    while(true){
        
        if(kbhit()){
            char key = getch();
            move_avatar(key, a, c, *map);
        }
    }

    return 0;
}