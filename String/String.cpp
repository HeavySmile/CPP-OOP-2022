#include "String.hpp"
#include <iostream>
using namespace std;

String::String()
{
    string = nullptr;
}
String::String(const char* string)
{
    this->string = new char[strLen(string) + 1];
    strCpy(this->string, string);
    this->string[strLen(string)] = '\0';   
}
String::String(const String& string)
{
    this->string = new char[string.length() + 1];
    strCpy(this->string, string.string);
    this->string[string.length()] = '\0';
}
String& String::operator=(const String& string)
{
    if(this != &string)
    {
        delete[] this->string;
        this->string = new char[string.length() + 1];
        strCpy(this->string, string.string);
        this->string[string.length()] = '\0';
    }

    return *this;
}
String& String::operator=(const char* string)
{
    this->string = new char[strLen(string) + 1];
    strCpy(this->string, string);
    this->string[strLen(string)] = '\0';

    return *this;
}
String String::operator+(const String& string)
{
    char* newString = new char[this->length() + string.length() + 1];
    int i, k;
    for (i = 0, k = 0; i < this->length() + string.length(); k++, i++)
    {
        if(i == this->length()) k = 0;
        if(i < this->length())
        {
            newString[i] = this->string[k];
        }
        else
        {
            newString[i] = string.string[k];
        }
    }
    newString[i] = '\0';

    return String(newString);
}
String& String::operator+=(const String& string)
{
    *this = *this + string;
    return *this;
} 
bool String::operator==(const String& string)
{
    return !strcmp(this->string, string.string);
}
bool String::operator!=(const String& string)
{
    return strcmp(this->string, string.string);
}
bool String::operator<(const String& string)
{
    return this->string < string.string;
}
bool String::operator<=(const String& string)
{
    return this->string <= string.string;
}
bool String::operator>(const String& string)
{
    return this->string > string.string;
}
bool String::operator>=(const String& string)
{
    return this->string >= string.string;
}
char String::operator[](size_t idx)
{
    return this->string[idx];
}
String::~String()
{
    delete[] string;
}

int String::length() const
{
    return strLen(this->string);
}
bool String::empty() const
{
    return this->length() == 0 ? true : false;
}
const char* String::c_str() const
{
    return this->string;
}

void String::clear()
{
    delete[] this->string;
    this->string = nullptr;
}
void String::append(const char ch)
{
    int curr_length = this->length();
    char* newString = new char[curr_length + 2];
    strCpy(newString, this->string);
    newString[curr_length] = ch;
    newString[curr_length + 1] = '\0';

    delete[] this->string;
    this->string = newString;
}

ostream& operator<<(ostream& os, const String& string)
{
    if(string.string == nullptr) os << "";
    else os << string.string;
    
    return os;
}
bool String::compare(String& str1, String& str2)
{
    int str1_length = str1.length();
    int str2_length = str2.length();
    
    if(str1_length != str2_length) return false;
    
    for (int i = 0; i < str1_length; i++)
    {
        if(str1[i] != str2[i]) return false;    
    }
    
    return true;
}

int strLen(const char* str)
{
   int count = 0;
   while(str[count] != '\0') ++count;

   return count; 
}
void strCpy(char* dest, const char* source)
{
    int source_length = strLen(source);
    delete[] dest;
    
    if(source_length > strLen(dest)) dest = new char[source_length + 1];
    
    int i;
    for (i = 0; i < source_length; i++)
    {
        dest[i] = source[i];
    }
    dest[i] = '\0';
}