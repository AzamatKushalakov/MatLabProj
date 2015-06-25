#pragma once
#include <exception>
#include <stdexcept>

// ���������� �� �������� ����
class file_error : public exception
{
public:
	file_error(const string m = "������ � ������ �� �����") :msg(m){}
	~file_error(){}
	const char* what(){ return msg.c_str(); }
private:
	string msg;
};

// ���������� �������������� ������ ������������ �������
class matrix_is_not_square :public exception{
public:
	matrix_is_not_square(const string m = "������� ������ ���� ����������") :msg(m){}
	~matrix_is_not_square(){}
	const char* what(){ return msg.c_str(); }
private:
	string msg;
};

// ���������� ������������� � ������ ������������� �������
class matrix_is_not_invertible : public exception
{
public:
	matrix_is_not_invertible(const string m = "������� ����������") :msg(m){}
	~matrix_is_not_invertible(){}
	const char* what(){ return msg.c_str(); }
private:
	string msg;
};

// ���������� �������������, ���� �������, ��������� � ����� �� ��������� ��������� ��������� ���������
class incorrect_size : public exception
{
public:
	incorrect_size(const string m = "������������ ������� ��� ������ ��������") :msg(m){}
	~incorrect_size(){}
	const char* what(){ return msg.c_str(); }
private:
	string msg;
};