#ifndef OBJECTS_H
#define OBJECTS_H
#include<iostream>
#include<string.h>

class OBJECT{
    int x, y;
    std::string name;
    std::string description;
    int code;
public:
    OBJECT(int _x, int _y, std::string _name, std::string _des, int code);
    int get_x();
    int get_y();
    void set_x(int _x);
    void set_y(int _y);
    virtual void content() = 0;
    std::string get_name(){ return name; }
    std::string get_description() { return description; }
    int get_code();
};

class LETTER_PRUEBA: public OBJECT{
public:
    LETTER_PRUEBA(int _x, int _y);
    void content() override;    
};




#endif