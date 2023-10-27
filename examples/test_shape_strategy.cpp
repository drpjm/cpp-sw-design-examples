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

    return 0;
}