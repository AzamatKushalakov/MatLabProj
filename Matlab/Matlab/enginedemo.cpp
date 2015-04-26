#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "engine.h"

using namespace std;
int main()
{
	int row = 2; // ����� �����
	int col = 2; // ��������

	// �������� MATLAB
	Engine *Eg;
	Eg = engOpen(NULL);

    // ������� 1-�� �������
	mxArray *Matrix1;
	Matrix1 = mxCreateDoubleMatrix(row, col, mxREAL); // 1-�� �������
	double *Matrixx1 = mxGetPr(Matrix1);
	double Arrays[] = { 1, 3, 4, 2 };
	// �������� �� ��� ������ �� Arrays � Matrixx ������ ��� ��� ������� ������ 
	memcpy(Matrixx1, Arrays, row*col* sizeof(double));
	// �������� ���������� Matrix1 � ������� ������� matlab
	engPutVariable(Eg, "Matrix1", Matrix1);

	// ������� 2 ������� � ������ ��� ����������
	mxArray *Matrix2;
	Matrix2 = mxCreateDoubleMatrix(row, col, mxREAL);
	double *Matrixx2 = mxGetPr(Matrix2);
	double Arrays2[] = { 0, 5, 2, 1 };
	memcpy(Matrixx2, Arrays2, row*col* sizeof(double));
	engPutVariable(Eg, "Matrix2", Matrix2);

	// ���� ���������� ������� � ������� ������� matlab
	engEvalString(Eg, "M_sum = Matrix + Matrix2");

	return 0;
}
	


