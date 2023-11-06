#include <vector>
#include <memory>
#include <iostream>
#include "round_pegs.hpp"
#include "peg_adapters/square_peg_adapter.hpp"

int main(){

    round_pegs::RoundHole hole1 {4.5};
    round_pegs::RoundHole hole2 {2.1};

    round_pegs::CirclePeg circ1 {4.0};
    round_pegs::CirclePeg circ2 {2.0};
    round_pegs::SquarePegAdapter circ3 { 
        std::make_unique<square_pegs::SquarePeg>(3.5)
    };

    std::cout << "CirclePeg - radius: " << circ1.get_radius() << std::endl;
    std::cout << "Fits Hole 1? " << hole1.fits(circ1) << std::endl;
    std::cout << "Fits Hole 2? " << hole2.fits(circ1) << std::endl;

    std::cout << "CirclePeg - radius: " << circ2.get_radius() << std::endl;
    std::cout << "Fits Hole 1? " << hole1.fits(circ2) << std::endl;
    std::cout << "Fits Hole 2? " << hole2.fits(circ2) << std::endl;

    std::cout << "CirclePeg (Adapter!) - radius: " << circ3.get_radius() << std::endl;
    std::cout << "Fits Hole 1? " << hole1.fits(circ3) << std::endl;
    std::cout << "Fits Hole 2? " << hole2.fits(circ3) << std::endl;   

}