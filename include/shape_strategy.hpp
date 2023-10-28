#ifndef SHAPE_STRATEGY_HPP
#define SHAPE_STRATEGY_HPP

#include <memory>
#include <utility>

namespace shape_strategy {

/**
 *  Sets up the highest level abstract interfaces.
 *  Note that this pattern limits the operations, but allows new types
 *  in the Shape hierarchy.
 **/
class Shape {
    public:
        virtual ~Shape() = default;
        virtual void print( /* args */ ) const = 0;
};

/**
 *  This class is an INTERFACE! No instantiation.
 *  All subclasses must implement the print() function
 *  based on the ShapeType. 
 **/
template<typename ShapeType>
class PrintStrategy {
    public:
        virtual ~PrintStrategy() = default;
        virtual void print( ShapeType const& ) const = 0;
};

class Circle : public Shape {

    public:
        explicit Circle(double radius, std::unique_ptr<PrintStrategy<Circle>> printer) :
            radius_ (radius), 
            circ_printer_ ( std::move( printer ) ) {}

        void print(/* stuff one day */) const override {
            circ_printer_->print( *this );
        }
        double radius() const { return radius_; }
    private:
        double radius_;
        std::unique_ptr<PrintStrategy<Circle>> circ_printer_;

};

}

#endif  // SHAPE_STRATEGY_HPP