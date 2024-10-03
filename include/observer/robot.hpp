#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <string>
#include <set>
#include <list>
#include <random>

#include "observer.hpp"

namespace robot {

struct BehaviorMessage
{
    int stamp;
    std::string behavior;
};

using BehaviorObserver = obsv::PushObserver<BehaviorMessage>;

class Robot {

    public:
        explicit Robot(int id, float x, float y, std::string behavior) : 
            id_ (id), curr_x_ (x), curr_y_ (y), curr_behavior_ (behavior) {}

        bool subscribe(BehaviorObserver* obsv){
            // Structured binding
            auto [pos, success] = observers_.insert(obsv);
            return success;
        }

        bool unsubscribe(BehaviorObserver* obsv){
            return ( observers_.erase( obsv ) > 0U );
        }

        void notify(){
            for( auto it = begin(observers_); it != end(observers_); ){
                auto const pos = it++;
                (*pos)->update( BehaviorMessage{0, curr_behavior_} );
            }
        }

        void change_behavior(){
            behavior_idx_++;
            if (behavior_idx_ > behavior_types_.size()) {
                behavior_idx_ = 0;
            }
            curr_behavior_ = behavior_types_[behavior_idx_];
        }

    private:
        std::string curr_behavior_;
        float curr_x_;
        float curr_y_;
        int id_;
        std::set<BehaviorObserver*> observers_;
        int behavior_idx_ {0};
        std::vector<std::string> behavior_types_ {"idle", "dancing", "driving"};

};

}

#endif  //ROBOT_HPP