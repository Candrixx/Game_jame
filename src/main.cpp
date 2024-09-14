#include<iostream>
#include<conio.h>
#include<chrono>
#include<list>
#include "../include/map.h"
#include "../include/avatar.h"
#include "../include/lights_out.h"


#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define UP2 'W'
#define DOWN2 'S'
#define LEFT2 'A'
#define RIGHT2 'D'
#define ACTION 'e'
#define ACTION2 'E'
#define INVENTORY 'i'
#define INVENTORY2 'I'

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
   std::cout << "\t\t\t\t" << m.get_name() << std::endl;
    for(int i = c.get_y(); i<12 + c.get_y(); i++){
        std::cout << "\t\t\t\t";
        for(int j = c.get_x(); j<52 + c.get_x(); j++){
            if(i >= 0 && j >= 0 && i < m.get_heigth() && j < m.get_width()){
                if(j == a.get_x() && i == a.get_y() && i < m.get_heigth()-4 && !a.is_behind(m, 0)) std::cout << a.get_lowbody();
                else if(j == a.get_x() && i == a.get_y()-1 && i < m.get_heigth()-4 && !a.is_behind(m, 1)) std::cout << a.get_head();
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
            if((key == UP || key == UP2) && a.get_y()-4 >= 0){
                a.set_dir(1);
                if(!a.collides(m)){
                    a.set_y(a.get_y()-1);
                    c.set_y(a.get_y()-6);
                    c.set_x(a.get_x()-26);
                }
            }
            else if((key == DOWN || key == DOWN2) && a.get_y()+1 < m.get_heigth()){
                a.set_dir(3);
                if(!a.collides(m)){
                    a.set_y(a.get_y()+1);
                    c.set_y(a.get_y()-6);
                    c.set_x(a.get_x()-26);
                }
            }
            else if((key == LEFT || key == LEFT2) && a.get_x()-2 >= 0){
                a.set_dir(4);
                if(!a.collides(m)){
                    a.set_x(a.get_x()-1);
                    c.set_y(a.get_y()-6);
                    c.set_x(a.get_x()-26);
                }
            }
            else if((key == RIGHT || key == RIGHT2) && a.get_x()+2 < m.get_width()){
                a.set_dir(2);
                if(!a.collides(m)){
                    a.set_x(a.get_x()+1);
                    c.set_y(a.get_y()-6);
                    c.set_x(a.get_x()-26);
                }
            }
            CLEAR_SCREEN;
            a.print_animation();
            draw_map(c, a, m);
            in_animation = true;
        }
        if(timer.get_elapsed_time() >= 0.2) break;
    }

    if((key == UP || key == UP2) && a.get_y()-4 >= 0){
        a.set_dir(1);
        if(!a.collides(m)){
            a.set_y(a.get_y()-1);
            c.set_y(a.get_y()-6);
            c.set_x(a.get_x()-26);
        }
    }
    else if((key == DOWN || key == DOWN2) && a.get_y()+1 < m.get_heigth()){
        a.set_dir(3);
        if(!a.collides(m)){
            a.set_y(a.get_y()+1);
            c.set_y(a.get_y()-6);
            c.set_x(a.get_x()-26);
        }
    }
    else if((key == LEFT || key == LEFT2) && a.get_x()-2 >= 0){
        a.set_dir(4);
        if(!a.collides(m)){
            a.set_x(a.get_x()-1);
            c.set_y(a.get_y()-6);
            c.set_x(a.get_x()-26);
        }
    }
    else if((key == RIGHT || key == RIGHT2) && a.get_x()+2 < m.get_width()){
        a.set_dir(2);
        if(!a.collides(m)){
            a.set_x(a.get_x()+1);
            c.set_y(a.get_y()-6);
            c.set_x(a.get_x()-26);
        }
    }
    CLEAR_SCREEN;
    a.print_standar();
    draw_map(c, a, m);
    

}


int main(){

    MAP* map = new MAP_PRUEBA();
    AVATAR a = AVATAR(26, 6);
    CAMERA c = CAMERA(0, 0);
    draw_map(c, a, *map);
    while(true){
        
        if(kbhit()){
            char key = getch();
            if(key == INVENTORY || key == INVENTORY2){
                a.open_inventory();
                CLEAR_SCREEN;
                draw_map(c, a, *map);
            }
            else if(key == ACTION || key == ACTION2) {
                CLEAR_SCREEN;
                run_lights_out();
                draw_map(c, a, *map);
            }
            else if (key == UP || key == UP2 || key == DOWN || key == DOWN2 || key == LEFT || key == LEFT2 || key == RIGHT || key == RIGHT2) 
                move_avatar(key , a, c, *map);

        }
    }

    return 0;
}