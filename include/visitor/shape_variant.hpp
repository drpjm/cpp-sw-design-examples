#ifndef SHAPE_VARIANT_HPP
#define SHAPE_VARIANT_HPP
#include <variant>

namespace shape_variant {

float PI = 3.14159;

class Circle {
    public:
        explicit Circle( double radius ) : radius_( radius ) {}
        double radius() const { return radius_; }

    private:
        double radius_;
};

class Square {
    public:
        explicit Square( double side ) : side_ (side) {}
        double side() const { return side_; }

    private:
        double side_;
};

class Rectangle {
    public:
        explicit Rectangle(double length, double width) : length_ (length), width_ (width) {}
        double length() const { return length_; }
        double width() const { return width_; }

    private:
        double length_;
        double width_;
};

/**
 * All hail the variant!
 */
using Shape = std::variant<Circle, Square, Rectangle>;

class AreaVisitor {
    public:
        float operator()(Circle const& circ) {
            return PI * std::pow(circ.radius(), 2);
        }
        float operator()(Square const& sq) {
            return sq.side() * sq.side();
        }
        float operator()(Rectangle const& rect) {
            return rect.length() * rect.width();
        }
};

class PerimeterVisitor {
    public:
        float operator()(Circle const& circ) {
            return 2 * PI * circ.radius();
        }
        float operator()(Square const& sq) {
            return 4 * sq.side();
        }
        float operator()(Rectangle const& rect) {
            return 2 * rect.length() + 2 * rect.width();
        }
};

}

#endif // SHAPE_VARIANT_HPP