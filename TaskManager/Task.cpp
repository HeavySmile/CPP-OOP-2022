#include "Task.hpp"
#include <iostream>
using namespace std;

Task::Task()
{
    id = 0;
    name = "";
    description = "";
    due_date = DateTime();
    label = nullptr;
    weight = 0;
}
Task::Task(size_t id, string name, string description, DateTime dueDate, const Label* label, uint8_t weight)
{
    this->id = id;
    this->name = name;
    this->description = description;
    this->due_date = dueDate;
    this->label = label;
    this->weight = weight;
}

size_t Task::getId() const
{
    return id;
}
string Task::getName() const
{
    return name;
}
string Task::getDescription() const
{
    return description;
}
DateTime Task::getDueDate() const
{
    return due_date;
}
Label Task::getLabel() const
{
    return *label;
}
uint8_t Task::getWeight() const
{
    return weight;
}

void Task::setId(size_t id)
{
    this->id = id;
}
void Task::setName(const string& name)
{
    this->name = name;
}
void Task::setDescription(const string& description)
{
    this->description = description;
}
void Task::setDueDate(const DateTime& dueDate)
{
    this->due_date = dueDate;
}
void Task::setLabel(const Label* label)
{
    this->label = label;
}
void Task::setWeight(uint8_t weight)
{
    this->weight = weight;
}

bool Task::operator<(const Task& task)
{
    return this->weight < task.weight;
}

istream& operator>>(istream& is, Task& task)
{
    int weight;
    cout << "Insert id: ";
    is >> task.id;
    cout << "Insert name: ";
    is.ignore();
    getline(is, task.name);
    cout << "Insert description: " << endl;
    getline(is, task.description);
    cout << "Insert deadline: " << endl;
    is >> task.due_date;
    cout << "Insert weight: ";
    is >> weight;
    
    task.weight = (uint8_t)weight;
    return is;
}
ostream& operator<<(ostream& os, const Task& task)
{
    os << "id: "<< task.id << endl;
    os << "name: "<< task.name << endl;
    os << "description: " << endl;
    os << task.description << endl;
    os << "due to: "<< task.due_date << endl;
    // os << task.label->name << endl;
    os << "weight: "<< (unsigned int)task.weight << endl;
    return os;
}

