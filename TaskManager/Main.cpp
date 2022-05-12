#include <iostream>
#include "DateTime.hpp"
using namespace std;

int main()
{
    // Date date;
    // date.year = 2002;
    // date.month = 2;
    // date.day = 14;
    


    int seconds = 0;
    int minutes = 0;
    int hours = 0;

    int days = 0;
    int months = 0;
    int years = 0;

    Time time1;
    time1.h = 17;
    time1.m = 47;
    time1.s = 29;
    
    Date date1;
    date1.day = 24;
    date1.month = 2;
    date1.year = 2006;

    Time time2;
    time2.h = 19;
    time2.m = 59;
    time2.s = 43;

    Date date2;
    date2.day = 29;
    date2.month = 4;
    date2.year = 2007;

    
    

    return 0;
}