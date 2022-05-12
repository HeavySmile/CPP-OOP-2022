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
    int day, month, year, hour, minute, second;
    Label* label = new Label;
    is >> task.id >> task.name >> task.description >> day >> month >> year;
    is >> hour >> minute >> second >> label->name >> task.weight;
    Date date;
    date.day = day;
    date.month = month;
    date.year = year;
    Time time;
    time.h = hour;
    time.m = minute;
    time.s = second;
    
    task.setDueDate(DateTime(date, time));
    return is;
}
ostream& operator<<(ostream& os, const Task& task)
{
    os << task.id << endl;
    os << task.name << endl;
    os << task.description << endl;
    os << task.due_date << endl;
    os << task.label->name << endl;
    os << task.weight << endl;
    return os;
}

