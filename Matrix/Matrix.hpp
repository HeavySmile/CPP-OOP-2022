#pragma once

class Matrix
{
private:
	int columns;
	int rows;
	double** elements;
public:
	Matrix(int, int);
	Matrix(const Matrix&);
	Matrix& operator=(const Matrix&);
	Matrix operator*(const double);
	Matrix operator+(const Matrix&) const;
	Matrix operator-(const Matrix&) const;
	Matrix operator*(const Matrix&) const;
	~Matrix();

	double findDeterminant() const;
	bool isInvertable() const;
	double getAt(int, int) const;
	char getMatrixSize() const;

	void setAt(int, int, double);
	void transponse();
	void printMatrix() const;
	void readMatrix();

};

	Matrix operator*(const double, Matrix);


double** allocateMatrix(int, int);

