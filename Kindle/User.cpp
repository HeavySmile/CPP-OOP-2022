#include "User.hpp"
#include "Kindle.hpp"
#include "Helpers.hpp"
#include <iostream>
#include <fstream>
#include "Constants.hpp"
using namespace std;

User::User()
{
    username = nullptr;
    password = nullptr;
    readBooks = new char*[INITIAL_OBJ_SIZE];
    for (int i = 0; i < INITIAL_OBJ_SIZE; i++)
    {
        readBooks[i] = nullptr;
    }
    writtenBooks = new Book[INITIAL_OBJ_SIZE];
    readBooksCount = 0;
    writtenBooksCount = 0;
    readBooksLimit = INITIAL_OBJ_SIZE;
    writtenBooksLimit = INITIAL_OBJ_SIZE;
}
User::User(const char* username, const char* password)
{
    this->username = new char[strlen(username) + 1];
    this->password = new char[strlen(password) + 1];
    strcpy(this->username, username);
    strcpy(this->password, password);

    readBooks = new char*[INITIAL_OBJ_SIZE];
    for (int i = 0; i < INITIAL_OBJ_SIZE; i++)
    {
        readBooks[i] = nullptr;
    }
    writtenBooks = new Book[INITIAL_OBJ_SIZE];
    readBooksCount = 0;
    writtenBooksCount = 0;
    readBooksLimit = INITIAL_OBJ_SIZE;
    writtenBooksLimit = INITIAL_OBJ_SIZE;
}
User::~User()
{
    delete[] username;
    delete[] password;
    for (int i = 0; i < readBooksLimit; i++) delete[] readBooks[i];
    delete[] readBooks;
    delete[] writtenBooks;
}

User& User::operator=(const User& user)
{
    if(this != &user)
    {
        delete[] username;
        delete[] password;
        for (int i = 0; i < readBooksLimit; i++) delete[] readBooks[i];
        delete[] readBooks;
        delete[] writtenBooks;
            
        // if the object is not initialized
        if(user.username == nullptr) this->username = nullptr;
        else
        {
            this->username = new char[strlen(user.username) + 1];
            strcpy(this->username, user.username);
        }
        
        // if the object is not initialized
        if(user.password == nullptr) this->password = nullptr;
        {
            this->password = new char[strlen(user.password) + 1];
            strcpy(this->password, user.password);
        }
        
        this->readBooks = new char*[user.readBooksLimit];
        for (int i = 0; i < user.readBooksLimit; i++)
        {
            readBooks[i] = nullptr;
        }
        
        this->writtenBooks = new Book[user.writtenBooksLimit];
        
        for (int i = 0; i < user.readBooksCount; i++)
        {
            this->readBooks[i] = new char[strlen(user.readBooks[i]) + 1];
            strcpy(this->readBooks[i], user.readBooks[i]);
        }
        for (int i = 0; i < writtenBooksCount; i++)
        {
            this->writtenBooks[i] = user.writtenBooks[i];
        }
        this->readBooksCount = user.readBooksCount;
        this->writtenBooksCount = user.writtenBooksCount;
        this->readBooksLimit = user.readBooksLimit;
        this->writtenBooksLimit = user.writtenBooksLimit;
    }

    return *this;
}
bool User::operator==(const User& user) const
{
    return !strcmp(this->username, user.username) && !strcmp(this->password, user.password);
}

char* User::getUsername() const
{
    return username;
}
char* User::getPassword() const
{
    return password;
}
void User::setUsername(const char* username)
{
    delete[] this->username;
    this->username = new char[strlen(username) + 1];
    strcpy(this->username, username); 
}

void User::removePage(const char* name)
{
    int page;
    cout << "Insert page to be removed: ";
    cin >> page;
    
    int book_idx = findWrittenBook(name);
    writtenBooks[book_idx].removePage(page);
}
void User::editPage(const char* name)
{
    int page;
    cout << "Insert page to be edited: ";
    cin >> page;
    
    int book_idx = findWrittenBook(name);
    writtenBooks[book_idx].editPage(page);
}
void User::addPageToBook(const char* name)
{
    int book_idx = findWrittenBook(name);
    writtenBooks[book_idx].addPage();
}

bool User::IsBookWritten(const char* name) const
{
    for (int i = 0; i < writtenBooksCount; i++)
    {
        if(!strcmp(writtenBooks[i].getBookName(), name)) return true;
    }

    return false;
}
bool User::IsBookRead(const char* name) const
{
    for (int i = 0; i < readBooksCount; i++)
    {
        if(!strcmp(readBooks[i], name)) return true;
    }

    return false;
}
Book& User::getWrittenBook(const char* name) const
{
    for (int i = 0; i < writtenBooksCount; i++)
    {
        if(!strcmp(writtenBooks[i].getBookName(), name))
        {
            return writtenBooks[i];
        }
    }
    
    return writtenBooks[0];
}
int User::findWrittenBook(const char* book_name) const
{
    for (int i = 0; i < writtenBooksCount; i++)
    {
        if(!strcmp(writtenBooks[i].getBookName(), book_name)) return i;
    }

    return -1;
}
void User::addWrittenBook(Book& book)
{
    // if array is too short to fit new data
    if(writtenBooksCount == writtenBooksLimit)
    {
        writtenBooks = resizeArray(writtenBooks, writtenBooksLimit, writtenBooksLimit*2);
        writtenBooksLimit *= 2;
    }
    
    writtenBooks[writtenBooksCount] = book;
}
void User::printReadBooks() const
{
    for (int i = 0; i < readBooksCount; i++)
    {
        cout << i + 1 << "." << readBooks[i] << endl;
    }
    cout << endl;
}
void User::printWrittenBooks() const
{
    for (int i = 0; i < writtenBooksCount; i++)
    {
        cout << i + 1 << "." << writtenBooks[i].getBookName() << endl;
    }
}
void User::setBookRead(const char* name)
{
    if(IsBookRead(name)) return;
    
    // if array is too short to fit new data
    if(readBooksCount == readBooksLimit)
    {
        readBooks = resizeArray(readBooks, readBooksLimit, readBooksLimit*2);
        readBooksLimit *= 2;
    }

    readBooks[readBooksCount] = new char[strlen(name) + 1];
    strcpy(readBooks[readBooksCount], name);
    ++readBooksCount;
}
Book& User::writeBook()
{
    // if array is too short to fit new data
    if(writtenBooksCount == writtenBooksLimit)
    {
        writtenBooks = resizeArray(writtenBooks, writtenBooksLimit, writtenBooksLimit*2);
        writtenBooksLimit *= 2;
    }
    
    char* title = new char[MAX_NAME_SIZE];
    int pagesCount = 0;

    cout << "   >>Enter title: ";
    cin.ignore();
    cin.getline(title, MAX_NAME_SIZE);
    
    cout << "   >>Enter page count: ";
    cin >> pagesCount;
    
    writtenBooks[writtenBooksCount].setName(title);
    writtenBooks[writtenBooksCount].setAuthor(this->username);
    
    // sets pages
    cin.ignore();
    for (int i = 0; i < pagesCount; i++)
    {
        writtenBooks[writtenBooksCount].addPage();
        cout << endl;
    }
    
    ++writtenBooksCount;

    delete[] title;
    // return newly written book for further usage
    return writtenBooks[writtenBooksCount - 1];
}

void User::serialize()
{
    ofstream file("Data.bin", ios::out | ios::binary | ios::app);
    
    // write username
    int length = strlen(username) + 1;
    file.write((const char*)&length, sizeof(length));
    file.write(username, length);
    
    // write password
    length = strlen(password) + 1;
    file.write((const char*)&length, sizeof(length));
    file.write(password, length);

    // write readBooksCount
    file.write((const char*)&readBooksCount, sizeof(readBooksCount));
    
    // write readBooksLimit
    file.write((const char*)&readBooksLimit, sizeof(readBooksLimit));
    
    for (int i = 0; i < readBooksCount; i++)
    {
        // write every readbook
        int inn_length = strlen(readBooks[i]) + 1;
        file.write((const char*)&inn_length, sizeof(inn_length));
        file.write(readBooks[i], inn_length);
    }
    
    // write writtenBooksCount
    file.write((const char*)&writtenBooksCount, sizeof(writtenBooksCount));
    
    // write writtenBooksLimit
    file.write((const char*)&writtenBooksLimit, sizeof(writtenBooksLimit));
    
    file.close();

    for (int i = 0; i < writtenBooksCount; i++)
    {
        writtenBooks[i].writeToFile();
    }

}
void User::deserialize(ifstream& file)
{
    // read username
    int length = 0;
    file.read((char*)&length, sizeof(length));
    delete[] username;
    username = new char[length];
    file.read(username, length);

    // read password
    length = 0;
    file.read((char*)&length, sizeof(length));
    delete[] password;
    password = new char[length];
    file.read(password, length);

    // read readBooksCount
    length = 0;
    file.read((char*)&length, sizeof(length));
    readBooksCount = length;

    // read readBooksLimit
    length = 0;
    file.read((char*)&length, sizeof(length));
    readBooksLimit = length;

    // read readBooks
    for (int i = 0; i < readBooksCount; i++)
    {
        // read every readbook
        int inn_length = 0;
        file.read((char*)&inn_length, sizeof(inn_length));
        readBooks[i] = new char[inn_length];
        file.read(readBooks[i], inn_length);
    }

    // read writtenBooksCount
    length = 0;
    file.read((char*)&length, sizeof(length));
    writtenBooksCount = length;

    //read writtenBooksLimit
    length = 0;
    file.read((char*)&length, sizeof(length));
    writtenBooksLimit = length;

    // read writtenBooks
    writtenBooks = resizeArray(writtenBooks, INITIAL_OBJ_SIZE, writtenBooksLimit);
    for (int i = 0; i < writtenBooksCount; i++)
    {
        writtenBooks[i].readFromFile(file);
    }
}

