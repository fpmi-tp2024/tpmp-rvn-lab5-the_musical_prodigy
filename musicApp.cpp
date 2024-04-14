#include <iostream>
#include <sqlite3.h>
#include <SQLiteCpp/SQLiteCpp.h>
#include "include/Model.h"

int main()
{
    Model* model = new Model();
    model->addDatabase("music_salon_v2.0.db");
    User user(USER, "user3", "abccdb");
    User user2(ADMIN, "stasN", "987123");
    User user3(ADMIN, "stasN", "9871234");
   /* std::cout << model->hasUser(user2);
    std::cout << model->hasUserWithLogin("stasN");
    std::cout<<model->addNewUser(user3);*/
    /*std::cout << model->canBuyCD(1, 8) <<std::endl;
    std::cout << model->canBuyCD(1, 90) << std::endl;
    std::cout << model->canBuyCD(1, 88) << std::endl;
    std::cout << model->canBuyCD(4, 8) << std::endl;*/
    std::cout << model->availableCDsInfo().size();
    return 0;
}
