#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdlib.h>
#include <stdexcept>
#include <stdio.h>
#include <string.h>
#include "engine.h"
#include "matrix_operations.h"
#include "Matrix_exceptions.h"
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

// конструктор, создающий нулевую матрицу 
Matrix::Matrix(int row_, int col_)
{
	row = row_;
	col = col_;

	// выделяем память под структуру mxArray
	matr = mxCreateDoubleMatrix(row, col, mxREAL);

	// получение доступа к элементам массива
	double* matr_ = mxGetPr(matr);

	// создаем одномерный массив
	double *Array = new double[row*col];

	// заполняем его нулями
	for (int i = 0; i < row*col; ++i)
		Array[i] = 0;

	// Копируем из Array в matr_
	memcpy(matr_, Array, row*col* sizeof(double));
}

// конструктор, создающий единичную матрицу 
Matrix::Matrix(int size)
{
	row = size;
	col = size;

	// выделяем память под структуру mxArray
	matr = mxCreateDoubleMatrix(row, col, mxREAL);

	// получение доступа к элементам массива
	double* matr_ = mxGetPr(matr);

	// создаем одномерный массив
	double *Array = new double[row*col];

	// заполняем его единицами на диагонали
	for (int i = 0; i < row*col; ++i)
	{
		if (i % (size + 1) == 0)
			Array[i] = 1;
		else
			Array[i] = 0; // и нулями не на диагонали
	}

	// Копируем из Array в matr_
	memcpy(matr_, Array, row*col* sizeof(double));
}

// конструктор, создающий матрицу с элементами, считанными из файла
Matrix::Matrix(int row_, int col_, char* fileName)
{
	row = row_;
	col = col_;

	// Выделение динамической памяти для матрицы
	double **mas = new double *[row];	// Указатель на массив указателей;
	for (int i = 0; i < row; ++i)
		mas[i] = new double[col];
	ifstream inarray(fileName);	// Открытие файла для ввода
	if (!inarray)
		throw file_error();

	// Заполнение матрицы (считыванием из файла)
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			inarray >> mas[i][j];
		}
	}
	inarray.close();
	matr = mxCreateDoubleMatrix(row, col, mxREAL);// выделяем память под структуру mxArray
	double* matr_ = mxGetPr(matr);// получение доступа к элементам массива
	double *Array = new double[row*col]; // создаем одномерный массив

	// заполняем его элементами двумерного массива mas
	for (int j = 0; j < col; ++j)
	{
		for (int i = 0; i < row; ++i)
		{
			Array[i + j*row] = mas[i][j];
		}
	}
	memcpy(matr_, Array, row*col* sizeof(double)); // Копируем из Array в matr_ 
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

	matr = mxCreateDoubleMatrix(row, col, mxREAL);
	memcpy(mxGetPr(matr), mxGetPr(matr_), row*col* sizeof(double));
}

Matrix::Matrix(const Matrix& other)
{
	row = other.row; // получаем число строк матрицы, представленной матлабовским массивом mxArray
	col = other.col; // число столбцов

	matr = mxCreateDoubleMatrix(row, col, mxREAL);
	memcpy(mxGetPr(matr), mxGetPr(other.matr), row*col* sizeof(double));
}

// деструктор
Matrix::~Matrix()
{
	// освобождаем память
	mxDestroyArray(matr);
}
int Matrix::GetColumns()
{
	return col;
}
int Matrix::GetRows()
{
	return row;
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

// Обратная матрица
void Matrix::InverseMatr()
{
	//Открытие MATLAB
	Engine *Eg;
	Eg = engOpen(NULL);

	// помещаем массив mxArray в рабочее пространство MATLAB
	engPutVariable(Eg, "M", matr);
	// проверяем, чтобы матрица была квадратной
	if (row != col)
		throw matrix_is_not_square();
	
	if (this->Det() == 0)
		throw matrix_is_not_invertible();
	else
	{
		// производим транспонирование в MATLABE
		engEvalString(Eg, "T = inv(M)");

		// достаем результат T_matr
		mxArray *T_matr = engGetVariable(Eg, "T");
		mxDestroyArray(matr); // освобождаем память(очищаем исходную матрицу)
		matr = T_matr; // заполняе матрицу элементами транспонированной матрицы
		engClose(Eg); // закрываем matlab
	}	
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
		throw mins;
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
Matrix Matrix::operator + (const Matrix& M)
{
	// Открытие MATLAB
	Engine *Eg;
	Eg = engOpen(NULL);

	// проверяем, чтобы матрицы были одинаковых размеров
	if ((row != M.row) || (col != M.col))
		throw ics;
	else
	{
		// помещаем массивы matr и M.matr в рабочее пространство MATLAB
		engPutVariable(Eg, "N", matr);
		engPutVariable(Eg, "M", M.matr);
		engEvalString(Eg, "S = N+M"); // вычисляем сумму в Matlab
	}
	mxArray *S_matr = engGetVariable(Eg, "S"); // достаем результат из матлаба
	Matrix *S = new Matrix(S_matr); // создаем вычисленную матрицу конструктором
	//engClose(Eg); // закрываем matlab
	return *S;
}

// оператор умножения
Matrix Matrix::operator * (Matrix M)
{
	// Открытие MATLAB
	Engine *Eg;
	Eg = engOpen(NULL);

	// проверка на правильност задания перемножаемых матриц
	if (col != M.row)
		throw ics;
	else
	{
		// помещаем массивы matr и M.matr в рабочее пространство MATLAB
		engPutVariable(Eg, "N", matr);
		engPutVariable(Eg, "M", M.matr);
		engEvalString(Eg, "P = N*M"); // перемножаем матрицы в рабочей области Matlab
	}
	mxArray *P_matr = engGetVariable(Eg, "P"); // достаем результат из матлаба
	Matrix *P = new Matrix(P_matr); // создаем вычисленную матрицу конструктором	
	//engClose(Eg); // закрываем matlab
	return *P;

}
