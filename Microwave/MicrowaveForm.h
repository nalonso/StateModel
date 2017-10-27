#pragma once
#ifndef __MicrowaveForm__
#define __MicrowaveForm__

#include "Microwave.h"
ref class Microwaves;

namespace MicrowaveForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MicrowaveForm : public System::Windows::Forms::Form
	{
	public:
		MicrowaveForm(void)
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
		~MicrowaveForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::ComponentModel::IContainer^  components;

	private: System::Windows::Forms::Button^  openDoorBtn;
	private: System::Windows::Forms::Button^  cookingBtn;
	private: System::Windows::Forms::Button^  closeDoorBtn;

	private: System::Windows::Forms::Label^  timerLabel;
	private: System::Windows::Forms::Label^  stateCurrent;
	private: System::Windows::Forms::Label^  currentStateLabel;

	private: System::Windows::Forms::PictureBox^  lightBulbs;
	private: System::Windows::Forms::PictureBox^  microwaveLogo;
	private: System::Windows::Forms::PictureBox^  microwaveImage;


	private: Microwaves^ microwave;
	
	protected:

	protected:

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
			this->openDoorBtn = (gcnew System::Windows::Forms::Button());
			this->cookingBtn = (gcnew System::Windows::Forms::Button());
			this->timerLabel = (gcnew System::Windows::Forms::Label());
			this->lightBulbs = (gcnew System::Windows::Forms::PictureBox());
			this->microwaveImage = (gcnew System::Windows::Forms::PictureBox());
			this->closeDoorBtn = (gcnew System::Windows::Forms::Button());
			this->stateCurrent = (gcnew System::Windows::Forms::Label());
			this->currentStateLabel = (gcnew System::Windows::Forms::Label());
			this->microwaveLogo = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lightBulbs))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->microwaveImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->microwaveLogo))->BeginInit();
			this->SuspendLayout();
			// 
			// openDoorBtn
			// 
			this->openDoorBtn->Location = System::Drawing::Point(381, 151);
			this->openDoorBtn->Name = L"openDoorBtn";
			this->openDoorBtn->Size = System::Drawing::Size(75, 23);
			this->openDoorBtn->TabIndex = 0;
			this->openDoorBtn->Text = L"OpenDoor";
			this->openDoorBtn->UseVisualStyleBackColor = true;
			this->openDoorBtn->Click += gcnew System::EventHandler(this, &MicrowaveForm::openDoorBtn_Click);
			// 
			// cookingBtn
			// 
			this->cookingBtn->Location = System::Drawing::Point(381, 93);
			this->cookingBtn->Name = L"cookingBtn";
			this->cookingBtn->Size = System::Drawing::Size(75, 23);
			this->cookingBtn->TabIndex = 1;
			this->cookingBtn->Text = L"Cooking";
			this->cookingBtn->UseVisualStyleBackColor = true;
			this->cookingBtn->Click += gcnew System::EventHandler(this, &MicrowaveForm::cookingBtn_Click);
			// 
			// timerLabel
			// 
			this->timerLabel->AutoSize = true;
			this->timerLabel->Font = (gcnew System::Drawing::Font(L"Courier New", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->timerLabel->Location = System::Drawing::Point(362, 12);
			this->timerLabel->MaximumSize = System::Drawing::Size(94, 31);
			this->timerLabel->MinimumSize = System::Drawing::Size(94, 31);
			this->timerLabel->Name = L"timerLabel";
			this->timerLabel->Size = System::Drawing::Size(94, 31);
			this->timerLabel->TabIndex = 2;
			this->timerLabel->Text = L"00:00";
			this->timerLabel->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// lightBulbs
			// 
			this->lightBulbs->Location = System::Drawing::Point(12, 12);
			this->lightBulbs->Name = L"lightBulbs";
			this->lightBulbs->Size = System::Drawing::Size(160, 160);
			this->lightBulbs->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->lightBulbs->TabIndex = 3;
			this->lightBulbs->TabStop = false;
			// 
			// microwaveImage
			// 
			this->microwaveImage->Location = System::Drawing::Point(178, 112);
			this->microwaveImage->Name = L"microwaveImage";
			this->microwaveImage->Size = System::Drawing::Size(190, 60);
			this->microwaveImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->microwaveImage->TabIndex = 4;
			this->microwaveImage->TabStop = false;
			// 
			// closeDoorBtn
			// 
			this->closeDoorBtn->Location = System::Drawing::Point(381, 122);
			this->closeDoorBtn->Name = L"closeDoorBtn";
			this->closeDoorBtn->Size = System::Drawing::Size(75, 23);
			this->closeDoorBtn->TabIndex = 5;
			this->closeDoorBtn->Text = L"CloseDoor";
			this->closeDoorBtn->UseVisualStyleBackColor = true;
			this->closeDoorBtn->Click += gcnew System::EventHandler(this, &MicrowaveForm::closeDoorBtn_Click);
			// 
			// stateCurrent
			// 
			this->stateCurrent->AutoSize = true;
			this->stateCurrent->Font = (gcnew System::Drawing::Font(L"Courier New", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stateCurrent->Location = System::Drawing::Point(12, 184);
			this->stateCurrent->Name = L"stateCurrent";
			this->stateCurrent->Size = System::Drawing::Size(238, 31);
			this->stateCurrent->TabIndex = 6;
			this->stateCurrent->Text = L"Current State:";
			// 
			// currentStateLabel
			// 
			this->currentStateLabel->AutoSize = true;
			this->currentStateLabel->Font = (gcnew System::Drawing::Font(L"Courier New", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->currentStateLabel->Location = System::Drawing::Point(282, 184);
			this->currentStateLabel->MaximumSize = System::Drawing::Size(174, 31);
			this->currentStateLabel->MinimumSize = System::Drawing::Size(174, 31);
			this->currentStateLabel->Name = L"currentStateLabel";
			this->currentStateLabel->Size = System::Drawing::Size(174, 31);
			this->currentStateLabel->TabIndex = 7;
			this->currentStateLabel->Text = L"onOpenDoor";
			this->currentStateLabel->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// microwaveLogo
			// 
			this->microwaveLogo->ImageLocation = L"C:\\Personal\\Microwaves\\Microwave\\Microwave\\Resource\\microwave.png";
			this->microwaveLogo->Location = System::Drawing::Point(198, 13);
			this->microwaveLogo->Name = L"microwaveLogo";
			this->microwaveLogo->Size = System::Drawing::Size(149, 93);
			this->microwaveLogo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->microwaveLogo->TabIndex = 8;
			this->microwaveLogo->TabStop = false;
			// 
			// MicrowaveForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(472, 218);
			this->Controls->Add(this->microwaveLogo);
			this->Controls->Add(this->currentStateLabel);
			this->Controls->Add(this->stateCurrent);
			this->Controls->Add(this->closeDoorBtn);
			this->Controls->Add(this->microwaveImage);
			this->Controls->Add(this->lightBulbs);
			this->Controls->Add(this->timerLabel);
			this->Controls->Add(this->cookingBtn);
			this->Controls->Add(this->openDoorBtn);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MicrowaveForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Microwave :: Alonso Nahuel :: EDI III";
			this->Load += gcnew System::EventHandler(this, &MicrowaveForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lightBulbs))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->microwaveImage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->microwaveLogo))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
			//Microwaves
			this->microwave = (gcnew Microwaves(this->lightBulbs,this->microwaveImage));
			this->microwave->setTimerContainer(this->timerLabel);
			this->microwave->setStateContainer(this->currentStateLabel);
		}
		private: System::Void cookingBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			this->microwave->pushBtn();
		}
		private: System::Void openDoorBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			this->microwave->openDoor();
		}
		private: System::Void closeDoorBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			this->microwave->closeDoor();
		}
};
}
#endif // !__MicrowaveForm__