#ifndef MAP_OBJECTS_H
#define MAP_OBJECTS_H
#include<iostream>
#include<string.h>
#include<list>

class MAP_OBJECT{
    std::string name;
    int up_left_x;
    int up_left_y;
    int bot_right_x;
    int bot_right_y;
    int object_heigth;
    std::list<int> objects;
public:
    MAP_OBJECT(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y, std::string name, int object_heigth);
    std::string get_name(){ return name;}
    int get_up_left_x();
    int get_up_left_y();
    int get_bot_right_x();
    int get_bot_right_y();
    int get_object_heigth();
    void set_up_left_x(int _x);
    void set_up_left_y(int _y);
    void set_bot_right_x(int _x);
    void set_bot_right_y(int _y);
    virtual void print(char** &map) = 0;
    std::list<int>* get_objects();
};

class CUPBOARD:public MAP_OBJECT{
public:
    CUPBOARD(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y);
    void print(char** &map) override;
};

class TABLE:public MAP_OBJECT{
public:
    TABLE(int left_up_x, int left_up_y, int bot_right_x, int bot_right_y);
    void print(char** &map) override;
};

#endif