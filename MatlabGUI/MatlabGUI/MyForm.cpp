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
// Ручной ввод матриц
void MyForm::Mass_Creator(int row, int col,  DataGridView^ dataGridView)
{
	// Выделение памяти
	double **mas = new double *[row];
	for (int i = 0; i < row; ++i)
		mas[i] = new double[col];
	// Ввод данныхв ячейки таблицы
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			mas[i][j] = Convert::ToInt32(dataGridView->Rows[i]->Cells[j]->Value);
}
// Вывод матриц в таблицу
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
// Вывод пустой матрицы в таблицу
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
// Считывание из таблицы в двумерный массив. Данная функция нужна для вывода матриц
double**MyForm::ReadFromDGV(DataGridView^ dataGridView)
{
	// Выделение памяти
	double **mas = new double *[dataGridView->RowCount];
	for (int i = 0; i < dataGridView->RowCount; ++i)
		mas[i] = new double[dataGridView->ColumnCount];
	// Считывание
	for (int i = 0; i < dataGridView->RowCount; i++)
		for (int j = 0; j < dataGridView->ColumnCount; j++)
			//Преобразуем значения из ячеек в числа, и пишем в массив
			//Если не число то происходит вызов исключения и его обработка
			mas[i][j] = Convert::ToDouble(dataGridView->Rows[i]->Cells[j]->Value);
	return mas;
}
// Очистка таблиц (заполнение ячеек нулями)
void MyForm::Clear(DataGridView^ datagridview)
{
	for (int i = 0; i < datagridview->Rows->Count; i++)
		for (int j = 0; j < datagridview->Columns->Count; j++)
			datagridview->Rows[i]->Cells[j]->Value = 0;
}
// Считывание из файла в таблицу
System::Void MyForm::FillGridFromFile(DataGridView^ dg, String^ fileName)
{
	char file[255];
	sprintf(file, "%s", fileName);
	// исключение на открытие txt файла
	ifstream inarray(file);	// Открытие файла для ввода

	double nextValue;
	//Заполнение матрицы (считыванием из файла)
	for (int i = 0; i < dg->RowCount; ++i)
		for (int j = 0; j < dg->ColumnCount; ++j) 
		{
			// считывается каждый double 
			inarray >> nextValue;
			dg->Rows[i]->Cells[j]->Value = nextValue;
		}
	// Проработать исключение на количество
	inarray.close();
}
System::Void MyForm::OK_Click(System::Object^  sender, System::EventArgs^  e) {
	// Создается таблица для матрицы А
	dataGridView1->ColumnCount = Convert::ToInt32(numericUpDown2->Value);
	dataGridView1->RowCount = Convert::ToInt32(numericUpDown1->Value);
	// Создается таблица для матрицы В
	dataGridView2->ColumnCount = Convert::ToInt32(numericUpDown4->Value);
	dataGridView2->RowCount = Convert::ToInt32(numericUpDown3->Value);
	// Выравнивание ячеек
	dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	dataGridView1->AutoResizeColumns();
	dataGridView2->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	dataGridView2->AutoResizeColumns();
	try
	{
		// Ручной ввод таблиц
		Mass_Creator(Convert::ToInt32(numericUpDown1->Value), Convert::ToInt32(numericUpDown2->Value), dataGridView1);
		Mass_Creator(Convert::ToInt32(numericUpDown3->Value), Convert::ToInt32(numericUpDown4->Value), dataGridView2);
	}
	catch (FormatException ^e)
	{
		MessageBox::Show("\nОшибка! Вы уже ввели размер матрицы");
		return;
	}
	// Вывод матриц
	Show_Mass(Convert::ToInt32(numericUpDown1->Value), Convert::ToInt32(numericUpDown2->Value), dataGridView1);
	Show_Mass(Convert::ToInt32(numericUpDown3->Value), Convert::ToInt32(numericUpDown4->Value), dataGridView2);
}
System::Void MyForm::SummOfMatrix_Click(System::Object^  sender, System::EventArgs^  e) {			  
	try
	{
		// Считывание из таблицы в массив
		ReadFromDGV(dataGridView1);
		ReadFromDGV(dataGridView2);
	}
	//обработка пойманного исключения
	catch (FormatException^ e)
	{
		MessageBox::Show("\nИспользование букв и символов недопустимо!");
		return;
	}
	// Создание операнд
	Matrix A(Convert::ToInt32(numericUpDown1->Value), Convert::ToInt32(numericUpDown2->Value), ReadFromDGV(dataGridView1));
	Matrix B(Convert::ToInt32(numericUpDown3->Value), Convert::ToInt32(numericUpDown4->Value), ReadFromDGV(dataGridView2));
	try
	{
		// Складываем матрицы
		Matrix C = A + B;
		// Создаем таблицу для результата
		dataGridView3->ColumnCount = C.GetColumns();
		dataGridView3->RowCount = C.GetRows();
		// Выводим результат
		Show_Mass(C.GetRows(), C.GetColumns(), C.ReturnMass(), dataGridView3);
	}
	// обработка исключения
	catch (exception& e)
	{
		String^ error = gcnew String(e.what());
		MessageBox::Show(error);
	};
}
System::Void MyForm::MultiplicationOfMatrix_Click(System::Object^  sender, System::EventArgs^  e) {
	try
	{
		// Считывание из таблицы в массив
		ReadFromDGV(dataGridView1);
		ReadFromDGV(dataGridView2);
	}
	catch (FormatException^ e)//обработка пойманного исключения
	{
		MessageBox::Show("\nИспользование букв и символов недопустимо!");
		return;
	}
	// Создание операнд
	Matrix A(Convert::ToInt32(numericUpDown1->Value), Convert::ToInt32(numericUpDown2->Value), ReadFromDGV(dataGridView1));
	Matrix B(Convert::ToInt32(numericUpDown3->Value), Convert::ToInt32(numericUpDown4->Value), ReadFromDGV(dataGridView2));
	try
	{
		// Умножаем матрицы
		Matrix C = A * B;
		// Создаем таблицу под результат
		dataGridView3->ColumnCount = C.GetColumns();
		dataGridView3->RowCount = C.GetRows();
		// Выводим результат
		Show_Mass(C.GetRows(), C.GetColumns(), C.ReturnMass(), dataGridView3);
	}
	catch (exception& e)
	{
		String^ error = gcnew String(e.what());
		MessageBox::Show(error);
	};
}
System::Void MyForm::DeterminateFirstMatrix_Click(System::Object^  sender, System::EventArgs^  e) {
	// Считывание из DGV в двумерный массив
	try
	{
		// Считывание из таблицы в массив
		ReadFromDGV(dataGridView1);
	}
	catch (FormatException^ e)//обработка пойманного исключения
	{
		MessageBox::Show("\nИспользование букв и символов недопустимо!");
		return;
	}

	Matrix A(Convert::ToInt32(numericUpDown1->Value), Convert::ToInt32(numericUpDown2->Value), ReadFromDGV(dataGridView1));
	try
	{
		MessageBox::Show("Определитель матрицы = " + A.Det().ToString());
	}
	catch (exception& e)
	{
		String^ error = gcnew String(e.what());
		MessageBox::Show(error);
	};
}
System::Void MyForm::TransposeFirstMatrix_Click(System::Object^  sender, System::EventArgs^  e) {
	// Считывание из таблицы в двумерный массив
	try
	{
		ReadFromDGV(dataGridView1);
	}
	catch (FormatException^ e)//обработка пойманного исключения
	{
		MessageBox::Show("\nИспользование букв и символов недопустимо!");
		return;
	}
	// Создание матрицы
	Matrix A(Convert::ToInt32(numericUpDown1->Value), Convert::ToInt32(numericUpDown2->Value), ReadFromDGV(dataGridView1));
	// Создание таблиц
	dataGridView1->ColumnCount = A.GetRows();
	dataGridView1->RowCount = A.GetColumns();
	// Транспонирование
	A.Transport();
	// вывод матрицы
	Show_Mass(A.GetRows(), A.GetColumns(), A.ReturnMass(), dataGridView1);
}
System::Void MyForm::InverseFirstMatrix_Click(System::Object^  sender, System::EventArgs^  e) {
	// Считывание из DGV в двумерный массив
	try
	{
		ReadFromDGV(dataGridView1);
	}
	catch (FormatException^ e)//обработка пойманного исключения
	{
		MessageBox::Show("\nИспользование букв и символов недопустимо!");
		return;
	}
	// Создание матрицы
	Matrix A(Convert::ToInt32(numericUpDown1->Value), Convert::ToInt32(numericUpDown2->Value), ReadFromDGV(dataGridView1));
	// Обратная матрица 		
	try
	{
		A.InverseMatr();
	}
	catch (exception& e)
	{
		String^ error = gcnew String(e.what());
		MessageBox::Show(error);
	};
	// Вывод матрицы
	Show_Mass(dataGridView1->RowCount, dataGridView1->ColumnCount, A.ReturnMass(), dataGridView1);
}
System::Void MyForm::UnitFirstMatrix_Click(System::Object^  sender, System::EventArgs^  e) {
	// Размер таблиц
	dataGridView1->ColumnCount = Convert::ToInt32(numericUpDown2->Value);
	dataGridView1->RowCount = Convert::ToInt32(numericUpDown1->Value);
	// Проверка данных на входе
	if (dataGridView1->ColumnCount != dataGridView1->RowCount)
	{
		MessageBox::Show("\nЕдиничная матрица должна быть квадратной!");
		return;
	}
	Matrix A(dataGridView1->RowCount);
	// Вывод матрицы
	Show_Mass(dataGridView1->RowCount, dataGridView1->RowCount, A.ReturnMass(), dataGridView1);
}
System::Void MyForm::UnitSecondMatrix_Click(System::Object^  sender, System::EventArgs^  e) {
	// Размер таблиц
	dataGridView2->ColumnCount = Convert::ToInt32(numericUpDown4->Value);
	dataGridView2->RowCount = Convert::ToInt32(numericUpDown3->Value);
	// Проверка данных на входе
	if (dataGridView2->ColumnCount != dataGridView2->RowCount)
	{
		MessageBox::Show("\nЕдиничная матрица должна быть квадратной!");
		return;
	}
	Matrix A(dataGridView2->RowCount);
	// Вывод матрицы
	Show_Mass(dataGridView2->RowCount, dataGridView2->RowCount, A.ReturnMass(), dataGridView2);
}
System::Void MyForm::NullFirstMatrix_Click(System::Object^  sender, System::EventArgs^  e) {
	// Размер таблиц
	dataGridView1->ColumnCount = Convert::ToInt32(numericUpDown2->Value);
	dataGridView1->RowCount = Convert::ToInt32(numericUpDown1->Value);
	Matrix A(dataGridView1->RowCount, dataGridView1->ColumnCount);
	// Вывод матрицы
	Show_Mass(dataGridView1->RowCount, dataGridView1->ColumnCount, A.ReturnMass(), dataGridView1);
}
System::Void MyForm::NullSecondMatrix_Click(System::Object^  sender, System::EventArgs^  e) {
	// Размер таблиц
	dataGridView2->ColumnCount = Convert::ToInt32(numericUpDown4->Value);
	dataGridView2->RowCount = Convert::ToInt32(numericUpDown3->Value);
	Matrix A(dataGridView2->RowCount, dataGridView2->ColumnCount);
	// Вывод матрицы
	Show_Mass(dataGridView2->RowCount, dataGridView2->ColumnCount, A.ReturnMass(), dataGridView2);
}
System::Void MyForm::InputToFirstMatrix_Click(System::Object^  sender, System::EventArgs^  e) {
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		// считывание из файла
		FillGridFromFile(dataGridView1, openFileDialog1->FileName);
}
System::Void MyForm::InputToSecondMatrix_Click(System::Object^  sender, System::EventArgs^  e) {
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		// считвание из файла
		FillGridFromFile(dataGridView2, openFileDialog1->FileName);
}