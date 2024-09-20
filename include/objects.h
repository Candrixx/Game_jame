#ifndef OBJECTS_H
#define OBJECTS_H
#include<iostream>
#include<string.h>

class OBJECT{
    int x, y;
    std::string name;
    std::string description;
    std::string interac_text;
    int code;
public:
    OBJECT(int _x, int _y, std::string _name, std::string _des, int code);
    int get_x();
    int get_y();
    void set_x(int _x);
    void set_y(int _y);
    void print(char** &m);
    void delete_(char** &m);
    void set_interact_text(std::string text);
    virtual void content() = 0;
    std::string get_name(){ return name; }
    std::string get_description() { return description; }
    std::string get_interact_text(){ return interac_text; }
    int get_code();
};

class LETTER_PRUEBA: public OBJECT{
public:
    LETTER_PRUEBA(int _x, int _y);
    void content() override;
};

class KEY_PRUEBA: public OBJECT{
public:
    KEY_PRUEBA(int _x, int _y);
    void content() override;
};

class LETTER_TUTORIAL: public OBJECT{
public:
    LETTER_TUTORIAL(int _x, int _y);
    void content() override;
};




#endif