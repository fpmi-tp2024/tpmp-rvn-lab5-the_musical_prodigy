#include <iostream>
#include "../include/View/view.h"

int main()
{
    View* view = new View();
    Controller* controller = new Controller();
    if (!controller->addModel("music_salon_v2.0.db"))
    {
        std::cout << "Can't connect to database\n";
        return 0;
    }

    view->addController(controller);
    view->start();
    return 0;
}

