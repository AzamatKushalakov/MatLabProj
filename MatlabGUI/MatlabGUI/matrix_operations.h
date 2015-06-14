#pragma once
#include <iostream>

using namespace std;

class Matrix
{
private:
	mxArray *matr; // mxArray - ��������� ������������� �������� � Matlab
	int row; // ����� ����� �������
	int col; // ��������
public:
	Matrix(); // �����������, ��������� ������ �������
	Matrix(int, int); // �����������, ��������� ������� ������� ���������� � ��������� ��������
	Matrix(int); // �����������, ��������� ��������� ������� ����������� � ��������� �������
	Matrix(int, int, char*); // ���������� ������� ����������� �� �����
	Matrix(int, int, double**); // ����������� � �����������, ����������� ������� ���������� ������������� ���������� �������
	Matrix(mxArray*); // ����������� � ����������
	Matrix(const Matrix& other); // �������� �����������
	~Matrix(); // ����������

	// ������ � ���������, ����������� ��������� �������� � ���������
	int GetColumns();
	int GetRows();
	void Transport(); // ���������������� �������
	void InverseMatr(); // ����� �������� �������
	void PrintMatr(); // ����� ������ � �������
	int Det(); // ������������ �������
	double** ReturnMass(); // ���������� ��������� ������, ����������� ���������� ������� Matrix

	Matrix  operator = (Matrix); // �������� ������������
	Matrix operator + (const Matrix&); // �������� ��������
	Matrix operator * (Matrix); // �������� ���������
};
