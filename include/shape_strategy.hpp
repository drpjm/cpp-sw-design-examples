#ifndef SHAPE_STRATEGY_HPP
#define SHAPE_STRATEGY_HPP

namespace shape_strategy {

class Circle;
class Square;
class Rectangle;

/**
 *  These abstract strategy classes setup the structure
 *  for varying the implementation of printing each of these shapes. 
 **/
class PrintCircleStrategy {
    public:
        virtual ~PrintCircleStrategy() = default;
        virtual void print( Circle const& circ ) const;
};
class PrintSquareStrategy {
    public:
        virtual ~PrintSquareStrategy() = default;
        virtual void print( Square const& sq ) const;
};
class PrintRectangleStrategy {
    public:
        virtual ~PrintRectangleStrategy() = default;
        virtual void print( Circle const& rect ) const;
};

/**
 *  Sets up the highest level abstract interfaces.
 *  Note that this pattern limits the operations, but allows new types. 
 **/
class Shape {
    public:
        virtual ~Shape() = default;
        virtual void print() const = 0;
};

}

#endif  // SHAPE_STRATEGY_HPP