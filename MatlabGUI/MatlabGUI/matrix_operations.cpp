#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdlib.h>
#include <stdexcept>
#include <stdio.h>
#include <string.h>
#include "engine.h"
#include "matrix_operations.h"
#include "Matrix_exceptions.h"
#include <cstdio>
#include "MyForm.h"

using namespace std;

// ����������� �� ���������
Matrix::Matrix()
{
	row = 0;
	col = 0;

	//������� mxCreateDoubieMatrix �������� ������ ��� ��������� mxArray
	matr = mxCreateDoubleMatrix(row, col, mxREAL);
}

// �����������, ��������� ������� ������� 
Matrix::Matrix(int row_, int col_)
{
	row = row_;
	col = col_;

	// �������� ������ ��� ��������� mxArray
	matr = mxCreateDoubleMatrix(row, col, mxREAL);

	// ��������� ������� � ��������� �������
	double* matr_ = mxGetPr(matr);

	// ������� ���������� ������
	double *Array = new double[row*col];

	// ��������� ��� ������
	for (int i = 0; i < row*col; ++i)
		Array[i] = 0;

	// �������� �� Array � matr_
	memcpy(matr_, Array, row*col* sizeof(double));
}

// �����������, ��������� ��������� ������� 
Matrix::Matrix(int size)
{
	row = size;
	col = size;

	// �������� ������ ��� ��������� mxArray
	matr = mxCreateDoubleMatrix(row, col, mxREAL);

	// ��������� ������� � ��������� �������
	double* matr_ = mxGetPr(matr);

	// ������� ���������� ������
	double *Array = new double[row*col];

	// ��������� ��� ��������� �� ���������
	for (int i = 0; i < row*col; ++i)
	{
		if (i % (size + 1) == 0)
			Array[i] = 1;
		else
			Array[i] = 0; // � ������ �� �� ���������
	}

	// �������� �� Array � matr_
	memcpy(matr_, Array, row*col* sizeof(double));
}

// �����������, ��������� ������� � ����������, ���������� �� �����
Matrix::Matrix(int row_, int col_, char* fileName)
{
	row = row_;
	col = col_;

	// ��������� ������������ ������ ��� �������
	double **mas = new double *[row];	// ��������� �� ������ ����������;
	for (int i = 0; i < row; ++i)
		mas[i] = new double[col];
	ifstream inarray(fileName);	// �������� ����� ��� �����
	if (!inarray)
		throw file_error();

	// ���������� ������� (����������� �� �����)
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			inarray >> mas[i][j];
		}
	}
	inarray.close();
	matr = mxCreateDoubleMatrix(row, col, mxREAL);// �������� ������ ��� ��������� mxArray
	double* matr_ = mxGetPr(matr);// ��������� ������� � ��������� �������
	double *Array = new double[row*col]; // ������� ���������� ������

	// ��������� ��� ���������� ���������� ������� mas
	for (int j = 0; j < col; ++j)
	{
		for (int i = 0; i < row; ++i)
		{
			Array[i + j*row] = mas[i][j];
		}
	}
	memcpy(matr_, Array, row*col* sizeof(double)); // �������� �� Array � matr_ 
}

// ����������� � �����������, ����������� ������� ���������� ������������� ���������� �������
Matrix::Matrix(int row_, int col_, double** mas)
{
	row = row_;
	col = col_;

	// �������� ������ ��� ��������� mxArray
	matr = mxCreateDoubleMatrix(row, col, mxREAL);

	// ��������� ������� � ��������� �������
	double* matr_ = mxGetPr(matr);

	// ������� ���������� ������
	double *Array = new double[row*col];

	// ��������� ��� ���������� ���������� ������� mas
	for (int j = 0; j < col; ++j)
	{
		for (int i = 0; i < row; ++i)
		{
			Array[i + j*row] = mas[i][j];
		}
	}

	// �������� �� Array � matr_ 
	memcpy(matr_, Array, row*col* sizeof(double));
}

// ����������� � ����������
Matrix::Matrix(mxArray *matr_)
{
	row = mxGetM(matr_); // �������� ����� ����� �������, �������������� ������������ �������� mxArray
	col = mxGetN(matr_); // ����� ��������

	matr = mxCreateDoubleMatrix(row, col, mxREAL);
	memcpy(mxGetPr(matr), mxGetPr(matr_), row*col* sizeof(double));
}

Matrix::Matrix(const Matrix& other)
{
	row = other.row; // �������� ����� ����� �������, �������������� ������������ �������� mxArray
	col = other.col; // ����� ��������

	matr = mxCreateDoubleMatrix(row, col, mxREAL);
	memcpy(mxGetPr(matr), mxGetPr(other.matr), row*col* sizeof(double));
}

// ����������
Matrix::~Matrix()
{
	// ����������� ������
	mxDestroyArray(matr);
}
int Matrix::GetColumns()
{
	return col;
}
int Matrix::GetRows()
{
	return row;
}

// ���������� ��������� ������, ����������� ���������� ������� Matrix
double** Matrix::ReturnMass()
{
	double** mas = new double*[row];
	for (int i = 0; i < row; ++i)
		mas[i] = new double[col];
	for (int j = 0; j < col; ++j)
	{
		for (int i = 0; i < row; ++i)
		{
			mas[i][j] = *(mxGetPr(matr) + i + row*j);
		}
	}
	return mas;
}

// ����� �������
void Matrix::PrintMatr()
{
	// ������� ������������ ��������� ������
	double** mas = new double*[row];
	for (int i = 0; i < row; ++i)
		mas[i] = new double[col];

	// ��������� ��� ���������� ������������� ������� mxArray
	for (int j = 0; j < col; ++j)
	{
		for (int i = 0; i < row; ++i)
		{
			mas[i][j] = *(mxGetPr(matr) + i + row*j);
		}
	}

	// ������� ������ �� �����
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			printf("%8.2f", mas[i][j]);
		}
		cout << "\n";
	}
	cout << endl;
}

// ����������������
void Matrix::Transport()
{
	//�������� MATLAB
	Engine *Eg;
	Eg = engOpen(NULL);

	// �������� ������ mxArray � ������� ������������ MATLAB
	engPutVariable(Eg, "M", matr);

	// ���������� ���������������� � MATLABE
	engEvalString(Eg, "T = M'");

	// ������� ��������� T_matr
	mxArray *T_matr = engGetVariable(Eg, "T");

	// ��������� T � ������ �++
	row = mxGetM(T_matr); // ����� ����� ���������������� �������
	col = mxGetN(T_matr); // ����� ��������
	mxDestroyArray(matr); // ����������� ������(������� �������� �������)
	matr = T_matr; // �������� ������� ���������� ����������������� �������
	engClose(Eg); // ��������� matlab
}

// �������� �������
void Matrix::InverseMatr()
{
	//�������� MATLAB
	Engine *Eg;
	Eg = engOpen(NULL);

	// �������� ������ mxArray � ������� ������������ MATLAB
	engPutVariable(Eg, "M", matr);
	// ���������, ����� ������� ���� ����������
	if (row != col)
		throw matrix_is_not_square();
	
	if (this->Det() == 0)
		throw matrix_is_not_invertible();
	else
	{
		// ���������� ���������������� � MATLABE
		engEvalString(Eg, "T = inv(M)");

		// ������� ��������� T_matr
		mxArray *T_matr = engGetVariable(Eg, "T");
		mxDestroyArray(matr); // ����������� ������(������� �������� �������)
		matr = T_matr; // �������� ������� ���������� ����������������� �������
		engClose(Eg); // ��������� matlab
	}	
}
// ������������ �������
int Matrix::Det()
{
	// �������� MATLAB
	Engine *Eg;
	Eg = engOpen(NULL);

	// �������� ������ mxArray � ������� ������������ MATLAB
	engPutVariable(Eg, "M", matr);

	// ���������, ����� ������� ���� ����������
	if (row != col)
		throw mins;
	else
	{
		// ������� ������������ � MATLABE
		engEvalString(Eg, "D = det(M)");
		mxArray *D = engGetVariable(Eg, "D"); // ������� ��������� D 
		double det = *mxGetPr(D); // ��������� ����������� � ��� double ����� C++
		return det;
	}
	engClose(Eg); // ��������� matlab
}

// �������� ������������
Matrix  Matrix::operator = (Matrix  M)
{
	mxDestroyArray(matr); // ������� ������
	row = M.row; // ������ ����� ����� �������������� �������
	col = M.col; // ����� ��������
	matr = M.matr; // ������ mxArray
	return *this;
}

// �������� ��������
Matrix Matrix::operator + (const Matrix& M)
{
	// �������� MATLAB
	Engine *Eg;
	Eg = engOpen(NULL);

	// ���������, ����� ������� ���� ���������� ��������
	if ((row != M.row) || (col != M.col))
		throw ics;
	else
	{
		// �������� ������� matr � M.matr � ������� ������������ MATLAB
		engPutVariable(Eg, "N", matr);
		engPutVariable(Eg, "M", M.matr);
		engEvalString(Eg, "S = N+M"); // ��������� ����� � Matlab
	}
	mxArray *S_matr = engGetVariable(Eg, "S"); // ������� ��������� �� �������
	Matrix *S = new Matrix(S_matr); // ������� ����������� ������� �������������
	//engClose(Eg); // ��������� matlab
	return *S;
}

// �������� ���������
Matrix Matrix::operator * (Matrix M)
{
	// �������� MATLAB
	Engine *Eg;
	Eg = engOpen(NULL);

	// �������� �� ����������� ������� ������������� ������
	if (col != M.row)
		throw ics;
	else
	{
		// �������� ������� matr � M.matr � ������� ������������ MATLAB
		engPutVariable(Eg, "N", matr);
		engPutVariable(Eg, "M", M.matr);
		engEvalString(Eg, "P = N*M"); // ����������� ������� � ������� ������� Matlab
	}
	mxArray *P_matr = engGetVariable(Eg, "P"); // ������� ��������� �� �������
	Matrix *P = new Matrix(P_matr); // ������� ����������� ������� �������������	
	//engClose(Eg); // ��������� matlab
	return *P;

}
