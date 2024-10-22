#include "visitor/shape_variant.hpp"
#include <vector>
#include <iostream>

int main(){
    shape_variant::Circle circle1 { 1.2 };
    shape_variant::Square square1 { 2.5 };
    shape_variant::Square square2 { 4.6 };
    shape_variant::Rectangle rect1 { 3.14, 2.0 };

    /**
     * Variant structure gives us some compile time flexibility!
     */
    std::vector<shape_variant::Shape> shapes {};
    shapes.emplace_back( circle1 );
    shapes.emplace_back( square1 );
    shapes.emplace_back( square2 );
    shapes.emplace_back( rect1 );

    for (auto const& shape : shapes) {
        std::cout << "Area: " << std::visit(shape_variant::AreaVisitor(), shape) << std::endl;
        std::cout << "Perimeter: " << std::visit(shape_variant::PerimeterVisitor(), shape) << std::endl;
    }

}