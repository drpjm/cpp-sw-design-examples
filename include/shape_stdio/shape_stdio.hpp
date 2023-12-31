#ifndef SHAPE_STDIO_HPP
#define SHAPE_STDIO_HPP

#include <iostream>
#include "shape_strategy.hpp"

namespace shape_strategy {

class StdIoPrintCircle : public PrintStrategy<Circle>{

    public:
        explicit StdIoPrintCircle() {}
        void print( Circle const& circ /* stuff one day */) const override{
            std::cout << "StdIoPrintCircle:Radius: " << circ.radius() << std::endl;
        }
};

class StdIoPrintSquare : public PrintStrategy<Square>{

    public:
        explicit StdIoPrintSquare() {}
        void print( Square const& sq /* stuff one day */) const override{
            std::cout << "StdIoPrintCircle:Side: " << sq.side() << std::endl;
        }
};

}

#endif  // SHAPE_STDIO_HPP