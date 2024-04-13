﻿#include <iostream>
#include "view.h"

int main()
{
    View* view = new View();
    Controller* controller = new Controller();
    if (!controller->addModel("dbfilename"))
    {
        std::cout << "Can't connect to database\n";
        return 0;
    }

    view->addController(controller);
    view->start();
    return 0;
}

