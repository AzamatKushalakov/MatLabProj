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
	int number;

	cout << "Выберите операцию с матрицами (введите номер пункта)" << endl;
	cout << "1. '+' " << endl << "2. '*' " << endl << "3. 'Trans' " << endl << "4. 'Det' " << endl;

	cin >> number;

	if (number < 1 || number > 4)
	{
		cout << "Ошибка!!!! Вам необходимо ввести число от 1 до 4" << endl;
	}
	
	switch (number)
	{
	case 1:
		{
			// размеры матрицы А
			int row_a, col_a;
			cout << "Введите число строк и столбцов матрицы A:" << endl;
			cin >> row_a >> col_a;

			if (row_a < 1 || col_a < 1)
			{
				cout << "Ошибка!!!! Вам необходимо ввести положительные числа";
				return 1;
			}

			double **A = new double *[row_a];
			for (int i = 0; i < row_a; ++i)
				A[i] = new double[col_a];

			cout << "Введите матрицу A, последовательно заполняя каждую строку:" << endl;
			for (int i = 0; i < row_a; ++i)
			{
				for (int j = 0; j < col_a; ++j)
					cin >> A[i][j];
			}

			cout << "Введите число строк и столбцов матрицы B:" << endl;
			// размеры матрицы B
			int row_b, col_b;
			cin >> row_b >> col_b;
			
			if (row_b < 1 || col_b < 1)
			{
				cout << "Ошибка!!!! Вам необходимо ввести положительные числа";
				return 1;
			}
			
			double **B = new double *[row_b];
			for (int i = 0; i < row_b; ++i)
				B[i] = new double[col_b];
			
			cout << "Введите матрицу B, последовательно заполняя каждую строку:" << endl;
			for (int i = 0; i < row_b; ++i)
			{
				for (int j = 0; j < col_b; ++j)
					cin >> B[i][j];
			}
			
			cout << "Матрица A:" << endl;
			Print_Matrix(row_a, col_a, A);
			
			cout << "Матрица B:" << endl;
			Print_Matrix(row_b, col_b, B);
			
			// Сложение
			cout << "*****************A+B = " << endl;
			try
			{
				double **S = BinaryOperation(row_a, col_a, A, row_b, col_b, B, '+');
				Print_Matrix(row_a, col_a, S);
				cout << endl;
			}
			catch (exception e)
			{
				cout << e.what() << endl;
			}
		}
		break;
	case 2:
		{
			// размеры матрицы А
			int row_a, col_a;
			cout << "Введите число строк и столбцов матрицы A:" << endl;
			cin >> row_a >> col_a;

			if (row_a < 1 || col_a < 1)
			{
				cout << "Ошибка!!!! Вам необходимо ввести положительные числа";
				return 1;
			}

			double **A = new double *[row_a];
			for (int i = 0; i < row_a; ++i)
				A[i] = new double[col_a];
			
			cout << "Введите матрицу A, последовательно заполняя каждую строку:" << endl;
			for (int i = 0; i < row_a; ++i)
			{
				for (int j = 0; j < col_a; ++j)
					cin >> A[i][j];
			}

			cout << "Введите число строк и столбцов матрицы B:" << endl;
			// размеры матрицы B
			int row_b, col_b;
			cin >> row_b >> col_b;
			
			if (row_b < 1 || col_b < 1)
			{
				cout << "Ошибка!!!! Вам необходимо ввести положительные числа";
				return 1;
			}
			
			double **B = new double *[row_b];
			for (int i = 0; i < row_b; ++i)
				B[i] = new double[col_b];
			
			cout << "Введите матрицу B, последовательно заполняя каждую строку:" << endl;
			for (int i = 0; i < row_b; ++i)
			{
				for (int j = 0; j < col_b; ++j)
					cin >> B[i][j];
			}
			
			cout << "Матрица A:" << endl;
			Print_Matrix(row_a, col_a, A);
			
			cout << "Матрица B:" << endl;
			Print_Matrix(row_b, col_b, B);
			
			// Умножение
			cout << "*****************A*B = " << endl;
			try
			{
				double **P = BinaryOperation(row_a, col_a, A, row_b, col_b, B, '*');
				Print_Matrix(row_a, col_b, P);
				cout << endl;
			}
			catch (exception e)
			{
				cout << e.what() << endl;
			}
		}
		break;
	case 3:
		{
			// размеры матрицы А
			int row_a, col_a;
			cout << "Введите число строк и столбцов матрицы A:" << endl;
			cin >> row_a >> col_a;

			if (row_a < 1 || col_a < 1)
			{
				cout << "Ошибка!!!! Вам необходимо ввести положительные числа";
				return 1;
			}

			double **A = new double *[row_a];
			for (int i = 0; i < row_a; ++i)
				A[i] = new double[col_a];
			
			cout << "Введите матрицу A, последовательно заполняя каждую строку:" << endl;
			for (int i = 0; i < row_a; ++i)
			{
				for (int j = 0; j < col_a; ++j)
					cin >> A[i][j];
			}
			
			// Транспонирование матрицы А
			double **T = Transpose(row_a, col_a, A);
			cout << "*****************Transpose(A) =  " << endl;
			Print_Matrix(col_a, row_a, T);
			cout << endl;
		}
		break;
	case 4:
		{
			cout << "Введите число строк и столбцов матрицы B:" << endl;
			// размеры матрицы B
			int row_b, col_b;
			cin >> row_b >> col_b;
			if (row_b < 1 || col_b < 1)
			{
				cout << "Ошибка!!!! Вам необходимо ввести положительные числа";
				return 1;
			}
			double **B = new double *[row_b];
			for (int i = 0; i < row_b; ++i)
				B[i] = new double[col_b];
			cout << "Введите матрицу B, последовательно заполняя каждую строку:" << endl;
			for (int i = 0; i < row_b; ++i)
			{
				for (int j = 0; j < col_b; ++j)
					cin >> B[i][j];
			}
			// Определитель матрицы B

			cout << "*****************Det(B) = ";
			try
			{
				double det = Det(row_b, col_b, B);
				cout << det << endl;
			}
			catch (exception e)
			{
				cout << e.what() << endl;
			}	  
		}
		break;
	}
	system("pause");
	return 0;
}