#include "Point.hpp"

Point::Point() : x(0), y(0) {}
Point::Point(const double x, const double y) : x(x), y(y) {}
Point::Point(const Point& copyFrom) : x(copyFrom.x), y(copyFrom.y) {}

double Point::getX() const
{
    return x;
}
double Point::getY() const
{
    return y;
}

void Point::setX(const double x)
{
    this->x = x;
}
void Point::setY(const double y)
{
    this->y = y;
}

void Point::translate(const double x_change, const double y_change)
{
    x += x_change;
    y += y_change;
}
void Point::read(istream& is)
{
    is >> x >> y;

    if(x < 0 || y < 0)
    {
        x = 1;
        y = 1;
    }
}
void Point::print(ostream& os) const
{
    os << "x = " << x << " y = " << y;
}