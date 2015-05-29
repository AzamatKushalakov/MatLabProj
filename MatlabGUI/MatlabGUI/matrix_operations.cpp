#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <stdexcept>
#include <stdio.h>
#include <string.h>
#include "engine.h"
#include "matrix_operations.h"
#include <cstdio>

using namespace std;

Matrix::Matrix()
{
	row = 0;
	col = 0;
	//������� mxCreateDoubieMatrix �������� ������ ��� ��������� mxArray
	matr = mxCreateDoubleMatrix(row, col, mxREAL);
}

Matrix::Matrix(int row_, int col_, double** mas)
{
	//Engine *Eg;
	//Eg = engOpen(NULL);
	row = row_;
	col = col_;
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

Matrix::Matrix(int row_, int col_, mxArray *matr_)
{
	row = row_;
	col = col_;
	matr = matr_;
}

Matrix::~Matrix()
{
	// ����������� ������
	mxDestroyArray(matr);
}

// ��� ��-�������� ������ ������ ����, ���� ����� ��������
Matrix  Matrix::operator = (Matrix  M)
{
	mxDestroyArray(matr);
	row = M.row;
	col = M.col;
	matr = M.matr;
	return *this;
}

void Matrix::PrintMatr()
{
	//Engine *Eg;
	//Eg = engOpen(NULL);
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
void Matrix::Transport()
{
	//�������� MATLAB
	Engine *Eg;
	Eg = engOpen(NULL);
	engPutVariable(Eg, "M", matr);
	engEvalString(Eg, "T = M'");
	// ������� ��������� T_matr
	mxArray *T_matr = engGetVariable(Eg, "T");
	// ��������� T � ������ �++
	row = mxGetM(T_matr); // ����� �����
	col = mxGetN(T_matr); // ����� ��������
	mxDestroyArray(matr);
	matr = T_matr;
}
int Matrix::Det()
{
	// �������� MATLAB
	Engine *Eg;
	Eg = engOpen(NULL);
	engPutVariable(Eg, "M", matr);
	engEvalString(Eg, "d = det(M)");
	if (row == col)
		engEvalString(Eg, "D = det(M)");
	// ������� ��������� D
	mxArray *D = engGetVariable(Eg, "D");
	double det = *mxGetPr(D);
	return det;
}
Matrix Matrix::operator + (Matrix M)
{
	Engine *Eg;
	Eg = engOpen(NULL);
	Matrix N(*this);
	if ((N.row == M.row) && (N.col == M.col))
	{
		engPutVariable(Eg, "N", matr);
		engPutVariable(Eg, "M", M.matr);
		engEvalString(Eg, "S = N+M");
	}
	mxDestroyArray(matr);

	// ������� ��������� �� �������
	matr = engGetVariable(Eg, "S");
	return N;
}
Matrix Matrix::operator * (Matrix M)
{
	Engine *Eg;
	Eg = engOpen(NULL);
	if (col == M.row)
	{
		engPutVariable(Eg, "N", matr);
		engPutVariable(Eg, "M", M.matr);
		engEvalString(Eg, "P = N*M");
		mxArray *P_matr = engGetVariable(Eg, "P");
		int P_row = mxGetM(P_matr); // ����� ����� ������� P
		int P_col = mxGetN(P_matr); // ����� �������� ������� P
		Matrix P(P_row, P_col, P_matr);
		return P;
	}
	//����� ���������� ����������
	else
		return (*this);
}

//double** BinaryOperation(int row_a, int col_a, double** Matrix_A , int row_b, int col_b, double** Matrix_B, char operation)
//{
//	// �������� MATLAB
//	Engine *Eg;
//	Eg = engOpen(NULL);
//
//	// ������� ������� A
//	mxArray *A;
//	A = mxCreateDoubleMatrix(row_a, col_a, mxREAL);
//	double *_A = mxGetPr(A);
//	double *Array_A = new double[row_a*col_a];
//	for (int j = 0; j < col_a; ++j)
//	{
//		for (int i = 0; i < row_a; ++i)
//		{
//			Array_A[i + j*row_a] = Matrix_A[i][j];
//		}
//	}
//	// �������� �� Arrays_A � A_ 
//	memcpy(_A, Array_A, row_a*col_a* sizeof(double));
//
//	// �������� ���������� A � ������� ������� matlab
//	engPutVariable(Eg, "A", A);
//
//	// ������� ������� B � ������ ��� ����������
//	mxArray *B;
//	B = mxCreateDoubleMatrix(row_b, col_b, mxREAL);
//	double *_B = mxGetPr(B);
//	double *Array_B = new double[row_b*col_b];
//	for (int j = 0; j < col_b; ++j)
//	{
//		for (int i = 0; i < row_b; ++i)
//		{
//			Array_B[i + j*row_b] = Matrix_B[i][j];
//		}
//	}
//	memcpy(_B, Array_B, row_b*col_b* sizeof(double));
//	engPutVariable(Eg, "B", B);
//	// ��������� �������� ��� ���������
//	if (operation == '+')
//	{
//		if (row_a == row_b && col_a == col_b)
//			engEvalString(Eg, "Result = A+B");
//		else
//			throw runtime_error("������ ������ ������ ���� ����������");
//	}
//	else if (operation == '*')
//	{
//		if (col_a == row_b)
//			engEvalString(Eg, "Result = A*B");
//		else
//			throw runtime_error("���������� �������� ������ ������� ������ ��������� ���������� ����� ������!!!");
//	}
//	// ������� ��������� Result
//	mxArray *Result = engGetVariable(Eg, "Result");
//
//	// ��������� Result � ������ �++
//	int r_row = mxGetM(Result); // ����� �����
//	int r_col = mxGetN(Result); // ����� ��������
//	double** Array_R = new double*[r_row];
//	for (int i = 0; i < r_row; ++i)
//		Array_R[i] = new double[r_col];
//	for (int j = 0; j < r_col; ++j)
//	{
//		for (int i = 0; i < r_row; ++i)
//		{
//			Array_R[i][j] = *(mxGetPr(Result) + i + r_row*j);
//		}
//	}
//	// ����������� ������
//	mxDestroyArray(A); 
//	mxDestroyArray(B);
//	mxDestroyArray(Result);
//	// ��������� ������� �������
//	engClose(Eg); 
//	return Array_R;
//}
//
//double** Transpose(int row, int col, double** Matrix)
//{
//	// �������� MATLAB
//	Engine *Eg;
//	Eg = engOpen(NULL);
//	// ������� ������� �, ������ ��� ���������� �����������
//	mxArray *M;
//	M = mxCreateDoubleMatrix(row, col, mxREAL);
//	double *_M = mxGetPr(M);
//	double *Array_M = new double[row*col];
//	for (int j = 0; j < col; ++j)
//	{
//		for (int i = 0; i < row; ++i)
//		{
//			Array_M[i + j*row] = Matrix[i][j];
//		}
//	}
//	memcpy(_M, Array_M, row*col* sizeof(double));
//	engPutVariable(Eg, "M", M);
//	engEvalString(Eg, "T = M'");
//	// ������� ��������� Result
//	mxArray *T = engGetVariable(Eg, "T");
//
//	// ��������� Result � ������ �++
//	int t_row = mxGetM(T); // ����� �����
//	int t_col = mxGetN(T); // ����� ��������
//	double** Array_T = new double*[t_row];
//	for (int i = 0; i < t_row; ++i)
//		Array_T[i] = new double[t_col];
//	for (int j = 0; j < t_col; ++j)
//	{
//		for (int i = 0; i < t_row; ++i)
//		{
//			Array_T[i][j] = *(mxGetPr(T) + i + t_row*j);
//		}
//	}
//	mxDestroyArray(M); // ����������� ������
//	mxDestroyArray(T);
//	engClose(Eg); // ��������� ������� �������
//	return Array_T;
//}
//
//double Det(int row, int col, double** Matrix)
//{
//	// �������� MATLAB
//	Engine *Eg;
//	Eg = engOpen(NULL);
//	mxArray *M;
//	M = mxCreateDoubleMatrix(row, col, mxREAL);
//	double *_M = mxGetPr(M);
//	double *Array_M = new double[row*col];
//	for (int j = 0; j < col; ++j)
//	{
//		for (int i = 0; i < row; ++i)
//		{
//			Array_M[i + j*row] = Matrix[i][j];
//		}
//	}
//	memcpy(_M, Array_M, row*col* sizeof(double));
//	engPutVariable(Eg, "M", M);
//	if (row == col)
//		engEvalString(Eg, "d = det(M)");
//	else
//		throw runtime_error("������� ������ ���� ����������!!!");
//	// ������� ��������� Result
//	mxArray *d = engGetVariable(Eg, "d");
//	double det = *mxGetPr(d);
//	return det;
//}
//
//void Print_Matrix(int row, int col, double** Matrix)
//{	
//	for (int i = 0; i < row; ++i)
//	{
//		for (int j = 0; j < col; ++j)
//		{
//			printf("%8.2f", Matrix[i][j]);
//		}
//		cout << "\n";
//	}
//	cout << endl;
//}