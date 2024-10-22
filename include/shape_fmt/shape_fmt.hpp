#ifndef SHAPE_FMT_HPP
#define SHAPE_FMT_HPP

#include <fmt/core.h>
#include "shape_strategy.hpp"

namespace shape_strategy {

class FmtPrintCircle : public PrintStrategy<Circle>{

    public:
        explicit FmtPrintCircle() {}

        void print( Circle const& circ /* stuff one day */ ) const override {
            fmt::print("FmtPrintCircle:Radius: {rad}\n", fmt::arg("rad", circ.radius()));
        }
};

class FmtPrintSquare : public PrintStrategy<Square> {

    public:
        explicit FmtPrintSquare() {}

        void print( Square const& sq /* stuff one day */ ) const override {
            fmt::print("FmtPrintCircle:Side: {side}\n", fmt::arg("side", sq.side()));
        }
};

}

#endif  // SHAPE_FMT_HPP