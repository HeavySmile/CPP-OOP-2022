#pragma once
#include "Helpers/Helpers.hpp"
#include <fstream>
#include <iostream>
using namespace std;

class Log
{
private:
    char* text;
public:
    Log();
    ~Log();
    
    void write(const char*);
    void print() const;

    void writeAddCustomer(const char*, const char*);
    void writeDeleteCustomer(const char*, const char*);
    void writeAddAccount(const char*, const char*, const char*);
    void writeDeleteAccount(const char*);
    void writeTransfer(const double, const char*, const char*);
    void writeDeposit(const double, const char*);
    void writeWithdraw(const double, const char*);

    void writeToFile(const char*);
};
