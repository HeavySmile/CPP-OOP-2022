#pragma once
#include <cstdint>

class Date
{
public:
    int year;
    uint8_t day;
    uint8_t month;

    friend ostream& operator<<(ostream&, const Date&);
};

ostream& operator<<(ostream& os, const Date& date)
{
    os << date.day << "." << date.month << "." << date.year;
    return os;
}