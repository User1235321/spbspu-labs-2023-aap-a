#ifndef POLYGON_HPP
#define POLYGON_HPP
#include "base-types.hpp"
#include "shape.hpp"
#include <cstddef>
namespace rebdev
{
  class Polygon: public Shape
  {
    public:
      Polygon(const point_t * vertexs, const size_t numOfVertexs);

      virtual ~Polygon();
      virtual double getArea() const;
      virtual rectangle_t getFrameRect() const;
      virtual void move(const point_t point);
      virtual void move(const double x, const double y);
      virtual void scale(const double k);
    private:
      point_t * vertexs_;
      size_t numOfVertexs_;
  };
}
#endif