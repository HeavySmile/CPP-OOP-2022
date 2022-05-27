#include "SavingsAccount.hpp"
#include <iostream>
using namespace std;

SavingsAccount::SavingsAccount() : Account(), interestRate(0) {}

bool SavingsAccount::withdraw(const double amount)
{
    return false;
}
void SavingsAccount::display() const
{
    cout << "Account type : Savings" << endl;
    cout << "IBAN : " << getIBAN() << endl;
    cout << "Owner's ID : " << getId() << endl;
    cout << "Balance : " << getBalance() << endl;
}