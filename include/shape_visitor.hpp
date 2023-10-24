#ifndef SHAPE_VISITOR_HPP
#define SHAPE_VISITOR_HPP

/**
 * We declare these here so the ShapeVisitor knows what they are.
 * They will be implemented elsewhere.
 **/
namespace shape {
    class Circle;
    class Square;
    class Rectangle;
}

namespace shape_visitor {

class ShapeVisitor {
    /**
     *  This class is not implemented - it is an interface.
     */
    public:
        virtual ~ShapeVisitor() = default;

        /**
         *  The ShapeVisitor base class must know about all of the
         *  types in advance. 
         **/
        virtual void visit( shape::Circle const& ) const = 0;
        virtual void visit( shape::Square const& ) const = 0;
        virtual void visit( shape::Rectangle const& ) const = 0;
};

}

#endif  // SHAPE_VISITOR_HPP