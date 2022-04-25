#include "Item.hpp"
#include <iostream>
using namespace std;

Item::Item()
{
	this->name = nullptr;
	this->count = 0;
	this->price = 0;
}
Item::Item(char* name, int count, double price)
{
	this->name = name;
	this->count = count;
	this->price = price;
}
Item::Item(const Item& item)
{
	name = new char[strlen(item.name) + 1];
	strcpy(name, item.name);
	count = item.count;
	price = item.price;
}
Item Item::operator=(const Item& item)
{
	if (this != &item)
	{
		delete[] name;
		name = new char[strlen(item.name) + 1];
		strcpy(name, item.name);
		count = item.count;
		price = item.price;
	}
	
	return *this;
}
Item::~Item()
{
	delete[] name;
}

const char* Item::GetName() const
{
	return name;
}
const int Item::GetCount() const
{
	return count;
}
const double Item::GetPrice() const
{
	return price;
}

void Item::SetName(char* name)
{
	this->name = name;
}
void Item::SetCount(int count)
{
	this->count = count;
}
void Item::SetPrice(double price)
{
	this->price = price;
}