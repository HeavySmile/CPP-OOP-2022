#pragma once
#include "Shape.hpp"

Shape* clone(const Shape*);

char* extractFromQuotes(const char*);
bool checkPointWithinRectangle(const Point& point, const Point& start, const double width, const double height);
bool checkPointWithinCircle(const Point& point, const Point& center, const double radius);

Color getColorByName(const char*);
const char* colorToString(const Color&);

template <typename T>
T* resizeArray(T* arr, int oldSize, int newSize)
{
    if(oldSize == newSize) return arr;

    T* new_arr = new T[newSize];
    for (int i = 0; i < oldSize; i++)
    {
        new_arr[i] = arr[i];
    }
    
    delete[] arr;
    return new_arr;
}