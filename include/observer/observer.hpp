#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "spdlog/spdlog.h"

namespace obsv {

struct BehaviorMessage
{
    int stamp;
    std::string behavior;
};

class RobotBehaviorObserver {

    public:
        ~RobotBehaviorObserver() = default;
        virtual void update(BehaviorMessage const& msg) = 0;

};

class FunRobotBehaviorObserver : public RobotBehaviorObserver {

    public:
        explicit FunRobotBehaviorObserver(std::string id) : id_ (id) {};

        void update(BehaviorMessage const& msg) override {
            spdlog::info("I'm {0} - stamp={1}, behavior={2}", id_,  msg.stamp, msg.behavior);
        }

    private:
        std::string id_;

};

}

#endif  // OBSERVER_HPP