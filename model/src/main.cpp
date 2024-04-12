#include "../include/Model.h"

int main()
{
    Model *model = new Model();
    std::cout << model->addDatabase("../database/music_salon_v2.0.db");
    return 0;
}