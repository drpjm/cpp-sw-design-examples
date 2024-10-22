#ifndef SHAPE_OPERATIONS_HPP
#define SHAPE_OPERATIONS_HPP

#include "shape_visitor.hpp"
#include <iostream>
#include <cmath>

/**
 *  This header captures the operations we want to perform over the 
 *  Shape objects using the visitor pattern.
 **/

namespace shape_visitor {

float PI = 3.14159;

class Area : public ShapeVisitor {

    public:
        /**
         * This visitor type computes the area of each entity that will be visited.
         */
        void visit(shape_visitor::Circle const& circ) const override {
            auto area = PI * std::pow(circ.radius(), 2);
            std::cout << "Area Circle: " << area << std::endl;
            return;
        }
        void visit(shape_visitor::Square const& sq) const override {
            auto area = sq.side() * sq.side();
            std::cout << "Area Square: " << area << std::endl;
            return;
        }
        void visit(shape_visitor::Rectangle const& rect) const override {
            auto area = rect.length() * rect.width();
            std::cout << "Area Rectangle: " << area << std::endl;
            return;
        }

};

class Perimeter : public ShapeVisitor {

    public:
        /**
         * This visitor computes the perimeter of the given shape.
         */
        void visit(shape_visitor::Circle const& circ) const override {
            auto perim = 2 * PI * circ.radius();
            std::cout << "Perimeter Circle: " << perim << std::endl;
            return;
        }
        void visit(shape_visitor::Square const& sq) const override {
            auto perim = 4 * sq.side();
            std::cout << "Perimeter Square: " << perim << std::endl;
            return;
        }
        void visit(shape_visitor::Rectangle const& rect) const override {
            auto perim = 2 * rect.length() + 2 * rect.width();
            std::cout << "Perimeter Rectangle: " << perim << std::endl;
            return;
        }

};

}

#endif  // SHAPE_OPERATIONS_HPP