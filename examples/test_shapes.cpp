#include "shape_operations.hpp"
#include <vector>
#include <memory>

/**
 * Some fancy aliasing to help a bit!
 **/
using Shapes = std::vector< std::unique_ptr<shape::Shape> >; // Unique pointer will get cleaned up!

int main(){
    shape::Circle circle1 { 1.2 };
    shape::Square square1 { 2.5 };
    shape::Square square2 { 4.6 };
    shape::Rectangle rect1 { 3.14, 2.0 };

    Shapes shapes {}; // An empty vector of shapes (wrapped in unique pointers)
    shapes.emplace_back( std::make_unique<shape::Circle>(circle1) );
    shapes.emplace_back( std::make_unique<shape::Square>(square1) );
    shapes.emplace_back( std::make_unique<shape::Rectangle>(rect1) );
    shapes.emplace_back( std::make_unique<shape::Square>(square2) );

    // Modern c++ for loop!
    for (auto const& shape : shapes) {
        /**
         *  We invoke the visitor by calling accept() and passing the operation! 
         **/
        shape->accept( shape_visitor::Print{} );
    }

}