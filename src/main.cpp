#include<iostream>
#include<conio.h>
#include<chrono>
#include<list>
#include "../include/map.h"
#include "../include/avatar.h"
#include "../include/lights_out.h"
#include "../include/objects.h"

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
#define MOVE_OBJECT 'r'
#define MOVE_OBJECT2 'R'

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

void draw_map(CAMERA &c, AVATAR &a, MAP* &m){
        
   std::cout << std::endl << std::endl << std::endl << std::endl;
   std::cout << "\t\t\t\t" << m->get_name() << std::endl;
    for(int i = c.get_y(); i<12 + c.get_y(); i++){
        std::cout << "\t\t\t\t";
        for(int j = c.get_x(); j<52 + c.get_x(); j++){
            if(i >= 0 && j >= 0 && i < m->get_heigth() && j < m->get_width()){
                if(j == a.get_x() && i == a.get_y() && i < m->get_heigth()-4 && !a.is_behind(*m, 0)) std::cout << a.get_lowbody();
                else if(j == a.get_x() && i == a.get_y()-1 && i < m->get_heigth()-4 && !a.is_behind(*m, 1)) std::cout << a.get_head();
                else std::cout << m->get_map(j, i);
            }
            else{
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

void move_map_objects(MAP* &m, AVATAR &a, CAMERA &c){
    char ** matriz = m->get_map_matriz(); 
    MAP_OBJECT* map_object;
    if(!a.interact_map_objects(*m, map_object)) return;
    if(map_object->get_moved()){
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tNo parece que se pueda mover mas";
        while(true){
            if(kbhit()){
                if(true) return;
            }
        }
    }
    else if(!map_object->get_moved()){
        map_object->move(matriz, a.get_dir(), m->get_heigth(), m->get_width());
        m->fill_map();
        m->print_elements_map();
        return;
    }
}

void draw_pause_menu() {

    std::cout << "\t\t\t\t\tPAUSA" << std::endl << std::endl << std::endl << std::endl;
    std::cout << "\t\t\t\tReanudar" << std::endl;
}

void draw_menu_interaction(MAP_OBJECT* map_object, std::list<OBJECT*>* &objects, int cmmi){
    std::list<OBJECT*>::iterator itO;
    int i;
    if(objects->empty()){
        map_object->get_interact_empty();
    }
    else{
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\t" << map_object->get_name() << std::endl;
        for(i = 0, itO = objects->begin(); itO != objects->end(); i++, itO++){
            if(i == 5) break;
           std::cout << "\t\t\t\t"; i == cmmi ? std::cout << "*" : std::cout << "o"; std::cout << " " << (*itO)->get_name() << std::endl;
        }
        std::cout << std::endl << "\t\t\t\tTOMAR: E";
    }
}

void move_cmmi(char key,int &cmmi, std::list<OBJECT*>* &objects){
    if((key == UP || key == UP2) && cmmi > 0) cmmi--;
    else if((key == DOWN || key == DOWN) && cmmi < 5 && cmmi < objects->size()-1) cmmi++;
}

void take_object(std::list<OBJECT*>* &objects, int &cmmi, AVATAR &a){
    std::list<OBJECT*>::iterator itO;
    int i = 0;
    if(objects->empty()) return;
    else{
        for(itO = objects->begin(); itO != objects->end(); itO++, i++){
            if(i == cmmi){
                a.take_object((*itO));
                itO = objects->erase(itO);
                cmmi = 0;
                return;
            }
        }
    }
}

void change_map(std::list<MAP*> &maps, MAP* &m, AVATAR &a, CAMERA &c){
    ENTRY_EXITS* entry_exit;
    std::list<ENTRY_EXITS*>* e;
    std::list<ENTRY_EXITS*>::iterator itE;
    std::list<MAP*>::iterator itM;
    std::list<OBJECT*>* o = a.get_inventory()->get_objects() ;
    if(!a.interact_entrys_exits(*m, entry_exit)) return;
    for(itM = maps.begin(); itM != maps.end(); itM++){
        e = (*itM)->get_entries_exits();
        for(itE = e->begin(); itE != e->end(); itE++){
            if(entry_exit->get_code()+1 == (*itE)->get_code() || entry_exit->get_code()-1 == (*itE)->get_code()){
                if((*itE)->interact_entry(o)){
                    m = (*itM);
                    a.set_x((*itE)->get_entry_exit_x());
                    a.set_y((*itE)->get_entry_exit_y());
                    c.set_y(a.get_y()-6);
                    c.set_x(a.get_x()-26);
                    return;
                }
                else return;
            }
        }
    }
}

void pick_up_item(MAP* &m, AVATAR &a, CAMERA &c){
    char key;
    OBJECT* item;
    char** map = m->get_map_matriz();
    if(!a.interact_objects(*m, item)) return;
    a.take_object(item);
    item->delete_(map);
    item->set_x(0);
    item->set_y(0);
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\t" << item->get_interact_text();
    while(true){
        if(kbhit()){
            key = getch();
            if(false);
            else return;
        }
    }
}

void menu_interact(MAP* &m, AVATAR &a, CAMERA &c){
    MAP_OBJECT* map_object;
    std::list<OBJECT*>* o;
    int cmmi = 0;
    char key = ' ';
    if(!a.interact_map_objects(*m, map_object)) return;
    o = map_object->get_objects();
    CLEAR_SCREEN;
    draw_map(c, a, m);
    draw_menu_interaction(map_object, o, cmmi);
    while(true){
        if(kbhit()){
            key = getch();
            if(key == ACTION || key == ACTION2){
                take_object(o, cmmi, a);
                CLEAR_SCREEN;
                draw_map(c, a, m);
                draw_menu_interaction(map_object, o, cmmi);
            }
            else if(key == UP || key == UP2 || key == DOWN || key == DOWN2){
                move_cmmi(key, cmmi, o);
                CLEAR_SCREEN;
                draw_map(c, a, m);
                draw_menu_interaction(map_object, o, cmmi);
            }
            else return;
        }
    }
}

void move_avatar(char key, AVATAR &a, CAMERA &c, MAP* &m){
    bool in_animation = false;
    Timer timer;
    while(true){
        if(!in_animation){
            if((key == UP || key == UP2) && a.get_y()-4 >= 0){
                a.set_dir(1);
                if(!a.collides(*m)){
                    a.set_y(a.get_y()-1);
                    c.set_y(a.get_y()-6);
                    c.set_x(a.get_x()-26);
                }
            }
            else if((key == DOWN || key == DOWN2) && a.get_y()+1 < m->get_heigth()){
                a.set_dir(3);
                if(!a.collides(*m)){
                    a.set_y(a.get_y()+1);
                    c.set_y(a.get_y()-6);
                    c.set_x(a.get_x()-26);
                }
            }
            else if((key == LEFT || key == LEFT2) && a.get_x()-2 >= 0){
                a.set_dir(4);
                if(!a.collides(*m)){
                    a.set_x(a.get_x()-1);
                    c.set_y(a.get_y()-6);
                    c.set_x(a.get_x()-26);
                }
            }
            else if((key == RIGHT || key == RIGHT2) && a.get_x()+2 < m->get_width()){
                a.set_dir(2);
                if(!a.collides(*m)){
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
        if(!a.collides(*m)){
            a.set_y(a.get_y()-1);
            c.set_y(a.get_y()-6);
            c.set_x(a.get_x()-26);
        }
    }
    else if((key == DOWN || key == DOWN2) && a.get_y()+1 < m->get_heigth()){
        a.set_dir(3);
        if(!a.collides(*m)){
            a.set_y(a.get_y()+1);
            c.set_y(a.get_y()-6);
            c.set_x(a.get_x()-26);
        }
    }
    else if((key == LEFT || key == LEFT2) && a.get_x()-2 >= 0){
        a.set_dir(4);
        if(!a.collides(*m)){
            a.set_x(a.get_x()-1);
            c.set_y(a.get_y()-6);
            c.set_x(a.get_x()-26);
        }
    }
    else if((key == RIGHT || key == RIGHT2) && a.get_x()+2 < m->get_width()){
        a.set_dir(2);
        if(!a.collides(*m)){
            a.set_x(a.get_x()+1);
            c.set_y(a.get_y()-6);
            c.set_x(a.get_x()-26);
        }
    }
    CLEAR_SCREEN;
    a.print_standar();
    draw_map(c, a, m);
}

void intro(std::list<MAP*> &maps, MAP* &map){
    std::list<MAP*>::iterator itM;
    char key;
    bool flag = false;
    std::string text1 = "\t\t\tDetras de cada puerta cerrada se esconde un secreto, y detras de cada secreto,\n\n\t\t\tuna verdad. En este juego, te sumergiras en un mundo lleno de enigmas y misterios.\n\n\t\t\tEstas listo para descubrir el precio de la libertad y desvelar los secretos que se\n\n\t\t\tesconden en la sombra?";
    std::string text2 = "\t\t\tNelson Mandela dijo: 'La libertad es el precio de la valentia'.\n\n\t\t\tLa libertad no es gratis; es una deuda que se paga dia a dia con el sudor de nuestro\n\n\t\t\tesfuerzo y el ingenio de nuestra mente.\n\n\n\t\t\tEstas dispuesto a pagar el precio de la libertad?";
    std::string* pointer = &text1;
    
    while(true){
        std::cout  << std::endl << std::endl << std::endl << std::endl << std::endl;
        for(int i=0; i<(*pointer).length(); i++){
            std::cout << (*pointer)[i];
            Timer timer;
            while(true){
                if(timer.get_elapsed_time() >= 0.03) break;
            }
            if(kbhit()){
                key = getch();
                if(key == ACTION || key == ACTION2){
                    CLEAR_SCREEN;
                    return;
                }
                if(key == INVENTORY || key == INVENTORY2){
                    for(itM = maps.begin(); itM != maps.end(); itM++){
                        if((*itM)->get_name() == "Mapa Prueba"){
                            map = (*itM);
                        }
                    }
                }
            }
        }
        Timer t;
        while(true){
            if(t.get_elapsed_time() >= 5) break;
        }
        CLEAR_SCREEN;
        if(flag) return;
        pointer = &text2;
        flag = true;
    }
}


int main(){
    std::list<MAP*> maps;
    std::list<MAP*>::iterator itM;
    maps.push_back(new MAP_PRUEBA2());
    maps.push_back(new MAP_PRUEBA());
    itM = maps.begin();
    MAP* map = (*itM);
    AVATAR a = AVATAR(26, 6);
    char key;
    CAMERA c = CAMERA(0, 0);
    intro(maps, map);
    draw_map(c, a, map);
    while(true){
        
        if(kbhit()){
            key = getch();
            if(key == INVENTORY || key == INVENTORY2){
                a.open_inventory();
                CLEAR_SCREEN;
                draw_map(c, a, map);
            }
            else if(key == ACTION || key == ACTION2) {
                menu_interact(map, a, c);
                change_map(maps, map, a, c);
                pick_up_item(map, a, c);
                CLEAR_SCREEN;
                draw_map(c, a, map);
                // CLEAR_SCREEN;
                // run_lights_out();
                // draw_map(c, a, *map);
            }
            else if(key == MOVE_OBJECT || key == MOVE_OBJECT2){
                move_map_objects(map, a, c);
                CLEAR_SCREEN;
                draw_map(c, a, map);              
            }
            else if (key == UP || key == UP2 || key == DOWN || key == DOWN2 || key == LEFT || key == LEFT2 || key == RIGHT || key == RIGHT2)
                move_avatar(key , a, c, map);
            
                

        }
    }

    return 0;
}