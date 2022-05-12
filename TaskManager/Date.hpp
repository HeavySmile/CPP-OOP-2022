#pragma once
#include <cstdint>
#include <iostream>
using namespace std;

class Date
{
public:
    int year;
    uint8_t day;
    uint8_t month;

    friend ostream& operator<<(ostream&, const Date&);
    friend istream& operator>>(istream&, Date&);
};