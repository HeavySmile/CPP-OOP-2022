#pragma once
#include <iostream>
using namespace std;

struct IntStack
{
	int* arr = nullptr;
	int topIdx = -1;

	void push(int);
	void pop();
	int top();
	bool isEmpty();
	size_t size();
};