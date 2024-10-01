#include <stdlib.h>
#include <vector>
#include <variant>
#include <memory>

namespace variant
{


class Circle
{
public:
  explicit Circle( double rad)
    : radius_{ rad }
    {}

  double getRadius() const { return radius_; };

private:
  double radius_;
};

class Square
{
public:
  explicit Square( double s)
    : side_{ s }
    {}

  double getSide() const { return side_; };

private:
  double side_;
};

class Draw
{
public:
  void operator()( const Circle& c) const {
    volatile auto a = c.getRadius();
    return;
  };
  void operator()( const Square& s) const {
    volatile auto a = s.getSide();
    return;
  };
};

using Shape = std::variant<Circle, Square>;

void drawAllShapes(
  const std::vector<Shape>& shapes)
{
  for(const auto& s : shapes)
  {
    std::visit(Draw{}, s);
  }
}

using Shapes = std::vector<Shape>;

Shapes makeShapes(int N)
{
    Shapes shapes;
    shapes.reserve(N);
    for (int i=0; i<N; i++) {
        int r = rand();
        if ((r%2)==0)
            shapes.emplace_back(Circle(r));
        else
            shapes.emplace_back(Square(r));
    }
    return shapes;
}

}
