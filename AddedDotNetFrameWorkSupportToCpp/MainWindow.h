#pragma once

namespace Project1 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::TextBox^ usernameTextBox;
    private: System::Windows::Forms::TextBox^ passwordTextBox;
    private: System::Windows::Forms::TextBox^ emailTextBox;
    private: System::Windows::Forms::Label^ usernameLabel;
    private: System::Windows::Forms::Label^ passwordLabel;
    private: System::Windows::Forms::Label^ emailLabel;
    private: System::Windows::Forms::Button^ signupButton;
    private: System::Windows::Forms::Label^ developerLabel;
    private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               this->usernameTextBox = (gcnew System::Windows::Forms::TextBox());
               this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
               this->emailTextBox = (gcnew System::Windows::Forms::TextBox());
               this->usernameLabel = (gcnew System::Windows::Forms::Label());
               this->passwordLabel = (gcnew System::Windows::Forms::Label());
               this->emailLabel = (gcnew System::Windows::Forms::Label());
               this->signupButton = (gcnew System::Windows::Forms::Button());
               this->developerLabel = (gcnew System::Windows::Forms::Label());

               this->SuspendLayout();
               // 
               // usernameTextBox
               // 
               this->usernameTextBox->Location = System::Drawing::Point(150, 50);
               this->usernameTextBox->Name = L"usernameTextBox";
               this->usernameTextBox->Size = System::Drawing::Size(200, 22);
               this->usernameTextBox->TabIndex = 0;
               // 
               // passwordTextBox
               // 
               this->passwordTextBox->Location = System::Drawing::Point(150, 100);
               this->passwordTextBox->Name = L"passwordTextBox";
               this->passwordTextBox->Size = System::Drawing::Size(200, 22);
               this->passwordTextBox->TabIndex = 1;
               this->passwordTextBox->UseSystemPasswordChar = true;
               // 
               // emailTextBox
               // 
               this->emailTextBox->Location = System::Drawing::Point(150, 150);
               this->emailTextBox->Name = L"emailTextBox";
               this->emailTextBox->Size = System::Drawing::Size(200, 22);
               this->emailTextBox->TabIndex = 2;
               // 
               // usernameLabel
               // 
               this->usernameLabel->AutoSize = true;
               this->usernameLabel->Location = System::Drawing::Point(50, 50);
               this->usernameLabel->Name = L"usernameLabel";
               this->usernameLabel->Size = System::Drawing::Size(77, 17);
               this->usernameLabel->TabIndex = 3;
               this->usernameLabel->Text = L"Username:";
               // 
               // passwordLabel
               // 
               this->passwordLabel->AutoSize = true;
               this->passwordLabel->Location = System::Drawing::Point(50, 100);
               this->passwordLabel->Name = L"passwordLabel";
               this->passwordLabel->Size = System::Drawing::Size(73, 17);
               this->passwordLabel->TabIndex = 4;
               this->passwordLabel->Text = L"Password:";
               // 
               // emailLabel
               // 
               this->emailLabel->AutoSize = true;
               this->emailLabel->Location = System::Drawing::Point(50, 150);
               this->emailLabel->Name = L"emailLabel";
               this->emailLabel->Size = System::Drawing::Size(46, 17);
               this->emailLabel->TabIndex = 5;
               this->emailLabel->Text = L"Email:";
               // 
               // signupButton
               // 
               this->signupButton->Location = System::Drawing::Point(150, 200);
               this->signupButton->Name = L"signupButton";
               this->signupButton->Size = System::Drawing::Size(200, 50);
               this->signupButton->TabIndex = 6;
               this->signupButton->Text = L"Sign Up";
               this->signupButton->UseVisualStyleBackColor = true;
               this->signupButton->Click += gcnew System::EventHandler(this, &MyForm::signupButton_Click);
               // 
               // developerLabel
               // 
               this->developerLabel->AutoSize = true;
               this->developerLabel->Location = System::Drawing::Point(50, 300);
               this->developerLabel->Name = L"developerLabel";
               this->developerLabel->Size = System::Drawing::Size(250, 17);
               this->developerLabel->TabIndex = 7;
               this->developerLabel->Text = L"Developed by Muhammad Bilal Noshahi";
               this->developerLabel->Font = (gcnew System::Drawing::Font(L"Arial", 10));
               this->developerLabel->ForeColor = System::Drawing::Color::Gray;

               // 
               // MyForm
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->ClientSize = System::Drawing::Size(400, 400);
               this->Controls->Add(this->usernameTextBox);
               this->Controls->Add(this->passwordTextBox);
               this->Controls->Add(this->emailTextBox);
               this->Controls->Add(this->usernameLabel);
               this->Controls->Add(this->passwordLabel);
               this->Controls->Add(this->emailLabel);
               this->Controls->Add(this->signupButton);
               this->Controls->Add(this->developerLabel);
               this->Name = L"MyForm";
               this->Text = L"Sign Up";
               this->ResumeLayout(false);
               this->PerformLayout();
           }
#pragma endregion

    private: System::Void signupButton_Click(System::Object^ sender, System::EventArgs^ e) {
        MessageBox::Show("Sign Up button clicked!");
        // You can add more logic here for signup processing.
    }
    };
}
