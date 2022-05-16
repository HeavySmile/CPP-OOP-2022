#include "TaskManager.hpp"
#include <ctime>
#include <fstream>

#define GREEN   "\033[32m"      /* Green */
#define RED     "\033[31m"      /* Red */
#define RESET   "\033[0m"

TaskManager::TaskManager()
{
    id_counter = 0;
    labels.push_back(Label("Done"));
    labels.push_back(Label("In progress"));
    labels.push_back(Label("Open"));
}

void TaskManager::saveDataToFile(const char* str) const
{
    ofstream file(str, ios::out | ios::binary | ios::trunc);

    // write id_counter
    file.write((const char*)&id_counter, sizeof(id_counter));

    // write labels count
    int length = labels.size();
    file.write((const char*)&length, sizeof(length));
    
    string buffer;
    // write labels
    for (int i = 0; i < labels.size(); i++)
    {
        length = labels[i].name.size();
        file.write((const char*)&length, sizeof(length));
        file << labels[i].name;
    }
    
    // write tasks count
    length = tasks.size();
    file.write((const char*)&length, sizeof(length));

    // write tasks
    for (int i = 0; i < tasks.size(); i++)
    {
        // write task id
        size_t id = tasks[i].getId();
        file.write((const char*)&id, sizeof(id));
    
        // write task name
        length = tasks[i].getName().size();
        file.write((const char*)&length, sizeof(length));
        file << tasks[i].getName();
        
        // write description
        length = tasks[i].getDescription().size();
        file.write((const char*)&length, sizeof(length));
        file << tasks[i].getDescription();
        
        // write due date
        Date date = tasks[i].getDueDate().getDate();
        Time time = tasks[i].getDueDate().getTime();
        file.write((const char*)&date.day, sizeof(date.day));
        file.write((const char*)&date.month, sizeof(date.month));
        file.write((const char*)&date.year, sizeof(date.year));
        file.write((const char*)&time.h, sizeof(time.h));
        file.write((const char*)&time.m, sizeof(time.m));
        file.write((const char*)&time.s, sizeof(time.s));

        // write label
        length = tasks[i].getLabel().name.size();
        file.write((const char*)&length, sizeof(length));
        file << tasks[i].getLabel().name;
        
        // write weight
        uint8_t weight = tasks[i].getWeight();
        file.write((const char*)&weight, sizeof(weight));
    }
    
    file.close();
}

Task TaskManager::getTaskById(size_t id) const
{
    return tasks[id];
}
void TaskManager::changeName(size_t id, const string& name)
{
    tasks[id].setName(name);
}
void TaskManager::changeDescription(size_t id, const string& description)
{
    tasks[id].setDescription(description);
}
void TaskManager::changeDueDate(size_t id, const DateTime& due_date)
{
    tasks[id].setDueDate(due_date);
}
void TaskManager::changeLabel(size_t id, const Label* label)
{
    tasks[id].setLabel(label);
}
void TaskManager::changeWeight(size_t id, uint8_t weight)
{
    tasks[id].setWeight(weight);
}

void TaskManager::printLabels()
{
    for (int i = 0; i < labels.size(); i++)
    {
        if(i != 0) cout << " | ";
        cout << labels[i].name;
    }
    cout << endl;
}
void TaskManager::printTasks()
{
    time_t t = time(0);
    tm* now = localtime(&t);
    
    Date currentDate((uint8_t)now->tm_mday, (uint8_t)(now->tm_mon + 1), now->tm_year + 1900);
    Time currentTime((uint8_t)now->tm_hour, (uint8_t)now->tm_min, (uint8_t)now->tm_sec);

    DateTime currentDateTime(currentDate, currentTime);
    
    // cout << (now->tm_year + 1900) << endl;
    // cout << (now->tm_mon + 1) << endl;
    // cout << now->tm_mday << endl;
    // cout << now->tm_hour << endl;
    // cout << now->tm_min << endl;
    // cout << now->tm_sec << endl;
    
    cout << endl;
    for (int i = 0; i < tasks.size(); i++)
    {
        cout << "id: " << tasks[i].getId() << endl;
        cout << "name: " << tasks[i].getName() << endl;
        cout << "description: " << endl;
        cout << tasks[i].getDescription() << endl;
        cout << "due to: ";
        
        if(tasks[i].getDueDate() < currentDateTime && (tasks[i].getLabel().name.compare("Done"))) 
        {
            cout << RED;
        }
        else cout << GREEN;
        
        cout << tasks[i].getDueDate() << RESET << endl;
        cout << "label: " << tasks[i].getLabel().name << endl;
        cout << "weight: " << (unsigned int)(tasks[i].getWeight()) << endl;
        cout << endl;
    } 
}
void TaskManager::addNewTask()
{
    string name, description, label;
    Label* label_p;
    
    int weight, day, month, year, hour, minute, second;
    
    cout << "Insert name: ";
    getline(cin, name);
    cout << "Insert description: " << endl;
    getline(cin, description);
    cout << "Insert deadline: " << endl;
    cout << "   day: ";
    cin >> day;
    cout << "   month: ";
    cin >> month;
    cout << "   year: ";
    cin >> year;
    cout << "   hour: ";
    cin >> hour;
    cout << "   minute: ";
    cin >> minute;
    cout << "   second: ";
    cin >> second;
    cout << "Insert label: ";
    cin.ignore();
    getline(cin, label);
    for (int i = 0; i < labels.size(); i++)
    {
        if(!label.compare(labels[i].name))
        {
            label_p = &labels[i];
        }
    }
    cout << "Insert weight: ";
    cin >> weight;

    DateTime dueDate(Date((uint8_t)day, (uint8_t)month, year), Time((uint8_t)hour, (uint8_t)minute, (uint8_t)second));
    tasks.push_back(Task(id_counter, name, description, dueDate, label_p, (uint8_t)weight));
    ++id_counter;
}
void TaskManager::addNewLabel()
{
    string name;
    
    cout << "Insert label: ";
    getline(cin, name);

    labels.push_back(Label(name));
}

istream& operator>>(istream& is, TaskManager& tm)
{
    for (int i = 0; i < tm.tasks.size(); i++)
    {
        is >> tm.tasks[i];
    }
    
    return is;
}
ostream& operator<<(ostream& os, const TaskManager& tm)
{
    for (int i = 0; i < tm.tasks.size(); i++)
    {
        os << tm.tasks[i];
    }

    return os;
}