#include "visitor/shape_operations.hpp"
#include <vector>
#include <memory>

/**
 * Some fancy aliasing to help a bit!
 **/
using Shapes = std::vector< std::unique_ptr<shape_visitor::Shape> >; // Unique pointer will get cleaned up!

int main(){
    shape_visitor::Circle circle1 { 1.2 };
    shape_visitor::Square square1 { 2.5 };
    shape_visitor::Square square2 { 4.6 };
    shape_visitor::Rectangle rect1 { 3.14, 2.0 };

    Shapes shapes {}; // An empty vector of shapes (wrapped in unique pointers)
    shapes.emplace_back( std::make_unique<shape_visitor::Circle>(circle1) );
    shapes.emplace_back( std::make_unique<shape_visitor::Square>(square1) );
    shapes.emplace_back( std::make_unique<shape_visitor::Rectangle>(rect1) );
    shapes.emplace_back( std::make_unique<shape_visitor::Square>(square2) );

    // Modern c++ for loop!
    shape_visitor::Area area_visitor {};
    shape_visitor::Perimeter perim_visitor {};
    
    for (auto const& shape : shapes) {
        /**
         *  We invoke the visitor by calling accept() and passing the operation! 
         **/
        shape->accept( area_visitor );
        std::cout << "Area: " << area_visitor.get_value() << std::endl;
        shape->accept( perim_visitor );
        std::cout << "Perimeter: " << perim_visitor.get_value() << std::endl;
    }

}