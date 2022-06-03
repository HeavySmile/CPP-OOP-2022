#pragma once
#include "Shape.hpp"

class Rectangle : public Shape
{
private:
    double width, height;
public:
    Rectangle();
    Rectangle(const Point&, const Color&, const double, const double);
    ~Rectangle();

    Shape* clone() const override;

    double getWidth() const;
    double getHeight() const;
    double getArea() const override;
    double getPerimeter() const override;
    
    void setWidth(const double);
    void setHeight(const double);

    void writeToFile(ostream&) override;
    void readFromTag(const char*) override;

    bool withinRectangle(const Point&, const double, const double) const override;
    bool withinCircle(const Point&, const double) const override;
    bool pointIn(const Point&) const override;
    void translate(const double, const double) override;
    void read(istream&) override;
    void print(ostream&) const override;
};