#include<iostream>
#include<string.h>
#include<conio.h>
#include "../include/objects.h"
#define CLEAR_SCREEN system("cls")
#define ACTION 'e'
#define ACTION2 'E'
#define ESC 27

OBJECT::OBJECT(int _x, int _y, std::string _name, std::string _des, int _code){
    this->x = _x;
    this->y = _y;
    this->name = _name;
    this->description = _des;
    this->code = _code;
}

int OBJECT::get_x(){ return x; }
int OBJECT::get_y(){ return y; }
int OBJECT::get_code(){ return code; }

void OBJECT::print(char** &m){
    m[y][x] = '+';
}

void OBJECT::delete_(char** &m){
    m[y][x] = ' ';
}

void OBJECT::set_x(int _x){
    this->x = _x;
}

void OBJECT::set_y(int _y){
    this->y = _y;
}

void OBJECT::set_interact_text(std::string text){
    this->interac_text = text;
}

LETTER_PRUEBA::LETTER_PRUEBA(int _x, int _y): OBJECT(_x, _y, "Carta de Prueba", "Carta escrita por una persona anonima", 191){
    std::string text = "Has recogido una Carta de Prueba";
    set_interact_text(text);
}

void LETTER_PRUEBA::content(){
    std::string text = "Contenido de prueba para probar como seria una carta/nota etc.\n\t\t\t\t........................................................\n\t\t\t\t.....................................................\n\t\t\t\t..............................................\n\t\t\t\t....................................\n\t\t\t\t................................";
    CLEAR_SCREEN;
    std::cout << std::endl << std::endl << std::endl << std::endl;
    std::cout << "\t\t\t\t" << text;
    while(true){
        if(kbhit()){
            char key = getch();
            if(key == ACTION || key == ACTION2 || key == ESC) return;
        }
    }    
}

KEY_PRUEBA::KEY_PRUEBA(int _x, int _y): OBJECT(_x, _y, "Llave de Prueba", "Llave que abre una cerradura", 211){
    std::string text = "Has recogido una Llave de Prueba";
    set_interact_text(text);
}

void KEY_PRUEBA::content(){
}

LETTER_TUTORIAL::LETTER_TUTORIAL(int _x, int _y): OBJECT(_x, _y, "Carta sin Remitente", "¿Una carta dirigida a mi?", 192){
}

void LETTER_TUTORIAL::content(){
    std::string text = "-Hola de nuevo XXXXX o como sea que te llames ahora,\n\t\t\t\tdiria que ya te sabes las reglas pero ese no es el\n\t\t\t\tcaso. En fin, empecemos desde el principio, en este\n\t\t\t\tmomento estas ATRAPADO (vaya novedad), salir? depen-\n\t\t\t\tdera de tus habilidades, en este lugar encontraras\n\t\t\t\tdistintos enigmas aun por desvelar, tu trabajo es encontrar\n\t\t\t\tla manera de salir de este lugar (si puedes).\n\t\t\t\tUn consejo: Todo lo que encuentres tiene una razon.\n\n\t\t\t\t Att: El JUEZ";
    CLEAR_SCREEN;
    std::cout << std::endl << std::endl << std::endl << std::endl;
    std::cout << "\t\t\t\t" << text;
    while(true){
        if(kbhit()){
            char key = getch();
            if(key == ACTION || key == ACTION2 || key == ESC) return;
        }
    }
}
//
PIECE1::PIECE1(int _x, int _y): OBJECT(_x, _y, "Pieza rota", "Parece formar parte de algo mas grande", 391){
    std::string text = "Has recogido una pieza rota";
    set_interact_text(text);
}

void PIECE1::content(){
}

PIECE2::PIECE2(int _x, int _y): OBJECT(_x, _y, "Pieza rota", "Parece formar parte de algo mas grande", 392){
    std::string text = "Has recogido una pieza rota";
    set_interact_text(text);
}

void PIECE2::content(){
}

PIECE3::PIECE3(int _x, int _y): OBJECT(_x, _y, "Pieza rota", "Parece formar parte de algo mas grande", 393){
    std::string text = "Has recogido una pieza rota";
    set_interact_text(text);
}

void PIECE3::content(){
}

PIECE4::PIECE4(int _x, int _y): OBJECT(_x, _y, "Pieza rota", "Parece formar parte de algo mas grande", 394){
    std::string text = "Has recogido una pieza rota";
    set_interact_text(text);
}

void PIECE4::content(){
}

PIECE5::PIECE5(int _x, int _y): OBJECT(_x, _y, "Pieza rota", "Parece formar parte de algo mas grande", 395){
    std::string text = "Has recogido una pieza rota";
    set_interact_text(text);
}

void PIECE5::content(){
}

PIECE6::PIECE6(int _x, int _y): OBJECT(_x, _y, "Pieza rota", "Parece formar parte de algo mas grande", 396){
    std::string text = "Has recogido una pieza rota";
    set_interact_text(text);
}

void PIECE6::content(){
}

PIECE7::PIECE7(int _x, int _y): OBJECT(_x, _y, "Pieza rota", "Parece formar parte de algo mas grande", 397){
    std::string text = "Has recogido una pieza rota";
    set_interact_text(text);
}

void PIECE7::content(){
}

PIECE8::PIECE8(int _x, int _y): OBJECT(_x, _y, "Pieza rota", "Parece formar parte de algo mas grande", 398){
    std::string text = "Has recogido una pieza rota";
    set_interact_text(text);
}

void PIECE8::content(){
}

PIECE9::PIECE9(int _x, int _y): OBJECT(_x, _y, "Pieza rota", "Parece formar parte de algo mas grande", 399){
    std::string text = "Has recogido una pieza rota";
    set_interact_text(text);
}

void PIECE9::content(){
}

KEY_TO_THREE::KEY_TO_THREE(int _x, int _y): OBJECT(_x, _y, "Llave oxidada", "Podria servir en alguna puerta", 211){
    std::string text = "Has recogido Llave oxidada";
    set_interact_text(text);
}

void KEY_TO_THREE::content(){
}

LOG1::LOG1(int _x, int _y): OBJECT(_x, _y, "Reporte legal Nº1", "Reporte de un caso legal. ¿Por que estaria esto aqui?", 193){
    std::string text = "Has recogido Reporte legal Nº1";
    set_interact_text(text);
}

void LOG1::content(){
    std::string text = "Estado vs. Juan Perez\n\n\t\t\t\tJuan Perez, un joven a la edad de veintiuno, fue acusado y posteriormente\n\t\t\t\tcondenado por el delito de vandalismo tras pintar grafitis en un\n\t\t\t\tmuro propiedad de la ciudad. El juez condeno a Perez a \n\t\t\t\t12 meses de prision en Mansfield";
    CLEAR_SCREEN;
    std::cout << std::endl << std::endl << std::endl << std::endl;
    std::cout << "\t\t\t\t" << text;
    while(true){
        if(kbhit()){
            char key = getch();
            if(key == ACTION || key == ACTION2 || key == ESC) return;
        }
    }
}

LOG2::LOG2(int _x, int _y): OBJECT(_x, _y, "Reporte legal Nº2", "Reporte de un caso legal.", 194){
    std::string text = "Has recogido Reporte legal Nº2";
    set_interact_text(text);
}

void LOG2::content(){
    std::string text = "Javier Reddy\n\n\t\t\t\tJavier fue atrapado robando 3 telefonos de alta gama de\n\t\t\t\tla tienda Solly Electronics. Fue acusado y condenado por\n\t\t\t\trobo mayor con una sentencia de cuarenta y ocho meses\n\t\t\t\ten Mansfield y una multa substancial";
    CLEAR_SCREEN;
    std::cout << std::endl << std::endl << std::endl << std::endl;
    std::cout << "\t\t\t\t" << text;
    while(true){
        if(kbhit()){
            char key = getch();
            if(key == ACTION || key == ACTION2 || key == ESC) return;
        }
    }
}

LOG3::LOG3(int _x, int _y): OBJECT(_x, _y, "Reporte legal Nº3", "Reporte de un caso legal.", 195){
    std::string text = "Has recogido Reporte legal Nº3";
    set_interact_text(text);
}

void LOG3::content(){
    std::string text = "Estado vs. Eric de Andrade\n\n\t\t\t\tEric de Andrade, joven ingeniero a la edad de veinticinco, trabajaba para 1\n\t\t\t\tempresa no muy grande dedicada a la produccion\n\t\t\t\tde productos quimicos. Con el fin de ahorrar costos para la empresa, virtio de manera\n\t\t\t\tilegal residuos toxicos en un rio cercano. Fue condenado a sesenta \n\t\t\t\ty cinco meses en la prision Mansfield";
    CLEAR_SCREEN;
    std::cout << std::endl << std::endl << std::endl << std::endl;
    std::cout << "\t\t\t\t" << text;
    while(true){
        if(kbhit()){
            char key = getch();
            if(key == ACTION || key == ACTION2 || key == ESC) return;
        }
    }
}

LOG4::LOG4(int _x, int _y): OBJECT(_x, _y, "Reporte legal Nº4", "Reporte de un caso legal.", 196){
    std::string text = "Has recogido Reporte legal Nº4";
    set_interact_text(text);
}

void LOG4::content(){
    std::string text = "Mark Redfield\n\n\t\t\t\tMark, un contador a la edad de veintiocho, trabajaba en el banco universal Terra.\n\t\t\t\tAprovechando su posición, ideo un elaborado esquema de fraude para desviar fondos\n\t\t\t\tde las cuentas de clientes hacia cuentas falsas que el controlaba.\n\t\t\t\tFue sentenciado a 92 meses en la prision Mansfield.";
    CLEAR_SCREEN;
    std::cout << std::endl << std::endl << std::endl << std::endl;
    std::cout << "\t\t\t\t" << text;
    while(true){
        if(kbhit()){
            char key = getch();
            if(key == ACTION || key == ACTION2 || key == ESC) return;
        }
    }
}

LOG5::LOG5(int _x, int _y): OBJECT(_x, _y, "Reporte legal Nº5", "Reporte de un caso legal.", 197){
    std::string text = "Has recogido Reporte legal Nº5";
    set_interact_text(text);
}

void LOG5::content(){
    std::string text = "David Ortega\n\n\t\t\t\tJoven a la edad de veintitres hackeo los sistemas de seguridad de 2 empresas\n\t\t\t\ttecnologicas, Zenith Innovations y Nexus Digital,\n\t\t\t\ta pesar de no haber obtenido beneficio economico\n\t\t\t\tdirecto, su condena fue de cincuenta y cuatro meses los\n\t\t\t\tcuales debio servir en la prision Mansfield.";
    CLEAR_SCREEN;
    std::cout << std::endl << std::endl << std::endl << std::endl;
    std::cout << "\t\t\t\t" << text;
    while(true){
        if(kbhit()){
            char key = getch();
            if(key == ACTION || key == ACTION2 || key == ESC) return;
        }
    }
}
