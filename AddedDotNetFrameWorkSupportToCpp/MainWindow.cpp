#include "../MainWindow.h"
#include <iostream> // For debugging output

using namespace System;
using namespace System::Windows::Forms;

sqlite3* db;  // Native SQLite database pointer

MainWindow::MainWindow(void)
{
    InitializeComponent();
    InitializeDatabase();
}

MainWindow::~MainWindow()
{
    this->!MainWindow();
}

MainWindow::!MainWindow()
{
    if (db)
    {
        sqlite3_close(db);
    }
}

void MainWindow::InitializeDatabase()
{
    std::string dbPath = "users.db";

    int rc = sqlite3_open(dbPath.c_str(), &db); // Pass the address of db

    if (rc != SQLITE_OK)
    {
        MessageBox::Show("Can't open database: " + gcnew String(sqlite3_errmsg(db)));
        std::cerr << "SQLite error: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    if (CreateTable() != SQLITE_OK)
    {
        MessageBox::Show("Failed to create table.");
    }
}

void MainWindow::InitializeComponent(void)
{
    this->signupButton = gcnew Button();
    this->usernameTextBox = gcnew TextBox();
    this->passwordTextBox = gcnew TextBox();
    this->usernameLabel = gcnew Label();
    this->passwordLabel = gcnew Label();

    // 
    // signupButton
    // 
    this->signupButton->Location = Drawing::Point(100, 150);
    this->signupButton->Name = "signupButton";
    this->signupButton->Size = Drawing::Size(100, 23);
    this->signupButton->Text = "Sign Up";
    this->signupButton->Click += gcnew EventHandler(this, &MainWindow::SignupButton_Click);

    // 
    // usernameTextBox
    // 
    this->usernameTextBox->Location = Drawing::Point(100, 30);
    this->usernameTextBox->Name = "usernameTextBox";
    this->usernameTextBox->Size = Drawing::Size(200, 20);

    // 
    // passwordTextBox
    // 
    this->passwordTextBox->Location = Drawing::Point(100, 80);
    this->passwordTextBox->Name = "passwordTextBox";
    this->passwordTextBox->Size = Drawing::Size(200, 20);
    this->passwordTextBox->UseSystemPasswordChar = true;

    // 
    // usernameLabel
    // 
    this->usernameLabel->Location = Drawing::Point(30, 30);
    this->usernameLabel->Name = "usernameLabel";
    this->usernameLabel->Size = Drawing::Size(70, 20);
    this->usernameLabel->Text = "Username";

    // 
    // passwordLabel
    // 
    this->passwordLabel->Location = Drawing::Point(30, 80);
    this->passwordLabel->Name = "passwordLabel";
    this->passwordLabel->Size = Drawing::Size(70, 20);
    this->passwordLabel->Text = "Password";

    // 
    // MainWindow
    // 
    this->ClientSize = Drawing::Size(400, 200);
    this->Controls->Add(this->signupButton);
    this->Controls->Add(this->usernameTextBox);
    this->Controls->Add(this->passwordTextBox);
    this->Controls->Add(this->usernameLabel);
    this->Controls->Add(this->passwordLabel);
    this->Name = "MainWindow";
    this->Text = "Sign Up";
}

void MainWindow::SignupButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ username = usernameTextBox->Text;
    String^ password = passwordTextBox->Text;

    if (InsertUser(username, password) == SQLITE_OK)
    {
        MessageBox::Show("Signup successful!");
    }
    else
    {
        MessageBox::Show("Failed to sign up.");
    }
}

int MainWindow::CreateTable()
{
    const char* createTableSQL =
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "username TEXT NOT NULL UNIQUE, "
        "password TEXT NOT NULL);";

    char* errMsg = nullptr;
    return sqlite3_exec(db, createTableSQL, 0, 0, &errMsg);
}

int MainWindow::InsertUser(String^ username, String^ password)
{
    const char* insertSQL = "INSERT INTO users (username, password) VALUES (?, ?);";
    sqlite3_stmt* stmt;

    int rc = sqlite3_prepare_v2(db, insertSQL, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        MessageBox::Show("Failed to prepare statement: " + gcnew String(sqlite3_errmsg(db)));
        return rc;
    }

    std::string usernameStr = msclr::interop::marshal_as<std::string>(username);
    std::string passwordStr = msclr::interop::marshal_as<std::string>(password);

    sqlite3_bind_text(stmt, 1, usernameStr.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, passwordStr.c_str(), -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        MessageBox::Show("Failed to insert data: " + gcnew String(sqlite3_errmsg(db)));
    }

    sqlite3_finalize(stmt);
    return rc;
}
