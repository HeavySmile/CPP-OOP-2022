#pragma once
#include "Account.hpp"

class NormalAccount : public Account
{
public:
    //NormalAccount();

    void deposit(const double);
    bool withdraw(const double);
    void display() const;
};