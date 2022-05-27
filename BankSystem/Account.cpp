#include "Account.hpp"
#include <ctime>
#include <iostream>
using namespace std;

Account::Account() : username(nullptr), password(nullptr), IBAN(nullptr), Id(-1), amount(0), dateOfCreation(time(0)) {}
Account::Account(const Account& account) : Id(account.Id), amount(account.amount), dateOfCreation(account.dateOfCreation)
{
    username = new char[strlen(account.username) + 1];
    password = new char[strlen(account.password) + 1];
    IBAN = new char[strlen(account.IBAN) + 1];

    strcpy(username, account.username);
    strcpy(password, account.password);
    strcpy(IBAN, account.IBAN);
}
Account& Account::operator=(const Account& account)
{
    if(this != &account)
    {
        delete[] username;
        delete[] password;
        delete[] IBAN;

        username = new char[strlen(account.username) + 1];
        password = new char[strlen(account.password) + 1];
        IBAN = new char[strlen(account.IBAN) + 1];

        strcpy(username, account.username);
        strcpy(password, account.password);
        strcpy(IBAN, account.IBAN);
        Id = account.Id;
        amount = account.amount;
        dateOfCreation = account.dateOfCreation;
    }

    return *this;
}
Account::~Account()
{
    delete[] username;
    delete[] password;
    delete[] IBAN;
}

char* Account::getUsername() const
{
    return username;
}
char* Account::getPassword() const
{
    return password;
}
char* Account::getIBAN() const
{
    return IBAN;
}
int Account::getId() const
{
    return Id;
}
double Account::getBalance() const
{
    return amount;
}
time_t Account::getDateOfCreation() const
{
    return dateOfCreation;
}

void Account::setUsername(const char* username)
{
    delete[] this->username;
    this->username = new char[strlen(username) + 1];
    strcpy(this->username, username);
}
void Account::setPassword(const char* password)
{
    delete[] this->password;
    this->password = new char[strlen(password) + 1];
    strcpy(this->password, password);
}
void Account::setIBAN(const char* IBAN)
{
    delete[] this->IBAN;
    this->IBAN = new char[strlen(IBAN) + 1];
    strcpy(this->IBAN, IBAN);    
}
void Account::setId(const int Id)
{
    this->Id = Id;
}
void Account::setAmount(const double amount)
{
    this->amount = amount;
}
void Account::setDateOfCreation(const time_t dateOfCreation)
{
    this->dateOfCreation = dateOfCreation;
}

void Account::deposit(const double amount)
{
    setAmount(getBalance() + amount);
}

// void Account::deposit(const double amount)
// {
//     this->amount += amount; 
// }
// void Account::withdraw(const double amount)
// {
//     this->amount -= amount;
// }
// void Account::display() const
// {
//     cout << "IBAN : " << IBAN << endl;
//     cout << "Balance : " << amount << endl;
// }


