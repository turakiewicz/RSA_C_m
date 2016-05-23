#pragma once

#include "RSA.h"



namespace OJP_CLI_Projekt/*WindowsFormApplication1*/ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Eratostenes
	/// </summary>
	public ref class Eratostenes : public System::Windows::Forms::Form
	{
	public:
		Eratostenes()
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	public: System::Windows::Forms::Button^  show_button;

	public:
		RSA* rsaErato = new RSA();

	public: long long int _n, _e, _d;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Eratostenes()
		{
			delete rsaErato;
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  primes_textBox;
	protected:

	protected:
	private: System::Windows::Forms::ComboBox^  from_comboBox;
	private: System::Windows::Forms::ComboBox^  to_comboBox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  p_textBox;
	private: System::Windows::Forms::TextBox^  q_textBox;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->primes_textBox = (gcnew System::Windows::Forms::TextBox());
			this->from_comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->to_comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->p_textBox = (gcnew System::Windows::Forms::TextBox());
			this->q_textBox = (gcnew System::Windows::Forms::TextBox());
			this->show_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// primes_textBox
			// 
			this->primes_textBox->Location = System::Drawing::Point(12, 12);
			this->primes_textBox->Multiline = true;
			this->primes_textBox->Name = L"primes_textBox";
			this->primes_textBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->primes_textBox->Size = System::Drawing::Size(417, 207);
			this->primes_textBox->TabIndex = 10;
			// 
			// from_comboBox
			// 
			this->from_comboBox->FormattingEnabled = true;
			this->from_comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"0" });
			this->from_comboBox->Location = System::Drawing::Point(117, 225);
			this->from_comboBox->Name = L"from_comboBox";
			this->from_comboBox->Size = System::Drawing::Size(75, 21);
			this->from_comboBox->TabIndex = 0;
			// 
			// to_comboBox
			// 
			this->to_comboBox->FormattingEnabled = true;
			this->to_comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"1000", L"10000", L"100000", L"1000000" });
			this->to_comboBox->Location = System::Drawing::Point(220, 225);
			this->to_comboBox->Name = L"to_comboBox";
			this->to_comboBox->Size = System::Drawing::Size(75, 21);
			this->to_comboBox->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 228);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(99, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Prime numbers from";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(198, 228);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(16, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"to";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(45, 260);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(78, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Choose your p:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(235, 260);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(37, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"and q:";
			// 
			// p_textBox
			// 
			this->p_textBox->Location = System::Drawing::Point(129, 257);
			this->p_textBox->Name = L"p_textBox";
			this->p_textBox->Size = System::Drawing::Size(100, 20);
			this->p_textBox->TabIndex = 7;
			this->p_textBox->TextChanged += gcnew System::EventHandler(this, &Eratostenes::p_textBox_TextChanged);
			// 
			// q_textBox
			// 
			this->q_textBox->Location = System::Drawing::Point(278, 257);
			this->q_textBox->Name = L"q_textBox";
			this->q_textBox->Size = System::Drawing::Size(100, 20);
			this->q_textBox->TabIndex = 8;
			this->q_textBox->TextChanged += gcnew System::EventHandler(this, &Eratostenes::q_textBox_TextChanged);
			// 
			// show_button
			// 
			this->show_button->Location = System::Drawing::Point(321, 225);
			this->show_button->Name = L"show_button";
			this->show_button->Size = System::Drawing::Size(86, 23);
			this->show_button->TabIndex = 9;
			this->show_button->Text = L"Show primes";
			this->show_button->UseVisualStyleBackColor = true;
			this->show_button->Click += gcnew System::EventHandler(this, &Eratostenes::show_button_Click);
			// 
			// Eratostenes
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(441, 286);
			this->Controls->Add(this->show_button);
			this->Controls->Add(this->q_textBox);
			this->Controls->Add(this->p_textBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->to_comboBox);
			this->Controls->Add(this->from_comboBox);
			this->Controls->Add(this->primes_textBox);
			this->Name = L"Eratostenes";
			this->Text = L"Eratostenes Primes Sieve BETA";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Eratostenes::Eratostenes_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public: System::Void show_button_Click(System::Object^  sender, System::EventArgs^  e)
		{
			Cursor->Current = Cursors::WaitCursor;
			try{
				string primes = rsaErato->sitoEratostenesa(System::Int64::Parse(from_comboBox->Text),
					System::Int64::Parse(to_comboBox->Text));
				Cursor->Current = Cursors::Default;
				primes_textBox->Text = gcnew String(primes.c_str());
				primes_textBox->SelectionStart = primes_textBox->TextLength;
				primes_textBox->ScrollToCaret();
				primes_textBox->ScrollBars = ScrollBars::Vertical;
			}
			catch(Exception^ ex){

			}
			
		}
private: System::Void p_textBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	try{
		rsaErato->createKeys(System::Int64::Parse(p_textBox->Text), System::Int64::Parse(p_textBox->Text));
		_n = rsaErato->get_n();
		_e = rsaErato->get_e();
		_d = rsaErato->get_d();
	}
	catch (Exception ^ex){}
}
private: System::Void q_textBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	try{
		rsaErato->createKeys(System::Int64::Parse(p_textBox->Text), System::Int64::Parse(p_textBox->Text));
		_n = rsaErato->get_n();
		_e = rsaErato->get_e();
		_d = rsaErato->get_d();
	}
	catch (Exception ^ex){}
}
private: System::Void Eratostenes_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	
}
};
}
