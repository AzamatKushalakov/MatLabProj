#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "engine.h"
#include "matrix_operations.h"
#include <cstdio>
using namespace std;

double** Sum(int row, int col, double** Matrix_A , double** Matrix_B)
{
	// �������� MATLAB
	Engine *Eg;

	Eg = engOpen(NULL);

	// ������� 1-�� �������
	mxArray *A;
	A = mxCreateDoubleMatrix(row, col, mxREAL);
	double *A_ = mxGetPr(A);
	double *Array_A = new double[row*col];
	for (int j = 0; j < col; ++j)
	{
		for (int i = 0; i < row; ++i)
		{
			Array_A[i + j*row] = Matrix_A[i][j];
		}
	}
	// �������� �� Arrays1 � A_ 
	memcpy(A_, Array_A, row*col* sizeof(double));

	// �������� ���������� Matrix1 � ������� ������� matlab
	engPutVariable(Eg, "A", A);

	// ������� 2 ������� � ������ ��� ����������
	mxArray *B;
	B = mxCreateDoubleMatrix(row, col, mxREAL);
	double *B_ = mxGetPr(B);
	double *Array_B = new double[row*col];
	for (int j = 0; j < col; ++j)
	{
		for (int i = 0; i < row; ++i)
		{
			Array_B[i + j*row] = Matrix_B[i][j];
		}
	}
	memcpy(B_, Array_B, row*col* sizeof(double));
	engPutVariable(Eg, "B", B);
	engEvalString(Eg, "S = A+B");

	// ������� ��������� S
	mxArray *S = engGetVariable(Eg, "S");

	// ��������� S � ������ �++
	int s_row = mxGetM(S); // ����� �����
	int s_col = mxGetN(S); // ����� ��������
	double** Array_S = new double*[s_row];
	for (int i = 0; i < s_row; ++i)
		Array_S[i] = new double[s_col];
	for (int j = 0; j < s_col; ++j)
	{
		for (int i = 0; i < s_row; ++i)
		{
			Array_S[i][j] = *(mxGetPr(S) + i + s_row*j);
		}
	}
	mxDestroyArray(A); // ����������� ������
	mxDestroyArray(B);
	mxDestroyArray(S);
	engClose(Eg); // ��������� ������� �������
	return Array_S;
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
