#include <iostream>
#include "Matrix.hpp"

using namespace std;
int main()
{
	Matrix matrix1(3, 3);
	matrix1.readMatrix();
	//matrix1 = 2 * matrix1;
	matrix1.printMatrix();
	cout << matrix1.isInvertable() << endl;
	cout << matrix1.findDeterminant() << endl;
	//matrix1.transponse();
	//matrix1.printMatrix();
}

