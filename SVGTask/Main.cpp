#include "Figures.hpp"
#include "Constants.hpp"
#include <iostream>
using namespace std;

int main()
{
    
    Figures container;
    
    container.readFromFile("Data.svg");

    char buffer[MAX_COMMAND_SIZE];
    do
    {
        cout << "> ";
        cin >> buffer;

        if(!strcmp(buffer, "create"))
        {
            container.create();
        }
        else if(!strcmp(buffer, "print"))
        {
            container.print();
        }
        else if(!strcmp(buffer, "within"))
        {
            cin >> buffer;
            if(!strcmp(buffer, "rectangle"))
            {
                container.withinRectangle();
            }
            else if(!strcmp(buffer, "circle"))
            {
                container.withinCircle();
            }
        }
        else if(!strcmp(buffer, "pointIn"))
        {
            container.pointIn();
        }
        else if(!strcmp(buffer, "translate"))
        {
            double x_change, y_change;
            cin >> x_change >> y_change;
            container.translateAll(x_change, y_change);
        }
        else if(!strcmp(buffer, "erase"))
        {
            container.erase();
        }
        else if(!strcmp(buffer, "pers"))
        {
            container.pers();
        }
        else if(!strcmp(buffer, "areas"))
        {
            container.areas();
        }
    } 
    while (strcmp(buffer, "exit"));
    
    container.writeToFile("Data.svg");

    return 0;
}