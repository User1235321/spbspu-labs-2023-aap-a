#include "outputShapes.hpp"

void rebdev::outputShapes(Shape ** shapes, size_t numOfShapes, std::ostream & out)
{
  double sum = 0;
  for (size_t i = 0; i < numOfShapes; ++i)
  {
    sum += shapes[i]->getArea();
  }

  out << std::fixed;
  out.precision(1);

  out << sum;

  for (size_t i = 0; i < numOfShapes; ++i)
  {
    rebdev::rectangle_t rect = shapes[i]->getFrameRect();
    rebdev::point_t lowLeft = {rect.pos.x - rect.width / 2, rect.pos.y - rect.height / 2};
    rebdev::point_t upRight = {rect.pos.x + rect.width / 2, rect.pos.y + rect.height / 2};
    out << ' ' << lowLeft.x << ' ' << lowLeft.y;
    out << ' ' << upRight.x << ' ' << upRight.y;
  }
};
