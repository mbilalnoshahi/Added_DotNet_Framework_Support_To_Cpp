#include <iostream>
#include <sqlite3.h>
#include <string>

// Function declarations
int CreateTable(sqlite3* db);
int InsertUser(sqlite3* db, const std::string& username, const std::string& password);

int main() {
    sqlite3* db;
    char* errMsg = 0;

    // Open SQLite database
    int rc = sqlite3_open("users.db", &db);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
    
    // Create the users table
    if (CreateTable(db) != SQLITE_OK) {
        sqlite3_close(db);
        return 1;
    }
    
    std::string username;
    std::string password;
    
    std::cout << "Enter username: ";
    std::getline(std::cin, username);
    std::cout << "Enter password: ";
    std::getline(std::cin, password);

    // Insert user into database
    if (InsertUser(db, username, password) != SQLITE_OK) {
        sqlite3_close(db);
        return 1;
    }
    
    std::cout << "Signup successful!" << std::endl;
    
    // Close the database connection
    sqlite3_close(db);
    return 0;
}

// Function to create the users table if it does not exist
int CreateTable(sqlite3* db) {
    const char* createTableSQL = 
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "username TEXT NOT NULL UNIQUE, "
        "password TEXT NOT NULL);";
    
    char* errMsg = 0;
    return sqlite3_exec(db, createTableSQL, 0, 0, &errMsg);
}

// Function to insert a new user into the database
int InsertUser(sqlite3* db, const std::string& username, const std::string& password) {
    const char* insertSQL = "INSERT INTO users (username, password) VALUES (?, ?);";
    sqlite3_stmt* stmt;
    
    int rc = sqlite3_prepare_v2(db, insertSQL, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return rc;
    }
    
    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Failed to insert data: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
    return rc;
}
