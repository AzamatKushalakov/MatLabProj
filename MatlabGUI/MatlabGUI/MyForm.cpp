#include "MyForm.h"


using namespace MatlabGUI; //name of project

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew MyForm());
	return 0;
}
// ������ ���� ������
void MyForm::Mass_Creator(int row, int col,  DataGridView^ dataGridView)
{
	// ��������� ������
	double **mas = new double *[row];
	for (int i = 0; i < row; ++i)
		mas[i] = new double[col];
	// ���� ������� ������ �������
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			mas[i][j] = Convert::ToInt32(dataGridView->Rows[i]->Cells[j]->Value);
}
// ����� ������ � �������
void MyForm::Show_Mass(int row, int col, double **mas, DataGridView^ dataGridView)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			// �������� ������� � ������� ����� ����
			dataGridView->TopLeftHeaderCell->Value = "�������";
			// ����� ������� ��������
			dataGridView->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
			// ����� ������� �����
			dataGridView->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
			// ����� ��������
			dataGridView->Rows[i]->Cells[j]->Value = mas[i][j];
		}
}
// ����� ������ ������� � �������
void MyForm::Show_Mass(int row, int col, DataGridView^ dataGridView)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			// �������� ������� � ������� ����� ����
			dataGridView->TopLeftHeaderCell->Value = "�������";
			// ����� ������� ��������
			dataGridView->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
			// ����� �������� �����
			dataGridView->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
		}
}
// ���������� �� ������� � ��������� ������. ������ ������� ����� ��� ������ ������
double**MyForm::ReadFromDGV(DataGridView^ dataGridView)
{
	// ��������� ������
	double **mas = new double *[dataGridView->RowCount];
	for (int i = 0; i < dataGridView->RowCount; ++i)
		mas[i] = new double[dataGridView->ColumnCount];
	// ����������
	for (int i = 0; i < dataGridView->RowCount; i++)
		for (int j = 0; j < dataGridView->ColumnCount; j++)
			//����������� �������� �� ����� � �����, � ����� � ������
			//���� �� ����� �� ���������� ����� ���������� � ��� ���������
			mas[i][j] = Convert::ToDouble(dataGridView->Rows[i]->Cells[j]->Value);
	return mas;
}
// ������� ������ (���������� ����� ������)
void MyForm::Clear(DataGridView^ datagridview)
{
	for (int i = 0; i < datagridview->Rows->Count; i++)
		for (int j = 0; j < datagridview->Columns->Count; j++)
			datagridview->Rows[i]->Cells[j]->Value = 0;
}
// ���������� �� ����� � �������
System::Void MyForm::FillGridFromFile(DataGridView^ dg, String^ fileName)
{
	char file[255];
	sprintf(file, "%s", fileName);
	// ���������� �� �������� txt �����
	ifstream inarray(file);	// �������� ����� ��� �����

	double nextValue;
	//���������� ������� (����������� �� �����)
	for (int i = 0; i < dg->RowCount; ++i)
		for (int j = 0; j < dg->ColumnCount; ++j) 
		{
			// ����������� ������ double 
			inarray >> nextValue;
			dg->Rows[i]->Cells[j]->Value = nextValue;
		}
	// ����������� ���������� �� ����������
	inarray.close();
}
System::Void MyForm::OK_Click(System::Object^  sender, System::EventArgs^  e) {
	// ��������� ������� ��� ������� �
	dataGridView1->ColumnCount = Convert::ToInt32(numericUpDown2->Value);
	dataGridView1->RowCount = Convert::ToInt32(numericUpDown1->Value);
	// ��������� ������� ��� ������� �
	dataGridView2->ColumnCount = Convert::ToInt32(numericUpDown4->Value);
	dataGridView2->RowCount = Convert::ToInt32(numericUpDown3->Value);
	// ������������ �����
	dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	dataGridView1->AutoResizeColumns();
	dataGridView2->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	dataGridView2->AutoResizeColumns();
	try
	{
		// ������ ���� ������
		Mass_Creator(Convert::ToInt32(numericUpDown1->Value), Convert::ToInt32(numericUpDown2->Value), dataGridView1);
		Mass_Creator(Convert::ToInt32(numericUpDown3->Value), Convert::ToInt32(numericUpDown4->Value), dataGridView2);
	}
	catch (FormatException ^e)
	{
		MessageBox::Show("\n������! �� ��� ����� ������ �������");
		return;
	}
	// ����� ������
	Show_Mass(Convert::ToInt32(numericUpDown1->Value), Convert::ToInt32(numericUpDown2->Value), dataGridView1);
	Show_Mass(Convert::ToInt32(numericUpDown3->Value), Convert::ToInt32(numericUpDown4->Value), dataGridView2);
}
System::Void MyForm::SummOfMatrix_Click(System::Object^  sender, System::EventArgs^  e) {			  
	try
	{
		// ���������� �� ������� � ������
		ReadFromDGV(dataGridView1);
		ReadFromDGV(dataGridView2);
	}
	//��������� ���������� ����������
	catch (FormatException^ e)
	{
		MessageBox::Show("\n������������� ���� � �������� �����������!");
		return;
	}
	// �������� �������
	Matrix A(Convert::ToInt32(numericUpDown1->Value), Convert::ToInt32(numericUpDown2->Value), ReadFromDGV(dataGridView1));
	Matrix B(Convert::ToInt32(numericUpDown3->Value), Convert::ToInt32(numericUpDown4->Value), ReadFromDGV(dataGridView2));
	try
	{
		// ���������� �������
		Matrix C = A + B;
		// ������� ������� ��� ����������
		dataGridView3->ColumnCount = C.GetColumns();
		dataGridView3->RowCount = C.GetRows();
		// ������� ���������
		Show_Mass(C.GetRows(), C.GetColumns(), C.ReturnMass(), dataGridView3);
	}
	// ��������� ����������
	catch (exception& e)
	{
		String^ error = gcnew String(e.what());
		MessageBox::Show(error);
	};
}
System::Void MyForm::MultiplicationOfMatrix_Click(System::Object^  sender, System::EventArgs^  e) {
	try
	{
		// ���������� �� ������� � ������
		ReadFromDGV(dataGridView1);
		ReadFromDGV(dataGridView2);
	}
	catch (FormatException^ e)//��������� ���������� ����������
	{
		MessageBox::Show("\n������������� ���� � �������� �����������!");
		return;
	}
	// �������� �������
	Matrix A(Convert::ToInt32(numericUpDown1->Value), Convert::ToInt32(numericUpDown2->Value), ReadFromDGV(dataGridView1));
	Matrix B(Convert::ToInt32(numericUpDown3->Value), Convert::ToInt32(numericUpDown4->Value), ReadFromDGV(dataGridView2));
	try
	{
		// �������� �������
		Matrix C = A * B;
		// ������� ������� ��� ���������
		dataGridView3->ColumnCount = C.GetColumns();
		dataGridView3->RowCount = C.GetRows();
		// ������� ���������
		Show_Mass(C.GetRows(), C.GetColumns(), C.ReturnMass(), dataGridView3);
	}
	catch (exception& e)
	{
		String^ error = gcnew String(e.what());
		MessageBox::Show(error);
	};
}
System::Void MyForm::DeterminateFirstMatrix_Click(System::Object^  sender, System::EventArgs^  e) {
	// ���������� �� DGV � ��������� ������
	try
	{
		// ���������� �� ������� � ������
		ReadFromDGV(dataGridView1);
	}
	catch (FormatException^ e)//��������� ���������� ����������
	{
		MessageBox::Show("\n������������� ���� � �������� �����������!");
		return;
	}

	Matrix A(Convert::ToInt32(numericUpDown1->Value), Convert::ToInt32(numericUpDown2->Value), ReadFromDGV(dataGridView1));
	try
	{
		MessageBox::Show("������������ ������� = " + A.Det().ToString());
	}
	catch (exception& e)
	{
		String^ error = gcnew String(e.what());
		MessageBox::Show(error);
	};
}
System::Void MyForm::TransposeFirstMatrix_Click(System::Object^  sender, System::EventArgs^  e) {
	// ���������� �� ������� � ��������� ������
	try
	{
		ReadFromDGV(dataGridView1);
	}
	catch (FormatException^ e)//��������� ���������� ����������
	{
		MessageBox::Show("\n������������� ���� � �������� �����������!");
		return;
	}
	// �������� �������
	Matrix A(Convert::ToInt32(numericUpDown1->Value), Convert::ToInt32(numericUpDown2->Value), ReadFromDGV(dataGridView1));
	// �������� ������
	dataGridView1->ColumnCount = A.GetRows();
	dataGridView1->RowCount = A.GetColumns();
	// ����������������
	A.Transport();
	// ����� �������
	Show_Mass(A.GetRows(), A.GetColumns(), A.ReturnMass(), dataGridView1);
}
System::Void MyForm::InverseFirstMatrix_Click(System::Object^  sender, System::EventArgs^  e) {
	// ���������� �� DGV � ��������� ������
	try
	{
		ReadFromDGV(dataGridView1);
	}
	catch (FormatException^ e)//��������� ���������� ����������
	{
		MessageBox::Show("\n������������� ���� � �������� �����������!");
		return;
	}
	// �������� �������
	Matrix A(Convert::ToInt32(numericUpDown1->Value), Convert::ToInt32(numericUpDown2->Value), ReadFromDGV(dataGridView1));
	// �������� ������� 		
	try
	{
		A.InverseMatr();
	}
	catch (exception& e)
	{
		String^ error = gcnew String(e.what());
		MessageBox::Show(error);
	};
	// ����� �������
	Show_Mass(dataGridView1->RowCount, dataGridView1->ColumnCount, A.ReturnMass(), dataGridView1);
}
System::Void MyForm::UnitFirstMatrix_Click(System::Object^  sender, System::EventArgs^  e) {
	// ������ ������
	dataGridView1->ColumnCount = Convert::ToInt32(numericUpDown2->Value);
	dataGridView1->RowCount = Convert::ToInt32(numericUpDown1->Value);
	// �������� ������ �� �����
	if (dataGridView1->ColumnCount != dataGridView1->RowCount)
	{
		MessageBox::Show("\n��������� ������� ������ ���� ����������!");
		return;
	}
	Matrix A(dataGridView1->RowCount);
	// ����� �������
	Show_Mass(dataGridView1->RowCount, dataGridView1->RowCount, A.ReturnMass(), dataGridView1);
}
System::Void MyForm::UnitSecondMatrix_Click(System::Object^  sender, System::EventArgs^  e) {
	// ������ ������
	dataGridView2->ColumnCount = Convert::ToInt32(numericUpDown4->Value);
	dataGridView2->RowCount = Convert::ToInt32(numericUpDown3->Value);
	// �������� ������ �� �����
	if (dataGridView2->ColumnCount != dataGridView2->RowCount)
	{
		MessageBox::Show("\n��������� ������� ������ ���� ����������!");
		return;
	}
	Matrix A(dataGridView2->RowCount);
	// ����� �������
	Show_Mass(dataGridView2->RowCount, dataGridView2->RowCount, A.ReturnMass(), dataGridView2);
}
System::Void MyForm::NullFirstMatrix_Click(System::Object^  sender, System::EventArgs^  e) {
	// ������ ������
	dataGridView1->ColumnCount = Convert::ToInt32(numericUpDown2->Value);
	dataGridView1->RowCount = Convert::ToInt32(numericUpDown1->Value);
	Matrix A(dataGridView1->RowCount, dataGridView1->ColumnCount);
	// ����� �������
	Show_Mass(dataGridView1->RowCount, dataGridView1->ColumnCount, A.ReturnMass(), dataGridView1);
}
System::Void MyForm::NullSecondMatrix_Click(System::Object^  sender, System::EventArgs^  e) {
	// ������ ������
	dataGridView2->ColumnCount = Convert::ToInt32(numericUpDown4->Value);
	dataGridView2->RowCount = Convert::ToInt32(numericUpDown3->Value);
	Matrix A(dataGridView2->RowCount, dataGridView2->ColumnCount);
	// ����� �������
	Show_Mass(dataGridView2->RowCount, dataGridView2->ColumnCount, A.ReturnMass(), dataGridView2);
}
System::Void MyForm::InputToFirstMatrix_Click(System::Object^  sender, System::EventArgs^  e) {
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		// ���������� �� �����
		FillGridFromFile(dataGridView1, openFileDialog1->FileName);
}
System::Void MyForm::InputToSecondMatrix_Click(System::Object^  sender, System::EventArgs^  e) {
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		// ��������� �� �����
		FillGridFromFile(dataGridView2, openFileDialog1->FileName);
}