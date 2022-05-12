#pragma once
#include <cstdint>
#include <iostream>
using namespace std;

class Time
{
public:
    uint8_t h;
    uint8_t m;
    uint8_t s;

    friend ostream& operator<<(ostream&, const Time&);
    friend istream& operator>>(istream&, Time&);
};