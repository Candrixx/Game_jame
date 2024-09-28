#include <chrono>
#include <iostream>
#include <string>

char question = 168;

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

int main() {
    std::cin.get();
    Timer timer;
    std::string text = "####\n\t\t\t\t\t\t\t     ##########\n\t\t\t\t\t\t\t   ##############\n\t\t\t\t\t\t\t ##################\n\t\t\t\t\t\t\t ##################\n\t\t\t\t\t\t\t ##################\n\t\t\t\t\t\t\t  ################\n\t\t\t\t\t\t   ##############\n\t\t\t\t\t\t    ############\n\t\t\t\t\t\t      ########\n\t\t\t\t\t\t       ######\n\t\t\t\t\t\t         ##";
    std::cout << "\t\t\t\t\t\t\t\t" << text;
    std::cout << std::endl << std::endl << question << "Prueba?";
    std::cin.get();
    float elapsed_time = timer.get_elapsed_time();
    std::cout << "Elapsed time: " << elapsed_time << " seconds" << std::endl;
    return 0;
}