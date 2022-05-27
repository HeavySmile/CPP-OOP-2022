#include "Bank.hpp"
#include "NormalAccount.hpp"
#include "SavingsAccount.hpp"
#include "PrivilegeAccount.hpp"
#include "Resize.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

Bank::Bank(const char* name, const char* address)
{
    this->name = new char[strlen(name) + 1];
    this->address = new char[strlen(address) + 1];

    strcpy(this->name, name);
    strcpy(this->address, address);

    customers = new Customer[INITIAL_ARR_SIZE];
    accounts = new Account*[INITIAL_ARR_SIZE];
    customersCount = 0;
    accountsCount = 0;
    customersLimit = INITIAL_ARR_SIZE;
    accountsLimit = INITIAL_ARR_SIZE;

    customer_id_counter = 0;
}
Bank::~Bank()
{
    delete[] name;
    delete[] address;
    delete[] customers;
    for (int i = 0; i < accountsCount; i++)
    {
        delete accounts[i];
    }
    delete[] accounts;
}

void Bank::addCustomer()
{
    char* name = new char[MAX_INPUT_SIZE];
    char* address = new char[MAX_INPUT_SIZE];
    
    cout << "Insert name: ";
    cin.getline(name, MAX_INPUT_SIZE);
    
    if(findCustomerByName(name) != -1)
    {
        cout << "The customer with this name already exists" << endl;
        return;
    }

    cout << "Insert address: ";
    cin.getline(address, MAX_INPUT_SIZE);
    
    if(customersCount == customersLimit)
    {
        customers = resizeArray(customers, customersCount, customersLimit*2);
        customersLimit *= 2;
    }

    customers[customersCount].setId(customer_id_counter);
    customers[customersCount].setName(name);
    customers[customersCount].setAddress(address);
    ++customersCount;
    ++customer_id_counter;
    
    log.writeAddCustomer(name, address);

    delete[] name;
    delete[] address;
}
void Bank::deleteCustomer()
{
    char* name = new char[MAX_INPUT_SIZE];
    cout << "Insert name: ";
    cin.getline(name, MAX_INPUT_SIZE);

    int customer_idx = findCustomerByName(name);
    if(customer_idx == -1)
    {
        cout << "No customer found" << endl;
        return;
    }

    log.writeDeleteCustomer(name, customers[customer_idx].getAddress());

    if(customer_idx == customersCount - 1) --customersCount;
    else
    {
        for (int i = customer_idx; i < customersCount - 1; i++)
        {
            customers[i] = customers[i + 1];
        }
        --customersCount;
    }

    for (int i = 0; i < accountsCount; i++)
    {
        if(accounts[i]->getId() == customer_idx)
        {
            for (int j = i; j < accountsCount - 1; j++)
            {
                accounts[j] = accounts[j + 1];
            }
            --accountsCount;
        }
    }

    delete[] name;
}
void Bank::addAccount()
{
    char* customer_name = new char[MAX_INPUT_SIZE];
    char* username = new char[MAX_INPUT_SIZE];
    char* password = new char[MAX_INPUT_SIZE];
    char* IBAN = new char[MAX_INPUT_SIZE];
    char* type = new char[MAX_INPUT_SIZE];

    cout << "Insert customer's name: ";
    cin.getline(customer_name, MAX_INPUT_SIZE);

    int customer_idx = findCustomerByName(customer_name);
    if(customer_idx == -1)
    {
        cout << setw(6 + strlen("No customer found")) << "No customer found" << endl;
        return;
    }
    
    cout << "Insert username: ";
    cin.getline(username, MAX_INPUT_SIZE);
    cout << "Insert password: ";
    cin.getline(password, MAX_INPUT_SIZE);
    cout << "Insert IBAN: ";
    cin.getline(IBAN, MAX_INPUT_SIZE);
    cout << "Insert account type: ";
    cin.getline(type, MAX_INPUT_SIZE);

    if(accountsCount == accountsLimit)
    {
        accounts = resizeArray(accounts, accountsCount, accountsLimit*2);
        accountsLimit *= 2;
    }

    delete accounts[accountsCount];
    if(!strcmp(type, "Normal"))
    {
        accounts[accountsCount] = new NormalAccount();
    }
    else if(!strcmp(type, "Saving"))
    {
        accounts[accountsCount] = new SavingsAccount();
    }
    else
    {
        accounts[accountsCount] = new PrivilegeAccount();
    }

    accounts[accountsCount]->setUsername(username);
    accounts[accountsCount]->setPassword(password);
    accounts[accountsCount]->setIBAN(IBAN);
    accounts[accountsCount]->setId(customer_idx);
    ++accountsCount;

    log.writeAddAccount(customer_name, IBAN, type);
    
    delete[] customer_name;
    delete[] username;
    delete[] password;
    delete[] IBAN;
    delete[] type;
}
void Bank::deleteAccount()
{
    char* username = new char[MAX_INPUT_SIZE];
    char* password = new char[MAX_INPUT_SIZE];

    cout << "Insert username: ";
    cin >> username;
    cout << "Insert password: ";
    cin >> password;

    int account_idx = findAccountByLogin(username, password);
    if(account_idx == -1)
    {
        cout << "Invalid username or password" << endl;
        return;
    }

    log.writeDeleteAccount(accounts[account_idx]->getIBAN());

    for (int i = account_idx; i < accountsCount; i++)
    {
        accounts[i] = accounts[i + 1];
    }
    --accountsCount;

    
    delete[] username;
    delete[] password;
}

void Bank::listCustomers() const
{
    cout << endl;
    for (int i = 0; i < customersCount; i++)
    {
        customers[i].printCustomer();
        cout << endl;
    }
}
void Bank::listAccounts() const
{
    cout << endl;
    for (int i = 0; i < accountsCount; i++)
    {
        accounts[i]->display();
    }
}
void Bank::listCustomerAccounts() const
{
    char* name = new char[MAX_INPUT_SIZE];
    
    cout << "Insert customer's name: ";
    cin.getline(name, MAX_INPUT_SIZE);
    
    int customer_idx = findCustomerByName(name);
    if(customer_idx == -1)
    {
        cout << "No customer found" << endl;
        return;
    }

    cout << endl;
    for (int i = 0; i < accountsCount; i++)
    {
        if(accounts[i]->getId() == customer_idx)
        {
            
            accounts[i]->display();
            cout << endl;
        }
    }
    delete[] name;
}
void Bank::listLog() const
{
    log.print();
}
void Bank::display() const
{
    cout << "Bank name: " << name << endl;
    cout << "Bank address: " << address << endl;
    cout << "Customers count: " << customersCount << endl;
    cout << "Accounts count: " << accountsCount << endl;
}

int Bank::findCustomerByName(const char* name) const
{
    for (int i = 0; i < customersCount; i++)
    {
        if(!strcmp(customers[i].getName(), name)) return i;
    }
    
    return -1;
}
int Bank::findAccountByIBAN(const char* IBAN) const
{
    for (int i = 0; i < customersCount; i++)
    {
        if(!strcmp(accounts[i]->getIBAN(), IBAN)) return i;
    }
    
    return -1;
}
int Bank::findAccountByLogin(const char* username, const char* password) const
{
    for (int i = 0; i < accountsCount; i++)
    {
        if(!strcmp(accounts[i]->getUsername(), username) && !strcmp(accounts[i]->getPassword(), password))
        {
            return i;
        }
    }

    return -1;
}
Account* Bank::authenticate()
{
    char* username = new char[MAX_INPUT_SIZE];
    char* password = new char[MAX_INPUT_SIZE];

    cout << "Insert username: ";
    cin >> username;
    cout << "Insert password: ";
    cin >> password;

    int account_idx = findAccountByLogin(username, password);
    if(account_idx == -1)
    {
        cout << "Invalid username or password" << endl;
        return nullptr;
    }

    return accounts[account_idx];
}

void Bank::transfer(const double amount, const char* fromIBAN, const char* toIBAN)
{
    int from_idx = findAccountByIBAN(fromIBAN);
    if(from_idx == -1)
    {
        cout << "Sender has invalid IBAN" << endl;
        return;
    }

    int to_idx = findAccountByIBAN(toIBAN);
    if(to_idx == -1)
    {
        cout << "Receiver has invalid IBAN" << endl;
        return;
    }

    accounts[from_idx]->withdraw(amount);
    accounts[to_idx]->deposit(amount);

    log.write("transfer");
}
void Bank::withdrawFromAccount(const double amount, const char* IBAN)
{
    int account_idx = findAccountByIBAN(IBAN);
    if(account_idx == -1)
    {
        cout << "Invalid IBAN" << endl;
        return;
    }

    accounts[account_idx]->withdraw(amount);

    log.write("withdraw");
}



