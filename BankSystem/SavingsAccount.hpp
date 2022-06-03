#pragma once
#include "Account.hpp"

class SavingsAccount : public Account
{
private:
    double interestRate;
public:
    SavingsAccount();

    bool withdraw(const double) override;
    void display() const override;
};