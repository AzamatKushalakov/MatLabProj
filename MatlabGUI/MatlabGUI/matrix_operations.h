#pragma once
#include <iostream>


using namespace std;

class Matrix
{
private:
	// mxArray - ��������� ������������� �������� � Matlab
	mxArray *matr;
	int row; // ����� ����� �������
	int col; // ��������
public:
	Matrix(); // �����������, ��������� ������ �������
	Matrix(int, int, double**); // ����������� � �����������, ����������� ������� ���������� ������������� ���������� �������
	Matrix(mxArray*); // ����������� � ����������
	Matrix(const Matrix& other); // ����������� � ����������
	~Matrix(); // ����������
	Matrix(int, int); // ��������� �������

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
