#pragma once
#include <iostream>
using namespace std;

class Customer
{
private:
    int id;
    char* name;
    char* address;

public:
    Customer();
    Customer(const int, const char*, const char*);
    Customer(const Customer&);
    Customer& operator=(const Customer&);
    ~Customer();

    int getId() const;
    char* getName() const;
    char* getAddress() const;

    void setId(const int);
    void setName(const char*);
    void setAddress(const char*);

    void printCustomer() const;
};