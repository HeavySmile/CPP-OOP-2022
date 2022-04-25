#pragma once
#include <cstring>

class Item
{
private:
	char* name;
	int count;
	double price;

public:
	friend class ShoppingCart;
	Item();
	Item(char*, int, double);
	Item(const Item&);
	Item operator=(const Item&);
	~Item();

	const char* GetName() const;
	const int GetCount() const;
	const double GetPrice() const;

	void SetName(char*);
	void SetCount(int);
	void SetPrice(double);
};