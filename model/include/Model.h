#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../include/User.h"
#include "../include/CD.h"
class Model
{
private:
    std::string dbFileName;
public:
    Model();
    Model(std::string dbFileName);
    ~Model();
    bool addDatabase(std::string dbFileName);
    bool addNewUser(User* user);
    bool hasUder(User* user);
    bool buyCD(int CDCode, int quantity);
    std::vector<CD*> availableCDsInfo();
    std::vector<CD*> bestSellingCDsInfo();
    int getMostPopularSingerSoldCDsAmount();
    int getSoldCDsAmount(int CDCode, std::string startPeriod, std::string endPeriod);
    std::vector<std::vector<std::string>> getSoldAndLeftCDSortedDescDiff();
    std::vector<std::string> getSoldCDsNumberAndProfitByEachAuthor();
    bool addCD(int CDCode, int quantity);
    std::vector<std::vector<std::string>> getReceivedAndSoldCDAmountByEachCD(std::string startPeriod, std::string endPeriod);
    std::vector<std::vector<std::string>> getSoldCDsAmountAndProfit(int CDCode, std::string startPeriod, std::string endPeriod);
};


