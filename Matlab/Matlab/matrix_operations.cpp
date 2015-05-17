#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "engine.h"
#include "matrix_operations.h"
#include <cstdio>
using namespace std;

double** BinaryOperation(int row_a, int col_a, double** Matrix_A , int row_b, int col_b, double** Matrix_B, char operation)
{
	// �������� MATLAB
	Engine *Eg;
	Eg = engOpen(NULL);

	// ������� ������� A
	mxArray *A;
	A = mxCreateDoubleMatrix(row_a, col_a, mxREAL);
	double *_A = mxGetPr(A);
	double *Array_A = new double[row_a*col_a];
	for (int j = 0; j < col_a; ++j)
	{
		for (int i = 0; i < row_a; ++i)
		{
			Array_A[i + j*row_a] = Matrix_A[i][j];
		}
	}
	// �������� �� Arrays_A � A_ 
	memcpy(_A, Array_A, row_a*col_a* sizeof(double));

	// �������� ���������� A � ������� ������� matlab
	engPutVariable(Eg, "A", A);

	// ������� ������� B � ������ ��� ����������
	mxArray *B;
	B = mxCreateDoubleMatrix(row_b, col_b, mxREAL);
	double *_B = mxGetPr(B);
	double *Array_B = new double[row_b*col_b];
	for (int j = 0; j < col_b; ++j)
	{
		for (int i = 0; i < row_b; ++i)
		{
			Array_B[i + j*row_b] = Matrix_B[i][j];
		}
	}
	memcpy(_B, Array_B, row_b*col_b* sizeof(double));
	engPutVariable(Eg, "B", B);
	if (operation == '+')
	{
		if (row_a == row_b && col_a == col_b)
			engEvalString(Eg, "Result = A+B");
	}
	else if (operation == '*')
	{
		if (col_a = row_b)
			engEvalString(Eg, "Result = A*B");
	}
	// ������� ��������� Result
	mxArray *Result = engGetVariable(Eg, "Result");

	// ��������� Result � ������ �++
	int r_row = mxGetM(Result); // ����� �����
	int r_col = mxGetN(Result); // ����� ��������
	double** Array_R = new double*[r_row];
	for (int i = 0; i < r_row; ++i)
		Array_R[i] = new double[r_col];
	for (int j = 0; j < r_col; ++j)
	{
		for (int i = 0; i < r_row; ++i)
		{
			Array_R[i][j] = *(mxGetPr(Result) + i + r_row*j);
		}
	}
	mxDestroyArray(A); // ����������� ������
	mxDestroyArray(B);
	mxDestroyArray(Result);
	engClose(Eg); // ��������� ������� �������
	return Array_R;
}
double** Transpose(int row, int col, double** Matrix)
{
	// �������� MATLAB
	Engine *Eg;
	Eg = engOpen(NULL);
	mxArray *M;
	M = mxCreateDoubleMatrix(row, col, mxREAL);
	double *_M = mxGetPr(M);
	double *Array_M = new double[row*col];
	for (int j = 0; j < col; ++j)
	{
		for (int i = 0; i < row; ++i)
		{
			Array_M[i + j*row] = Matrix[i][j];
		}
	}
	memcpy(_M, Array_M, row*col* sizeof(double));
	engPutVariable(Eg, "M", M);
	engEvalString(Eg, "T = M'");
	// ������� ��������� Result
	mxArray *T = engGetVariable(Eg, "T");

	// ��������� Result � ������ �++
	int t_row = mxGetM(T); // ����� �����
	int t_col = mxGetN(T); // ����� ��������
	double** Array_T = new double*[t_row];
	for (int i = 0; i < t_row; ++i)
		Array_T[i] = new double[t_col];
	for (int j = 0; j < t_col; ++j)
	{
		for (int i = 0; i < t_row; ++i)
		{
			Array_T[i][j] = *(mxGetPr(T) + i + t_row*j);
		}
	}
	mxDestroyArray(M); // ����������� ������
	mxDestroyArray(T);
	engClose(Eg); // ��������� ������� �������
	return Array_T;
}
double Det(int row, int col, double** Matrix)
{
	// �������� MATLAB
	Engine *Eg;
	Eg = engOpen(NULL);
	mxArray *M;
	M = mxCreateDoubleMatrix(row, col, mxREAL);
	double *_M = mxGetPr(M);
	double *Array_M = new double[row*col];
	for (int j = 0; j < col; ++j)
	{
		for (int i = 0; i < row; ++i)
		{
			Array_M[i + j*row] = Matrix[i][j];
		}
	}
	memcpy(_M, Array_M, row*col* sizeof(double));
	engPutVariable(Eg, "M", M);
	engEvalString(Eg, "d = det(M)");
	// ������� ��������� Result
	mxArray *d = engGetVariable(Eg, "d");
	double det = *mxGetPr(d);
	return det;
}
void Print_Matrix(int row, int col, double** Matrix)
{	
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			printf("%8.2f", Matrix[i][j]);
		}
		cout << "\n";
	}
	cout << endl;
}
