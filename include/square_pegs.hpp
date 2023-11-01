#ifndef SQUARE_PEGS_HPP
#define SQUARE_PEGS_HPP

namespace square_pegs {

class SquarePeg {

    explicit SquarePeg(float side_length) : side_length_ (side_length) {}

    float get_side_length() const {
        return side_length_;
    }

    private:
        float side_length_;

};

}

#endif  // SQUARE_PEGS_HPP