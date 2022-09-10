#pragma once
#include "GameForm.h";

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for StartForm
	/// </summary>
	public ref class StartForm : public System::Windows::Forms::Form
	{
	public:
		StartForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StartForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ txtPalabra;
	private: System::Windows::Forms::Button^ btnInciar;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtPalabra = (gcnew System::Windows::Forms::TextBox());
			this->btnInciar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(51, 43);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(127, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Ingrese la Palabra:";
			// 
			// txtPalabra
			// 
			this->txtPalabra->Location = System::Drawing::Point(193, 43);
			this->txtPalabra->Name = L"txtPalabra";
			this->txtPalabra->Size = System::Drawing::Size(140, 22);
			this->txtPalabra->TabIndex = 1;
			// 
			// btnInciar
			// 
			this->btnInciar->Location = System::Drawing::Point(356, 42);
			this->btnInciar->Name = L"btnInciar";
			this->btnInciar->Size = System::Drawing::Size(122, 23);
			this->btnInciar->TabIndex = 2;
			this->btnInciar->Text = L"Iniciar";
			this->btnInciar->UseVisualStyleBackColor = true;
			this->btnInciar->Click += gcnew System::EventHandler(this, &StartForm::btnInciar_Click);
			// 
			// StartForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(526, 128);
			this->Controls->Add(this->btnInciar);
			this->Controls->Add(this->txtPalabra);
			this->Controls->Add(this->label1);
			this->Name = L"StartForm";
			this->Text = L"Juego del Ahorcado";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnInciar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ palabra = txtPalabra->Text;
		if (!palabra->Trim()->Equals("")) { //Not empty string
			GameForm^ nuevoJuego = gcnew GameForm(palabra);
			nuevoJuego->ShowDialog();
		}
		else { //Empty string
			MessageBox::Show("Debe ingresar una palabra", "Input incorrecto", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	};
}
