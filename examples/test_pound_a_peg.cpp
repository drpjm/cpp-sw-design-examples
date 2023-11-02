#include <vector>
#include "round_pegs.hpp"
#include "peg_adapters/square_peg_adapter.hpp"

int main(){

    round_pegs::RoundHole hole1 {4.5};
    round_pegs::RoundHole hole2 {2.5};

    std::vector<round_pegs::RoundPeg> pegs {
        round_pegs::RoundPeg(4.0),
        round_pegs::RoundPeg(3.5)
    };

}