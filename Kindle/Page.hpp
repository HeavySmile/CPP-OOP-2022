#pragma once

class Page
{
private:
    char* text;
public:
    Page();
    ~Page();

    Page& operator=(const Page&);

    void printPage(const int) const;
    void setText(const char*);
    void writeToFile();
    void readFromFile(const char*, int&);

};