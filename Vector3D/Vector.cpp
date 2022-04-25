#include <iostream>
#include <fstream>
#include <cmath>
#include "Vector.hpp"

using namespace std;

double Vector::getLength()
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

int scalarMultiplication(Vector vector1, Vector vector2)
{
	int mult = vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
	return mult;
}

bool isVectorPerpendicular(Vector vector1, Vector vector2)
{
	if (scalarMultiplication(vector1, vector2) == 0) return true;
	else return false;
}

Vector vectorMultiplication(Vector vector1, Vector vector2)
{
	Vector product;
	product.x = vector1.y * vector2.z - vector1.z * vector2.y;
	product.y = vector1.z * vector2.x - vector1.x * vector2.z;
	product.z = vector1.x * vector2.y - vector1.y * vector2.x;
	return product;
}

void writeToFile(Vector vector)
{
	ofstream file("vector.bin", ios::binary | ios::app);
	if (file.is_open())
	{
		file.write((char*)&vector, sizeof(Vector));
		file.close();
	}
	else cout << "Something went wrong" << endl;
}

int getFileSize(const char* path)
{
	ifstream file(path, ios::binary);
	Vector buffer;
	int size = 0;
	while (file.read((char*)&buffer, sizeof(Vector)))
	{
		size++;
	}
	return size;
}

void readFromFile(const char* path, Vector* vectors)
{
	ifstream file(path, ios::binary);
	if (file.is_open())
	{
		for (int i = 0; file.read((char*)&vectors[i], sizeof(Vector)); i++);
		file.close();
		return;
	}
	
	cout << "Something went wrong" << endl;

	return;
}