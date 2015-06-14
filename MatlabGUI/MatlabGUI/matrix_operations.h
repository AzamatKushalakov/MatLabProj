#pragma once
#include <iostream>

using namespace std;

class Matrix
{
private:
	mxArray *matr; // mxArray - структура представления массивов в Matlab
	int row; // число строк матрицы
	int col; // столбцов
public:
	Matrix(); // конструктор, создающий пустую матрицу
	Matrix(int, int); // конструктор, создающий нулевую матрицу переданных в параметры размеров
	Matrix(int); // конструктор, создающий единичную матрицу переданного в параметры размера
	Matrix(int, int, char*); // заполнение матрицы считыванием из файла
	Matrix(int, int, double**); // конструктор с параметрами, заполняющий матрицу элементами передаваемого двумерного массива
	Matrix(mxArray*); // конструктор с параметром
	Matrix(const Matrix& other); // оператор копирования
	~Matrix(); // деструктор

	// методы и операторы, выполняющие некоторые операции с матрицами
	int GetColumns();
	int GetRows();
	void Transport(); // транспонирование матрицы
	void InverseMatr(); // поиск обратной матрицы
	void PrintMatr(); // вывод матриц в консоль
	int Det(); // определитель матрицы
	double** ReturnMass(); // возвращает двумерный массив, заполненный элементами матрицы Matrix

	Matrix  operator = (Matrix); // оператор присваивания
	Matrix operator + (const Matrix&); // оператор сложения
	Matrix operator * (Matrix); // оператор умножения
};
