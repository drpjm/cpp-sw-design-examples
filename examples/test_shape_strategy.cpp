#include <vector>
#include <iostream>

#include "shape_strategy.hpp"
/**
 * Some fancy aliasing to help a bit!
 **/
// using Shapes = std::vector< std::unique_ptr<shape_visitor::Shape> >; // Unique pointer will get cleaned up!

int main(){

    std::cout << "*** Print Strategy Demo ***" << std::endl;
    using Shapes = std::vector<std::unique_ptr<shape_strategy::Shape>>;

    Shapes shapes {};
    auto circ = std::make_unique<shape_strategy::Circle>(2.3, std::make_unique<shape_strategy::StdIoPrintCircle>());

    return 0;
}