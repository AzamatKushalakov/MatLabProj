#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <stdexcept>
#include <stdio.h>
#include <string.h>
#include "engine.h"
#include "matrix_operations.h"
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
int Matrix:: GetColumns()
{
	return col;
}
int Matrix:: GetRows()
{
	return row;
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
	matr = matr_;
}

// ����������
Matrix::~Matrix()
{
	// ����������� ������
	mxDestroyArray(matr);
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
		throw runtime_error("������� ������ ���� ����������!");
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
Matrix Matrix::operator + (Matrix M)
{
	// �������� MATLAB
	Engine *Eg;
	Eg = engOpen(NULL);

	// ���������, ����� ������� ���� ���������� ��������
	if ((row != M.row) && (col != M.col))
		throw runtime_error("������� ������ ���� ���������� ��������!");
	else
	{
		// �������� ������� matr � M.matr � ������� ������������ MATLAB
		engPutVariable(Eg, "N", matr);
		engPutVariable(Eg, "M", M.matr);
		engEvalString(Eg, "S = N+M"); // ��������� ����� � Matlab
	}
	mxArray *S_matr = engGetVariable(Eg, "S"); // ������� ��������� �� �������
	Matrix S(S_matr); // ������� ����������� ������� �������������
	return S;
	engClose(Eg); // ��������� matlab
}

// �������� ���������
Matrix Matrix::operator * (Matrix M)
{
	// �������� MATLAB
	Engine *Eg;
	Eg = engOpen(NULL);

	// �������� �� ����������� ������� ������������� ������
	if (col != M.row)
		throw runtime_error("������� ���������� �� �����!");
	else
	{
		// �������� ������� matr � M.matr � ������� ������������ MATLAB
		engPutVariable(Eg, "N", matr);
		engPutVariable(Eg, "M", M.matr);
		engEvalString(Eg, "P = N*M"); // ����������� ������� � ������� ������� Matlab
	}
	mxArray *P_matr = engGetVariable(Eg, "P"); // ������� ��������� �� �������
	Matrix P(P_matr); // ������� ����������� ������� �������������
	return P;
	engClose(Eg); // ��������� matlab
}
