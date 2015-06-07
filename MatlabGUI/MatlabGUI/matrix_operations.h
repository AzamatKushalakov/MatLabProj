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
	~Matrix(); // ����������

	// ������ � ���������, ����������� ��������� �������� � ���������
	int GetColumns();
	int GetRows();
	void Transport(); // ���������������� �������
	void PrintMatr(); // ����� ������ � �������
	int Det(); // ������������ �������
	double** ReturnMass(); // ���������� ��������� ������, ����������� ���������� ������� Matrix

	Matrix  operator = (Matrix); // �������� ������������
	Matrix operator + (Matrix); // �������� ��������
	Matrix operator * (Matrix); // �������� ���������
};
