#pragma once
#include <iostream>
using namespace std;

class String
{
public:
    char* string;
    String();
    String(const char*);
    String(const String&);
    String& operator=(const String&);
    String& operator=(const char* string);
    String operator+(const String&);
    String& operator+=(const String&);
    bool operator==(const String&);
    bool operator!=(const String&);
    bool operator<(const String&);
    bool operator<=(const String&);
    bool operator>(const String&);
    bool operator>=(const String&);
    char operator[](size_t);
    ~String();

    int length() const;
    bool empty() const;
    const char* c_str() const;
    
    void append(const char);
    void clear();
    
    friend ostream& operator<<(ostream& os, const String& string);
    static bool compare(String&, String&);
};

ostream& operator<<(ostream& os, const String& string);

int strLen(const char*);
void strCpy(char*, const char*);
    