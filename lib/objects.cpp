#include<iostream>
#include<string.h>
#include<conio.h>
#include "../include/objects.h"
#define CLEAR_SCREEN system("cls")
#define ACTION 'e'
#define ACTION2 'E'
#define ESC 27

char question = 168;
char exclamation = 173;

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

LETTER_PRUEBA::LETTER_PRUEBA(int _x, int _y): OBJECT(_x, _y, "Carta de Prueba", "Carta escrita por una persona anonima.", 171){
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

KEY_PRUEBA::KEY_PRUEBA(int _x, int _y): OBJECT(_x, _y, "Llave de Prueba", "Llave que abre una cerradura.", 211){
    std::string text = "Has recogido una Llave de Prueba";
    set_interact_text(text);
}

void KEY_PRUEBA::content(){
}

LETTER_TUTORIAL::LETTER_TUTORIAL(int _x, int _y): OBJECT(_x, _y, "Carta sin Remitente", "Parece ser una carta dirigida a mi.", 172){
}

void LETTER_TUTORIAL::content(){
    std::string text = "-Hola de nuevo XXXXX o como sea que te llames ahora,\n\t\t\t\tdiria que ya te sabes las reglas pero ese no es el\n\t\t\t\tcaso. En fin, empecemos desde el principio, en este\n\t\t\t\tmomento estas ATRAPADO (vaya novedad), ";
    std::string text2 = "salir? depen-\n\t\t\t\tdera de tus habilidades, en este lugar encontraras\n\t\t\t\tdistintos enigmas aun por desvelar, tu trabajo es encontrar\n\t\t\t\tla manera de salir de este lugar (si puedes).\n\t\t\t\tUn consejo: Todo lo que encuentres tiene una razon.\n\n\t\t\t\t Att: El JUEZ";
    CLEAR_SCREEN;
    std::cout << std::endl << std::endl << std::endl << std::endl;
    std::cout << "\t\t\t\t" << text << question << text2;
    while(true){
        if(kbhit()){
            char key = getch();
            if(key == ACTION || key == ACTION2 || key == ESC) return;
        }
    }
}
//
PIECE1::PIECE1(int _x, int _y): OBJECT(_x, _y, "Pieza rota         ", "Parece formar parte de algo mas grande.", 391){
    std::string text = "Has recogido una pieza rota";
    set_interact_text(text);
}

void PIECE1::content(){
}

PIECE2::PIECE2(int _x, int _y): OBJECT(_x, _y, "Pieza rota         ", "Parece formar parte de algo mas grande.", 392){
    std::string text = "Has recogido una pieza rota";
    set_interact_text(text);
}

void PIECE2::content(){
}

PIECE3::PIECE3(int _x, int _y): OBJECT(_x, _y, "Pieza rota         ", "Parece formar parte de algo mas grande.", 393){
    std::string text = "Has recogido una pieza rota";
    set_interact_text(text);
}

void PIECE3::content(){
}

PIECE4::PIECE4(int _x, int _y): OBJECT(_x, _y, "Pieza rota         ", "Parece formar parte de algo mas grande.", 394){
    std::string text = "Has recogido una pieza rota";
    set_interact_text(text);
}

void PIECE4::content(){
}

PIECE5::PIECE5(int _x, int _y): OBJECT(_x, _y, "Pieza rota         ", "Parece formar parte de algo mas grande.", 395){
    std::string text = "Has recogido una pieza rota";
    set_interact_text(text);
}

void PIECE5::content(){
}

PIECE6::PIECE6(int _x, int _y): OBJECT(_x, _y, "Pieza rota         ", "Parece formar parte de algo mas grande.", 396){
    std::string text = "Has recogido una pieza rota";
    set_interact_text(text);
}

void PIECE6::content(){
}

PIECE7::PIECE7(int _x, int _y): OBJECT(_x, _y, "Pieza rota         ", "Parece formar parte de algo mas grande.", 397){
    std::string text = "Has recogido una pieza rota";
    set_interact_text(text);
}

void PIECE7::content(){
}

PIECE8::PIECE8(int _x, int _y): OBJECT(_x, _y, "Pieza rota         ", "Parece formar parte de algo mas grande.", 398){
    std::string text = "Has recogido una pieza rota";
    set_interact_text(text);
}

void PIECE8::content(){
}

PIECE9::PIECE9(int _x, int _y): OBJECT(_x, _y, "Pieza rota         ", "Parece formar parte de algo mas grande.", 399){
    std::string text = "Has recogido una pieza rota";
    set_interact_text(text);
}

void PIECE9::content(){
}

KEY_TO_THREE::KEY_TO_THREE(int _x, int _y): OBJECT(_x, _y, "Llave oxidada", "Podria servir en alguna puerta.", 222){
    std::string text = "Has recogido Llave oxidada";
    set_interact_text(text);
}

void KEY_TO_THREE::content(){
}

LOG1::LOG1(int _x, int _y): OBJECT(_x, _y, "Reporte legal #1", "Reporte de un caso legal. Tiene partes redactadas.", 451){
    std::string text = "Has recogido Reporte legal #1";
    set_interact_text(text);
}

void LOG1::content(){
    std::string text = "Acusado: Juan Perez\n\t\t\t\tJuez: XXXXX XXXXXXX\n\t\t\t\tFecha de la audiencia: 28 de febrero de 2001\n\n\t\t\t\tJuan Perez, un joven a la edad de veintiuno, fue acusado y posteriormente\n\t\t\t\tcondenado por el delito de vandalismo tras pintar grafitis en un\n\t\t\t\tmuro propiedad de la ciudad. El juez XXXXXXX condeno a Perez a \n\t\t\t\t12 meses de prision en Mansfield.";
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

LOG2::LOG2(int _x, int _y): OBJECT(_x, _y, "Reporte legal #2", "Reporte de un caso legal. Tiene partes redactadas.", 452){
    std::string text = "Has recogido Reporte legal #2";
    set_interact_text(text);
}

void LOG2::content(){
    std::string text = "Acusado: Javier Reddy\n\t\t\t\tJuez: XXXXX XXXXXXX\n\t\t\t\tFecha de la audiencia: 07 de abril de 2001\n\n\t\t\t\tJavier fue atrapado robando 4 telefonos de alta gama de\n\t\t\t\tla tienda Solly Electronics. Fue acusado y condenado por\n\t\t\t\trobo mayor con una sentencia de cuarenta y ocho meses\n\t\t\t\ten Mansfield y una multa substancial.";
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

LOG3::LOG3(int _x, int _y): OBJECT(_x, _y, "Reporte legal #3", "Reporte de un caso legal. Tiene partes redactadas.", 453){
    std::string text = "Has recogido Reporte legal #3";
    set_interact_text(text);
}

void LOG3::content(){
    std::string text = "Acusado: Eric de Andrade\n\t\t\t\tJuez: XXXXX XXXXXXX\n\t\t\t\tFecha de la audiencia: 13 de enero de 2002\n\n\t\t\t\tEric de Andrade, joven ingeniero a la edad de veinticinco, trabajaba\n\t\t\t\tpara 1 empresa no muy grande dedicada a la elaboracion de\n\t\t\t\tproductos quimicos. Con el fin de ahorrar costos para la empresa,\n\t\t\t\tvirtio de manera ilegal residuos toxicos en un rio cercano. Fue\n\t\t\t\tcondenado a sesenta y cinco meses en la prision Mansfield.";
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

LOG4::LOG4(int _x, int _y): OBJECT(_x, _y, "Reporte legal #4", "Reporte de un caso legal. Tiene partes redactadas.", 454){
    std::string text = "Has recogido Reporte legal #4";
    set_interact_text(text);
}

void LOG4::content(){
    std::string text = "Acusado: Mark Redfield\n\t\t\t\tJuez: XXXXX XXXXXXX\n\t\t\t\tFecha de la audiencia: 24 de octubre de 2002\n\n\t\t\t\tMark, un contador a la edad de veintiocho, trabajaba en el banco universal Terra.\n\t\t\t\tAprovechando su posicion, ideo un elaborado esquema de fraude para desviar fondos\n\t\t\t\tde las cuentas de clientes hacia cuentas falsas que el controlaba.\n\t\t\t\tFue sentenciado a 92 meses en la prision Mansfield.";
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

LOG5::LOG5(int _x, int _y): OBJECT(_x, _y, "Reporte legal #5", "Reporte de un caso legal. Tiene partes redactadas.", 455){
    std::string text = "Has recogido Reporte legal #5";
    set_interact_text(text);
}

void LOG5::content(){
    std::string text = "Acusado: David Ortega\n\t\t\t\tJuez: XXXXX XXXXXXX\n\t\t\t\tFecha de la audiencia: 29 de marzo de 2003\n\n\t\t\t\tJoven a la edad de veintitres hackeo los sistemas de seguridad de\n\t\t\t\t2 empresas tecnologicas, Zenith Innovations y Nexus Digital,\n\t\t\t\ta pesar de no haber obtenido beneficio economico\n\t\t\t\tdirecto, su condena fue de cincuenta y cuatro meses los\n\t\t\t\tcuales debio servir en la prision Mansfield.";
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

NOTE1::NOTE1(int _x, int _y): OBJECT(_x, _y, "Nota               ", "Nota escrita por una persona desconocida.", 173){
    std::string text = "Has recogido Nota";
    set_interact_text(text);
}

void NOTE1::content(){
    std::string text1 = "Este lugar... "; 
    std::string text2 = "donde estoy? Las habitaciones cambian. Juro que el armario estaba\n\t\t\talla hace un segundo. Y los rompecabezas... "; 
    std::string text3 = "no terminan! Cada vez que creo haber\n\t\t\tresuelto uno, aparece otro. Encuentro estos reportes pero no se que hacer con ellos...\n\n\n\t\t\t";
    std::string text4 = "Recorde mi nombre! es JXXXX XXXXXXX, necesito escribirlo porque los recuerdos\n\t\t\tson difusos, en cualquier momento podria olvidar.\n\n\n\t\t\tAlgo esta mal, muy mal. Necesito salir de aqui. Necesito encontrar una salida.";
    CLEAR_SCREEN;
    std::cout << std::endl << std::endl << std::endl << std::endl;
    std::cout << "\t\t\t" << text1 << question << text2 << exclamation << text3 << exclamation << text4;
    while(true){
        if(kbhit()){
            char key = getch();
            if(key == ACTION || key == ACTION2 || key == ESC) return;
        }
    }
}

NOTE2::NOTE2(int _x, int _y): OBJECT(_x, _y, "Nota misteriosa    ", "Esta nota parece indicar algo...", 174){
    std::string text = "Has recogido Nota misteriosa";
    set_interact_text(text);
}

void NOTE2::content(){
    std::string text = "En el obraje del creador, donde las manos dan forma,\n\t\t\t\tCinco signos esperan, su orden se desvela.\n\t\t\t\tEl primero, donde tus instrumentos aguardan el primer toque.\n\t\t\t\tEn la sabiduria de los bocetos y trazos, sus secretos invoca.\n\t\t\t\tDebajo de este, el tercero, oculta un paso mas al arte.\n\t\t\t\tSeguido, sientate y elabora tu destino.\n\t\t\t\tFinalmente, en el corazon del oficio, el enigma se desvela.";
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

NEWSPAPER::NEWSPAPER(int _x, int _y): OBJECT(_x, _y, "Pedazo de periodico", "Es de un periodico de hace tiempo", 175){
    std::string text = "Has recogido Pedazo de periodico";
    set_interact_text(text);
}

void NEWSPAPER::content(){
    std::string text = "2 de marzo de 2004\n\n\t\t\tEscandalo sacude al sistema judicial: Juez XXXXXXX involucrado en\n\t\t\ttrama de corrupcion\n\n\t\t\tEn una noticia que ha conmocionado al pais, una exhaustiva investigacion federal\n\t\t\tha destapado una red de corrupcion que involucra al juez federal, XXXXX XXXXXXX,\n\t\t\ty la prision privada Mansfield. Segun fuentes confiables, el magistrado habria\n\t\t\testado recibiendo sobornos a cambio de imponer sentencias desproporcionadas,\n\t\t\tespecialmente a jovenes acusados de delitos menores. La investigacion, que se prolongo\n\t\t\tdurante varios meses, revelo una compleja trama de pagos encubiertos y presiones\n\t\t\tejercidas sobre el juez GXXXXXX para favorecer los intereses de la prision privada\n\t\t\tMansfield. Al parecer, la sobrepoblacion en el centro penitenciario y la necesidad de mano de\n\t\t\tobra barata habrian motivado a sus directivos a buscar complices en el poder judicial.\n\t\t\tNumerosas organizaciones defensoras de los derechos humanos han exigido la destitucion\n\t\t\tinmediata del juez XXXXXXX y la apertura de una investigacion a fondo para determinar\n\t\t\tsi existen otros magistrados involucrados en practicas similares.";
    CLEAR_SCREEN;
    std::cout << std::endl << std::endl << std::endl << std::endl;
    std::cout << "\t\t\t" << text;
    while(true){
        if(kbhit()){
            char key = getch();
            if(key == ACTION || key == ACTION2 || key == ESC) return;
        }
    }
}

NEWSPAPERCUT::NEWSPAPERCUT(int _x, int _y): OBJECT(_x, _y, "Recorte de periodico", "Parece ser un recorte de periodico", 176){
    std::string text = "Has recogido Recorte de periodico";
    set_interact_text(text);
}

void NEWSPAPERCUT::content(){
    std::string text = "\n\t\t\t\t\t\t\t####\n\t\t\t\t\t\t     ##########\n\t\t\t\t\t\t   ##############\n\t\t\t\t\t\t ##################\n\t\t\t\t\t\t ##################\n\t\t\t\t\t\t ##################\n\t\t\t\t\t\t  ################\n\t\t\t\t\t\t   ##############\n\t\t\t\t\t\t    ############\n\t\t\t\t\t\t      ########\n\t\t\t\t\t\t       ######\n\t\t\t\t\t\t         ##";
    CLEAR_SCREEN;
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "\t\t\t\t\t      " << "Prision Privada Mansfield" << std::endl << std::endl << std::endl << text;
    while(true){
        if(kbhit()){
            char key = getch();
            if(key == ACTION || key == ACTION2 || key == ESC) return;
        }
    }
}

NOTE3::NOTE3(int _x, int _y): OBJECT(_x, _y, "Nota arrugada    ", "Esta arrugada pero aun es legible", 177){
    std::string text = "Has recogido Nota arrugada";
    set_interact_text(text);
}

void NOTE3::content(){
    std::string text1 = "Estan por todas partes. Numeros, codigos, simbolos que no significan nada.\n\t\t\tPaginas y paginas de leyes que se retuercen en mi cabeza. ";
    std::string text2 = "Por que estoy aqui?\n\t\t\t";
    std::string text3 = "Que he hecho para merecer esto? Quiero salir de este laberinto, de\n\t\t\teste limbo legal. Las paredes se cierran sobre mi, los puzzles me atormentan.\n\t\t\tMis pensamientos son un rompecabezas sin solucion. ";
    std::string text4 = "Alguien\n\t\t\tme oye? ";
    std::string text5 = "Alguien puede ayudarme a escapar de esta pesadilla?";
    CLEAR_SCREEN;
    std::cout << std::endl << std::endl << std::endl << std::endl;
    std::cout << "\t\t\t" << text1 << question << text2 << question << text3 << question << text4 << question << text5;
    while(true){
        if(kbhit()){
            char key = getch();
            if(key == ACTION || key == ACTION2 || key == ESC) return;
        }
    }
}
