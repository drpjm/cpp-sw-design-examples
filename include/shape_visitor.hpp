#ifndef SHAPE_VISITOR_HPP
#define SHAPE_VISITOR_HPP

/**
 * We declare these here so the ShapeVisitor knows what they are.
 * They will be implemented elsewhere.
 **/
namespace shape_visitor {

class Circle;
class Square;
class Rectangle;

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
        virtual void visit( shape_visitor::Circle const& ) const = 0;
        virtual void visit( shape_visitor::Square const& ) const = 0;
        virtual void visit( shape_visitor::Rectangle const& ) const = 0;
};

}

#endif  // SHAPE_VISITOR_HPP