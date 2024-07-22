#pragma once

namespace MainWindow 
{
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyMainWindow : public System::Windows::Forms::Form
    {
    public:
        MyMainWindow(void)
        {
            InitializeComponent();
        }

    protected:
        ~MyMainWindow()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Button^ myButton;
    private: System::Windows::Forms::Label^ myLabel;
    private: System::Windows::Forms::Panel^ mainPanel;
    private: System::Windows::Forms::PictureBox^ logoPictureBox;
    private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               this->myButton = (gcnew System::Windows::Forms::Button());
               this->myLabel = (gcnew System::Windows::Forms::Label());
               this->mainPanel = (gcnew System::Windows::Forms::Panel());
               this->logoPictureBox = (gcnew System::Windows::Forms::PictureBox());
               this->mainPanel->SuspendLayout();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logoPictureBox))->BeginInit();
               this->SuspendLayout();
               // 
               // myButton
               // 
               this->myButton->Location = System::Drawing::Point(100, 150);
               this->myButton->Name = L"myButton";
               this->myButton->Size = System::Drawing::Size(100, 50);
               this->myButton->TabIndex = 0;
               this->myButton->Text = L"Click Me";
               this->myButton->UseVisualStyleBackColor = true;
               this->myButton->BackColor = System::Drawing::Color::LightSkyBlue;
               this->myButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
               this->myButton->Click += gcnew System::EventHandler(this, &MyMainWindow::myButton_Click);
               // 
               // myLabel
               // 
               this->myLabel->AutoSize = true;
               this->myLabel->Location = System::Drawing::Point(100, 220);
               this->myLabel->Name = L"myLabel";
               this->myLabel->Size = System::Drawing::Size(46, 17);
               this->myLabel->TabIndex = 1;
               this->myLabel->Text = L"Hello!";
               this->myLabel->Font = (gcnew System::Drawing::Font(L"Arial", 10));
               // 
               // mainPanel
               // 
               this->mainPanel->Controls->Add(this->myButton);
               this->mainPanel->Controls->Add(this->myLabel);
               this->mainPanel->Controls->Add(this->logoPictureBox);
               this->mainPanel->Location = System::Drawing::Point(12, 12);
               this->mainPanel->Name = L"mainPanel";
               this->mainPanel->Size = System::Drawing::Size(360, 240);
               this->mainPanel->TabIndex = 2;
               this->mainPanel->BackColor = System::Drawing::Color::WhiteSmoke;
               // 
               // logoPictureBox
               // 
               this->logoPictureBox->Location = System::Drawing::Point(100, 20);
               this->logoPictureBox->Name = L"logoPictureBox";
               this->logoPictureBox->Size = System::Drawing::Size(100, 100);
               this->logoPictureBox->TabIndex = 3;
               this->logoPictureBox->TabStop = false;
               this->logoPictureBox->Image = Image::FromFile(L"coder.png");
               // 
               // MyMainWindow
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->ClientSize = System::Drawing::Size(384, 261);
               this->Controls->Add(this->mainPanel);
               this->Name = L"MyMainWindow";
               this->Text = L"MyMainWindow";
               this->mainPanel->ResumeLayout(false);;
               this->mainPanel->PerformLayout();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logoPictureBox))->EndInit();
               this->ResumeLayout(false);
           }
#pragma endregion

    private: System::Void myButton_Click(System::Object^ sender, System::EventArgs^ e) {
        this->myLabel->Text = L"Button Clicked!";
    }
    };
}
