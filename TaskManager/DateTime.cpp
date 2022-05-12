#include "DateTime.hpp"
#include <iostream>
using namespace std;

const int getMonthDays(const int month)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;
    case 2:
        if((month % 4 == 0 && month % 100 != 0) || (month % 400 == 0)) return 29;
        else return 28;
        break;
    }

    return -1;
}

DateTime::DateTime()
{
    date.day = 1;
    date.month = 1;
    date.year = 1;
    
    time.s = 0;
    time.m = 0;
    time.h = 0;
}
DateTime::DateTime(Date date, Time time)
{
    this->date = date;
    this->time = time;
}

Date DateTime::getDate() const
{
    return date;
}
Time DateTime::getTime() const
{
    return time;
}

void DateTime::setDate(Date date)
{
    this->date = date;
}
void DateTime::setTime(Time time)
{
    this->time = time;
}

DateTime DateTime::timeTo(const DateTime& dateTime) const
{
    int seconds = 0;
    int minutes = 0;
    int hours = 0;

    int days = 0;
    int months = 0;
    int years = 0;
    
    Time time;
    time.s = seconds;
    time.m = minutes;
    time.h = hours;

    Date date;
    date.day = days;
    date.month = months;
    date.year = years;
    
    if(dateTime < *this)
    {
        std::cout << "Error! The start date is after the end date." << std::endl;
        return DateTime(date, time);
    }
    
    if(time.s > dateTime.time.s)
    {
        seconds += 60 + (dateTime.time.s - time.s);
        minutes--;
    }
    else seconds += dateTime.time.s - time.s;

    if(time.m > dateTime.time.m)
    {
        minutes += 60 + (dateTime.time.m - time.m);
        hours--;
    }
    else minutes += dateTime.time.m - time.m;
    
    if(time.h > dateTime.time.h)
    {
        hours += 24 + (dateTime.time.h - time.h);
        days--;
    }
    else hours += dateTime.time.h - time.h;

    if(date.day > dateTime.date.day)
    {
        days += getMonthDays(dateTime.date.month - 1) + (dateTime.date.day - date.day);
        months--;
    }
    else days += dateTime.date.day - date.day;

    if(date.month > dateTime.date.month)
    {
        months += 12 + (dateTime.date.month - date.month);
        years--;
    }
    else months += dateTime.date.month - date.month;

    years += dateTime.date.year - date.year;

    time.s = seconds;
    time.m = minutes;
    time.h = hours;

    date.day = days;
    date.month = months;
    date.year = years;

    return DateTime(date, time);
}
bool DateTime::operator<(const DateTime& dateTime) const
{
    if(this->date.year < dateTime.date.year) return true;
    else if(this->date.year > dateTime.date.year) return false;
    
    if(this->date.month < dateTime.date.month) return true;
    else if(this->date.month > dateTime.date.month) return false;
    
    if(this->date.day < dateTime.date.day) return true;
    else if(this->date.day > dateTime.date.day) return false;
    
    if(this->time.h < dateTime.time.h) return true;
    else if(this->time.h > dateTime.time.h) return false;
    
    if(this->time.m < dateTime.time.m) return true;
    else if(this->time.m > dateTime.time.m) return false;
    
    if(this->time.s < dateTime.time.s) return true;
    else if(this->time.s > dateTime.time.s) return false;
    
    return false;
}

ostream& operator<<(ostream& os, const DateTime& dateTime)
{
    os << dateTime.date << " " << dateTime.time;
    return os;
}
istream& operator>>(istream& is, DateTime& dateTime)
{
    is >> dateTime.date;
    is.ignore(); 
    is >> dateTime.time;
    return is;
}