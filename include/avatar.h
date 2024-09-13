#ifndef AVATAR_H
#define AVATAR_H
#include "../include/map.h"
#include "../include/map_objects.h"

class CAMERA{
    int x, y;
public:
    CAMERA(int x, int y);
    int get_x();
    int get_y();
    void set_x(int _x);
    void set_y(int _y);
};

class AVATAR{
    int x, y;
    int dir;
    char head;
    char low_body;
public:
    AVATAR(int _x, int _y);
    int get_x();
    int get_y();
    char get_head();
    char get_lowbody();
    void set_x(int x);
    void set_y(int y);
    int get_dir();
    void set_dir(int d);
    void print_animation();
    void print_standar();
    bool collides(MAP &m);
    bool is_behind(MAP &m, int c);
};


#endif