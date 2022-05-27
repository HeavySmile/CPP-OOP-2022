#include "NormalAccount.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;

//NormalAccount::NormalAccount() : Account() {}

bool NormalAccount::withdraw(const double amount)
{
    if(amount > getBalance()) return false;
    
    setAmount(getBalance() - amount);
    return true;
}
void NormalAccount::display() const
{
    cout << "Account type : Normal" << endl;
    cout << "IBAN : " << getIBAN() << endl;
    cout << "Owner's ID : " << getId() << endl;
    cout << "Balance : " << getBalance() << endl;
}