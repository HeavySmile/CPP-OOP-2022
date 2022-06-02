#pragma once
#include "Point.hpp"
#include "Constants.hpp"
#include <iostream>
#include <cmath>
using namespace std;

enum Color
{
    RED = 0,
    GREEN = 1,
    BLUE = 2,
    YELLOW = 3,
    BLACK = 4,
    PURPLE = 5,
    DEFAULT = 6
};

class Shape
{
private:
    Point start;
    Color fill;
public:
    Shape();
    Shape(const Point&, const Color&);
    virtual ~Shape() = 0;

    virtual Shape* clone() const = 0;

    Point getStartPoint() const;
    Color getFill() const;
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void writeToFile(ostream&) = 0;
    virtual void readFromTag(const char*) = 0;

    void setStartPoint(const Point&);
    void setFill(const Color&);

    void readStartPoint(istream&);
    void readColor(istream&);

    virtual bool withinRectangle(const Point&, const double, const double) const = 0;
    virtual bool withinCircle(const Point&, const double) const = 0;
    virtual void read(istream&) = 0;  
    virtual bool pointIn(const Point&) const = 0;  
    virtual void translate(const double, const double);
    virtual void print(ostream&) const;

    static int shapes_counter;
};