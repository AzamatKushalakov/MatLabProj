#pragma once
#include <exception>
#include <stdexcept>

// Исключение на файловый ввод
class file_error : public exception
{
public:
	file_error(const string m = "Ошибка в чтении из файла") :msg(m){}
	~file_error(){}
	const char* what(){ return msg.c_str(); }
private:
	string msg;
};

// Исключение выбрасываетсяв случае неквадратной матрицы
class matrix_is_not_square :public exception{
public:
	matrix_is_not_square(const string m = "Матрица должна быть квадратной") :msg(m){}
	~matrix_is_not_square(){}
	const char* what(){ return msg.c_str(); }
private:
	string msg;
};

// Исключение выбрасывается в случае необратимости матрицы
class matrix_is_not_invertible : public exception
{
public:
	matrix_is_not_invertible(const string m = "Матрица необратима") :msg(m){}
	~matrix_is_not_invertible(){}
	const char* what(){ return msg.c_str(); }
private:
	string msg;
};

// Исключение выбрасывается, если размеры, введенные в форме не позволяют корректно вычислить результат
class incorrect_size : public exception
{
public:
	incorrect_size(const string m = "Некорректные размеры для данной операции") :msg(m){}
	~incorrect_size(){}
	const char* what(){ return msg.c_str(); }
private:
	string msg;
};