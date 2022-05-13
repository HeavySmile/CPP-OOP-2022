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

istream& operator>>(istream& is, TaskManager& tm)
{

}
ostream& operator<<(ostream& os, const TaskManager tm)
{

}