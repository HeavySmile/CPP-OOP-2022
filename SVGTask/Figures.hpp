#pragma once
#include "Shapes/Shape.hpp"
#include "Shapes/Rectangle.hpp"
#include "Shapes/Circle.hpp"
#include "Shapes/Line.hpp"
#include <fstream>
#include <iostream>
using namespace std;

class Figures
{
private:
    Shape** shapes;
    int shapesLimit;
    
    Shape* createShapeByName(const char*);
    Shape* cloneShape(const Shape*);
public:
    Figures();
    ~Figures();

    void translate(const int, const double, const double);
    void translateAll(const double, const double);
    void create();
    void erase();

    void pers() const;
    void areas() const;
    void pointIn() const;
    void withinRectangle();
    void withinCircle();
    void writeToFile(const char*);
    void readFromFile(const char*);
    void print() const;
};