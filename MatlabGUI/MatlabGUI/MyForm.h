#pragma once
#include "engine.h"
#include "matrix_operations.h"
#include <stdexcept>
#include <fstream>
//#include "Matrix_exceptions.h"

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

	protected:

	private: System::Windows::Forms::Button^  OK;
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
	private: System::Windows::Forms::Button^  SummOfMatrix;
	private: System::Windows::Forms::Button^  MultiplicationOfMatrix;
	private: System::Windows::Forms::Button^  DeterminateFirstMatrix;
	private: System::Windows::Forms::Button^  TransposeFirstMatrix;
	private: System::Windows::Forms::Button^  InverseFirstMatrix;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  очисткаТаблицToolStripMenuItem;





	private: System::Windows::Forms::Button^  UnitFirstMatrix;
	private: System::Windows::Forms::Button^  NullFirstMatrix;
	private: System::Windows::Forms::Button^  UnitSecondMatrix;
	private: System::Windows::Forms::Button^  NullSecondMatrix;
	private: System::Windows::Forms::Button^  InputToFirstMatrix;
	private: System::Windows::Forms::Button^  InputToSecondMatrix;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;


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
			this->OK = (gcnew System::Windows::Forms::Button());
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
			this->SummOfMatrix = (gcnew System::Windows::Forms::Button());
			this->MultiplicationOfMatrix = (gcnew System::Windows::Forms::Button());
			this->DeterminateFirstMatrix = (gcnew System::Windows::Forms::Button());
			this->TransposeFirstMatrix = (gcnew System::Windows::Forms::Button());
			this->InverseFirstMatrix = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->очисткаТаблицToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->UnitFirstMatrix = (gcnew System::Windows::Forms::Button());
			this->NullFirstMatrix = (gcnew System::Windows::Forms::Button());
			this->UnitSecondMatrix = (gcnew System::Windows::Forms::Button());
			this->NullSecondMatrix = (gcnew System::Windows::Forms::Button());
			this->InputToFirstMatrix = (gcnew System::Windows::Forms::Button());
			this->InputToSecondMatrix = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
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
			// OK
			// 
			this->OK->Location = System::Drawing::Point(363, 43);
			this->OK->Name = L"OK";
			this->OK->Size = System::Drawing::Size(111, 39);
			this->OK->TabIndex = 2;
			this->OK->Text = L"OK";
			this->OK->UseVisualStyleBackColor = true;
			this->OK->Click += gcnew System::EventHandler(this, &MyForm::OK_Click);
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
			this->label3->Location = System::Drawing::Point(524, 43);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(109, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Число строк матр В";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(506, 64);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(127, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Число столбцов матр В";
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(639, 43);
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(120, 20);
			this->numericUpDown3->TabIndex = 9;
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->Location = System::Drawing::Point(639, 60);
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(120, 20);
			this->numericUpDown4->TabIndex = 10;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(108, 122);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(192, 137);
			this->dataGridView1->TabIndex = 11;
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(549, 122);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(192, 137);
			this->dataGridView2->TabIndex = 12;
			// 
			// dataGridView3
			// 
			this->dataGridView3->AllowUserToAddRows = false;
			this->dataGridView3->AllowUserToDeleteRows = false;
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Location = System::Drawing::Point(334, 287);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->ReadOnly = true;
			this->dataGridView3->Size = System::Drawing::Size(192, 137);
			this->dataGridView3->TabIndex = 13;
			// 
			// SummOfMatrix
			// 
			this->SummOfMatrix->Location = System::Drawing::Point(382, 122);
			this->SummOfMatrix->Name = L"SummOfMatrix";
			this->SummOfMatrix->Size = System::Drawing::Size(75, 52);
			this->SummOfMatrix->TabIndex = 14;
			this->SummOfMatrix->Text = L"+";
			this->SummOfMatrix->UseVisualStyleBackColor = true;
			this->SummOfMatrix->Click += gcnew System::EventHandler(this, &MyForm::SummOfMatrix_Click);
			// 
			// MultiplicationOfMatrix
			// 
			this->MultiplicationOfMatrix->Location = System::Drawing::Point(382, 207);
			this->MultiplicationOfMatrix->Name = L"MultiplicationOfMatrix";
			this->MultiplicationOfMatrix->Size = System::Drawing::Size(75, 52);
			this->MultiplicationOfMatrix->TabIndex = 15;
			this->MultiplicationOfMatrix->Text = L"*";
			this->MultiplicationOfMatrix->UseVisualStyleBackColor = true;
			this->MultiplicationOfMatrix->Click += gcnew System::EventHandler(this, &MyForm::MultiplicationOfMatrix_Click);
			// 
			// DeterminateFirstMatrix
			// 
			this->DeterminateFirstMatrix->Location = System::Drawing::Point(12, 178);
			this->DeterminateFirstMatrix->Name = L"DeterminateFirstMatrix";
			this->DeterminateFirstMatrix->Size = System::Drawing::Size(90, 23);
			this->DeterminateFirstMatrix->TabIndex = 16;
			this->DeterminateFirstMatrix->Text = L"Определитель";
			this->DeterminateFirstMatrix->UseVisualStyleBackColor = true;
			this->DeterminateFirstMatrix->Click += gcnew System::EventHandler(this, &MyForm::DeterminateFirstMatrix_Click);
			// 
			// TransposeFirstMatrix
			// 
			this->TransposeFirstMatrix->Location = System::Drawing::Point(12, 207);
			this->TransposeFirstMatrix->Name = L"TransposeFirstMatrix";
			this->TransposeFirstMatrix->Size = System::Drawing::Size(90, 23);
			this->TransposeFirstMatrix->TabIndex = 17;
			this->TransposeFirstMatrix->Text = L"Транспонирование";
			this->TransposeFirstMatrix->UseVisualStyleBackColor = true;
			this->TransposeFirstMatrix->Click += gcnew System::EventHandler(this, &MyForm::TransposeFirstMatrix_Click);
			// 
			// InverseFirstMatrix
			// 
			this->InverseFirstMatrix->Location = System::Drawing::Point(12, 236);
			this->InverseFirstMatrix->Name = L"InverseFirstMatrix";
			this->InverseFirstMatrix->Size = System::Drawing::Size(90, 23);
			this->InverseFirstMatrix->TabIndex = 18;
			this->InverseFirstMatrix->Text = L"Обратная";
			this->InverseFirstMatrix->UseVisualStyleBackColor = true;
			this->InverseFirstMatrix->Click += gcnew System::EventHandler(this, &MyForm::InverseFirstMatrix_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->очисткаТаблицToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(848, 24);
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
			// UnitFirstMatrix
			// 
			this->UnitFirstMatrix->Location = System::Drawing::Point(12, 122);
			this->UnitFirstMatrix->Name = L"UnitFirstMatrix";
			this->UnitFirstMatrix->Size = System::Drawing::Size(90, 23);
			this->UnitFirstMatrix->TabIndex = 25;
			this->UnitFirstMatrix->Text = L"Единичная матрица";
			this->UnitFirstMatrix->UseVisualStyleBackColor = true;
			this->UnitFirstMatrix->Click += gcnew System::EventHandler(this, &MyForm::UnitFirstMatrix_Click);
			// 
			// NullFirstMatrix
			// 
			this->NullFirstMatrix->Location = System::Drawing::Point(12, 149);
			this->NullFirstMatrix->Name = L"NullFirstMatrix";
			this->NullFirstMatrix->Size = System::Drawing::Size(90, 23);
			this->NullFirstMatrix->TabIndex = 26;
			this->NullFirstMatrix->Text = L"Нулевая матрица";
			this->NullFirstMatrix->UseVisualStyleBackColor = true;
			this->NullFirstMatrix->Click += gcnew System::EventHandler(this, &MyForm::NullFirstMatrix_Click);
			// 
			// UnitSecondMatrix
			// 
			this->UnitSecondMatrix->Location = System::Drawing::Point(747, 122);
			this->UnitSecondMatrix->Name = L"UnitSecondMatrix";
			this->UnitSecondMatrix->Size = System::Drawing::Size(90, 23);
			this->UnitSecondMatrix->TabIndex = 27;
			this->UnitSecondMatrix->Text = L"Единичная";
			this->UnitSecondMatrix->UseVisualStyleBackColor = true;
			this->UnitSecondMatrix->Click += gcnew System::EventHandler(this, &MyForm::UnitSecondMatrix_Click);
			// 
			// NullSecondMatrix
			// 
			this->NullSecondMatrix->Location = System::Drawing::Point(747, 149);
			this->NullSecondMatrix->Name = L"NullSecondMatrix";
			this->NullSecondMatrix->Size = System::Drawing::Size(90, 23);
			this->NullSecondMatrix->TabIndex = 28;
			this->NullSecondMatrix->Text = L"Нулевая";
			this->NullSecondMatrix->UseVisualStyleBackColor = true;
			this->NullSecondMatrix->Click += gcnew System::EventHandler(this, &MyForm::NullSecondMatrix_Click);
			// 
			// InputToFirstMatrix
			// 
			this->InputToFirstMatrix->Location = System::Drawing::Point(108, 93);
			this->InputToFirstMatrix->Name = L"InputToFirstMatrix";
			this->InputToFirstMatrix->Size = System::Drawing::Size(148, 23);
			this->InputToFirstMatrix->TabIndex = 29;
			this->InputToFirstMatrix->Text = L"Загрузить из файла";
			this->InputToFirstMatrix->UseVisualStyleBackColor = true;
			this->InputToFirstMatrix->Click += gcnew System::EventHandler(this, &MyForm::InputToFirstMatrix_Click);
			// 
			// InputToSecondMatrix
			// 
			this->InputToSecondMatrix->Location = System::Drawing::Point(549, 93);
			this->InputToSecondMatrix->Name = L"InputToSecondMatrix";
			this->InputToSecondMatrix->Size = System::Drawing::Size(156, 23);
			this->InputToSecondMatrix->TabIndex = 30;
			this->InputToSecondMatrix->Text = L"Загрузить из файла";
			this->InputToSecondMatrix->UseVisualStyleBackColor = true;
			this->InputToSecondMatrix->Click += gcnew System::EventHandler(this, &MyForm::InputToSecondMatrix_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(848, 436);
			this->Controls->Add(this->InputToSecondMatrix);
			this->Controls->Add(this->InputToFirstMatrix);
			this->Controls->Add(this->NullSecondMatrix);
			this->Controls->Add(this->UnitSecondMatrix);
			this->Controls->Add(this->NullFirstMatrix);
			this->Controls->Add(this->UnitFirstMatrix);
			this->Controls->Add(this->InverseFirstMatrix);
			this->Controls->Add(this->TransposeFirstMatrix);
			this->Controls->Add(this->DeterminateFirstMatrix);
			this->Controls->Add(this->MultiplicationOfMatrix);
			this->Controls->Add(this->SummOfMatrix);
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
			this->Controls->Add(this->OK);
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
	// Считывание из таблицы в массив
	private: double** ReadFromDGV(DataGridView^ dataGridView);
	// очистка таблицы
	private: void Clear(DataGridView^ datagridview);
	private: System::Void FillGridFromFile(DataGridView^ dg, String^ fileName);
	// ОК - кнопка
	private: System::Void OK_Click(System::Object^  sender, System::EventArgs^  e);
	// +
	private: System::Void SummOfMatrix_Click(System::Object^  sender, System::EventArgs^  e);
	// *
	private: System::Void MultiplicationOfMatrix_Click(System::Object^  sender, System::EventArgs^  e);
	// определитель
	private: System::Void DeterminateFirstMatrix_Click(System::Object^  sender, System::EventArgs^  e);
	// Транспонирование
	private: System::Void TransposeFirstMatrix_Click(System::Object^  sender, System::EventArgs^  e);
	// единичная для 1 матрицы
	private: System::Void UnitFirstMatrix_Click(System::Object^  sender, System::EventArgs^  e);
	// единичная для 2 матрицы
	private: System::Void UnitSecondMatrix_Click(System::Object^  sender, System::EventArgs^  e);
	// нулевая для 1 матрицы
	private: System::Void NullFirstMatrix_Click(System::Object^  sender, System::EventArgs^  e);
	// нулевая для 2 матрицы
	private: System::Void NullSecondMatrix_Click(System::Object^  sender, System::EventArgs^  e);
	// Очистить таблицы
	private: System::Void очисткаТаблицToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Clear(dataGridView1);
		Clear(dataGridView2);
		Clear(dataGridView3);
	}
	private: System::Void InverseFirstMatrix_Click(System::Object^  sender, System::EventArgs^  e);
	// форма
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	// Считывание в 1 матрицу
	private: System::Void InputToFirstMatrix_Click(System::Object^  sender, System::EventArgs^  e);
	// Возможность считывать из файла
	private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	}
	// Считывание во 2 матрицу
	private: System::Void InputToSecondMatrix_Click(System::Object^  sender, System::EventArgs^  e);
};
}
