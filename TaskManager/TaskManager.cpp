#include "TaskManager.hpp"

TaskManager::TaskManager()
{
    id_counter = 0;
    labels.push_back(Label("Done"));
    labels.push_back(Label("In progress"));
    labels.push_back(Label("Open"));
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
    cout << endl;
    for (int i = 0; i < tasks.size(); i++)
    {
        cout << "id: " << tasks[i].getId() << endl;
        cout << "name: " << tasks[i].getName() << endl;
        cout << "description: " << endl;
        cout << tasks[i].getDescription() << endl;
        cout << "due to: " << tasks[i].getDueDate() << endl;
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