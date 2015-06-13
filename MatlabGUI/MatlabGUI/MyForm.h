#pragma once
#include "engine.h"
#include "matrix_operations.h"
#include <stdexcept>
#include <fstream>

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





	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
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
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
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
			// button1
			// 
			this->button1->Location = System::Drawing::Point(363, 43);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(111, 39);
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
			// button2
			// 
			this->button2->Location = System::Drawing::Point(382, 122);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 52);
			this->button2->TabIndex = 14;
			this->button2->Text = L"+";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(382, 207);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 52);
			this->button3->TabIndex = 15;
			this->button3->Text = L"*";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(12, 178);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(90, 23);
			this->button4->TabIndex = 16;
			this->button4->Text = L"Определитель";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(12, 207);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(90, 23);
			this->button5->TabIndex = 17;
			this->button5->Text = L"Транспонирование";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(12, 236);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(90, 23);
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
			// button9
			// 
			this->button9->Location = System::Drawing::Point(12, 122);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(90, 23);
			this->button9->TabIndex = 25;
			this->button9->Text = L"Единичная матрица";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(12, 149);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(90, 23);
			this->button10->TabIndex = 26;
			this->button10->Text = L"Нулевая матрица";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(747, 122);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(90, 23);
			this->button11->TabIndex = 27;
			this->button11->Text = L"Единичная";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(747, 149);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(90, 23);
			this->button12->TabIndex = 28;
			this->button12->Text = L"Нулевая";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(108, 93);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(148, 23);
			this->button7->TabIndex = 29;
			this->button7->Text = L"Загрузить из файла";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(549, 93);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(156, 23);
			this->button8->TabIndex = 30;
			this->button8->Text = L"Загрузить из файла";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
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
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
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
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
	// +
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);
	// *
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e);
	// определитель
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e);
	// Транспонирование
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e);
	// единичная для 1 матрицы
	private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e);
	// единичная для 2 матрицы
	private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e);
	// нулевая для 1 матрицы
	private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e);
	// нулевая для 2 матрицы
	private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e);
	// Очистить таблицы
	private: System::Void очисткаТаблицToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Clear(dataGridView1);
		Clear(dataGridView2);
		Clear(dataGridView3);
	}
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e);
	// форма
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	// Считывание в 1 матрицу
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e);
	// Возможность считывать из файла
	private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	}
	// Считывание во 2 матрицу
	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e);
};
}
