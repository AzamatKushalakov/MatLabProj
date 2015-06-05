//double** BinaryOperation(int, int, double** , int, int, double **, char);
//double** Transpose(int, int, double**);
//double Det(int, int, double**);
//void Print_Matrix(int, int, double**);
#pragma once
#include <iostream>

using namespace std;

class Matrix
{
private:
	mxArray *matr;
	int row;
	int col;
public:
	Matrix();
	Matrix(int, int, double**);
	Matrix(int, int, mxArray*);
	~Matrix();

	double** ReturnMass(Matrix);
	void Transport();
	void PrintMatr();
	int Det();
	int GetColumns();
	int GetRows();
	Matrix  operator = (Matrix);
	Matrix operator + (Matrix);
	Matrix operator * (Matrix);
};
