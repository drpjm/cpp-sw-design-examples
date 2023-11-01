#ifndef PEGS_HPP
#define PEGS_HPP

/**
 *  This header file holds the classes needed for making a
 *  "Pound-a-Peg" toy! Oh fun!
 **/

namespace round_pegs {

class RoundPeg {
    public:
        RoundPeg(float radius) : radius_ (radius) {}

        float get_radius() const {
            return radius_;
        }

    private:
        float radius_;
};

class RoundHole {

    public:
        explicit RoundHole(float radius) : radius_ (radius) {}

        float get_radius() const {
            return radius_;
        }

        bool fits(RoundPeg peg){
            if(peg.get_radius() <= radius_) {
                return true;
            }
            else{
                return false;
            }
        }

    private:
        float radius_;

};

}

#endif  // PEGS_HPP
