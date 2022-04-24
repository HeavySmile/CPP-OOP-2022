#include "Matrix.hpp"
#include <iostream>
using namespace std;

Matrix::Matrix(int columns, int rows)
{
	if(columns < 2 || rows < 2)
	{
		columns = 2;
		rows = 2;
	}
	this->columns = columns;
	this->rows = rows;
	elements = allocateMatrix(columns, rows);
}
Matrix::Matrix(const Matrix& p)
{
	rows = p.rows;
	columns = p.columns;
	elements = allocateMatrix(p.columns, p.rows);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			elements[i][j] = p.elements[i][j];
		}
	}
}
Matrix& Matrix::operator=(const Matrix& p)
{
	if (this != &p)
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] elements[i];
		}
		delete[] elements;
		elements = allocateMatrix(p.columns, p.rows);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				elements[i][j] = p.elements[i][j];
			}
		}
		rows = p.rows;
		columns = p.columns;
		
	}
	
	return *this;
}
Matrix Matrix::operator*(const double p) 
{
	Matrix matrix(columns, rows);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrix.elements[i][j] = elements[i][j] * p;
		}
	}
	
	return matrix;
}
Matrix Matrix::operator+(const Matrix& p) const
{
	Matrix matrix(columns, rows);
	if (columns == p.columns && rows == p.rows)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matrix.elements[i][j] = this->elements[i][j] + p.elements[i][j];
			}
		}
		return matrix;
	}
	
	cout << "Error" << endl;
	return matrix;
}
Matrix Matrix::operator-(const Matrix& p) const
{
	Matrix matrix(columns, rows);
	if (columns == p.columns && rows == p.rows)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matrix.elements[i][j] = this->elements[i][j] - p.elements[i][j];
			}
		}
		return matrix;
	}
	
	cout << "Error" << endl;
	return matrix;
}
Matrix Matrix::operator*(const Matrix& p) const
{
	Matrix matrix(columns, rows);
	if (columns == p.rows)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				for (int k = 0; k < columns; k++)
				{
					matrix.elements[i][j] += elements[i][k] * p.elements[k][j];
				}
			}
		}
		return matrix;
	}
	
	cout << "Error" << endl;
	return matrix;
}
Matrix::~Matrix()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] elements[i];
	}
	delete[] elements;
}

double Matrix::findDeterminant() const
{
	if(rows == 2 && columns == 2)
	{
		return elements[0][0]*elements[1][1] - elements[0][1]*elements[1][0]; 
	}
	if(rows == 3 && columns == 3)
	{
		double** e = elements;
		double mult1 = e[0][0]*e[1][1]*e[2][2]+e[0][1]*e[1][2]*e[2][0]+e[0][2]*e[1][0]*e[2][1];
		double mult2 = e[0][2]*e[1][1]*e[2][0]+e[0][1]*e[1][0]*e[2][2]+e[0][0]*e[1][2]*e[2][1];
		return mult1 - mult2; 
	}
	
	cout << "Error" << endl;
	return 0;
}
bool Matrix::isInvertable() const
{
	if((columns == 2 && rows == 2) || (columns == 3 && rows == 3))
	{
		return this->findDeterminant() != 0;
	}

	cout << "Error" << endl;
	return false;
}
double Matrix::getAt(int column, int row) const
{
	return elements[row][column];
}


void Matrix::setAt(int column, int row, double value)
{
	if(column > this->columns || row > this->rows) cout << "Error" << endl;
	elements[row][column] = value;
}
void Matrix::transponse()
{
	double** newElements = allocateMatrix(rows, columns);
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			newElements[j][i] = elements[i][j];
		}
	}
	
	for (int i = 0; i < rows; i++)
	{
		delete[] this->elements[i];
	}
	delete[] elements;	
	elements = newElements;
}
void Matrix::printMatrix() const
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << elements[i][j] << " ";
		}
		cout << endl;
	}
	
}
void Matrix::readMatrix()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> elements[i][j];
		}
	}
}

double** allocateMatrix(int columns, int rows)
{
	double** elements = new double*[rows];
	for (int i = 0; i < rows; i++)
	{
		elements[i] = new double[columns];
		for (int j = 0; j < columns; j++)
		{
			elements[i][j] = 0;
		}
	}
	
	return elements;
}
Matrix operator*(const double p, Matrix matrix)
{
	return matrix*2;
}

