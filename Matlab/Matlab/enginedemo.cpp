#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "engine.h"
#include "matrix_operations.h"
#include <cstdio>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "������� ����� ����� � �������� ������� A:" << endl;
	int row_a, col_a;
	cin >> row_a >> col_a;
	double **A = new double *[row_a];
	for (int i = 0; i < row_a; ++i)
		A[i] = new double[col_a];
	cout << "������� ������� A, ��������������� �������� ������ ������:" << endl;
	for (int i = 0; i < row_a; ++i)
	{
		for (int j = 0; j < col_a; ++j)
			cin >> A[i][j];
	}
	cout << "������� A:" << endl;
	Print_Matrix(row_a, col_a, A);

	cout << "������� ����� ����� � �������� ������� B:" << endl;
	int row_b, col_b;
	cin >> row_b >> col_b;
	double **B = new double *[row_b];
	for (int i = 0; i < row_b; ++i)
		B[i] = new double[col_b];
	cout << "������� ������� B, ��������������� �������� ������ ������:" << endl;
	for (int i = 0; i < row_b; ++i)
	{
		for (int j = 0; j < col_b; ++j)
			cin >> B[i][j];
	}
	cout << "������� B:" << endl;
	Print_Matrix(row_b, col_b, B);

	cout << "A+B = " << endl;
	double **S = Sum(row_a, col_b, A, B);
	Print_Matrix(row_a, col_a, S);
	cout << endl;
	system("pause");
	return 0;
}
	


