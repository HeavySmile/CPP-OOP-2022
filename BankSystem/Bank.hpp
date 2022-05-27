#pragma once
#include "Account.hpp"
#include "Customer.hpp"
#include "Log.hpp"

const int MAX_INPUT_SIZE = 1600;
const int INITIAL_ARR_SIZE = 10;

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

    void transfer(double, const char*, const char*s);
    void withdrawFromAccount(double, const char*);
};

