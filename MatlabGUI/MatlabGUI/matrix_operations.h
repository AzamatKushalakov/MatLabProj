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
	void Transport(); // ���������������� �������
	void PrintMatr(); // ����� ������ � �������
	int Det(); // ������������ �������
	double** ReturnMass(Matrix); // ���������� ��������� ������, ����������� ���������� ������� Matrix

	Matrix  operator = (Matrix); // �������� ������������
	Matrix operator + (Matrix); // �������� ��������
	Matrix operator * (Matrix); // �������� ���������
};
