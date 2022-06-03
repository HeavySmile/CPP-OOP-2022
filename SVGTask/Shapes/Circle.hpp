#pragma once
#include "Shape.hpp"

class Circle : public Shape
{
private:
    double radius;
public:
    Circle();
    Circle(const Point&, const Color&, const double);
    ~Circle();

    Shape* clone() const override;

    double getRadius() const;
    double getArea() const override;
    double getPerimeter() const override;
    
    void setRadius(const double);

    void writeToFile(ostream&) override;
    void readFromTag(const char*) override;
    
    bool withinRectangle(const Point&, const double, const double) const override;
    bool withinCircle(const Point&, const double) const override;
    bool pointIn(const Point&) const override;
    void translate(const double, const double) override;
    void read(istream&) override;
    void print(ostream&) const override;
};