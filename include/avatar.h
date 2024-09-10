#ifndef AVATAR_H
#define AVATAR_H
#include "C:\Users\USER\Documents\ProyectoTutorialC++\GameJam\include/map.h"

class CAMERA{
    int x, y;
public:
    CAMERA(int x, int y);
    int get_x();
    int get_y();
};

class AVATAR{
    int x, y;
    int dir;
public:
    AVATAR(int _x, int _y);
    int get_x();
    int get_y();
    void set_x(int x);
    void set_y(int y);
    int get_dir();
    void set_dir(int d);
    void print_standar(MAP &m);
    void print_animation(MAP &m);
    void delte_(MAP &m);
    bool colision(MAP &m);
};


#endif