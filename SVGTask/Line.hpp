#pragma once
#include "Shape.hpp"
#include "Helpers.hpp"

class Line : public Shape
{
private:
    Point end;
public:
    Line();
    Line(const Point&, const Color&, const Point&);
    ~Line();

    Shape* clone() const override;

    Point getEndPoint() const;
    double getArea() const override;
    double getPerimeter() const override;
    void writeToFile(ostream&) override;
    void readFromTag(const char*) override;

    void setEndPoint(const Point&);
    
    bool withinRectangle(const Point&, const double, const double) const override;
    bool withinCircle(const Point&, const double) const override;
    bool pointIn(const Point&) const override;
    void translate(const double, const double) override;
    void read(istream&) override;
    void print(ostream&) const override;
};