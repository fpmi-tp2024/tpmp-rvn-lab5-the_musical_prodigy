﻿#include <iostream>
#include <sqlite3.h>
#include <SQLiteCpp/SQLiteCpp.h>
#include "include/Model.h"

// TESTING GROUND

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
    //std::cout << model->availableCDsInfo().size();
    //std::cout << model->bestSellingCDInfo().getCDCode();
    /*std::cout << model->getSoldCDsAmount(3, "2024-01-02", "2024-01-18") << std::endl;
    std::cout << model->getSoldCDsAmount(3, "2024-01-02", "2024-01-03") << std::endl;
    std::cout << model->getSoldCDsAmount(3, "2024-01-01", "2024-01-19") << std::endl;
    std::cout << model->getSoldCDsAmount(3, "2024-01-19", "2024-01-20") << std::endl;
    std::vector<std::vector<std::string>> res = model->getSoldAndLeftCDSortedDescDiff();
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
        {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }*/
    std::vector<std::vector<int>> res = model->getReceivedAndSoldCDAmountByEachCD("2024-01-01", "2024-01-18");
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
        {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::vector<double> res2 = model->getSoldCDsAmountAndProfit(3, "2024-01-02", "2024-01-18");
    for (int i = 0; i < res2.size(); i++)
    {
        std::cout << res2[i]<< " ";
    }
    std::cout << std::endl;
    std::cout << model->getSoldCDsAmount(3, "2024-01-02", "2024-01-02") << std::endl;
    std::cout << model->getMostPopularSingerSoldCDsAmount() << std::endl;
    Operation op(OperationCode::SELL, 1, "2024-04-18", 100);
    Operation op2(OperationCode::SELL, 3, "2024-04-18", 10);
    std::vector<Operation> vect;
    vect.push_back(op);
    vect.push_back(op2);

    std::cout << model->addOrBuyCD(vect);
    return 0;
}
