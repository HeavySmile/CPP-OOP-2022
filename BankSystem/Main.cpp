#include "NormalAccount.hpp"
#include "SavingsAccount.hpp"
#include "PrivilegeAccount.hpp"
#include "Bank.hpp"
#include <iostream>
#include <ctime>
#include "Log.hpp"
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
                Account* current_acc = bank.authenticate();
                double withdrawnAmount;
                
                cout << "Insert amount to withdraw: ";
                cin >> withdrawnAmount;
                
                current_acc->withdraw(withdrawnAmount);
            }
            else if(!strcmp(buffer, "b"))
            {
                cout << endl;
                bank.listAccounts();
            }
            else if(!strcmp(buffer, "c"))
            {
                cout << "   ";
                bank.listCustomerAccounts();
            }
        }
        else if(!strcmp(buffer, "4"))
        {
            bank.display();
        }
    } 
    while (strcmp(buffer, "5"));
    

    return 0;
}