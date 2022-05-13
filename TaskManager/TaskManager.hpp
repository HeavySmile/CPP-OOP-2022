#pragma once
#include "Task.hpp"
#include <iostream>
#include <vector>
using namespace std;

class TaskManager
{
private:
    size_t id_counter;
    vector<Task> tasks;
    vector<Label> labels;

public:
    TaskManager();

    void loadDataFromFile(const char*);
    void saveDataToFile(const char*) const;

    Task getTaskById(size_t) const;
    void changeName(size_t, const string&);
    void changeDescription(size_t, const string&);
    void changeDueDate(size_t, const DateTime&);
    void changeLabel(size_t, const Label*);
    void changeWeight(size_t, uint8_t);

    friend istream& operator>>(istream&, TaskManager&);
    friend ostream& operator<<(ostream&, const TaskManager&);
};