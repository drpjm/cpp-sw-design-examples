#include <vector>
#include <memory>
#include "round_pegs.hpp"
#include "peg_adapters/square_peg_adapter.hpp"

int main(){

    round_pegs::RoundHole hole1 {4.5};
    round_pegs::RoundHole hole2 {2.5};

    using Pegs = std::vector<std::unique_ptr<round_pegs::RoundPeg>>;
    Pegs pegs {};

    pegs.emplace_back(
        std::make_unique<round_pegs::CirclePeg>(3.5)
    );
    pegs.emplace_back(
        std::make_unique<round_pegs::CirclePeg>(2.0)
    );

}