#pragma once
#include "Item.hpp"

class ShoppingCart
{
private:
	Item* items;
	int itemCount;
	int capacity;

public:
	ShoppingCart();
	~ShoppingCart();

	int itemsCount() const;
	bool exists(char*);
	bool isEmpty() const;
	double getPriceOf(char*) const;
	double totalPrice() const;


	void printCart();
	void sortByName();
	bool save(char*);
	void addItem(Item);
	void removeItem(char*);

	void resize();
	int find(char*);
};