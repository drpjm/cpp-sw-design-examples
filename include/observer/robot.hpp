#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "observer.hpp"
#include <string>
#include <set>

namespace robot {

struct BehaviorMessage
{
    int stamp;
    std::string behavior;
};

class Robot {

    using BehaviorObserver = obsv::PushObserver<BehaviorMessage>;

    public:
        explicit Robot(int id, float x, float y, std::string behavior) : 
            id_ (id), curr_x_ (x), curr_y_ (y), curr_behavior_ (behavior) {}

        bool attach(BehaviorObserver* obsv){
            // Structured binding
            auto [pos, success] = observers_.insert(obsv);
            return success;
        }

        bool detach(BehaviorObserver* obsv){
            return ( observers_.erase( obsv ) > 0U );
        }

        void notify(){
            for( auto it = begin(observers_); it != end(observers_); ){
                auto const pos = it++;
                (*pos)->update( BehaviorMessage{0, "idle"} );
            }
        }

    private:
        std::string curr_behavior_;
        float curr_x_;
        float curr_y_;
        int id_;
        std::set<BehaviorObserver*> observers_;

};

}

#endif  //ROBOT_HPP