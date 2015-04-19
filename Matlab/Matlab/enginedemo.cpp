#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "engine.h"

int main()
{
	int row = 2;
	int col = 2;

	// �������� MATLAB
	Engine *Eg;
	Eg = engOpen(NULL);

	// ������� �������, mxArray - ��������� ��� ��� ������� � �++
	mxArray *Matrix1;
	
	Matrix1 = mxCreateDoubleMatrix(row, col, mxREAL);

	// ������� ���������, ��� ����� �����, ��� ����� �����
	double *Matrixx = mxGetPr(Matrix1);

	double Arrays[] = { 1, 3, 4, 2 };

	// �������� �� ��� ������ �� Arrays � Matrixx ������ ��� ��� ������� ������ (� ����� �������� ������������, � ������ �� �����)
	memcpy(Matrixx, Arrays, row*col* sizeof(double));

	// ������� 2 �������
	mxArray *Matrix2;

	Matrix1 = mxCreateDoubleMatrix(row, col, mxREAL);
	double *Matrixxx = mxGetPr(Matrix2);

	double Arrayss[] = { 0, 5, 2, 1 };

	memcpy(Matrixxx, Arrayss, row*col* sizeof(double));

	engPutVariable(Eg, "Matrix2", Matrix2);

	/* ������ ���� ����������� ��� ����������� ���������� � ����� ���������, ��� ����� �� ������
	*/

	return 0;
}
	


