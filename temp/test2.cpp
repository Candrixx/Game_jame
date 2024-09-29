#include <chrono>
#include <iostream>
#include <string>
#include <stdlib.h>

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

int main(){
    char camera[11][51];
    for(int i=0; i<11; i++){
        for(int j=0; j<51; j++){
            camera[i][j] = 32;
        }
    }
}