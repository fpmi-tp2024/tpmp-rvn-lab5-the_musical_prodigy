#include <iostream>
#include <sqlite3.h>
#include <SQLiteCpp/SQLiteCpp.h>
#include "include/Model.h"

int main()
{
    Model* model = new Model();
    model->addDatabase("music_salon_v2.0.db");
    return 0;
}
