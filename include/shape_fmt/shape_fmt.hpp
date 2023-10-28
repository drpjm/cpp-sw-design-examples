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

}

#endif  // SHAPE_FMT_HPP