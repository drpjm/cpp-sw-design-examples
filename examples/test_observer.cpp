#include <iostream>
#include <chrono>
#include <thread>

#include "spdlog/spdlog.h"
#include "observer/robot.hpp"

int main(){

    spdlog::set_level(spdlog::level::info);

    robot::Robot isadora {0, 0.0, 0.0};
    // Using new creates a pointer.
    auto funobs1 = new obsv::FunRobotBehaviorObserver("fun1");
    auto funobs2 = new obsv::FunRobotBehaviorObserver("fun2");

    isadora.subscribe(funobs1);
    isadora.subscribe(funobs2);

    int max_iter = 10;
    for (int i = 0; i < max_iter; i++){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        isadora.change_behavior();
        spdlog::info("Sending notifications to observers!");
        isadora.notify();
    }

}