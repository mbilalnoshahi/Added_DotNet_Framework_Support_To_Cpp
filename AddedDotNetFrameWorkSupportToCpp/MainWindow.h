#pragma once

#include <sqlite3.h>
#include <string>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

public ref class MainWindow : public System::Windows::Forms::Form
{
public:
    MainWindow(void);
protected:
    ~MainWindow();
    !MainWindow();

private:
    sqlite3* db;  // Native SQLite database pointer

    Button^ signupButton;
    TextBox^ usernameTextBox;
    TextBox^ passwordTextBox;
    Label^ usernameLabel;
    Label^ passwordLabel;

    void InitializeDatabase();
    void InitializeComponent(void);
    void SignupButton_Click(System::Object^ sender, System::EventArgs^ e);
};
