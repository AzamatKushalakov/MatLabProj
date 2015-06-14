#pragma once
#include <exception>

//using std::exception;

class file_error: public exception
{

}fe;

class matrix_is_not_square: public exception
{
	virtual const char* what() const throw()
	{
		return "Матрица должна быть квадратной";
	}
} mins;

class matrix_is_not_invertible: public exception
{
	virtual const char* what() const throw()
	{
		return "Матрица не обратима";
	}
} mini;

class incorrect_size: public exception
{
	virtual const char* what() const throw()
	{
		return "Задан некорректный размер матриц для данной операции";
	}
} ics;
class incorrect_input_value : public exception
{
	virtual const char* what() const throw()
	{
		return "Некорректный ввод! Используйте числа для ввода.";
	}
} icus;