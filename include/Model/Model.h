#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <sqlite3.h>
#include <SQLiteCpp/SQLiteCpp.h>
#include "User.h"
#include "CD.h"
#include "Operation.h"
class Model
{
private:
    std::string dbFileName;
    SQLite::Database* db = nullptr;
    int getBestSellingCDId();
    std::vector<int> getReceivedAmount(const std::string& startDate, const std::string& endDate);
    std::vector<std::vector<int>> getSoldAmount(const std::string& startDate, const std::string& endDate);
public:
    Model();
    Model(std::string dbFileName);
    ~Model();
    std::string getDBName() const;
    void setDBName(std::string& name);
    bool addDatabase(std::string dbFileName);
    bool addNewUser(const User& user);
    bool hasUser(const User& user);
    bool hasUserWithLogin(std::string login);
    bool canBuyCD(int CDCode, int quantity);
    bool canBuyCD(int CDCode);
    std::vector<CD> availableCDsInfo();
    CD bestSellingCDInfo();
    int getMostPopularSingerSoldCDsAmount();
    int getSoldCDsAmount(int CDCode, std::string startPeriod, std::string endPeriod);
    std::vector<std::vector<std::string>> getSoldAndLeftCDSortedDescDiff();
    std::vector<std::vector<std::string>> getSoldCDsNumberAndProfitByEachAuthor();
    bool addOrBuyCD(const std::vector<Operation>& operations);
    std::vector<std::vector<int>> getReceivedAndSoldCDAmountByEachCD(std::string startPeriod, std::string endPeriod);
    std::vector<double> getSoldCDsAmountAndProfit(int CDCode, std::string startPeriod, std::string endPeriod);
};
