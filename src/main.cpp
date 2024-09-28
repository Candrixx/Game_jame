#include<iostream>
#include<conio.h>
#include<chrono>
#include<list>
#include<windows.h>
#include "../include/map.h"
#include "../include/avatar.h"
#include "../include/objects.h"
#include "../include/timer.h"
#include "../include/pause_menu.h"

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

bool cinematic_1_flag = false;
bool cinematic_2_flag = false;
bool entry_room_2_1_flag = false;

void remove_cursor(){
    HANDLE encabezado;
    encabezado = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO f_cursor;
    f_cursor.dwSize = 1;
    f_cursor.bVisible = FALSE;

    SetConsoleCursorInfo(encabezado, &f_cursor);
}


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

void cinematic_1(MAP* &m, CAMERA &c, AVATAR &a){
    cinematic_1_flag = true;
    std::list<ENTRY_EXITS*>* e = m->get_entries_exits();
    std::list<ENTRY_EXITS*>::iterator itE;
    char** map = m->get_map_matriz();
    for(int i=0; i<3; i++){
        move_avatar('d', a, c, m);
        Timer t;
        while(true){
            if(t.get_elapsed_time() >= 0.8) break;
        }
    }
    for(itE = e->begin(); itE!=e->end(); itE++){
        if((*itE)->get_code() == 2){
            (*itE)->delete_(map);
        }
    }
    CLEAR_SCREEN;
    draw_map(c, a, m);
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\t*BAM*";
    Timer t;
    while(true){
        if(t.get_elapsed_time() >= 2) break;
    }
    move_avatar('a', a, c, m);
    Timer tim;
    while(true){
        if(tim.get_elapsed_time() >= 1.5) break;
    }
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\t";
    for(int i=0; i<3; i++){
        std::cout << ".";
        Timer ti;
        while(true){
            if(ti.get_elapsed_time() >= 1) break;
        }
    }
    CLEAR_SCREEN;
    draw_map(c, a, m);
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\t";
    std::string text = "La puerta acaba de desaparecer?????????";
    for(int i = 0; i < text.length(); i++){
        std::cout << text[i];
        Timer ti;
        while(true){
            if(ti.get_elapsed_time() >= 0.02) break;
        }
    }
    Timer time;
    while(true){
        if(time.get_elapsed_time() >= 2) break;
    }
    return;
}

void cinematic_2(MAP* &m, CAMERA &c, AVATAR &a){
    std::string text[3];
    text[0] = "Uh.. Esta algo oscuro y no puedo ver bien que es...";
    text[1] = "Mis ojos parecen acostumbrarse a la oscuridad.";
    text[2] = "A ver...";
    CLEAR_SCREEN;
    draw_map(c, a, m);
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\t";
    for(int i=0; i<3; i++){
        for(int j=0; j<text[i].length(); j++){
            std::cout << text[i][j];
            Timer time;
            while(true){
                if(time.get_elapsed_time() >= 0.02) break;
            }
        }
        Timer time;
        while(true){
            if(time.get_elapsed_time() >= 1.8) break;
        }
        CLEAR_SCREEN;
        draw_map(c, a, m);
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\t";
    }
    Timer time;
    while(true){
        if(time.get_elapsed_time() >= 0.2) break;
    }
    std::cout << "!!!!!!!!!!!!!!!!!!!";
    Timer time2;
    while(true){
        if(time2.get_elapsed_time() >= 1.2) break;
    }
    for(int i=0; i<2; i++){
        move_avatar('d', a, c, m);
        Timer time;
        while(true){
            if(time.get_elapsed_time() >= 2.2) break;
        }
    }
    text[0] = "Que cara.....";
    text[1] = "Porque hay un... Bleeeeeeeeeeegh.";
    text[2] = "Tengo que salir de aqui.";
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\t";
    for(int i=0; i<3; i++){
        for(int j=0; j<text[i].length(); j++){
            std::cout << text[i][j];
            Timer time;
            while(true){
                if(time.get_elapsed_time() >= 0.02) break;
            }
        }
        Timer time;
        while(true){
            if(time.get_elapsed_time() >= 1.8) break;
        }
        CLEAR_SCREEN;
        draw_map(c, a, m);
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\t";
    }
    return;
}

void move_map_objects(MAP* &m, AVATAR &a, CAMERA &c){
    char ** matriz = m->get_map_matriz(); 
    MAP_OBJECT* map_object;
    if(!a.interact_map_objects(*m, map_object)) return;
    if(map_object->get_moved()){
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tNo parece que se pueda mover mas." << std::endl << std::endl;
        std::cout << "\t\t\t\tCERRAR: ESC";
        while(true){
            if(kbhit()){
                char key = getch();
                if(key == ESC) return;
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

void draw_menu_interaction(MAP* &m, AVATAR &a, CAMERA &c, MAP_OBJECT* map_object, std::list<OBJECT*>* &objects, int cmmi){
    char** map = m->get_map_matriz();
    std::list<OBJECT*>::iterator itO;
    int i;
    if(map_object->get_name() == "Cadaver" && !cinematic_2_flag){
        cinematic_2(m, c, a);
        return;
    }
    if(map_object->get_name() == "Recuadro " && objects->empty()){
        map_object->get_interact_empty(map);
        if(picture_flag){
            CLEAR_SCREEN;
            draw_map(c, a, m);
        }
        else return;
    }
    if(objects->empty()){
        map_object->get_interact_empty(map);
        if(map_object->get_name() == "Armario con Mecanismo" && !lights_out_flag){
            CLEAR_SCREEN;
            draw_map(c, a, m);
            return;
        }
        else if(map_object->get_name() == "Palanca" && !error_order_levers_flag && (!lever_1_flag || !lever_2_flag || !lever_3_flag || !lever_4_flag || !lever_5_flag)){
            CLEAR_SCREEN;
            draw_map(c, a, m);
            return;
        }
        else if(map_object->get_name() == "Palanca" && entry_room_2_1_flag && lever_1_flag && lever_2_flag && lever_3_flag && lever_4_flag && lever_5_flag) return;
        else if(map_object->get_name() == "Palanca" && !entry_room_2_1_flag && lever_1_flag && lever_2_flag && lever_3_flag && lever_4_flag && lever_5_flag){
            if(m->get_name() == "Taller"){
                std::list<ENTRY_EXITS*>* e = m->get_entries_exits();
                std::list<ENTRY_EXITS*>::iterator itE;
                e->push_back(new EXIT_ROOM2_ENTRY_BASEMENT(13, 23));
                for(itE = e->begin(); itE!=e->end(); itE++){
                    if((*itE)->get_code() == 48){
                        (*itE)->print(map);
                        break;
                    } 
                }
                
            }
            CLEAR_SCREEN;
            draw_map(c, a, m);
            std::cout << std::endl << std::endl;
            std::cout << "\t\t\t\tAcaba de aparecer una puerta en el suelo de la habitacion.";
        }
        else if(map_object->get_name() == "Palanca" && error_order_levers_flag){
            std::list<MAP_OBJECT*>* mo = m->get_map_objects();
            std::list<MAP_OBJECT*>::iterator itMO;
            for(itMO = mo->begin(); itMO!=mo->end(); itMO++){
                if((*itMO)->get_name() == "Palanca") (*itMO)->print(map);
            }
            CLEAR_SCREEN;
            draw_map(c, a, m);
            std::cout << std::endl << std::endl;
            std::cout << "\t\t\t\tUh, parece que el orden de activacion no es correcto.";
        }
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\tCERRAR: ESC";
    }
    else{
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t\t" << map_object->get_name() << std::endl;
        for(i = 0, itO = objects->begin(); itO != objects->end(); i++, itO++){
            if(i == 5) break;
           std::cout << "\t\t\t\t"; i == cmmi ? std::cout << "*" : std::cout << "o"; std::cout << " " << (*itO)->get_name() << std::endl;
        }
        std::cout << std::endl << "\t\t\t\tTOMAR: E           CERRAR: ESC";
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
                    a.set_x((*itE)->get_entry_exit_x()+1);
                    a.set_y((*itE)->get_entry_exit_y()+1);
                    c.set_y(a.get_y()-6);
                    c.set_x(a.get_x()-26);
                    if(!cinematic_1_flag && (*itE)->get_code() == 2) cinematic_1(m, c, a);
                    return;
                }
                else return;
            }
        }
    }
}

void pick_up_item(MAP* &m, AVATAR &a, CAMERA &c){
    std::list<OBJECT*>* o = m->get_player_objects();
    std::list<OBJECT*>::iterator itO;
    char key;
    OBJECT* item;
    char** map = m->get_map_matriz();
    if(!a.interact_objects(*m, item)) return;
    a.take_object(item);
    item->delete_(map);
    item->set_x(0);
    item->set_y(0);
    for(itO = o->begin(); itO!=o->end(); itO++){
        if((*itO)->get_code() == item->get_code()){
            itO = o->erase(itO);
            break;
        }
    }
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\t\t" << item->get_interact_text() << std::endl << std::endl;
    std::cout << "\t\t\t\tCERRAR: ESC";
    while(true){
        if(kbhit()){
            key = getch();
            if(key == ESC) return;
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
    draw_menu_interaction(m, a, c, map_object, o, cmmi);
    if(map_object->get_name() == "Armario con Mecanismo" && !lights_out_flag) return;
    else if(map_object->get_name() == "Palanca" && !error_order_levers_flag && (!lever_1_flag || !lever_2_flag || !lever_3_flag || !lever_4_flag || !lever_5_flag)) return;
    else if(map_object->get_name() == "Palanca" && error_order_levers_flag) error_order_levers_flag = false;
    else if(map_object->get_name() == "Palanca" && entry_room_2_1_flag && lever_1_flag && lever_2_flag && lever_3_flag && lever_4_flag && lever_5_flag) return;
    else if(map_object->get_name() == "Palanca" && !entry_room_2_1_flag && lever_1_flag && lever_2_flag && lever_3_flag && lever_4_flag && lever_5_flag) entry_room_2_1_flag = true;
    else if(map_object->get_name() == "Recuadro " && !picture_flag) return;
    else if(map_object->get_name() == "Cadaver" && !cinematic_2_flag){
        cinematic_2_flag = true;
        return;
    }
    while(true){
        if(kbhit()){
            key = getch();
            if(key == ACTION || key == ACTION2){
                take_object(o, cmmi, a);
                CLEAR_SCREEN;
                draw_map(c, a, m);
                draw_menu_interaction(m, a, c, map_object, o, cmmi);
            }
            else if(key == UP || key == UP2 || key == DOWN || key == DOWN2){
                move_cmmi(key, cmmi, o);
                CLEAR_SCREEN;
                draw_map(c, a, m);
                draw_menu_interaction(m, a, c, map_object, o, cmmi);
            }
            else if(key == ESC) return;
        }
    }
}

void intro(std::list<MAP*> &maps, MAP* &map){
    std::list<MAP*>::iterator itM;
    char key;
    bool flag = false;
    std::string text1 = "\t\t\tDetras de cada puerta cerrada se esconde un secreto, y detras de cada secreto,\n\n\t\t\tuna verdad. En este juego, te sumergiras en un mundo lleno de enigmas y misterios.\n\n\t\t\tEstas listo para descubrir el precio de la libertad y desvelar los secretos que se\n\n\t\t\tesconden en la sombra?";
    std::string text2 = "\t\t\tLa libertad no es gratis; es una deuda que se paga dia a dia con el sudor de nuestro\n\n\t\t\tesfuerzo y el ingenio de nuestra mente.\n\n\n\t\t\tEstas dispuesto a pagar el precio de la libertad?";
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
    remove_cursor();
    std::list<MAP*> maps;
    maps.push_back(new TUTORIAL());
    maps.push_back(new ROOM1());
    maps.push_back(new ROOM2());
    maps.push_back(new BASEMENT());
    maps.push_back(new HALLWAY());
    maps.push_back(new ROOM3());
    maps.push_back(new MAP_PRUEBA2());
    maps.push_back(new MAP_PRUEBA());
    MAP* map = (*maps.begin());
    AVATAR a = AVATAR(10, 8);
    char key;
    CAMERA c = CAMERA(a.get_x()-26, a.get_y()-6);
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
                change_map(maps, map, a, c);
                menu_interact(map, a, c);
                pick_up_item(map, a, c);
                CLEAR_SCREEN;
                draw_map(c, a, map);
            }
            else if(key == MOVE_OBJECT || key == MOVE_OBJECT2){
                move_map_objects(map, a, c);
                CLEAR_SCREEN;
                draw_map(c, a, map);              
            }
            else if (key == UP || key == UP2 || key == DOWN || key == DOWN2 || key == LEFT || key == LEFT2 || key == RIGHT || key == RIGHT2)
                move_avatar(key , a, c, map);
            
            else if(key == ESC){
                if(run_pause_menu()){
                    return 0;
                }
                else{
                    draw_map(c, a, map);
                    continue;
                }
            } 
        }   
    }

    return 0;
}