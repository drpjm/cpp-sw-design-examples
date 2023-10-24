#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "shape_visitor.hpp"

namespace shape {

class Shape {
    /**
     *  This class is not implemented - it is an interface to accept visitors.
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

class Rectangle : public Shape {
    public:
        explicit Rectangle(double length, double width) : length_ (length), width_ (width) {}
        
        void accept( shape_visitor::ShapeVisitor const& sv ) override { sv.visit(*this); }
        double length() const { return length_; }
        double width() const { return width_; }

    private:
        double length_;
        double width_;
};

}

#endif  // SHAPE_HPP