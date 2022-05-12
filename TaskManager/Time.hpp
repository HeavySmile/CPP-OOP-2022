#pragma once
#include <cstdint>

class Time
{
public:
    uint8_t h;
    uint8_t m;
    uint8_t s;

    friend ostream& operator<<(ostream&, const Time&);
};

ostream& operator<<(ostream& os, const Time& time)
{
    os << time.h << "." << time.m << "." << time.s;
    return os;
}