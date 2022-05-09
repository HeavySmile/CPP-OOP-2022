#include <iostream>
#include <fstream>
#include "Kindle.hpp"
#include "Helpers.hpp"
#include "Constants.hpp"
using namespace std;

int main()
{
    Kindle kindle;
    int currentLoginIdx = -1;
    
    kindle.deserialize();
    
    char* buffer = new char[MAX_COMMAND_SIZE];
    do
    {       
        cout << "> ";
        cin >> buffer;
        
        if(!strcmp(buffer, "signup"))
        {
            if(currentLoginIdx != -1) cout << "Log out first" << endl;
            else kindle.addUser(); 
        }
        else if(!strcmp(buffer, "login"))
        {
            if(currentLoginIdx != -1) cout << "Log out first" << endl;
            else
            {
                char* name = new char[MAX_USERNAME_PASS_SIZE];
                char* pass = new char[MAX_USERNAME_PASS_SIZE];
                cout << "> Enter username: ";
                cin >> name;
                cout << "> Enter password: ";
                cin >> pass;  
                
                User user(name, pass);
                if(kindle.checkLogin(user))
                {
                    currentLoginIdx = kindle.findUserIdx(user);
                    cout << "   Welcome" << endl;
                }
                else cout << "   Incorrect username or password" << endl;
            
                delete[] name;
                delete[] pass;
            }
        }
        else if(!strcmp(buffer, "read"))
        {
            if(currentLoginIdx == -1) cout << "Please, log in first" << endl;
            else kindle.readBook(currentLoginIdx);
        }
        else if(!strcmp(buffer, "write"))
        {
            if(currentLoginIdx == -1) cout << "Please, log in first" << endl;
            else kindle.writeNewBook(currentLoginIdx);
        }
        else if(!strcmp(buffer, "viewRead")) 
        {
            if(currentLoginIdx == -1) cout << "Please, log in first" << endl;
            else kindle.printUserReadBooks(currentLoginIdx);
        }
        else if(!strcmp(buffer, "viewWritten")) 
        {
            if(currentLoginIdx == -1) cout << "Please, log in first" << endl;
            else kindle.printUserWrittenBooks(currentLoginIdx);
        }
        else if(!strcmp(buffer, "view")) 
        {
            if(currentLoginIdx == -1) cout << "Please, log in first" << endl;
            else kindle.printAvailableBooks();
        }
        else if(!strcmp(buffer, "rate")) 
        {
            if(currentLoginIdx == -1) cout << "Please, log in first" << endl;
            else kindle.rateBook(currentLoginIdx);
        }
        else if(!strcmp(buffer, "rates")) 
        {
            if(currentLoginIdx == -1) cout << "Please, log in first" << endl;
            else kindle.getBookRates();
        }
        else if(!strcmp(buffer, "comment")) 
        {
            if(currentLoginIdx == -1) cout << "Please, log in first" << endl;
            else kindle.commentBook(currentLoginIdx);
        }
        else if(!strcmp(buffer, "addPage")) 
        {
            if(currentLoginIdx == -1) cout << "Please, log in first" << endl;
            else kindle.addPageToBook(currentLoginIdx);
        }
        else if(!strcmp(buffer, "editPage")) 
        {
            if(currentLoginIdx == -1) cout << "Please, log in first" << endl;
            else kindle.editPage(currentLoginIdx);
        }
        else if(!strcmp(buffer, "removePage")) 
        {
            if(currentLoginIdx == -1) cout << "Please, log in first" << endl;
            else kindle.removePage(currentLoginIdx);
        }
        else if(!strcmp(buffer, "comments")) 
        {
            if(currentLoginIdx == -1) cout << "Please, log in first" << endl;
            else kindle.getComments();
        }
        else if(!strcmp(buffer, "logout"))
        {
            if(currentLoginIdx == -1) cout << "Please, log in first" << endl;
            else currentLoginIdx = -1;    
        }
    } 
    while (strcmp(buffer, "exit"));
    
    kindle.serialize();

    delete[] buffer;
    return 0;
}