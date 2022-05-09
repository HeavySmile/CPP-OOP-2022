#pragma once
#include "Book.hpp"
#include <fstream>
using namespace std;

class User
{
private:
    char* username;
    char* password;
    char** readBooks;
    Book* writtenBooks;
    int readBooksCount;
    int writtenBooksCount;
    int readBooksLimit;
    int writtenBooksLimit;

public:
    // constructors / destructors
    User();
    User(const char*, const char*);
    ~User();

    // operators
    User& operator=(const User&);
    bool operator==(const User&) const;
    
    // user related methods
    char* getUsername() const;
    char* getPassword() const;
    void setUsername(const char*);
    
    // page related methods
    void removePage(const char*);
    void editPage(const char*);
    void addPageToBook(const char*);
    
    // book related methods
    bool IsBookWritten(const char*) const;
    bool IsBookRead(const char*) const;
    Book& getWrittenBook(const char*) const;
    int findWrittenBook(const char*) const;
    void addWrittenBook(Book&);
    Book& writeBook();
    void setBookRead(const char*);
    
    // print books
    void printReadBooks() const;
    void printWrittenBooks() const;
    
    // serialization / deserialization
    void serialize();
    void deserialize(ifstream&);
};