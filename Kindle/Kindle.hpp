#pragma once
#include "User.hpp"

class Kindle
{
private:
    User* users;
    Book* availableBooks;
    int usersCount;
    int usersLimit;
    int availableBooksCount;
    int availableBooksLimit;
    
public:
    // constructors / destructors
    Kindle();
    ~Kindle();
    
    // user related methods
    char* getUserName(const int) const;
    void addUser();
    int findUserIdx(const User&) const;
    bool checkLogin(const User&) const;

    // book related methods
    int findAvailableBook(const char*) const;
    void updateBook(const int, const char*);
    void rateBook(const int);
    void commentBook(const int);
    void addBookToAvailableBooks(const Book&);
    void readBook(const int) const;
    void writeNewBook(const int);
    void getComments() const;
    void getBookRates() const;


    // book page related methods
    void addPageToBook(const int);
    void editPage(const int);
    void removePage(const int);
    
    void addAvailableBooks();

    // print book methods
    void printUserReadBooks(const int) const;
    void printUserWrittenBooks(const int) const;
    void printAvailableBooks() const;

    // serialization / deserialization
    void serialize();
    void deserialize();
};