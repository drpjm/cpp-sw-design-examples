#ifndef SHAPE_STDIO_HPP
#define SHAPE_STDIO_HPP

#include <fmt/core.h>

namespace shape_strategy {

class FmtPrintCircle : public PrintStrategy<Circle>{

    public:
        explicit FmtPrintCircle() {}

        void print( Circle const& circ /* stuff one day */ ) const override {

        }
};

}

#endif  // SHAPE_STDIO_HPP