#include "Bank.hpp"
#include "Constants.hpp"
#include <iostream>
using namespace std;

int main()
{
    Bank bank("my bank", "sofia");
    
    cout << "1. Edit" << endl;
    cout << "   a. Customer" << endl;
    cout << "      i. Add new customer" << endl;
    cout << "      ii. Delete customer" << endl;
    cout << "   b. Account" << endl;
    cout << "      i. Add new account" << endl;
    cout << "      ii. Delete account" << endl;
    cout << "2. List" << endl;
    cout << "   a. List all customers" << endl;
    cout << "   b. List all accounts" << endl;
    cout << "   c. List all customer accounts" << endl;
    cout << "   d. List log" << endl;
    cout << "3. Action" << endl;
    cout << "   a. Withdraw from account" << endl;
    cout << "   b. Deposit to account" << endl;
    cout << "   c. Transfer" << endl;
    cout << "4. Display info for the bank" << endl;
    cout << "5. Quit" << endl;
    cout << endl;
    
    char buffer[MAX_INPUT_SIZE];
    do
    {
        cout << "> ";
        cin >> buffer;
        
        if(!strcmp(buffer, "1"))
        {
            cin >> buffer;

            if(!strcmp(buffer, "a"))
            {
                cin >> buffer;

                if(!strcmp(buffer, "i"))
                {
                    cin.ignore();
                    bank.addCustomer();
                }
                else if(!strcmp(buffer, "ii"))
                {
                    cin.ignore();
                    bank.deleteCustomer();
                }
            }
            else if(!strcmp(buffer, "b"))
            {
                cin >> buffer;

                if(!strcmp(buffer, "i"))
                {
                    cin.ignore();
                    bank.addAccount();
                }
                else if(!strcmp(buffer, "ii"))
                {
                    cin.ignore();
                    bank.deleteAccount();
                }
            }
        }
        else if(!strcmp(buffer, "2"))
        {
            cin >> buffer;

            if(!strcmp(buffer, "a"))
            {
                cin.ignore();
                bank.listCustomers();
            }
            else if(!strcmp(buffer, "b"))
            {
                cin.ignore();
                bank.listAccounts();
            }
            else if(!strcmp(buffer, "c"))
            {
                cin.ignore();
                bank.listCustomerAccounts();
            }
            else if(!strcmp(buffer, "d"))
            {
                bank.listLog();
            }
        }
        else if(!strcmp(buffer, "3"))
        {
            cin >> buffer;
            
            if(!strcmp(buffer, "a"))
            {
                bank.withdrawFromAccount();
            }
            else if(!strcmp(buffer, "b"))
            {
                bank.depositToAccount();
            }
            else if(!strcmp(buffer, "c"))
            {
                char* fromIBAN = new char[MAX_INPUT_SIZE];
                char* toIBAN = new char[MAX_INPUT_SIZE];
                double amount;

                cout << "Insert transfer amount : ";
                cin >> amount;
                cout << "Insert IBAN to withdraw from : ";
                cin >> fromIBAN;
                cout << "Insert IBAN to deposit in : ";
                cin >> toIBAN;
                
                bank.transfer(amount, fromIBAN, toIBAN);

                delete[] fromIBAN;
                delete[] toIBAN;
            }
        }
        else if(!strcmp(buffer, "4"))
        {
            bank.display();
        }
    } 
    while (strcmp(buffer, "5"));
    
    bank.exportLog("Log.txt");

    return 0;
}