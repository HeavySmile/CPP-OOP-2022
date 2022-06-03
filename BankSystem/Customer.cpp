#include "Customer.hpp"

Customer::Customer() : id(-1), name(nullptr), address(nullptr) {}
Customer::Customer(const int id, const char* name, const char* address) : id(id)
{
    this->name = new char[strlen(name) + 1];
    this->address = new char[strlen(address) + 1];
    strcpy(this->name, name);
    strcpy(this->address, address);
}
Customer::Customer(const Customer& customer) : id(customer.id)
{
    name = new char[strlen(customer.name) + 1];
    address = new char[strlen(customer.address) + 1];
    strcpy(name, customer.name);
    strcpy(address, customer.address);
}
Customer& Customer::operator=(const Customer& customer)
{
    if(this != &customer)
    {
        delete[] name;
        delete[] address;

        name = new char[strlen(customer.name) + 1];
        address = new char[strlen(customer.address) + 1];

        id = customer.id;
        strcpy(name, customer.name);
        strcpy(address, customer.address);
    }

    return *this;
}
Customer::~Customer()
{
    delete[] name;
    delete[] address;
}

int Customer::getId() const
{
    return id;
}
char* Customer::getName() const
{
    return name;
}
char* Customer::getAddress() const
{
    return address;
}

void Customer::setId(const int id)
{
    this->id = id;
}
void Customer::setName(const char* name)
{
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}
void Customer::setAddress(const char* address)
{
    delete[] this->address;
    this->address = new char[strlen(address) + 1];
    strcpy(this->address, address);
}

void Customer::printCustomer() const
{
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Address: " << address << endl;
}