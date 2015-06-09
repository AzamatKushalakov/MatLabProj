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
// конструктор по умолчанию
Matrix::Matrix()
{
	row = 0;
	col = 0;

	//Функция mxCreateDoubieMatrix выделяет память под структуру mxArray
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
// конструктор с параметрами, заполняющий матрицу элементами передаваемого двумерного массива
Matrix::Matrix(int row_, int col_, double** mas)
{
	row = row_;
	col = col_;

	// выделяем память под структуру mxArray
	matr = mxCreateDoubleMatrix(row, col, mxREAL);

	// получение доступа к элементам массива
	double* matr_ = mxGetPr(matr);

	// создаем одномерный массив
	double *Array = new double[row*col];

	// заполняем его элементами двумерного массива mas
	for (int j = 0; j < col; ++j)
	{
		for (int i = 0; i < row; ++i)
		{
			Array[i + j*row] = mas[i][j];
		}
	}

	// Копируем из Array в matr_ 
	memcpy(matr_, Array, row*col* sizeof(double));
}

// конструктор с параметром
Matrix::Matrix(mxArray *matr_)
{
	row = mxGetM(matr_); // получаем число строк матрицы, представленной матлабовским массивом mxArray
	col = mxGetN(matr_); // число столбцов
	matr = matr_;
}

// деструктор
Matrix::~Matrix()
{
	// освобождаем память
	mxDestroyArray(matr);
}

// возвращает двумерный массив, заполненный элементами матрицы Matrix
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
// вывод матрицы
void Matrix::PrintMatr()
{
	// создаем динамический двумерный массив
	double** mas = new double*[row];
	for (int i = 0; i < row; ++i)
		mas[i] = new double[col];

	// заполняем его элементами матлабовского массива mxArray
	for (int j = 0; j < col; ++j)
	{
		for (int i = 0; i < row; ++i)
		{
			mas[i][j] = *(mxGetPr(matr) + i + row*j);
		}
	}

	// выводим массив на экран
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

// транспонирование
void Matrix::Transport()
{
	//Открытие MATLAB
	Engine *Eg;
	Eg = engOpen(NULL);

	// помещаем массив mxArray в рабочее пространство MATLAB
	engPutVariable(Eg, "M", matr);

	// производим транспонирование в MATLABE
	engEvalString(Eg, "T = M'");

	// достаем результат T_matr
	mxArray *T_matr = engGetVariable(Eg, "T");

	// переводим T в формат С++
	row = mxGetM(T_matr); // число строк транспонированой матрицы
	col = mxGetN(T_matr); // число столбцов
	mxDestroyArray(matr); // освобождаем память(очищаем исходную матрицу)
	matr = T_matr; // заполняе матрицу элементами транспонированной матрицы
	engClose(Eg); // закрываем matlab
}

// определитель матрицы
int Matrix::Det()
{
	// Открытие MATLAB
	Engine *Eg;
	Eg = engOpen(NULL);

	// помещаем массив mxArray в рабочее пространство MATLAB
	engPutVariable(Eg, "M", matr);

	// проверяем, чтобы матрица была квадратной
	if (row != col)
		throw runtime_error("Матрица должна быть квадратной!");
	else
	{
		// находим определитель в MATLABE
		engEvalString(Eg, "D = det(M)");
		mxArray *D = engGetVariable(Eg, "D"); // достаем результат D 
		double det = *mxGetPr(D); // переводим определител в тип double языка C++
		return det;
	}
	engClose(Eg); // закрываем matlab
}

// оператор присваивания
Matrix  Matrix::operator = (Matrix  M)
{
	mxDestroyArray(matr); // очищаем массив
	row = M.row; // задаем число строк сприсваиваемой матрицы
	col = M.col; // число столбцов
	matr = M.matr; // массив mxArray
	return *this;
}

// оператор сложения
Matrix Matrix::operator + (Matrix M)
{
	// Открытие MATLAB
	Engine *Eg;
	Eg = engOpen(NULL);

	// проверяем, чтобы матрицы были одинаковых размеров
	if ((row != M.row) && (col != M.col))
		throw runtime_error("Матрица должны быть одинаковых размеров!");
	else
	{
		// помещаем массивы matr и M.matr в рабочее пространство MATLAB
		engPutVariable(Eg, "N", matr);
		engPutVariable(Eg, "M", M.matr);
		engEvalString(Eg, "S = N+M"); // вычисляем сумму в Matlab
	}
	mxArray *S_matr = engGetVariable(Eg, "S"); // достаем результат из матлаба
	Matrix S(S_matr); // создаем вычисленную матрицу конструктором
	return S;
	engClose(Eg); // закрываем matlab
}

// оператор умножения
Matrix Matrix::operator * (Matrix M)
{
	// Открытие MATLAB
	Engine *Eg;
	Eg = engOpen(NULL);

	// проверка на правильност задания перемножаемых матриц
	if (col != M.row)
		throw runtime_error("Матрицы определены не верно!");
	else
	{
		// помещаем массивы matr и M.matr в рабочее пространство MATLAB
		engPutVariable(Eg, "N", matr);
		engPutVariable(Eg, "M", M.matr);
		engEvalString(Eg, "P = N*M"); // перемножаем матрицы в рабочей области Matlab
	}
	mxArray *P_matr = engGetVariable(Eg, "P"); // достаем результат из матлаба
	Matrix P(P_matr); // создаем вычисленную матрицу конструктором
	return P;
	engClose(Eg); // закрываем matlab
}
