#ifndef FIGUREFUNCTION_HPP
#define FIGUREFUNCTION_HPP

#include <cstddef>
#include "base-types.hpp"

namespace rebdev
{
  rectangle_t getFrameRectangle(const point_t vertexes[], size_t numOfVertexes);
  void scaleFigure(point_t vertexes[], size_t numOfVertexes, const point_t & center, double k);
}
#endif