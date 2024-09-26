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
//
class PIECE1: public OBJECT{
public:
    PIECE1(int _x, int _y);
    void content() override;
};

class PIECE2: public OBJECT{
public:
    PIECE2(int _x, int _y);
    void content() override;
};

class PIECE3: public OBJECT{
public:
    PIECE3(int _x, int _y);
    void content() override;
};

class PIECE4: public OBJECT{
public:
    PIECE4(int _x, int _y);
    void content() override;
};

class PIECE5: public OBJECT{
public:
    PIECE5(int _x, int _y);
    void content() override;
};

class PIECE6: public OBJECT{
public:
    PIECE6(int _x, int _y);
    void content() override;
};

class PIECE7: public OBJECT{
public:
    PIECE7(int _x, int _y);
    void content() override;
};

class PIECE8: public OBJECT{
public:
    PIECE8(int _x, int _y);
    void content() override;
};

class PIECE9: public OBJECT{
public:
    PIECE9(int _x, int _y);
    void content() override;
};

class KEY_TO_THREE: public OBJECT{
public:
    KEY_TO_THREE(int _x, int _y);
    void content() override;
};

class LOG1: public OBJECT{
public:
    LOG1(int _x, int _y);
    void content() override;
};

class LOG2: public OBJECT{
public:
    LOG2(int _x, int _y);
    void content() override;
};

class LOG3: public OBJECT{
public:
    LOG3(int _x, int _y);
    void content() override;
};

class LOG4: public OBJECT{
public:
    LOG4(int _x, int _y);
    void content() override;
};

class LOG5: public OBJECT{
public:
    LOG5(int _x, int _y);
    void content() override;
};

class NOTE1: public OBJECT{
public:
    NOTE1(int _x, int _y);
    void content() override;
};

class NOTE2: public OBJECT{
public:
    NOTE2(int _x, int _y);
    void content() override;
};

class NEWSPAPER: public OBJECT{
public:
    NEWSPAPER(int _x, int _y);
    void content() override;
};

class NEWSPAPERCUT: public OBJECT{
public:
    NEWSPAPERCUT(int _x, int _y);
    void content() override;
};

#endif