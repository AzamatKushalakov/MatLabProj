#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "engine.h"

using namespace std;
int main()
{
	int row = 2; // число строк
	int col = 2; // столбцов

	// Открытие MATLAB
	Engine *Eg;
	Eg = engOpen(NULL);

    // создаем 1-ую матрицу
	mxArray *Matrix1;
	Matrix1 = mxCreateDoubleMatrix(row, col, mxREAL); // 1-ая матрица
	double *Matrixx1 = mxGetPr(Matrix1);
	double Arrays[] = { 1, 3, 4, 2 };
	// Копируем мы тут потому из Arrays в Matrixx потому что так устроен матлаб 
	memcpy(Matrixx1, Arrays, row*col* sizeof(double));
	// Помещаем переменную Matrix1 в рабочую область matlab
	engPutVariable(Eg, "Matrix1", Matrix1);

	// Создаем 2 матрицу и делаем все аналогично
	mxArray *Matrix2;
	Matrix2 = mxCreateDoubleMatrix(row, col, mxREAL);
	double *Matrixx2 = mxGetPr(Matrix2);
	double Arrays2[] = { 0, 5, 2, 1 };
	memcpy(Matrixx2, Arrays2, row*col* sizeof(double));
	engPutVariable(Eg, "Matrix2", Matrix2);

	// Типо складывает матрицы в рабочей области matlab
	engEvalString(Eg, "M_sum = Matrix + Matrix2");

	return 0;
}
	


