#pragma once
#include "RSA.h"
#include "Eratostenes.h"
#include <msclr\marshal_cppstd.h>

namespace WindowsFormApplication1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace OJP_CLI_Projekt;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Eratostenes^ eratostenes;
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			eratostenes = gcnew Eratostenes();
		}

	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::ToolStripMenuItem^  erastotenesPrimesSiveToolStripMenuItem;
	public:

		///DODANE PRZEZE MNIE:
		RSA *rsa = new RSA();


		public: void set_plainText(String^ txt)
		{
			text_textBox->Text = txt/*gcnew String(txt.c_str())*/;
		}

		public: void set_ned(long long int n, long long int e, long long int d)
		{
			rsa->set_n(n);
			rsa->set_e(e);
			rsa->set_d(d);
		}
		///*******************
		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete rsa;
				delete components;
			}
		}

	protected:



	private: System::Windows::Forms::TextBox^  text_textBox;

	private: System::Windows::Forms::Label^  text_label;
	private: System::Windows::Forms::TextBox^  cryptogram_textBox;

	private: System::Windows::Forms::Label^  cryptogram_label;
	private: System::Windows::Forms::Button^  encrypt_button;
	private: System::Windows::Forms::Button^  decrypt_button;
	private: System::Windows::Forms::GroupBox^  publicKey_groupBox;
	private: System::Windows::Forms::Label^  e_label;


	private: System::Windows::Forms::Label^  n1_label;
	private: System::Windows::Forms::TextBox^  e_textBox;
	private: System::Windows::Forms::TextBox^  n1_textBox;



	private: System::Windows::Forms::GroupBox^  privateKey_groupBox;
	private: System::Windows::Forms::Label^  d_label;
	private: System::Windows::Forms::Label^  n2_label;
	private: System::Windows::Forms::TextBox^  d_textBox;
	private: System::Windows::Forms::TextBox^  n2_textBox;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;


	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->text_textBox = (gcnew System::Windows::Forms::TextBox());
			this->text_label = (gcnew System::Windows::Forms::Label());
			this->cryptogram_textBox = (gcnew System::Windows::Forms::TextBox());
			this->cryptogram_label = (gcnew System::Windows::Forms::Label());
			this->encrypt_button = (gcnew System::Windows::Forms::Button());
			this->decrypt_button = (gcnew System::Windows::Forms::Button());
			this->publicKey_groupBox = (gcnew System::Windows::Forms::GroupBox());
			this->e_label = (gcnew System::Windows::Forms::Label());
			this->n1_label = (gcnew System::Windows::Forms::Label());
			this->e_textBox = (gcnew System::Windows::Forms::TextBox());
			this->n1_textBox = (gcnew System::Windows::Forms::TextBox());
			this->privateKey_groupBox = (gcnew System::Windows::Forms::GroupBox());
			this->d_label = (gcnew System::Windows::Forms::Label());
			this->n2_label = (gcnew System::Windows::Forms::Label());
			this->d_textBox = (gcnew System::Windows::Forms::TextBox());
			this->n2_textBox = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->erastotenesPrimesSiveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->publicKey_groupBox->SuspendLayout();
			this->privateKey_groupBox->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// text_textBox
			// 
			this->text_textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->text_textBox->Location = System::Drawing::Point(12, 49);
			this->text_textBox->Multiline = true;
			this->text_textBox->Name = L"text_textBox";
			this->text_textBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->text_textBox->Size = System::Drawing::Size(298, 240);
			this->text_textBox->TabIndex = 2;
			// 
			// text_label
			// 
			this->text_label->AutoSize = true;
			this->text_label->Location = System::Drawing::Point(12, 33);
			this->text_label->Name = L"text_label";
			this->text_label->Size = System::Drawing::Size(50, 13);
			this->text_label->TabIndex = 3;
			this->text_label->Text = L"Plain text";
			// 
			// cryptogram_textBox
			// 
			this->cryptogram_textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->cryptogram_textBox->Location = System::Drawing::Point(321, 49);
			this->cryptogram_textBox->Multiline = true;
			this->cryptogram_textBox->Name = L"cryptogram_textBox";
			this->cryptogram_textBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->cryptogram_textBox->Size = System::Drawing::Size(298, 240);
			this->cryptogram_textBox->TabIndex = 4;
			// 
			// cryptogram_label
			// 
			this->cryptogram_label->AutoSize = true;
			this->cryptogram_label->Location = System::Drawing::Point(318, 33);
			this->cryptogram_label->Name = L"cryptogram_label";
			this->cryptogram_label->Size = System::Drawing::Size(60, 13);
			this->cryptogram_label->TabIndex = 5;
			this->cryptogram_label->Text = L"Cryptogram";
			// 
			// encrypt_button
			// 
			this->encrypt_button->Location = System::Drawing::Point(235, 295);
			this->encrypt_button->Name = L"encrypt_button";
			this->encrypt_button->Size = System::Drawing::Size(75, 23);
			this->encrypt_button->TabIndex = 6;
			this->encrypt_button->Text = L"Encrypt >>";
			this->encrypt_button->UseVisualStyleBackColor = true;
			this->encrypt_button->Click += gcnew System::EventHandler(this, &Form1::encrypt_button_Click);
			// 
			// decrypt_button
			// 
			this->decrypt_button->Location = System::Drawing::Point(321, 295);
			this->decrypt_button->Name = L"decrypt_button";
			this->decrypt_button->Size = System::Drawing::Size(75, 23);
			this->decrypt_button->TabIndex = 7;
			this->decrypt_button->Text = L"<< Decrypt";
			this->decrypt_button->UseVisualStyleBackColor = true;
			this->decrypt_button->Click += gcnew System::EventHandler(this, &Form1::decrypt_button_Click);
			// 
			// publicKey_groupBox
			// 
			this->publicKey_groupBox->Controls->Add(this->e_label);
			this->publicKey_groupBox->Controls->Add(this->n1_label);
			this->publicKey_groupBox->Controls->Add(this->e_textBox);
			this->publicKey_groupBox->Controls->Add(this->n1_textBox);
			this->publicKey_groupBox->Location = System::Drawing::Point(12, 295);
			this->publicKey_groupBox->Name = L"publicKey_groupBox";
			this->publicKey_groupBox->Size = System::Drawing::Size(217, 65);
			this->publicKey_groupBox->TabIndex = 8;
			this->publicKey_groupBox->TabStop = false;
			this->publicKey_groupBox->Text = L"Public key";
			// 
			// e_label
			// 
			this->e_label->AutoSize = true;
			this->e_label->Location = System::Drawing::Point(108, 42);
			this->e_label->Name = L"e_label";
			this->e_label->Size = System::Drawing::Size(13, 13);
			this->e_label->TabIndex = 3;
			this->e_label->Text = L"e";
			// 
			// n1_label
			// 
			this->n1_label->AutoSize = true;
			this->n1_label->Location = System::Drawing::Point(6, 42);
			this->n1_label->Name = L"n1_label";
			this->n1_label->Size = System::Drawing::Size(13, 13);
			this->n1_label->TabIndex = 2;
			this->n1_label->Text = L"n";
			// 
			// e_textBox
			// 
			this->e_textBox->Location = System::Drawing::Point(111, 19);
			this->e_textBox->Name = L"e_textBox";
			this->e_textBox->Size = System::Drawing::Size(100, 20);
			this->e_textBox->TabIndex = 1;
			this->e_textBox->TextChanged += gcnew System::EventHandler(this, &Form1::e_textBox_TextChanged);
			// 
			// n1_textBox
			// 
			this->n1_textBox->Location = System::Drawing::Point(6, 19);
			this->n1_textBox->Name = L"n1_textBox";
			this->n1_textBox->Size = System::Drawing::Size(100, 20);
			this->n1_textBox->TabIndex = 0;
			this->n1_textBox->TextChanged += gcnew System::EventHandler(this, &Form1::n1_textBox_TextChanged);
			// 
			// privateKey_groupBox
			// 
			this->privateKey_groupBox->Controls->Add(this->d_label);
			this->privateKey_groupBox->Controls->Add(this->n2_label);
			this->privateKey_groupBox->Controls->Add(this->d_textBox);
			this->privateKey_groupBox->Controls->Add(this->n2_textBox);
			this->privateKey_groupBox->Location = System::Drawing::Point(402, 295);
			this->privateKey_groupBox->Name = L"privateKey_groupBox";
			this->privateKey_groupBox->Size = System::Drawing::Size(217, 65);
			this->privateKey_groupBox->TabIndex = 9;
			this->privateKey_groupBox->TabStop = false;
			this->privateKey_groupBox->Text = L"Private key";
			// 
			// d_label
			// 
			this->d_label->AutoSize = true;
			this->d_label->Location = System::Drawing::Point(108, 42);
			this->d_label->Name = L"d_label";
			this->d_label->Size = System::Drawing::Size(13, 13);
			this->d_label->TabIndex = 3;
			this->d_label->Text = L"d";
			// 
			// n2_label
			// 
			this->n2_label->AutoSize = true;
			this->n2_label->Location = System::Drawing::Point(6, 42);
			this->n2_label->Name = L"n2_label";
			this->n2_label->Size = System::Drawing::Size(13, 13);
			this->n2_label->TabIndex = 2;
			this->n2_label->Text = L"n";
			// 
			// d_textBox
			// 
			this->d_textBox->Location = System::Drawing::Point(111, 19);
			this->d_textBox->Name = L"d_textBox";
			this->d_textBox->Size = System::Drawing::Size(100, 20);
			this->d_textBox->TabIndex = 1;
			this->d_textBox->TextChanged += gcnew System::EventHandler(this, &Form1::d_textBox_TextChanged);
			// 
			// n2_textBox
			// 
			this->n2_textBox->Location = System::Drawing::Point(6, 19);
			this->n2_textBox->Name = L"n2_textBox";
			this->n2_textBox->Size = System::Drawing::Size(100, 20);
			this->n2_textBox->TabIndex = 0;
			this->n2_textBox->TextChanged += gcnew System::EventHandler(this, &Form1::n2_textBox_TextChanged);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->toolsToolStripMenuItem, this->aboutToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(631, 24);
			this->menuStrip1->TabIndex = 10;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// toolsToolStripMenuItem
			// 
			this->toolsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->erastotenesPrimesSiveToolStripMenuItem });
			this->toolsToolStripMenuItem->Name = L"toolsToolStripMenuItem";
			this->toolsToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->toolsToolStripMenuItem->Text = L"Tools";
			// 
			// erastotenesPrimesSiveToolStripMenuItem
			// 
			this->erastotenesPrimesSiveToolStripMenuItem->Name = L"erastotenesPrimesSiveToolStripMenuItem";
			this->erastotenesPrimesSiveToolStripMenuItem->Size = System::Drawing::Size(234, 22);
			this->erastotenesPrimesSiveToolStripMenuItem->Text = L"Erastotenes Primes Sieve BETA";
			this->erastotenesPrimesSiveToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::erastotenesPrimesSiveToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->aboutToolStripMenuItem->Text = L"About";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(631, 372);
			this->Controls->Add(this->privateKey_groupBox);
			this->Controls->Add(this->publicKey_groupBox);
			this->Controls->Add(this->decrypt_button);
			this->Controls->Add(this->encrypt_button);
			this->Controls->Add(this->cryptogram_label);
			this->Controls->Add(this->cryptogram_textBox);
			this->Controls->Add(this->text_label);
			this->Controls->Add(this->text_textBox);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"RSA Cyphering machine 1.0";
			this->publicKey_groupBox->ResumeLayout(false);
			this->publicKey_groupBox->PerformLayout();
			this->privateKey_groupBox->ResumeLayout(false);
			this->privateKey_groupBox->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void encrypt_button_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (String::IsNullOrWhiteSpace(n1_textBox->Text) || String::IsNullOrWhiteSpace(e_textBox->Text))
		{
			cryptogram_textBox->Text = "Error: Public key is missing!";
		}
		else
		{
			try
			{
				String^ plainText = text_textBox->Text;
				string plainText_str = msclr::interop::marshal_as<string>(plainText);
				string cryptogram = rsa->encrypt(plainText_str.c_str());
				cryptogram_textBox->Text = gcnew String(cryptogram.c_str());
			}
			catch (Exception ^ex)
			{
				cryptogram_textBox->Text = "Error: Invalid data!";
			}
		}
	}
	private: System::Void decrypt_button_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (String::IsNullOrWhiteSpace(n2_textBox->Text) || String::IsNullOrWhiteSpace(d_textBox->Text))
		{
			text_textBox->Text = "Error: Private key is missing!";
		}
		else
		{
			try
			{
				String^ cryptogram = cryptogram_textBox->Text;
				string cryptogram_str = msclr::interop::marshal_as<string>(cryptogram);
				string plainText = rsa->decrypt(cryptogram_str.c_str());
				text_textBox->Text = gcnew String(plainText.c_str());
			}
			catch (Exception ^ex)
			{
				text_textBox->Text = "Error: Invalid data!";
			}
		}
	}
	private: System::Void n1_textBox_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		n2_textBox->Text = n1_textBox->Text;
		if (!String::IsNullOrWhiteSpace(n1_textBox->Text))
			rsa->set_n(System::Int64::Parse(n1_textBox->Text));
		eratostenes->_n = System::Int64::Parse(n1_textBox->Text);
		
	}
	private: System::Void n2_textBox_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		n1_textBox->Text = n2_textBox->Text;
		if (!String::IsNullOrWhiteSpace(n2_textBox->Text))
			rsa->set_n(System::Int64::Parse(n2_textBox->Text));
		eratostenes->_n = System::Int64::Parse(n2_textBox->Text);
	}
	private: System::Void e_textBox_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		rsa->set_e(System::Int64::Parse(e_textBox->Text));
		eratostenes->_e = System::Int64::Parse(e_textBox->Text);
	}
	private: System::Void d_textBox_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		rsa->set_d(System::Int64::Parse(d_textBox->Text));
		eratostenes->_d = System::Int64::Parse(d_textBox->Text);
	}
	private: System::Void generate_button_Click(System::Object^  sender, System::EventArgs^  e)
	{
		
		
	}




private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	n1_textBox->Text = System::Convert::ToString(eratostenes->_n);
	n2_textBox->Text = System::Convert::ToString(eratostenes->_n);
	e_textBox->Text = System::Convert::ToString(eratostenes->_e);
	d_textBox->Text = System::Convert::ToString(eratostenes->_d);
	rsa->set_n(eratostenes->_n);
	rsa->set_e(eratostenes->_e);
	rsa->set_d(eratostenes->_d);
}
private: System::Void erastotenesPrimesSiveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	eratostenes->Show();
}
};
}

