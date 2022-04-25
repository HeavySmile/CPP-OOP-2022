#include "ShoppingCart.hpp"
#include "Item.hpp"
#include <fstream>
#include <iostream>
using namespace std;

const int RESIZE_COEFFICIENT = 2;
const int INITIAL_CART_SIZE = 2;

void ShoppingCart::resize()
{
	Item* newItems = new Item[RESIZE_COEFFICIENT * capacity];
	for (int i = 0; i < itemCount; i++)
	{
		newItems[i] = items[i];
	}
	delete[] items;
	items = newItems;
	capacity *= 2;
}
int ShoppingCart::find(char* name)
{
	for (int i = 0; i < itemCount; i++)
	{
		if (!strcmp(items[i].name, name))
		{
			return i;
		}
	}

	return -1;
}

ShoppingCart::ShoppingCart()
{
	items = new Item[INITIAL_CART_SIZE];
	itemCount = 0;
	capacity = INITIAL_CART_SIZE;
}
ShoppingCart::~ShoppingCart()
{
	delete[] items;
}

int ShoppingCart::itemsCount() const
{
	return itemCount;
}
bool ShoppingCart::exists(char* name)
{
	return (find(name) == -1) ? false : true;
}
bool ShoppingCart::isEmpty() const
{
	return itemCount == 0;
}
double ShoppingCart::getPriceOf(char* name) const
{
	for (int i = 0; i < itemCount; i++)
	{
		if (!strcmp(items[i].GetName(), name)) return items[i].GetPrice();
	}
	
	return 0.0;
}
double ShoppingCart::totalPrice() const
{
	double totalPrice = 0;
	for (int i = 0; i < itemCount; i++)
	{
		totalPrice += items[i].GetPrice() * items[i].GetCount();
	}
	
	return totalPrice;
}


void ShoppingCart::printCart()
{
	for (int i = 0; i < itemCount; i++)
	{
		cout << "name: " << items[i].name << endl;
		cout << "amount: " << items[i].count << endl;
		cout << "price: " << items[i].price << endl;
		cout << endl;
	}
}

void ShoppingCart::sortByName()
{
	for (int i = 0; i < itemCount - 1; i++)
	{
		for (int j = 0; j < itemCount - i - 1; j++)
		{
			if (items[j].GetName() < items[j + 1].GetName())
			{
				Item swap = items[j];
				items[j] = items[j + 1];
				items[j + 1] = swap;
			}
		}
	}
}
bool ShoppingCart::save(char* filePath)
{
	ofstream file(filePath, ios::trunc);
	
	if (!file.is_open())
	{
		file.close();
		return false;
	}
	
	file << "name,amount,price \n";
	for (int i = 0; i < itemCount; i++)
	{
		file << items[i].name << ",";
		file << items[i].count << ",";
		file << items[i].price << "\n";
	}

	file.close();
	return true;
}
void ShoppingCart::addItem(Item item)
{
	if (exists(item.name))
	{
		cout << "Item already exists" << endl;
		return;
	}
	
	if (itemCount == capacity) resize();
	
	items[itemCount++] = item;
}
void ShoppingCart::removeItem(char* name)
{
	int removedItemIdx = find(name);
	
	if (removedItemIdx == itemCount - 1)
	{
		delete[] items[removedItemIdx].name;
		items[removedItemIdx].name = nullptr;
		items[removedItemIdx].count = 0;
		items[removedItemIdx].price = 0;
	}
	else
	{
		for (int i = removedItemIdx; i < itemCount - 1; i++)
		{
			items[i] = items[i + 1];
		}
	}
	
	itemCount--;
}
