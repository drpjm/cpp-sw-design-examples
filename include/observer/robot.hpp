#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <string>
#include <set>
#include <list>
#include <random>

#include "observer.hpp"

namespace robot {

class Robot {

    public:
        explicit Robot(int id, float x, float y) : 
            id_ (id), curr_x_ (x), curr_y_ (y) {
                curr_behavior_ = behavior_types_[0]; 
            }

        bool subscribe(obsv::RobotBehaviorObserver* rob_obsv){
            // Structured binding
            auto [pos, success] = observers_.insert(rob_obsv);
            return success;
        }

        bool unsubscribe(obsv::RobotBehaviorObserver* rob_obsv){
            return ( observers_.erase( rob_obsv ) > 0U );
        }

        void notify(){
            for( auto it = begin(observers_); it != end(observers_); ){
                auto const pos = it++;
                (*pos)->update( obsv::BehaviorMessage{0, curr_behavior_} );
            }
        }

        void change_behavior(){
            if (behavior_idx_ >= behavior_types_.size()) {
                behavior_idx_ = 0;
            }
            curr_behavior_ = behavior_types_[behavior_idx_];
            behavior_idx_++;
            spdlog::debug("behavior_idx = {}", behavior_idx_);
        }

    private:
        std::string curr_behavior_;
        float curr_x_;
        float curr_y_;
        int id_;
        std::set<obsv::RobotBehaviorObserver*> observers_;
        int behavior_idx_ {0};
        std::vector<std::string> behavior_types_ {"idle", "dancing", "driving"};

};

}

#endif  //ROBOT_HPP