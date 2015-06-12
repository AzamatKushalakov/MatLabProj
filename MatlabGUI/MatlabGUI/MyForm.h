#pragma once
#include "engine.h"
#include "matrix_operations.h"
#include <stdexcept>

namespace MatlabGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RadioButton^  radioButton1;
	protected:

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown3;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown4;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridView^  dataGridView2;
	private: System::Windows::Forms::DataGridView^  dataGridView3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  очисткаТаблицToolStripMenuItem;


	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->очисткаТаблицToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(27, 23);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(94, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Ввод вручную";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(299, 43);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(58, 32);
			this->button1->TabIndex = 2;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(157, 43);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 20);
			this->numericUpDown1->TabIndex = 3;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(157, 62);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(120, 20);
			this->numericUpDown2->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(24, 43);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(109, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Число строк матр А";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(24, 62);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(127, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Число столбцов матр А";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(372, 43);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(109, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Число строк матр В";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(372, 62);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(127, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Число столбцов матр В";
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(513, 43);
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(120, 20);
			this->numericUpDown3->TabIndex = 9;
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->Location = System::Drawing::Point(513, 62);
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(120, 20);
			this->numericUpDown4->TabIndex = 10;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(54, 101);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(192, 137);
			this->dataGridView1->TabIndex = 11;
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(418, 101);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(192, 137);
			this->dataGridView2->TabIndex = 12;
			// 
			// dataGridView3
			// 
			this->dataGridView3->AllowUserToAddRows = false;
			this->dataGridView3->AllowUserToDeleteRows = false;
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Location = System::Drawing::Point(237, 260);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->ReadOnly = true;
			this->dataGridView3->Size = System::Drawing::Size(192, 137);
			this->dataGridView3->TabIndex = 13;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(299, 101);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 27);
			this->button2->TabIndex = 14;
			this->button2->Text = L"+";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(299, 134);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 15;
			this->button3->Text = L"*";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(299, 164);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 16;
			this->button4->Text = L"Определитель";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(299, 193);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 17;
			this->button5->Text = L"Транспонирование";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(299, 222);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 18;
			this->button6->Text = L"Обратная";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->очисткаТаблицToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(674, 24);
			this->menuStrip1->TabIndex = 19;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// очисткаТаблицToolStripMenuItem
			// 
			this->очисткаТаблицToolStripMenuItem->Name = L"очисткаТаблицToolStripMenuItem";
			this->очисткаТаблицToolStripMenuItem->Size = System::Drawing::Size(107, 20);
			this->очисткаТаблицToolStripMenuItem->Text = L"Очистка таблиц";
			this->очисткаТаблицToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::очисткаТаблицToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(674, 422);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView3);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->numericUpDown4);
			this->Controls->Add(this->numericUpDown3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MatrixCalculator";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// Заполнение элементов в таблицу вручную
	private: void Mass_Creator(int row, int col, DataGridView^ dataGridView);
		  // Вывод матрицы
	private: void Show_Mass(int row, int col, double **mas, DataGridView^ dataGridView);
			// Вывод матрицы
	private: void Show_Mass(int row, int col, DataGridView^ dataGridView);
		// Считывание из таблицы в массив (поправить исключения)
	private: double** ReadFromDGV(DataGridView^ dataGridView);
		// очистка таблицы
	private: void Clear(DataGridView^ datagridview);
			 // ОК - кнопка
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
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
		if (radioButton1->Checked)
		{
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
					 
		}
		// Вывод матриц
		Show_Mass(Convert::ToInt32(numericUpDown1->Value), Convert::ToInt32(numericUpDown2->Value), dataGridView1);
		Show_Mass(Convert::ToInt32(numericUpDown3->Value), Convert::ToInt32(numericUpDown4->Value), dataGridView2);
	}
				 // +
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		// Выделение памяти				  
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
			Matrix C = A + B;
			dataGridView3->ColumnCount = C.GetColumns();
			dataGridView3->RowCount = C.GetRows();
			Show_Mass(C.GetRows(), C.GetColumns(), C.ReturnMass(), dataGridView3);
		}
		catch (runtime_error e)
		{
			String^ error = gcnew String(e.what());
			MessageBox::Show(error);
			return;
		};
	}
		// *
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		// Выделение памяти				  
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
			Matrix C = A * B;
			dataGridView3->ColumnCount = C.GetColumns();
			dataGridView3->RowCount = C.GetRows();
			Show_Mass(C.GetRows(), C.GetColumns(), C.ReturnMass(), dataGridView3);
		}
		catch (runtime_error e)
		{
			String^ error = gcnew String(e.what());
			MessageBox::Show(error);
			return;
		};
	}
		// определитель
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
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
		catch (runtime_error e)
		{
		String^ error = gcnew String(e.what());
		MessageBox::Show(error);
		};
	}
			 // Транспонирование
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		
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
		dataGridView3->ColumnCount = A.GetRows();
		dataGridView3->RowCount = A.GetColumns();
		// Транспонирование
		A.Transport();
		Show_Mass(dataGridView3->RowCount, dataGridView3->ColumnCount, A.ReturnMass(), dataGridView3);
	}
		// При выборе способа вручную, предыдущие таблицы очищаются
	private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		Clear(dataGridView1);
		Clear(dataGridView2);
		Clear(dataGridView3);
	}
		// Очистить таблицы
	private: System::Void очисткаТаблицToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Clear(dataGridView1);
		Clear(dataGridView2);
		Clear(dataGridView3);
	}
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
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
		catch (runtime_error e)
		{
			String^ error = gcnew String(e.what());
			MessageBox::Show(error);
			return;
		};
		// Создание таблицы
		dataGridView3->ColumnCount = A.GetRows();
		dataGridView3->RowCount = A.GetColumns();
		// Вывод матрицы
		Show_Mass(dataGridView3->RowCount, dataGridView3->ColumnCount, A.ReturnMass(), dataGridView3);
	}
  private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
  }
};
}
