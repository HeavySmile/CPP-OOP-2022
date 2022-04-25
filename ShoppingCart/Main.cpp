#include "ShoppingCart.hpp"
#include "Item.hpp"
#include <iostream>
using namespace std;

const int MAX_BUFFER_SIZE = 260;

int main()
{
	char buffer[MAX_BUFFER_SIZE];
	ShoppingCart shoppingCart;
	
	do
	{
		cout << "> ";
		cin >> buffer;
		if (!strcmp(buffer, "add"))
		{
			char* name = new char[MAX_BUFFER_SIZE];
			int count;
			double price;
			cin >> name >> count >> price;
			shoppingCart.addItem(Item(name, count, price));
		}
		else if (!strcmp(buffer, "remove"))
		{
			char* name = new char[MAX_BUFFER_SIZE];
			cin >> name;
			shoppingCart.removeItem(name);
			delete[] name;
		}
		else if (!strcmp(buffer, "count"))
		{
			cout << shoppingCart.itemsCount() << endl;
		}
		else if (!strcmp(buffer, "exists"))
		{
			char* name = new char[MAX_BUFFER_SIZE];
			cin >> name;
			
			if (shoppingCart.exists(name)) cout << "true\n";
			else cout << "false\n";
			delete[] name;
		}
		else if (!strcmp(buffer, "empty"))
		{
			if (shoppingCart.isEmpty()) cout << "true\n";
			else cout << "false\n";
		}
		else if (!strcmp(buffer, "price"))
		{
			char* name = new char[MAX_BUFFER_SIZE];
			cin >> name;
			cout << shoppingCart.getPriceOf(name) << endl;
			delete[] name;
		}
		else if (!strcmp(buffer, "sort"))
		{
			shoppingCart.sortByName();
		}
		else if (!strcmp(buffer, "save"))
		{
			char* filePath = new char[MAX_BUFFER_SIZE];
			cin >> filePath;
			shoppingCart.save(filePath);
			delete[] filePath;
		}
		else if (!strcmp(buffer, "totalprice"))
		{
			cout << shoppingCart.totalPrice() << endl;
		}
		else if (!strcmp(buffer, "view"))
		{
			shoppingCart.printCart();
		}
	}
	while (strcmp(buffer, "exit"));

}
