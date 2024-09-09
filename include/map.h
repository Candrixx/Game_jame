#ifndef MAPA_H
#define MAPA_H
#include<list>

class MAP{
    char ** map;
    int width, heigth;
    std::list<int> map_objects;
    std::list<int> player_objects;
public:
    MAP(int width, int heigth);
    ~MAP();
    virtual void llenar_matriz() = 0; 
    std::list<int>* get_map_objects();
    std::list<int>* get_player_objects();
    void draw_map();
};

#endif