#include <vector>
#include <iostream>

#include "shape_stdio/shape_stdio.hpp"
// #include "shape_fmt/shape_fmt.hpp"

int main(){

    std::cout << "*** Print Strategy Demo ***" << std::endl;
    using Shapes = std::vector<std::unique_ptr<shape_strategy::Shape>>;

    Shapes shapes {};
    shapes.emplace_back(
        std::make_unique<shape_strategy::Circle>(
            2.3, 
            std::make_unique<shape_strategy::StdIoPrintCircle>()
        )
    );

    for (auto const& shape : shapes){
        shape->print();
    }

    return 0;
}