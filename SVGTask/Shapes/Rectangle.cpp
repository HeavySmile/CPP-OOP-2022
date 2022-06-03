#include "Rectangle.hpp"
#include "../Helpers/Helpers.hpp"

Rectangle::Rectangle() : width(0), height(0) {}
Rectangle::Rectangle(const Point &point, const Color &fill, const double width, const double height) : 
Shape(point, fill), width(width), height(height) {}
Rectangle::~Rectangle() {}

Shape* Rectangle::clone() const
{
    return new Rectangle(*this);
}

double Rectangle::getWidth() const
{
    return width;
}
double Rectangle::getHeight() const
{
    return height;
}
double Rectangle::getArea() const 
{
    return height * width;
}
double Rectangle::getPerimeter() const
{
    return 2 * (height + width);
}
void Rectangle::writeToFile(ostream& os)
{
    os << "<rect x=\"" << getStartPoint().getX() << "\" ";
    os << "y=\"" << getStartPoint().getY() << "\" ";
    os << "width=\"" << width << "\" ";
    os << "height=\"" << height << "\" ";
    os << "fill=\"" << colorToString(getFill()) << "\" />";
}
void Rectangle::readFromTag(const char* tag)
{
    char buffer[MAX_INPUT_SIZE];
    
    for(int i = 0, char_counter = 0; i <= strlen(tag); i++)
    {
        
        if(tag[i] == ' ')
        {
            buffer[char_counter] = '\0';
            
            if(buffer[0] == 'x')
            {
                Point new_start(atof(extractFromQuotes(buffer)), getStartPoint().getY());
                setStartPoint(new_start);
            }
            if(buffer[0] == 'y')
            {
                Point new_start(getStartPoint().getX(), atof(extractFromQuotes(buffer)));
                setStartPoint(new_start);
            }
            if(buffer[0] == 'w')
            {
                setWidth(atof(extractFromQuotes(buffer)));
            }
            if(buffer[0] == 'h')
            {
                setHeight(atof(extractFromQuotes(buffer)));
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

void Rectangle::setWidth(const double width)
{
    this->width = width;
}
void Rectangle::setHeight(const double height)
{
    this->height = height;
}

bool Rectangle::withinRectangle(const Point& area_start, const double width, const double height) const
{   
    if(checkPointWithinRectangle(getStartPoint(), area_start, width, height))
    {
        Point shape_end(getStartPoint().getX() + width, getStartPoint().getY() - height);
        if(checkPointWithinRectangle(shape_end, area_start, width, height))
        {
            return true;
        }
    }

    return false;
}
bool Rectangle::withinCircle(const Point& center, const double radius) const
{
    Point shape_start = getStartPoint();  
    if(checkPointWithinCircle(shape_start, center, radius) &&
       checkPointWithinCircle(Point(shape_start.getX() + width, shape_start.getY() - height), center, radius))
    {
        return true;
    }
    return false;
}
bool Rectangle::pointIn(const Point& p_in) const
{
    return checkPointWithinRectangle(p_in, getStartPoint(), width, height);
}
void Rectangle::translate(const double x_change, const double y_change)
{
    Shape::translate(x_change, y_change);
}
void Rectangle::read(istream& is)
{
    readStartPoint(is);
    is >> width >> height;
    
    if(width < 0 || height < 0)
    {
        width = 1;
        height = 1;
    }

    readColor(is);
}
void Rectangle::print(ostream& os) const
{
    os << "rectangle ";
    Shape::print(os);
    os << " width = " << width << " height = " << height; 
}