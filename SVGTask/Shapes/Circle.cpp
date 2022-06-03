#include "Circle.hpp"
#include "../Helpers/Constants.hpp"
#include "../Helpers/Helpers.hpp"

Circle::Circle() : radius(0) {}
Circle::Circle(const Point& point, const Color& fill, const double radius) : Shape(point, fill), radius(radius) {}
Circle::~Circle() {}

Shape* Circle::clone() const
{
    return new Circle(*this);
}

double Circle::getRadius() const
{
    return radius;
}
double Circle::getArea() const
{
    return radius * radius * PI;
}
double Circle::getPerimeter() const
{
    return 2*PI*radius;
}

void Circle::setRadius(const double radius)
{
    this->radius = radius;
}

void Circle::writeToFile(ostream& os)
{
    os << "<circle cx=\"" << getStartPoint().getX() << "\" ";
    os << "cy=\"" << getStartPoint().getY() << "\" ";
    os << "r=\"" << radius << "\" ";
    os << "fill=\"" << colorToString(getFill()) << "\" />";
}
void Circle::readFromTag(const char* tag)
{
    char buffer[MAX_INPUT_SIZE];
    for(int i = 0, char_counter = 0; i <= strlen(tag); i++)
    {
        
        if(tag[i] == ' ')
        {
            buffer[char_counter] = '\0';
            
            if(buffer[0] == 'c' && buffer[1] == 'x')
            {
                Point new_start(atof(extractFromQuotes(buffer)), getStartPoint().getY());
                setStartPoint(new_start);
            }
            if(buffer[0] == 'c' && buffer[1] == 'y')
            {
                Point new_start(getStartPoint().getX(), atof(extractFromQuotes(buffer)));
                setStartPoint(new_start);
            }
            if(buffer[0] == 'r')
            {
                setRadius(atof(extractFromQuotes(buffer)));
            }
            if(buffer[0] == 'f')
            {
                setFill(getColorByName(extractFromQuotes(buffer)));
            }

            char_counter = 0;
            continue;
        }

        buffer[char_counter++] = tag[i];
    }
    
}

bool Circle::withinRectangle(const Point& area_start, const double width, const double height) const
{
    double shape_startX = getStartPoint().getX();
    double shape_startY = getStartPoint().getY();
    
    // check if five points are inside given rectangle
    if(checkPointWithinRectangle(getStartPoint(), area_start, width, height) &&
       checkPointWithinRectangle(Point(shape_startX + radius, shape_startY), area_start, width, height) &&
       checkPointWithinRectangle(Point(shape_startX - radius, shape_startY), area_start, width, height) &&
       checkPointWithinRectangle(Point(shape_startX, shape_startY + radius), area_start, width, height) &&
       checkPointWithinRectangle(Point(shape_startX, shape_startY - radius), area_start, width, height))
    {
       return true;
    }

    return false;
}
bool Circle::withinCircle(const Point& center, const double radius) const
{
    Point shape_center = getStartPoint();
    double distSq = sqrt(((center.getX() - shape_center.getX()) * 
                       (center.getX() - shape_center.getX()) + 
                       (center.getY() - shape_center.getY()) * 
                       (center.getY() - shape_center.getY())));
    
    if(distSq + this->radius <= radius)
    {
        return true;
    }
    
    return false;
}
bool Circle::pointIn(const Point& p_in) const
{
    return checkPointWithinCircle(p_in, getStartPoint(), radius);
}
void Circle::translate(const double x_change, const double y_change)
{
    Shape::translate(x_change, y_change);
}
void Circle::read(istream& is)
{
    readStartPoint(is);
    is >> radius;
    
    if(radius < 0)
    {
        radius = 1;
    }
    
    readColor(is);
}
void Circle::print(ostream& os) const
{
    os << "circle ";
    Shape::print(os);
    os << " radius = " << radius;
}