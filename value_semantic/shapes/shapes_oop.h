#include <stdlib.h>
#include <vector>
#include <variant>
#include <memory>

namespace oop
{

class Circle;
class Square;

class ShapeVisitor
{
public:
  virtual ~ShapeVisitor() = default;
  virtual void visit( const Circle& ) const = 0;
  virtual void visit( const Square& ) const = 0;
};

class Shape
{
public:
  Shape() = default;
  virtual ~Shape() = default;

  virtual void accept( const ShapeVisitor& ) = 0;
};

class Circle : public Shape
{
public:
  explicit Circle( double rad)
    : radius_{ rad }
    {}

  double getRadius() const { return radius_; };

  void accept( const ShapeVisitor& sv) override {
    sv.visit(*this);
  };

private:
  double radius_;
};

class Square : public Shape
{
public:
  explicit Square( double s)
    : side_{ s }
    {}

  double getSide() const { return side_; };

  void accept( const ShapeVisitor& sv) override {
    sv.visit(*this);
  };

private:
  double side_;
};

class Draw : public ShapeVisitor
{
public:
  void visit( const Circle& c) const override {
    volatile auto a = c.getRadius();
    return;
  };
  void visit( const Square& s) const override {
    volatile auto a = s.getSide();
    return;
  };
};

void drawAllShapes(
  const std::vector<std::unique_ptr<Shape>>& shapes)
{
  for(const auto& s : shapes)
  {
    s->accept(Draw{});
  }
}

using Shapes = std::vector<std::unique_ptr<oop::Shape>>;

Shapes makeShapes(int N)
{
  Shapes shapes;
  shapes.reserve(N);
  for (int i=0; i<N; i++) {
      int r = rand();
      if ((r%2)==0)
          shapes.emplace_back(std::make_unique<oop::Circle>(r));
      else
          shapes.emplace_back(std::make_unique<oop::Square>(r));
  }
  return shapes;
}

}
