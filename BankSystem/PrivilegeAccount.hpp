#pragma once
#include "Account.hpp"

const unsigned int DEFAULT_OVERDRAFT_SIZE = 1000;

class PrivilegeAccount : public Account
{
private:
    double overdraft;
public:
    PrivilegeAccount();

    bool withdraw(const double);
    void display() const;
};