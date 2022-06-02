#include "Helpers.hpp"

char* extractFromQuotes(const char* tag)
{
    bool inside = false;
    char* value = new char[20];
    for (int i = 0, j = 0; i <= strlen(tag); i++)
    {
        if(tag[i] == '\"')
        {
            inside = true;
            continue;
        }

        if(inside && tag[i] != '\"')
        {
            value[j] = tag[i];
            j++;
        }
        else if(inside && tag[i] == '\"')
        {
            value[j] = '\0';
            j = 0;
            break;
        }
    }

    return value;
}
bool checkPointWithinRectangle(const Point& point, const Point& start, const double width, const double height)
{
    if(point.getX() >= start.getX() && point.getY() <= start.getY() &&
       point.getX() <= (start.getX() + width) &&
       point.getY() >= (start.getY() - height))
    {
        return true;
    }

    return false;
}
bool checkPointWithinCircle(const Point& point, const Point& center, const double radius)
{
    if ((point.getX() - center.getX()) * (point.getX() - center.getX()) +
        (point.getY() - center.getY()) * (point.getY() - center.getY()) <= radius * radius)
    {
        return true;
    }

    return false;
}

Color getColorByName(const char* color_name)
{
    if(!strcmp(color_name, "red")) return RED;
    else if(!strcmp(color_name, "green")) return GREEN;
    else if(!strcmp(color_name, "blue")) return BLUE;
    else if(!strcmp(color_name, "yellow")) return YELLOW;
    else if(!strcmp(color_name, "black")) return BLACK;
    else if(!strcmp(color_name, "purple")) return PURPLE;
    
    return DEFAULT;
}
const char* colorToString(const Color& color)
{
    switch(color)
    {
    case RED:
        return "red";
        break;
    case GREEN:
        return "green";
        break;
    case BLUE:
        return "blue";
        break;
    case YELLOW:
        return "yellow";
        break;
    case BLACK:
        return "black";
        break;
    case PURPLE:
        return "purple";
        break;
    default:
        return "black";
        break;
    }
}