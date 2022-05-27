#include "PrivilegeAccount.hpp"
#include <iostream>
using namespace std;

PrivilegeAccount::PrivilegeAccount() : Account(), overdraft(DEFAULT_OVERDRAFT_SIZE) {}

bool PrivilegeAccount::withdraw(const double amount)
{
    if(getBalance() + overdraft < amount) return false;

    setAmount(getBalance() - amount);
    return true;
}
void PrivilegeAccount::display() const
{
    cout << "Account type : Privilege" << endl;
    cout << "IBAN : " << getIBAN() << endl;
    cout << "Owner's ID : " << getId() << endl;
    cout << "Balance : " << getBalance() << endl;
}
