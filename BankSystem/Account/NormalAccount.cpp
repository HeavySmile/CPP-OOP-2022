#include "NormalAccount.hpp"

void NormalAccount::display() const
{
    cout << "Account type : Normal" << endl;
    cout << "Owner's ID : " << getId() << endl;
    Account::display();
}