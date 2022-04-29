#pragma once
#include <iostream>
using namespace std;

class BigNumber
{
private:
    char* number;
    
public:
    BigNumber();
    BigNumber(const char*);
    BigNumber(long long int);
    BigNumber(const BigNumber&);
    ~BigNumber();

    BigNumber& operator=(const BigNumber&);
    BigNumber& operator=(const char*);
    BigNumber& operator=(long long int);
    BigNumber operator+(const BigNumber&) const;
    BigNumber operator-(const BigNumber&) const;
    BigNumber operator*(const BigNumber&);
    BigNumber operator/(const BigNumber&);
    BigNumber& operator+=(const BigNumber&);
    BigNumber& operator-=(const BigNumber&);
    BigNumber& operator*=(const BigNumber&);
    BigNumber& operator/=(const BigNumber&);
    
    bool operator==(const BigNumber&) const;
    bool operator!=(const BigNumber&) const;
    bool operator<(const BigNumber&) const;
    bool operator>(const BigNumber&) const;


    
    friend ostream& operator<<(ostream&, const BigNumber&);    
};

int getNumberSize(long long int);
ostream& operator<<(ostream&, const BigNumber&);

char* addZeros(const char*, int);
