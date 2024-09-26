#ifndef MAP_OBJECTS_H
#define MAP_OBJECTS_H
#include<iostream>
#include<string.h>
#include<list>
#include "../include/objects.h"

extern bool lights_out_flag;
extern bool lever_1_flag;
extern bool lever_2_flag;
extern bool lever_3_flag;
extern bool lever_4_flag;
extern bool lever_5_flag;
extern bool error_order_levers_flag;
extern bool picture_flag;

class MAP_OBJECT{
    std::string name;
    std::string text_empty;
    bool moved;
    int up_left_x;
    int up_left_y;
    int bot_right_x;
    int bot_right_y;
    int object_heigth;
    std::list<OBJECT*> objects;
public:
    MAP_OBJECT(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y, std::string name, int object_heigth);
    std::string get_name(){ return name;}
    int get_up_left_x();
    int get_up_left_y();
    int get_bot_right_x();
    int get_bot_right_y();
    int get_object_heigth();
    bool get_moved();
    virtual void get_interact_empty(char** &map) = 0;
    void set_up_left_x(int _x);
    void set_up_left_y(int _y);
    void set_bot_right_x(int _x);
    void set_bot_right_y(int _y);
    void set_object_heigth(int _higth);
    void set_moved(bool m);
    virtual void print(char** &map) = 0;
    virtual void delete_(char** &map) = 0;
    virtual void move(char** &m, int const &dir, int const &higth, int const &width) = 0;
    std::list<OBJECT*>* get_objects();
};

class CUPBOARD:public MAP_OBJECT{
public:
    CUPBOARD(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y);
    void print(char** &map) override;
    void delete_(char** &m) override;
    void get_interact_empty(char** &map) override;
    void move(char** &m, int const &dir, int const &higth, int const &width) override;
};

class CUPBOARD_ESPECIAL:public MAP_OBJECT{
public:
    CUPBOARD_ESPECIAL(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y);
    void print(char** &map) override;
    void delete_(char** &m) override;
    void get_interact_empty(char** &map) override;
    void move(char** &m, int const &dir, int const &higth, int const &width) override;
};

class TABLE:public MAP_OBJECT{
public:
    TABLE(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y);
    void print(char** &map) override;
    void delete_(char** &m) override;
    void get_interact_empty(char** &map) override;
    void move(char** &m, int const &dir, int const &higth, int const &width) override;
};

class BOX:public MAP_OBJECT{
public:
    BOX(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y);
    void print(char** &map) override;
    void delete_(char** &m) override;
    void get_interact_empty(char** &map) override;
    void move(char** &m, int const &dir, int const &higth, int const &width) override;
};

class TABLE_TUTORIAL:public MAP_OBJECT{
public:
    TABLE_TUTORIAL(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y);
    void print(char** &map) override;
    void delete_(char** &m) override;
    void get_interact_empty(char** &map) override;
    void move(char** &m, int const &dir, int const &higth, int const &width) override;
};

class WINDOW:public MAP_OBJECT{
public:
    WINDOW(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y);
    void print(char** &map) override;
    void delete_(char** &m) override;
    void get_interact_empty(char** &map) override;
    void move(char** &m, int const &dir, int const &higth, int const &width) override;
};

class BOX_TUTORIAL:public MAP_OBJECT{
public:
    BOX_TUTORIAL(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y);
    void print(char** &map) override;
    void delete_(char** &map) override;
    void get_interact_empty(char** &map) override;
    void move(char** &m, int const &dir, int const &higth, int const &width) override;
};

class CUPBOARD_PUZLE:public MAP_OBJECT{
public:
    CUPBOARD_PUZLE(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y);
    void print(char** &map) override;
    void delete_(char** &map) override;
    void get_interact_empty(char** &map) override;
    void move(char** &m, int const &dir, int const &higth, int const &width) override;
};

class LEVER_1:public MAP_OBJECT{
public:
    LEVER_1(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y);
    void print(char** &map) override;
    void delete_(char** &map) override;
    void get_interact_empty(char** &map) override;
    void move(char** &m, int const &dir, int const &higth, int const &width) override;
};

class LEVER_2:public MAP_OBJECT{
public:
    LEVER_2(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y);
    void print(char** &map) override;
    void delete_(char** &map) override;
    void get_interact_empty(char** &map) override;
    void move(char** &m, int const &dir, int const &higth, int const &width) override;
};

class LEVER_3:public MAP_OBJECT{
public:
    LEVER_3(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y);
    void print(char** &map) override;
    void delete_(char** &map) override;
    void get_interact_empty(char** &map) override;
    void move(char** &m, int const &dir, int const &higth, int const &width) override;
};

class LEVER_4:public MAP_OBJECT{
public:
    LEVER_4(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y);
    void print(char** &map) override;
    void delete_(char** &map) override;
    void get_interact_empty(char** &map) override;
    void move(char** &m, int const &dir, int const &higth, int const &width) override;
};

class LEVER_5:public MAP_OBJECT{
public:
    LEVER_5(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y);
    void print(char** &map) override;
    void delete_(char** &map) override;
    void get_interact_empty(char** &map) override;
    void move(char** &m, int const &dir, int const &higth, int const &width) override;
};

class SHELF_1:public MAP_OBJECT{
public:
    SHELF_1(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y);
    void print(char** &map) override;
    void delete_(char** &map) override;
    void get_interact_empty(char** &map) override;
    void move(char** &m, int const &dir, int const &higth, int const &width) override;
};

class SHELF_2:public MAP_OBJECT{
public:
    SHELF_2(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y);
    void print(char** &map) override;
    void delete_(char** &map) override;
    void get_interact_empty(char** &map) override;
    void move(char** &m, int const &dir, int const &higth, int const &width) override;
};

class SHELF_3:public MAP_OBJECT{
public:
    SHELF_3(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y);
    void print(char** &map) override;
    void delete_(char** &map) override;
    void get_interact_empty(char** &map) override;
    void move(char** &m, int const &dir, int const &higth, int const &width) override;
};

class PICTURE_1:public MAP_OBJECT{
public:
    PICTURE_1(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y);
    void print(char** &map) override;
    void delete_(char** &map) override;
    void get_interact_empty(char** &map) override;
    void move(char** &m, int const &dir, int const &higth, int const &width) override;
};

class PICTURE_2:public MAP_OBJECT{
public:
    PICTURE_2(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y);
    void print(char** &map) override;
    void delete_(char** &map) override;
    void get_interact_empty(char** &map) override;
    void move(char** &m, int const &dir, int const &higth, int const &width) override;
};

class PICTURE_ESPECIAL:public MAP_OBJECT{
public:
    PICTURE_ESPECIAL(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y);
    void print(char** &map) override;
    void delete_(char** &map) override;
    void get_interact_empty(char** &map) override;
    void move(char** &m, int const &dir, int const &higth, int const &width) override;
};

class CUPBOARD_2:public MAP_OBJECT{
public:
    CUPBOARD_2(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y);
    void print(char** &map) override;
    void delete_(char** &map) override;
    void get_interact_empty(char** &map) override;
    void move(char** &m, int const &dir, int const &higth, int const &width) override;
};

class CUPBOARD_3:public MAP_OBJECT{
public:
    CUPBOARD_3(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y);
    void print(char** &map) override;
    void delete_(char** &map) override;
    void get_interact_empty(char** &map) override;
    void move(char** &m, int const &dir, int const &higth, int const &width) override;
};

class CUPBOARD_SIDE:public MAP_OBJECT{
public:
    CUPBOARD_SIDE(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y);
    void print(char** &map) override;
    void delete_(char** &map) override;
    void get_interact_empty(char** &map) override;
    void move(char** &m, int const &dir, int const &higth, int const &width) override;
};

class CUPBOARD_2_SIDE:public MAP_OBJECT{
public:
    CUPBOARD_2_SIDE(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y);
    void print(char** &map) override;
    void delete_(char** &map) override;
    void get_interact_empty(char** &map) override;
    void move(char** &m, int const &dir, int const &higth, int const &width) override;
};

class CUPBOARD_3_SIDE:public MAP_OBJECT{
public:
    CUPBOARD_3_SIDE(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y);
    void print(char** &map) override;
    void delete_(char** &map) override;
    void get_interact_empty(char** &map) override;
    void move(char** &m, int const &dir, int const &higth, int const &width) override;
};

#endif