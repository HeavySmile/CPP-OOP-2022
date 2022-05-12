#include "Date.hpp"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, const Date& date)
{
    
    if(date.day / 10 == 0) os << "0";
    os << (unsigned int)date.day << ".";

    if(date.month / 10 == 0) os << "0";
    os << (unsigned int)date.month << ".";

    if(date.year / 1000 == 0) os << "0";
    if(date.year / 100 == 0) os << "0";
    if(date.year / 10 == 0) os << "0";
    os << (unsigned int)date.year;

    return os;
}
istream& operator>>(istream& is, Date& date)
{
    int month;
    int day;
    
    is >> day; 
    is >> month; 
    is >> date.year;
    
    date.day = (uint8_t)day;
    date.month = (uint8_t)month;

    return is;
}