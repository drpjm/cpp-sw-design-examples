#ifndef SHAPE_VISITOR_HPP
#define SHAPE_VISITOR_HPP

// We declare these here, but they will be implemented elsewhere.
class Circle;
class Square;

namespace shape_visitor {

class ShapeVisitor {
    /**
     *  This class is not implemented - it is an interface.
     */
    public:
        virtual ~ShapeVisitor() = default;

        virtual void visit( Circle const& ) const = 0;
        virtual void visit( Square const& ) const = 0;
};

}

#endif  // SHAPE_VISITOR_HPP