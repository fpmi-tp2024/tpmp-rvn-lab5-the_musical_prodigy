#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sqlite3.h>
#include <SQLiteCpp/SQLiteCpp.h>
#include "../include/User.h"
#include "../include/CD.h"
#include "../include/Operation.h"
class Model
{
private:
    std::string dbFileName;
    SQLite::Database *db = nullptr;
    int getBestSellingCDId();
public:
    Model();
    Model(std::string dbFileName);
    ~Model();
    std::string getDBName() const;
    void setDBName(std::string& name);
    bool addDatabase(std::string dbFileName);
    bool addNewUser(User& user);
    bool hasUser(User& user);
    bool hasUserWithLogin(std::string login);
    bool canBuyCD(int CDCode, int quantity);
    bool buyCD(const std::vector<Operation>& operations);
    std::vector<CD> availableCDsInfo();
    CD bestSellingCDInfo();
    int getMostPopularSingerSoldCDsAmount();
    int getSoldCDsAmount(int CDCode, std::string startPeriod, std::string endPeriod);
    std::vector<std::vector<std::string>> getSoldAndLeftCDSortedDescDiff();
    std::vector<std::string> getSoldCDsNumberAndProfitByEachAuthor();
    bool addCD(int CDCode, int quantity);
    std::vector<std::vector<std::string>> getReceivedAndSoldCDAmountByEachCD(std::string startPeriod, std::string endPeriod);
    std::vector<std::vector<std::string>> getSoldCDsAmountAndProfit(int CDCode, std::string startPeriod, std::string endPeriod);
};