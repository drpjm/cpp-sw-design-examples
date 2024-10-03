#include <iostream>
#include <chrono>
#include <thread>

#include "spdlog/spdlog.h"
#include "observer/robot.hpp"

int main(){

    robot::Robot isadora {0, 0.0, 0.0, "Idle"};

    int max_iter = 15;
    for (int i = 0; i < max_iter; i++){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        isadora.change_behavior();
        spdlog::info("Sending notifications to observers!");
        isadora.notify();
    }

}