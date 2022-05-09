#include "Book.hpp"
#include "Constants.hpp"
#include "Helpers.hpp"
#include <iostream>
#include <fstream>
using namespace std;

Book::Book()
{
    name = nullptr;
    author = nullptr;
    ratings = new char*[INITIAL_OBJ_SIZE];
    for (int i = 0; i < INITIAL_OBJ_SIZE; i++)
    {
        ratings[i] = nullptr;
    }
    pages = new Page[INITIAL_OBJ_SIZE];
    comments = new char*[INITIAL_OBJ_SIZE];
    for (int i = 0; i < INITIAL_OBJ_SIZE; i++)
    {
        comments[i] = nullptr;
    }
    commentsCount = 0;
    pagesCount = 0;
    ratingsCount = 0;
    commentsLimit = INITIAL_OBJ_SIZE;
    ratingsLimit = INITIAL_OBJ_SIZE;
    pagesLimit = INITIAL_OBJ_SIZE;
}
Book::Book(const char* name, const char* author)
{
    this->name = new char[strlen(name) + 1];
    this->author = new char[strlen(author) + 1];
    strcpy(this->name, name);
    strcpy(this->author, author);        
    this->comments = new char*[INITIAL_OBJ_SIZE];
    for (int i = 0; i < INITIAL_OBJ_SIZE; i++)
    {
        comments[i] = nullptr;
    }
    this->ratings = new char*[INITIAL_OBJ_SIZE];
    for (int i = 0; i < INITIAL_OBJ_SIZE; i++)
    {
        ratings[i] = nullptr;
    }
    this->pages = new Page[INITIAL_OBJ_SIZE];
    this->commentsCount = 0;
    this->pagesCount = 0;
    this->ratingsCount = 0;
    this->commentsLimit = INITIAL_OBJ_SIZE;
    this->ratingsLimit = INITIAL_OBJ_SIZE;
    this->pagesLimit = INITIAL_OBJ_SIZE;
}
Book::~Book()
{
    delete[] name;
    delete[] author;
    delete[] pages;
    for (int i = 0; i < commentsLimit; i++) delete[] comments[i];
    delete[] comments;
    for (int i = 0; i < ratingsLimit; i++) delete[] ratings[i];
    delete[] ratings;
}

Book& Book::operator=(const Book& book)
{
    if(this != &book)
    {
        delete[] name;
        delete[] author;
        delete[] pages;
        for (int i = 0; i < commentsLimit; i++) delete[] comments[i];
        delete[] comments; 
        for (int i = 0; i < ratingsLimit; i++) delete[] ratings[i];
        delete[] ratings;

        if(book.name == nullptr) this->name = nullptr;
        else 
        {
            this->name = new char[strlen(book.name) + 1];
            strcpy(this->name, book.name);
        }
         
        if(book.author == nullptr) this->author = nullptr;
        else 
        {
            this->author = new char[strlen(book.author) + 1]; 
            strcpy(this->author, book.author);
        }
        
        
        this->pages = new Page[book.pagesLimit];
        this->comments = new char*[book.commentsLimit];
        for (int i = 0; i < book.commentsLimit; i++)
        {
            this->comments[i] = nullptr;
        }
        this->ratings = new char*[book.ratingsLimit];
        for (int i = 0; i < book.ratingsLimit; i++)
        {
            this->ratings[i] = nullptr;
        }
        
        for (int i = 0; i < book.pagesCount; i++)
        {
            this->pages[i] = book.pages[i];
        }
        for (int i = 0; i < book.commentsCount; i++)
        {
            if(book.comments[i] == nullptr) this->comments[i] = nullptr;
            else 
            {
                this->comments[i] = new char[strlen(book.comments[i]) + 1];
                strcpy(this->comments[i], book.comments[i]);
            }
        }
        
        for (int i = 0; i < book.ratingsCount; i++)
        {
            if(book.ratings[i] == nullptr) this->ratings[i] = nullptr;
            else 
            {
                this->ratings[i] = new char[strlen(book.ratings[i]) + 1];
                strcpy(this->ratings[i], book.ratings[i]);
            }
        }
        
        this->ratingsCount = book.ratingsCount;
        this->commentsCount = book.commentsCount;
        this->pagesCount = book.pagesCount;
        
        this->pagesLimit = book.pagesLimit;
        this->commentsLimit = book.commentsLimit;
        this->ratingsLimit = book.ratingsLimit;
    }

    return *this;
}

char* Book::getBookName() const
{
    return name;
}
void Book::setName(const char* name)
{
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}
void Book::setAuthor(const char* author)
{
    delete[] this->author;
    this->author = new char[strlen(author) + 1];
    strcpy(this->author, author);
}
void Book::removePage(const int page)
{
    if(pagesCount == 0) 
    {
        cout << "No pages left" << endl;
        return;
    }
    
    if(page == pagesCount)
    {
        --pagesCount;
    }
    else if(page == 1)
    {
        for (int i = 1; i < pagesCount; i++)
        {
            pages[i - 1] = pages[i];
        }
        --pagesCount;
    }
    else
    {
        for (int i = page; i < pagesCount; i++)
        {
            pages[i - 1] = pages[i];
        }
        --pagesCount;
    }

}
void Book::editPage(const int page)
{
    char* text = new char[MAX_PAGE_SYMBOLS];
    cout << "Insert new page content: ";
    cin.ignore();
    cin.getline(text, MAX_PAGE_SYMBOLS);
    pages[page - 1].setText(text);
    delete[] text;
}
void Book::addPage()
{
    // if array is too short to fit new data
    if(pagesCount == pagesLimit)
    {
        pages = resizeArray(pages, pagesLimit, pagesLimit*2);
        pagesLimit *= 2;
    }
    
    char* text = new char[MAX_PAGE_SYMBOLS];
    cout << "  >>Page " << pagesCount + 1 << " : ";
    //cin.ignore();
    cin.getline(text, MAX_PAGE_SYMBOLS);
    
    pages[pagesCount].setText(text);
    ++pagesCount;
    delete[] text;
}
void Book::addComment(const char* comment)
{
    // if array is too short to fit new data
    if(commentsCount == commentsLimit)
    {
        comments = resizeArray(comments, commentsLimit, commentsLimit*2);
        commentsLimit *= 2;
    }
    
    comments[commentsCount] = new char[strlen(comment) + 1];
    strcpy(comments[commentsCount], comment);
    ++commentsCount;
}
void Book::rateBook(const char* rate_str)
{
    // if array is too short to fit new data
    if(ratingsCount == ratingsLimit)
    {
        ratings = resizeArray(ratings, ratingsLimit, ratingsLimit*2);
        ratingsLimit *= 2;
    }
    
    ratings[ratingsCount] = new char[strlen(rate_str) + 1];
    strcpy(ratings[ratingsCount], rate_str);
    ++ratingsCount;
}
void Book::readBook() const
{
    char buffer[2];
    int pageIdx = 0;
    pages[pageIdx].printPage(pageIdx + 1);
    do
    {
        cout << ">> ";
        cin >> buffer;
        if(!strcmp(buffer, "q")) break;
        if(!strcmp(buffer, "n"))
        {
            if(pageIdx >= pagesCount - 1)
            {
                pages[pagesCount - 1].printPage(pagesCount);
                continue;    
            } 
            ++pageIdx;
        }
        if(!strcmp(buffer, "p"))
        {
            if(pageIdx <= 0) 
            {
                pages[0].printPage(1);
                continue;
            }
            --pageIdx;
        }
        
        if(strcmp(buffer, "p") && strcmp(buffer, "q") && strcmp(buffer, "n"))
        {
            cout << "No such command" << endl;
            continue;
        }

        pages[pageIdx].printPage(pageIdx + 1);
    } 
    while (strcmp(buffer, "q"));
}

void Book::printRates() const
{
    for (int i = 0; i < ratingsCount; i++)
    {
        cout << ratings[i] << endl;
    }
}
void Book::printBook() const
{
    if(name != nullptr) cout << name << endl;
    else cout << endl;
    
    if(author != nullptr) cout << author << endl;
    else cout << endl;
    
    for (int i = 0; i < ratingsCount; i++)
    {
        cout << ratings[i] << " ";
    }
    cout << endl;
    cout << ratingsCount << endl;
    for (int i = 0; i < commentsCount; i++)
    {
        cout << comments[i] << " ";
    }
    cout << endl;
    cout << commentsCount << endl;
    for (int i = 0; i < pagesCount; i++)
    {
        cout << endl;
        pages[i].printPage(i + 1);
    }
    cout << endl;
    cout << pagesCount << endl;
}
void Book::printComments() const
{
    for (int i = 0; i < commentsCount; i++)
    {
        cout << comments[i] << endl;
    }
}

void Book::readFromFile(ifstream& file)
{
    int length = 0;
    
    // read book's name
    file.read((char*)&length, sizeof(length));
    delete[] name;
    name = new char[length ];
    file.read(name, length);
    
    // read book's author
    file.read((char*)&length, sizeof(length));
    delete[] author;
    author = new char[length];
    file.read(author, length);
    
    // read ratings
    file.read((char*)&ratingsCount, sizeof(int));
    for (int i = 0; i < ratingsCount; i++)
    {
        int inn_length = 0;
        file.read((char*)&inn_length, sizeof(inn_length));
        delete[] ratings[i];
        ratings[i] = new char[inn_length];
        file.read(ratings[i], inn_length);
    }

    // read comments
    file.read((char*)&commentsCount, sizeof(int));
    for (int i = 0; i < commentsCount; i++)
    {
        int inn_length = 0;
        file.read((char*)&inn_length, sizeof(inn_length));
        delete[] comments[i];
        comments[i] = new char[inn_length];
        file.read(comments[i], inn_length);
    }
    
    // read pages
    file.read((char*)&pagesCount, sizeof(int));
    pages = new Page[INITIAL_OBJ_SIZE];
    for (int i = 0; i < pagesCount; i++)
    {
        int inn_length = 0;
        file.read((char*)&inn_length, sizeof(inn_length));
        char* text = new char[inn_length];
        file.read(text, inn_length);
        pages[i].setText(text);
    }
    
}
void Book::writeToFile()
{
    ofstream file("Data.bin", ios::out | ios::binary | ios::app);
    
    if(!file)
    {
        cout << "Failed to serialize data" << endl;
        return;
    }
    
    // write name
    int length = strlen(name) + 1;
    file.write((const char*)&length, sizeof(length));
    file.write(name, length);
    
    // write author
    length = strlen(author) + 1;
    file.write((const char*)&length, sizeof(length));
    file.write(author, length);
    
    // write ratings
    length = ratingsCount;
    file.write((const char*)&length, sizeof(length));
    for (int i = 0; i < ratingsCount; i++)
    {
        int inn_length = strlen(ratings[i]) + 1;
        file.write((const char*)&inn_length, sizeof(inn_length));
        file.write(ratings[i], inn_length);
    }

    // write comments
    length = commentsCount;
    file.write((const char*)&length, sizeof(length));
    for (int i = 0; i < commentsCount; i++)
    {
        int inn_length = strlen(comments[i]) + 1;
        file.write((const char*)&inn_length, sizeof(inn_length));
        file.write(comments[i], inn_length);
    }
    
    // write pages
    length = pagesCount;
    file.write((const char*)&length, sizeof(length));
    file.close();
    for (int i = 0; i < pagesCount; i++)
    {
        pages[i].writeToFile();
    }
}
