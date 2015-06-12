#include "MyForm.h"

using namespace MatlabGUI; //name of your project

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew MyForm());
	return 0;
}
void MyForm::Mass_Creator(int row, int col,  DataGridView^ dataGridView)
{
			double **mas = new double *[row];
			for (int i = 0; i < row; ++i)
				mas[i] = new double[col];
			 for (int i = 0; i < row; i++)
				 for (int j = 0; j < col; j++)
					 mas[i][j] = Convert::ToInt32(dataGridView->Rows[i]->Cells[j]->Value);
}
void MyForm::Show_Mass(int row, int col, double **mas, DataGridView^ dataGridView)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			// Название таблицы в верхнем левом углу
			dataGridView->TopLeftHeaderCell->Value = "Матрица";
			// Вывод номеров столбцов
			dataGridView->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
			// Вывод номеров строк
			dataGridView->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
			// Вывод значений
			dataGridView->Rows[i]->Cells[j]->Value = mas[i][j];
		}
}
void MyForm::Show_Mass(int row, int col, DataGridView^ dataGridView)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			// Название таблицы в верхнем левом углу
			dataGridView->TopLeftHeaderCell->Value = "Матрица";
			// Вывод номеров столбцов
			dataGridView->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
			// Вывод ныомеров строк
			dataGridView->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
		}
}
double**MyForm::ReadFromDGV(DataGridView^ dataGridView)
{
	double **mas = new double *[dataGridView->RowCount];
	for (int i = 0; i < dataGridView->RowCount; ++i)
		mas[i] = new double[dataGridView->ColumnCount];
	for (int i = 0; i < dataGridView->RowCount; i++)
	{
		for (int j = 0; j < dataGridView->ColumnCount; j++)
		{
			//Преобразуем значения из ячеек в числа, и пишем в массив
			//Если не число то происходит вызов исключения и его обработка
			mas[i][j] = Convert::ToDouble(dataGridView->Rows[i]->Cells[j]->Value);
		}
	}
	return mas;
}
void MyForm::Clear(DataGridView^ datagridview)
{
	for (int i = 0; i < datagridview->Rows->Count; i++){
		for (int j = 0; j < datagridview->Columns->Count; j++){
			datagridview->Rows[i]->Cells[j]->Value = 0;
		}
	}
}