#include "Kindle.hpp"
#include "Constants.hpp"
#include "Helpers.hpp"
#include <iostream>
#include <fstream>
using namespace std;



Kindle::Kindle()
{
    users = new User[INITIAL_OBJ_SIZE];
    availableBooks = new Book[INITIAL_OBJ_SIZE];
    usersCount = 0;
    usersLimit = INITIAL_OBJ_SIZE;
    availableBooksCount = 0;
    availableBooksLimit = INITIAL_OBJ_SIZE;
}
Kindle::~Kindle()
{
    delete[] users;
    delete[] availableBooks;
}

char* Kindle::getUserName(const int userIdx) const
{
    return users[userIdx].getUsername();
}
void Kindle::addUser()
{
    char* name = new char[MAX_USERNAME_PASS_SIZE];
    char* pass = new char[MAX_USERNAME_PASS_SIZE];

    cout << "> Enter username: ";
    cin >> name;
    cout << "> Enter password: ";
    cin >> pass;  
    cout << "   User registered" << endl;
    cout << endl;

    // if array is too short to fit new data
    if(usersCount == usersLimit)
    {
        users = resizeArray(users, usersLimit, usersLimit*2);
        usersLimit *= 2;
    }
    
    users[usersCount] = User(name, pass);
    ++usersCount;

    delete[] pass;
    delete[] name;
}
int Kindle::findUserIdx(const User& user) const
{
    for (int i = 0; i < usersCount; i++)
    {
        if(users[i] == user) return i;
    }
    
    return -1;
}
bool Kindle::checkLogin(const User& user) const
{
    for (int i = 0; i < usersCount; i++)
    {
        if(users[i] == user) return true;
    }

    return false;
}

int Kindle::findAvailableBook(const char* name) const
{
    // returns book's id
    for (int i = 0; i < availableBooksCount; i++)
    {
        if(!strcmp(availableBooks[i].getBookName(), name)) return i;
    }

    return -1;
}
void Kindle::updateBook(const int userIdx, const char* book_name)
{
    // applies changes made by user
    for (int i = 0; i < availableBooksCount; i++)
    {
        if(!strcmp(availableBooks[i].getBookName(), book_name))
        {
            availableBooks[i] = users[userIdx].getWrittenBook(book_name);
            return;
        }
    }
}
void Kindle::getComments() const
{
    char* book_name = new char[MAX_NAME_SIZE];
    cin.ignore();
    cin.getline(book_name, MAX_NAME_SIZE);
    
    int book_idx = findAvailableBook(book_name);
    availableBooks[book_idx].printComments();
    
    delete[] book_name;
}
void Kindle::commentBook(const int userIdx)
{
    char* book_name = new char[MAX_NAME_SIZE];
    char* comment = new char[MAX_PAGE_SYMBOLS];
    
    cin.ignore();
    cin.getline(book_name, MAX_NAME_SIZE);

    // checks if the book is read
    if(!users[userIdx].IsBookRead(book_name))   
    {
        cout << "Read book first" << endl;
        delete[] book_name;
        return;
    }
    
    // user types a commentary
    cout << "Type your commentary: ";
    cin.getline(comment, MAX_PAGE_SYMBOLS);
    
    // unites author's name and commentary
    char* full_comment = new char[strlen(users[userIdx].getUsername()) + strlen(comment) + 1];
    strcat(full_comment, users[userIdx].getUsername());
    strcat(full_comment, " wrote: ");
    strcat(full_comment, comment);
    
    // adds a comment
    int book_idx = findAvailableBook(book_name);
    availableBooks[book_idx].addComment(full_comment);

    delete[] book_name;
    delete[] comment;
    delete[] full_comment;
}
void Kindle::rateBook(const int userIdx)
{
    char* book_name = new char[MAX_NAME_SIZE];
    int rate;
    
    cin.ignore();
    cin.getline(book_name, MAX_NAME_SIZE);
    
    // user cannot rate the book he wrote
    if(users[userIdx].IsBookWritten(book_name))
    {
        cout << "Cannot rate your own book" << endl;
        delete[] book_name;
        return;
    }

    // user cannot rate unread book
    if(!users[userIdx].IsBookRead(book_name))
    {
        cout << "Read this book before you rate" << endl;
        delete[] book_name;
        return;
    }

    cout << "   Insert number from 0 to 10: ";
    cin >> rate;
    
    // checks for incorrect rate
    if(rate < 0 || rate > 10)
    {
        cout << "Incorrect rate" << endl;
        delete[] book_name;
        return;
    }

    char* rate_str = new char[3];
    
    // transforms int rate to char* rate
    if(rate / 10 == 0)
    {
        rate_str[0] = '0' + rate;
        rate_str[1] = '\0';
    }
    else if(rate / 10 == 1 && rate % 10 == 0)
    {
        rate_str[0] = '1';
        rate_str[1] = '0';
        rate_str[2] = '\0';
    }
    else return;

    // unites author's name and rate
    char* full_rate = new char[strlen(users[userIdx].getUsername()) + strlen(" rated 10 stars") + 1];
    strcpy(full_rate, users[userIdx].getUsername());
    strcat(full_rate, " rated ");
    strcat(full_rate, rate_str);
    strcat(full_rate, " stars");
    
    // adds a new rate
    int book_idx = findAvailableBook(book_name);
    availableBooks[book_idx].rateBook(full_rate);

    delete[] full_rate;
    delete[] book_name;
    delete[] rate_str;
}
void Kindle::getBookRates() const
{
    char* book_name = new char[MAX_NAME_SIZE];
    cin.ignore();
    cin.getline(book_name, MAX_NAME_SIZE);

    // prints all rates
    int book_idx = findAvailableBook(book_name);
    availableBooks[book_idx].printRates();

    delete[] book_name;
}
void Kindle::readBook(const int userIdx) const
{
    char* book_name = new char[MAX_NAME_SIZE];
    cin.ignore();
    cin.getline(book_name, MAX_NAME_SIZE);

    int book_idx = findAvailableBook(book_name);
    availableBooks[book_idx].readBook();
    users[userIdx].setBookRead(book_name);

    delete[] book_name;        
}
void Kindle::writeNewBook(const int userIdx)
{
    // adds the book to available book once written
    addBookToAvailableBooks(users[userIdx].writeBook());
}
void Kindle::addBookToAvailableBooks(const Book& book)
{
    // if array is too short to fit new data
    if(availableBooksCount == availableBooksLimit)
    {
        availableBooks = resizeArray(availableBooks, availableBooksLimit, availableBooksLimit*2);
        availableBooksLimit *= 2;
    }
    
    availableBooks[availableBooksCount] = book;
    ++availableBooksCount;
}

void Kindle::editPage(const int userIdx)
{
    char* book_name = new char[MAX_NAME_SIZE];
    cin.ignore();
    cin.getline(book_name, MAX_NAME_SIZE);
    
    users[userIdx].editPage(book_name);
    
    // applies changes to book
    updateBook(userIdx, book_name);

    delete[] book_name;
}
void Kindle::removePage(const int userIdx)
{
    char* book_name = new char[MAX_NAME_SIZE];
    cin.ignore();
    cin.getline(book_name, MAX_NAME_SIZE);
    
    users[userIdx].removePage(book_name);
    
     // applies changes to book
    updateBook(userIdx, book_name);

    delete[] book_name;
}
void Kindle::addPageToBook(const int userIdx)
{
    char* book_name = new char[MAX_NAME_SIZE];
    cin.ignore();
    cin.getline(book_name, MAX_NAME_SIZE);
    
    users[userIdx].addPageToBook(book_name);
    
    // applies changes to book    
    updateBook(userIdx, book_name);

    delete[] book_name;
}

void Kindle::addAvailableBooks()
{
    // ifstream file("Effective Java.bin")
    // availableBooks[0].readFromFile();
}

void Kindle::printUserReadBooks(const int userIdx) const
{
    users[userIdx].printReadBooks();
}
void Kindle::printUserWrittenBooks(const int userIdx) const
{
    users[userIdx].printWrittenBooks();
}
void Kindle::printAvailableBooks() const
{
    for (int i = 0; i < availableBooksCount; i++)
    {
        cout << i +1 << ". " << availableBooks[i].getBookName() << endl;
    }
}

void Kindle::serialize()
{
    ofstream file("Data.bin", ios::out | ios::binary | ios::trunc);
    
    if(!file)
    {
        cout << "Failed to serialize data" << endl;
        return;
    }

    // write usersCount
    int length = usersCount;
    file.write((const char*)&length, sizeof(length));
    
    // write usersLimit
    length = usersLimit;
    file.write((const char*)&length, sizeof(length));
    
    // write availableBooksCount
    length = availableBooksCount;
    file.write((const char*)&length, sizeof(length));
    
    // write availableBooksLimit
    length = availableBooksLimit;
    file.write((const char*)&length, sizeof(length));
    
    file.close();
    
    // write users
    for (int i = 0; i < usersCount; i++)
    {
        users[i].serialize();
    }
    
    // write availableBooks
    for (int i = 0; i < availableBooksCount; i++)
    {
        availableBooks[i].writeToFile();
    }
}
void Kindle::deserialize()
{
    ifstream file("Data.bin", ios::out | ios::binary);

    if(!file)
    {
        cout << "Failed to deserialize data" << endl;
        return;
    }

    // read usersCount
    int length = 0;
    file.read((char*)&length, sizeof(length));
    usersCount = length;
    
    // read usersLimit
    length = 0;
    file.read((char*)&length, sizeof(length));
    usersLimit = length;

    // read availableBooksCount
    length = 0;
    file.read((char*)&length, sizeof(length));
    availableBooksCount = length;

    // read availableBooksLimit
    length = 0;
    file.read((char*)&length, sizeof(length));
    availableBooksLimit = length;

    users = resizeArray(users, INITIAL_OBJ_SIZE, usersLimit);
    for (int i = 0; i < usersCount; i++)
    {
        users[i].deserialize(file);
    }
    
    availableBooks = resizeArray(availableBooks, INITIAL_OBJ_SIZE, availableBooksLimit);
    for (int i = 0; i < availableBooksCount; i++)
    {
        availableBooks[i].readFromFile(file);
    }
    
    file.close();
}


