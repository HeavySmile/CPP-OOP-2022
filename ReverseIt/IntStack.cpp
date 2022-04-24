#include "IntStack.hpp"
#include <iostream>

using namespace std;

bool IntStack::isEmpty()
{
	if (size() == 0) return true;
	else return false;
}

int IntStack::top()
{
	return arr[topIdx];
}

size_t IntStack::size()
{
	if (arr == nullptr) return 0;
	else return topIdx + 1;
}

void IntStack::push(int element)
{
	// allocating new memory for stack
	int* newArr = new int[size() + 1];
	
	// case when stack already has elements
	if (arr != nullptr)
	{
		for (int i = 0; i <= size(); i++) newArr[i] = arr[i];
	}
	
	topIdx++;
	newArr[topIdx] = element;
	// clearing unused memory
	delete[] arr;
	arr = newArr;
}

void IntStack::pop()
{
	if (arr == nullptr || isEmpty())
	{
		cout << "Empty stack" << endl;
	}
	else
	{
		topIdx--;
		int* newArr = new int[size()];
		for (int i = 0; i < size(); i++) newArr[i] = arr[i];
		// clearing unused memory
		delete[] arr;
		arr = newArr;
	}
}


