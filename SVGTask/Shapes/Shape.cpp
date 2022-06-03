#include "Shape.hpp"
#include "../Helpers/Constants.hpp"
#include "../Helpers/Helpers.hpp"

Shape::Shape() : start(0,0), fill(DEFAULT) {}
Shape::Shape(const Point& point, const Color& fill) : start(point), fill(fill) {}
Shape::~Shape() {}

Point Shape::getStartPoint() const
{
    return start;
}
Color Shape::getFill() const
{
    return fill;
}

void Shape::setStartPoint(const Point& point)
{
    start = point;
}
void Shape::setFill(const Color& fill)
{
    this->fill = fill;
}

void Shape::translate(const double x_change, const double y_change)
{
    start.translate(x_change, y_change);
}
void Shape::readStartPoint(istream& is)
{
    start.read(is);
}
void Shape::readColor(istream& is)
{
    char buffer[MAX_INPUT_SIZE];
    is >> buffer;

    fill = getColorByName(buffer);
}
void Shape::print(ostream& os) const
{
    start.print(os);
    os << " fill = ";
    switch (fill)
    {
    case RED:
        os << "red";
        break;
    case GREEN:
        os << "green";
        break;
    case BLUE:
        os << "blue";
        break;
    default:
        os << "black";
        break;
    }
}

int Shape::shapes_counter = 0;