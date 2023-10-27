#ifndef SHAPE_STRATEGY_HPP
#define SHAPE_STRATEGY_HPP

#include <memory>
#include <utility>

namespace shape_strategy {

class Circle;
// class Square;
// class Rectangle;

/**
 *  These abstract strategy classes setup the structure
 *  for varying the implementation of printing each of these shapes. 
 **/
class PrintCircleStrategy {
    public:
        virtual ~PrintCircleStrategy() = default;
        virtual void print( Circle const& circ ) const = 0;
};
// class PrintSquareStrategy {
//     public:
//         virtual ~PrintSquareStrategy() = default;
//         virtual void print( Square const& sq ) const = 0;
// };
// class PrintRectangleStrategy {
//     public:
//         virtual ~PrintRectangleStrategy() = default;
//         virtual void print( Circle const& rect ) const = 0;
// };

/**
 *  Sets up the highest level abstract interfaces.
 *  Note that this pattern limits the operations, but allows new types. 
 **/
class Shape {
    public:
        virtual ~Shape() = default;
        virtual void print() const = 0;
};

class Circle : Shape {
    public:
        explicit Circle(double radius, std::unique_ptr<PrintCircleStrategy> printer) : radius_ (radius) {}
        
        void print() const override {
            printer_->print( *this );
        }

        double radius() const {
            return radius_;
        }

    private:
        float radius_;
        std::unique_ptr<PrintCircleStrategy> printer_;
};

}

#endif  // SHAPE_STRATEGY_HPP