#pragma once

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
    void writeTransfer(const double, const char*);
    void writeDeposit(const double, const char*);
    void writeWithdraw(const double, const char*);
};