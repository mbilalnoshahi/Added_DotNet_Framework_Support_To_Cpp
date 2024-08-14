#pragma once

#include <sqlite3.h>
#include <string>
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

public ref class MainWindow : public Form
{
public:
    MainWindow(void);
protected:
    ~MainWindow();
    !MainWindow();

private:
    Button^ signupButton;
    TextBox^ usernameTextBox;
    TextBox^ passwordTextBox;
    Label^ usernameLabel;
    Label^ passwordLabel;

    void InitializeDatabase();
    void InitializeComponent(void);
    void SignupButton_Click(System::Object^ sender, System::EventArgs^ e);
    int CreateTable();
    int InsertUser(String^ username, String^ password);
};
