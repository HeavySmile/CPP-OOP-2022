#include "SavingsAccount.hpp"

SavingsAccount::SavingsAccount() : Account(), interestRate(0) {}

bool SavingsAccount::withdraw(const double amount)
{
    return false;
}
void SavingsAccount::display() const
{
    cout << "Account type : Savings" << endl;
    cout << "Owner's ID : " << getId() << endl;
    Account::display();
}