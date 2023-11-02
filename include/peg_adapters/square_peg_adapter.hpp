#ifndef SQUARE_PEG_ADAPTER_HPP
#define SQUARE_PEG_ADAPTER_HPP

#include "round_pegs.hpp"
#include "square_pegs.hpp"

namespace round_pegs {

class SquarePegAdapter : public RoundPeg {

    private:
        square_pegs::SquarePeg square_peg_;

};

}

#endif  // SQUARE_PEG_ADAPTERE_HPP