#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "shape_visitor.hpp"

namespace shape {

class Shape {
    /**
     *  This class is not implemented - it is an interface.
     */
    public:
        virtual ~Shape() = default;
        virtual void accept( shape_visitor::ShapeVisitor const& sv ) = 0;
};

class Circle : public Shape
{
    public:
        explicit Circle( double radius ) : radius_( radius ) {}
        
        void accept( shape_visitor::ShapeVisitor const& sv ) override { sv.visit(*this); } 
        double radius() const { return radius_; }

    private:
        double radius_;
};

class Square : public Shape {
    public:
        explicit Square( double side ) : side_ (side) {}

        void accept( shape_visitor::ShapeVisitor const& sv ) override { sv.visit(*this); }
        double side() const { return side_; }

    private:
        double side_;
};

}

#endif  // SHAPE_HPP