#pragma once
#include "Page.hpp"
#include <fstream>
using namespace std;

class Book
{
private:
    char* name;
    char* author;
    char** ratings;
    char** comments;
    int commentsCount;
    int commentsLimit;
    Page* pages;
    int pagesCount;
    int ratingsCount;
    int ratingsLimit;
    int pagesLimit;

public:
    // constructors/destructors
    Book();
    Book(const char*, const char*);
    ~Book();

    Book& operator=(const Book&);
    
    // book content related methods
    char* getBookName() const;
    void setName(const char*);
    void setAuthor(const char*);
    void removePage(const int);
    void editPage(const int);
    void addPage();
    void addComment(const char*);
    void rateBook(const char*);
    void readBook() const;
    void addPages(const int);
    
    // print book's attributes
    void printRates() const;
    void printComments() const;
    void printBook() const;
    void printPages() const;

    // serialization / deserialization
    void writeToFile();
    void readFromFile(ifstream&);
};