#ifndef SQUARE_PEG_ADAPTER_HPP
#define SQUARE_PEG_ADAPTER_HPP

#include <memory>
#include <utility>
#include <cmath>
#include "round_pegs.hpp"
#include "square_pegs.hpp"

namespace round_pegs {

class SquarePegAdapter : public RoundPeg {

    public:
        
        explicit SquarePegAdapter(std::unique_ptr<square_pegs::SquarePeg> sq_peg) : 
            square_peg_ ( std::move( sq_peg) ) {}

        float get_radius() const override {
            // The radius of our square is the length of the diagonal!
            float length = square_peg_->get_side_length();
            return length * std::sqrt(2)/2;
        }

    private:
        std::unique_ptr<square_pegs::SquarePeg> square_peg_;
};

}

#endif  // SQUARE_PEG_ADAPTERE_HPP