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
		return "������� ������ ���� ����������";
	}
} mins;

class matrix_is_not_invertible: public exception
{
	virtual const char* what() const throw()
	{
		return "������� �� ��������";
	}
} mini;

class incorrect_size: public exception
{
	virtual const char* what() const throw()
	{
		return "����� ������������ ������ ������ ��� ������ ��������";
	}
} ics;
class incorrect_input_value : public exception
{
	virtual const char* what() const throw()
	{
		return "������������ ����! ����������� ����� ��� �����.";
	}
} icus;