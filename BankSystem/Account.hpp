#pragma once
#include <ctime>
using namespace std;

class Account
{
private:
    char* username;
    char* password;
    char* IBAN;
    int Id;
    double amount;
    time_t dateOfCreation;
public:
    Account();
    Account(const Account&);
    Account& operator=(const Account&);
    virtual ~Account();

    char* getUsername() const;
    char* getPassword() const;
    char* getIBAN() const;
    int getId() const;
    double getBalance() const;
    time_t getDateOfCreation() const;

    void setUsername(const char*);
    void setPassword(const char*);
    void setIBAN(const char*);
    void setId(const int);
    void setAmount(const double);
    void setDateOfCreation(const time_t);

    void deposit(const double);
    virtual bool withdraw(const double) = 0;
    virtual void display() const = 0;
};