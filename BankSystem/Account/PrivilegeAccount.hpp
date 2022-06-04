#pragma once
#include "Account.hpp"

class PrivilegeAccount : public Account
{
private:
    double overdraft;
public:
    PrivilegeAccount();

    bool withdraw(const double) override;
    void display() const override;
};