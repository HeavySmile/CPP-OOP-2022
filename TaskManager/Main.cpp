#include <iostream>
#include <ctime>
#include "DateTime.hpp"
#include "Task.hpp"
#include "TaskManager.hpp"
using namespace std;

#define GREEN   "\033[32m"      /* Green */
#define RED     "\033[31m"      /* Red */
#define RESET   "\033[0m"

int main()
{
    TaskManager tm;

    tm.loadDataFromFile("Data.bin");

    string buffer;
    do
    {
        cout << "> ";
        getline(cin, buffer);
        if(!buffer.compare("create new task"))
        {
            tm.addNewTask();
            cin.ignore();
        }
        if(!buffer.compare("view tasks"))
        {
            tm.printTasks();
        }
        if(!buffer.compare("create new label"))
        {
            tm.addNewLabel();
        }
        if(!buffer.compare("sort tasks"))
        {
            tm.sort();
        }
        if(!buffer.compare("remove label"))
        {
            tm.removeLabel();
        }
        if(!buffer.compare("view labels"))
        {
            tm.printLabels();
        }
        if(!buffer.compare("change label"))
        {
            size_t id;
            string label;

            cout << "Insert task's id: ";
            cin >> id;
            cout << "Insert new label: ";
            cin.ignore();
            getline(cin, label);
            
            int label_idx = tm.findLabelByName(label);
            if(label_idx < 0) throw underflow_error("No label found");

            tm.changeLabel(id, tm.getLabelByIdx(label_idx));
        }
    } 
    while (buffer.compare("exit"));
    
    tm.saveDataToFile("Data.bin");
    
    return 0;
}