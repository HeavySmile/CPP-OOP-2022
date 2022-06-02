#pragma once
#include <iostream>
using namespace std;

class Point
{
private:
    double x,y;
public:
    Point();
    Point(const double, const double);
    Point(const Point&);

    double getX() const;
    double getY() const;

    void setX(const double);
    void setY(const double);

    void translate(const double, const double);
    void read(istream&);
    void print(ostream&) const;
};