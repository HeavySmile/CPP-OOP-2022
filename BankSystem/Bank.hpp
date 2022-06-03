#pragma once
#include "Customer.hpp"
#include "NormalAccount.hpp"
#include "SavingsAccount.hpp"
#include "PrivilegeAccount.hpp"
#include "Helpers.hpp"
#include "Log.hpp"
#include <iostream>
#include <iomanip>


class Bank
{
private:
    char* name;
    char* address;
    Customer* customers;
    Account** accounts;

    int customersCount;
    int accountsCount;
    int customersLimit;
    int accountsLimit;

    int customer_id_counter;

    Log log;
public:
    Bank(const char*, const char*);
    ~Bank();

    void addCustomer();
    void deleteCustomer();
    void addAccount();
    void deleteAccount();

    void listCustomers() const;
    void listAccounts() const;
    void listCustomerAccounts() const;
    void listLog() const;
    void display() const;
    
    int findCustomerByName(const char*) const;
    int findAccountByIBAN(const char*) const;
    int findAccountByLogin(const char*, const char*) const;
    Account* authenticate();

    void transfer(const double, const char*, const char*s);
    void withdrawFromAccount(const double, const char*);
    void depositToAccount(const double, const char*);
    void exportLog(const char*);

};

