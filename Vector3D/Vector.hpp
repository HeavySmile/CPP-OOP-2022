#pragma once
#include <iostream>

struct Vector
{
	int x, y, z;
    
	double getLength();
};

int scalarMultiplication(Vector, Vector);

bool isVectorPerpendicular(Vector, Vector);

Vector vectorMultiplication(Vector, Vector);

void writeToFile(Vector);

int getFileSize(const char*);

void readFromFile(const char*, Vector*);