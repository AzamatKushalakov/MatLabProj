#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "engine.h"

int main()
{
	int row = 2;
	int col = 2;

	// Открытие MATLAB
	Engine *Eg;
	Eg = engOpen(NULL);

	// Создаем матрицу, mxArray - смешанный тип для матлаба и с++
	mxArray *Matrix1;
	
	Matrix1 = mxCreateDoubleMatrix(row, col, mxREAL);

	// Создаем указатель, хуй знает зачем, так мужик делал
	double *Matrixx = mxGetPr(Matrix1);

	double Arrays[] = { 1, 3, 4, 2 };

	// Копируем мы тут потому из Arrays в Matrixx потому что так устроен матлаб (В видео подробно разъясняется, я нифига не понял)
	memcpy(Matrixx, Arrays, row*col* sizeof(double));

	// Создаем 2 матрицу
	mxArray *Matrix2;

	Matrix1 = mxCreateDoubleMatrix(row, col, mxREAL);
	double *Matrixxx = mxGetPr(Matrix2);

	double Arrayss[] = { 0, 5, 2, 1 };

	memcpy(Matrixxx, Arrayss, row*col* sizeof(double));

	engPutVariable(Eg, "Matrix2", Matrix2);

	/* ТЕПЕРЬ НАДО РАЗОБРАТЬСЯ КАК ПРОИЗВОДИТЬ ВЫЧИСЛЕНИЯ С ЭТИМИ МАТРИЦАМИ, ВСЕ УЗНАЛ ИЗ ВИДЮХИ
	*/

	return 0;
}
	


