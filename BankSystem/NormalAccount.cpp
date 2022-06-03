#include "NormalAccount.hpp"

// bool NormalAccount::withdraw(const double amount)
// {
//     if(amount > getBalance()) return false;
    
//     setAmount(getBalance() - amount);
//     return true;
// }
void NormalAccount::display() const
{
    cout << "Account type : Normal" << endl;
    cout << "Owner's ID : " << getId() << endl;
    Account::display();
}