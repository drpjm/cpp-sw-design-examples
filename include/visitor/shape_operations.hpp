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
        void visit(shape_visitor::Circle const& circ)  override {
            value_ = PI * std::pow(circ.radius(), 2);
            return;
        }
        void visit(shape_visitor::Square const& sq)  override {
            value_ = sq.side() * sq.side();
            return;
        }
        void visit(shape_visitor::Rectangle const& rect)  override {
            value_ = rect.length() * rect.width();
            return;
        }
        float get_value() const {
            return value_;
        }
    private:
        float value_;
};

class Perimeter : public ShapeVisitor {

    public:
        /**
         * This visitor computes the perimeter of the given shape.
         */
        void visit(shape_visitor::Circle const& circ)  override {
            value_ = 2 * PI * circ.radius();
            return;
        }
        void visit(shape_visitor::Square const& sq)  override {
            value_ = 4 * sq.side();
            return;
        }
        void visit(shape_visitor::Rectangle const& rect)  override {
            value_ = 2 * rect.length() + 2 * rect.width();
            return;
        }
        float get_value() const {
            return value_;
        }
    private:
        float value_;

};

}

#endif  // SHAPE_OPERATIONS_HPP