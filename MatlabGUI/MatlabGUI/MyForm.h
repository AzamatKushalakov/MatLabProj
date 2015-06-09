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
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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


	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			this->SuspendLayout();
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(27, 12);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(94, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"���� �������";
			this->radioButton1->UseVisualStyleBackColor = true;
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
			this->label1->Text = L"����� ����� ���� �";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(24, 62);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(127, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"����� �������� ���� �";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(372, 43);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(109, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"����� ����� ���� �";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(372, 62);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(127, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"����� �������� ���� �";
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
			this->button4->Text = L"������������";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(299, 193);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 17;
			this->button5->Text = L"����������������";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(299, 222);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 18;
			this->button6->Text = L"��������";
			this->button6->UseVisualStyleBackColor = true;
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
			this->Name = L"MyForm";
			this->Text = L"MatrixCalculator";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// ���������� ��������� � ������� ������� (�� ���� ��� ������� � ��������, ����� ����� �����������)
		// �� ��� � ����������� - ��� �����! �� �� ������ ���� ���.
	private: void Mass_Creator(int row, int col, double **mas, DataGridView^ dataGridView)
	{
		for (int i = 0; i < row_b; i++){
			for (int j = 0; j < col_b; j++){
				mas[i][j] = Convert::ToInt32(dataGridView->Rows[i]->Cells[j]->Value);
			}
		}
	}
	/*private: void Mass_B_Creator(int row_b, int col_b, double **mas_B)
	{
				 for (int i = 0; i < row_b; i++){
					 for (int j = 0; j < col_b; j++){
						 mas_B[i][j] = Convert::ToInt32(dataGridView1->Rows[i]->Cells[j]->Value);
					 }
				 }
					
	}
		private: void Mass_A_Creator(int row_a, int col_a, double **mas_A)
		{
					 for (int i = 0; i < row_a; i++){
						 for (int j = 0; j < col_a; j++){
							 mas_A[i][j] = Convert::ToInt32(dataGridView1->Rows[i]->Cells[j]->Value);
						 }
					 }

		}*/
	private:void Show_Mass(int row, int col, double **mas, DataGridView^ dataGridView)
	{
		for (int i = 0; i < row_a; i++){
			for (int j = 0; j < col_a; j++){
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
	}
	//private:void Show_Mass_A(int row_a, int col_a, double **mas_A)
	//{
	//	for (int i = 0; i < row_a; i++){
	//		for (int j = 0; j < col_a; j++){
	//			// �������� ������� � ������� ����� ����
	//			dataGridView1->TopLeftHeaderCell->Value = "�������";
	//			// ����� ������� ��������
	//			dataGridView1->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
	//			// ����� ������� �����
	//			dataGridView1->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
	//			// ����� ��������
	//			dataGridView1->Rows[i]->Cells[j]->Value = mas_A[i][j];

	//		}
	//	}
	//}
	//private:void Show_Mass_B(int row_b, int col_b, double **mas_B)
	//{
	//	for (int i = 0; i < row_b; i++){
	//		for (int j = 0; j < col_b; j++){
	//			// �������� ������� � ������� ����� ����
	//			dataGridView2->TopLeftHeaderCell->Value = "�������";
	//			// ����� ������� ��������
	//			dataGridView2->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
	//			// ����� ������� �����
	//			dataGridView2->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
	//			// ����� ��������
	//			dataGridView2->Rows[i]->Cells[j]->Value = mas_B[i][j];

	//		}
	//	}
	//}
			// ���������� �� ������� � ������ (��������� ����������)
	private: double** ReadFromDGV(DataGridView^ dataGridView)
	{
				 
	    double **mas = new double *[dataGridView->RowCount];
		for (int i = 0; i < dataGridView->RowCount; ++i)
			mas[i] = new double[dataGridView->ColumnCount];
		//try//����� ����������
		//{
			for (int i = 0; i < dataGridView->RowCount; i++)
			{
				for (int j = 0; j < dataGridView->ColumnCount; j++)
				{
					//����������� �������� �� ����� � �����, � ����� � ������
					//���� �� ����� �� ���������� ����� ���������� � ��� ���������
					mas[i][j] = Convert::ToDouble(dataGridView->Rows[i]->Cells[j]->Value);
				}
			}
		//}
		//catch (InvalidCastException^ e)//��������� ���������� ����������
		//{
		//	MessageBox::Show("\n(������������� ���� � �������� �����������!)");
		//	// MessageBox.Show(e.Message + "\n(������������� ���� � �������� �����������!)", "������!", MessageBoxButtons.OK, MessageBoxIcon.Error);
		//}
		return mas;
	}
			 // �������
			 int row_a = 0;
			 int col_a = 0;
			 int row_b = 0;
			 int col_b = 0;
			 // ��
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 // �������, ������� �� ����� � �����
				 row_a = Convert::ToInt32(numericUpDown1->Value);
				 col_a = Convert::ToInt32(numericUpDown2->Value);
				 row_b = Convert::ToInt32(numericUpDown3->Value);
				 col_b = Convert::ToInt32(numericUpDown4->Value);
				
				 double **mas_A = new double *[row_a];
				 for (int i = 0; i < row_a; ++i)
					 mas_A[i] = new double[col_a];
				 // ��������� ������� ��� ������� �
				 dataGridView1->ColumnCount = col_a;
				 dataGridView1->RowCount = row_a;
				 double **mas_B = new double *[row_b];
				 for (int i = 0; i < row_b; ++i)
					 mas_B[i] = new double[col_b];
				 // ��������� ������� ��� ������� �
				 dataGridView2->ColumnCount = col_b;
				 dataGridView2->RowCount = row_b;
				 if (radioButton1->Checked){
					 Mass_Creator(row_a,col_a,mas_A, dataGridView1);
					 Mass_Creator(row_b, col_b, mas_B, dataGridView2);
					 
				 }
				 Show_Mass(row_a, col_a, mas_A,dataGridView1);
				 Show_Mass(row_b, col_b, mas_B,dataGridView1);
				 // ������������ �����
				 dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
				 dataGridView1->AutoResizeColumns();
				 dataGridView2->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
				 dataGridView2->AutoResizeColumns();
				 Matrix A(row_a, col_a, mas_A);
				 Matrix B(row_b, col_b, mas_B);
	}
			 // +
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 double **mas_A = new double *[Convert::ToInt32(numericUpDown1->Value)];
				  for (int i = 0; i < row_a; ++i)
					  mas_A[i] = new double[Convert::ToInt32(numericUpDown2->Value)];
				  
				  double **mas_B = new double *[Convert::ToInt32(numericUpDown3->Value)];
				  for (int i = 0; i < row_b; ++i)
					  mas_B[i] = new double[Convert::ToInt32(numericUpDown4->Value)];
				  
				  mas_A = ReadFromDGV(dataGridView1);
				  mas_B = ReadFromDGV(dataGridView2);
				  Matrix A(Convert::ToInt32(numericUpDown1->Value), Convert::ToInt32(numericUpDown2->Value), mas_A);
				  Matrix B(Convert::ToInt32(numericUpDown3->Value), Convert::ToInt32(numericUpDown4->Value), mas_B);
				  Matrix C= A + B;
				  dataGridView3->ColumnCount = C.GetColumns();
				  dataGridView3->RowCount = C.GetRows();
				  double **mas_� = new double *[C.GetRows()];
				  for (int i = 0; i < C.GetRows(); ++i)
					  mas_�[i] = new double[C.GetColumns()];
				  
				  mas_� = C.ReturnMass();
				  Show_Mass(C.GetRows(), C.GetColumns(), mas_�, dataGridView3);
	}
	// �� ��� �������� ����: ���� ���������� �� �������������� ����, ����� ��� ��� �������
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 double** mas_A = ReadFromDGV(dataGridView1);
				 double** mas_B = ReadFromDGV(dataGridView2);
				 Matrix A(row_a, col_a, mas_A);
				 Matrix B(row_b, col_b, mas_B);
				 Matrix C;
				 C = A * B;
				 double **mas_C = C.ReturnMass();
				 Show_Mass(C.GetRows(), C.GetColumns(), mas_C, dataGridView3);
	}
	// ������������
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 double **mas_A = new double *[Convert::ToInt32(numericUpDown1->Value)];
			 for (int i = 0; i < row_a; ++i)
				 mas_A[i] = new double[Convert::ToInt32(numericUpDown2->Value)];

			 mas_A = ReadFromDGV(dataGridView1);

			 Matrix A(Convert::ToInt32(numericUpDown1->Value), Convert::ToInt32(numericUpDown2->Value), mas_A);
			 MessageBox::Show("������������ ������� = " + A.Det().ToString());


}
		 // ����������������
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 double **mas_A = new double *[Convert::ToInt32(numericUpDown1->Value)];
			 for (int i = 0; i < row_a; ++i)
				 mas_A[i] = new double[Convert::ToInt32(numericUpDown2->Value)];

			 mas_A = ReadFromDGV(dataGridView1);

			 Matrix A(Convert::ToInt32(numericUpDown1->Value), Convert::ToInt32(numericUpDown2->Value), mas_A);
			 dataGridView3->ColumnCount = A.GetRows();
			 dataGridView3->RowCount = A.GetColumns();
			 A.Transport();

			 double **mas_� = new double *[A.GetRows()];
			 for (int i = 0; i < A.GetRows(); ++i)
				 mas_�[i] = new double[A.GetColumns()];

			 mas_� = A.ReturnMass();
			 Show_Mass(dataGridView3->RowCount, dataGridView3->ColumnCount, mas_�, dataGridView3);
			 
}
};
}
