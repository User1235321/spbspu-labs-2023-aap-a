#include "inputshape.hpp"
#include <string>
#include <iostream>
#include "compositeshape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "parallelogram.hpp"

void piyavkin::inputParameters(std::istream& in, double* parameters, size_t parametersCount)
{
  for (size_t j = 0; j < parametersCount; ++j)
  {
    in >> parameters[j];
  }
  if (!in)
  {
    throw std::logic_error("Invalid arguments");
  }
}

void piyavkin::clearMemory(Shape** shapes, size_t shapeCount)
{
  for (size_t i = 0; i < shapeCount; ++i)
  {
    delete shapes[i];
  }
  delete[] shapes;
}

piyavkin::Shape* piyavkin::inputRectangle(std::istream& in)
{
  constexpr size_t parametersCount = 4;
  double parameters[parametersCount] = {};
  inputParameters(in, parameters, parametersCount);
  Shape* shape = new Rectangle({parameters[0], parameters[1]}, {parameters[2], parameters[3]});
  return shape;
}

piyavkin::Shape* piyavkin::inputTriangle(std::istream& in)
{
  constexpr size_t parametersCount = 6;
  double parameters[parametersCount] = {};
  inputParameters(in, parameters, parametersCount);
  Shape* shape = new Triangle({parameters[0], parameters[1]}, {parameters[2], parameters[3]}, {parameters[4], parameters[5]});
  return shape;
}

piyavkin::Shape* piyavkin::inputParallelogram(std::istream& in)
{
  constexpr size_t parametersCount = 6;
  double parameters[parametersCount] = {};
  inputParameters(in, parameters, parametersCount);
  Shape* shape = new Parallelogram({parameters[0], parameters[1]}, {parameters[2], parameters[3]}, {parameters[4], parameters[5]});
  return shape;
}

void piyavkin::inputShape(std::istream& in, CompositeShape& cs)
{
  std::string name = "";
  constexpr size_t numbersFigures = 3;
  std::string shapeNames[numbersFigures] = {"RECTANGLE", "TRIANGLE", "PARALLELOGRAM"};
  char symbol = 0;
  while (in >> name)
  {
    for (size_t i = 0; i < numbersFigures; ++i)
    {
      if (name == shapeNames[i])
      {
        try
        {
          if (name == "RECTANGLE")
          {
            cs.push_back(inputRectangle(in));
          }
          else if (name == "TRIANGLE")
          {
            cs.push_back(inputTriangle(in));
          }
          else if (name == "PARALLELOGRAM")
          {
            cs.push_back(inputParallelogram(in));
          }
        }
        catch (const std::logic_error& e)
        {
          std::cerr << e.what() << '\n';
          continue;
        }
        catch (const std::bad_alloc& e)
        {
          throw;
        }
      }
    }
    if (name == "SCALE")
    {
      break;
    }
    in >> std::noskipws;
    while (symbol != '\n')
    {
      in >> symbol;
    }
    in >> std::skipws;
  }
  if (!in)
  {
    throw std::logic_error("It is not shape");
  }
}

