#include<iostream>
#include<chrono>
#include<conio.h>
#include<string.h>
#define CLEAR_SCREEN system("cls")
#define ACTION 'e'
#define ACTION2 'E'

class Timer {
public:
    Timer() : start_time_(std::chrono::steady_clock::now()) {}

    float get_elapsed_time() const {
        auto end_time = std::chrono::steady_clock::now();
        auto elapsed = end_time - start_time_;
        return static_cast<float>(std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count()) / 1000.0f;
    }

private:
    std::chrono::time_point<std::chrono::steady_clock> start_time_;
};

void intro(){
    char key;
    bool flag = false;
    std::string text1 = "\t\t\tDetras de cada puerta cerrada se esconde un secreto, y detras de cada secreto,\n\n\t\t\tuna verdad. En este juego, te sumergiras en un mundo lleno de enigmas y misterios.\n\n\t\t\tEstas listo para descubrir el precio de la libertad y desvelar los secretos que se\n\n\t\t\tesconden en la sombra?";
    std::string text2 = "\t\t\tNelson Mandela dijo: 'La libertad es el precio de la valentia'.\n\n\t\t\tLa libertad no es gratis; es una deuda que se paga dia a dia con el sudor de nuestro\n\n\t\t\tesfuerzo y el ingenio de nuestra mente.\n\n\n\t\t\tEstas dispuesto a pagar el precio de la libertad?";
    std::string* pointer = &text1;
    
    while(true){
        std::cout  << std::endl << std::endl << std::endl << std::endl << std::endl;
        for(int i=0; i<(*pointer).length(); i++){
            std::cout << (*pointer)[i];
            Timer timer;
            if(kbhit()){
                key = getch();
                if(key == ACTION || key == ACTION2) return;
            }
            while(true){
                if(timer.get_elapsed_time() >= 0.03) break;
            }
        }
        Timer t;
        while(true){
            if(t.get_elapsed_time() >= 5) break;
        }
        CLEAR_SCREEN;
        if(flag) return;
        pointer = &text2;
        flag = true;
    }
}

int main(){
    intro();
    return 0;
}