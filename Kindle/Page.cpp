#include "Page.hpp"
#include <fstream>
#include <iostream>
using namespace std;

Page::Page()
{
    text = nullptr;
}
Page::~Page()
{
    delete[] text;
}

Page& Page::operator=(const Page& page)
{
    if(this != &page)
    {
        delete[] this->text;
        if(page.text == nullptr) this->text = nullptr;
        else
        {
            this->text = new char[strlen(page.text) + 1];
            strcpy(this->text, page.text);
        } 
    }

    return *this;
}

void Page::printPage(const int pageNumber) const
{
    cout << endl;
    cout << "Page " << pageNumber << endl;
    cout <<  "-----------------------------------------------------------------------------" << endl;
    if(text != nullptr) cout << text << endl;
    cout << endl;
}
void Page::setText(const char* text)
{
    delete[] this->text;
    this->text = new char[strlen(text) + 1];
    strcpy(this->text, text);
}
void Page::writeToFile()
{
    ofstream file("Data.bin", ios::out | ios::binary | ios::app);
    int length = strlen(text) + 1;
    file.write((const char*)&length, sizeof(length));
    file.write(text, length);
    file.close();
}
