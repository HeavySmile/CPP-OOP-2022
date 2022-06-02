#include "Line.hpp"

Line::Line() : end() {}
Line::Line(const Point& start_point, const Color& fill, const Point& end_point) : Shape(start_point, fill), end(end_point) {}
Line::~Line() {};

Shape* Line::clone() const
{
    return new Line(*this);
}

Point Line::getEndPoint() const
{
    return end;
}
double Line::getArea() const
{
    return 0;
}
double Line::getPerimeter() const
{
    return 0;
}
void Line::writeToFile(ostream& os)
{
    os << "<line x1=\"" << getStartPoint().getX() << "\" ";
    os << "y1=\"" << getStartPoint().getY() << "\" ";
    os << "x2=\"" << end.getX() << "\" ";
    os << "y2=\"" << end.getY() << "\" ";
    os << "fill=\"" << colorToString(getFill()) << "\" />";
}
void Line::readFromTag(const char* tag)
{
    char buffer[MAX_INPUT_SIZE];
    for(int i = 0, char_counter = 0; i <= strlen(tag); i++)
    {
        
        if(tag[i] == ' ')
        {
            buffer[char_counter] = '\0';
            
            if(buffer[0] == 'x' && buffer[1] == '1')
            {
                Point new_start(atof(extractFromQuotes(buffer)), getStartPoint().getY());
                setStartPoint(new_start);
            }
            if(buffer[0] == 'y' && buffer[1] == '1')
            {
                Point new_start(getStartPoint().getX(), atof(extractFromQuotes(buffer)));
                setStartPoint(new_start);
            }
            if(buffer[0] == 'x' && buffer[1] == '2')
            {
                Point new_end(atof(extractFromQuotes(buffer)), end.getY());
                end = new_end;
            }
            if(buffer[0] == 'y' && buffer[1] == '2')
            {
                Point new_end(end.getX(), atof(extractFromQuotes(buffer)));
                end = new_end;
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

void Line::setEndPoint(const Point& end_point)
{
    end = end_point;
}
bool Line::withinRectangle(const Point& area_start, const double width, const double height) const
{
    if(checkPointWithinRectangle(getStartPoint(), area_start, width, height) &&
       checkPointWithinRectangle(end, area_start, width, height))
    {
        return true;
    }
    return false;
}
bool Line::withinCircle(const Point& center, const double radius) const
{
    Point shape_start = getStartPoint();  
    if(checkPointWithinCircle(shape_start, center, radius) &&
       checkPointWithinCircle(end, center, radius))
    {
        return true;
    }
    return false;
}
bool Line::pointIn(const Point& p_in) const
{
    Point shape_p1 = getStartPoint();
    Point shape_p2 = getEndPoint();

    double a = (shape_p2.getY() - shape_p1.getY()) / (shape_p2.getX() - shape_p2.getX());
    double b = shape_p1.getY() - a * shape_p1.getX();
    
    if (p_in.getY() - (a * p_in.getX() + b) < EPSILON || p_in.getY() - (a * p_in.getX() + b) > -EPSILON)
    {
        return true;
    }

    return false;
}
void Line::translate(const double x_change, const double y_change)
{
    Shape::translate(x_change, y_change);
    end.translate(x_change, y_change);
}
void Line::read(istream& is)
{
    readStartPoint(is);
    end.read(is);
    readColor(is);
}
void Line::print(ostream& os) const
{
    os << "line ";
    Shape::print(os);
    os << " ";
    end.print(os);
}