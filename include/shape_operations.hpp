#include "shape_visitor.hpp"
#include <iostream>

/**
 *  This header captures the operations we want to perform over the 
 *  Shape objects using the visitor pattern.
 **/

namespace shape_visitor {

/**
 *  Each new operation we want, we extend ShapeVisitor and implement
 *  what the visitor performs using the visit function. 
 **/
class Print : public ShapeVisitor{

    public:
        /**
         *  Every type within the Shape hierarchy needs its own visit function!
         *  So, better make sure you have all of your types! 
         **/
        void visit(shape_visitor::Circle const& circ) const override {
            std::cout << "Circle with r = " << circ.radius() << std::endl;
        }
        void visit(shape_visitor::Square const& sq) const override {
            std::cout << "Square with side = " << sq.side() << std::endl;
        }
        void visit(shape_visitor::Rectangle const& rect) const override {
            std::cout << "Rectangle with length = " << rect.length() << ", width = " << rect.width() << std::endl;
        }

};

}